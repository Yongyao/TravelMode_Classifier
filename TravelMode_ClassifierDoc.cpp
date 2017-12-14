
// TravelMode_ClassifierDoc.cpp : CTravelMode_ClassifierDoc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "TravelMode_Classifier.h"
#endif

#include "TravelMode_ClassifierDoc.h"
#include "DialogPara.h"
#include "GPoint.h"
#include "Segment.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#include <propkey.h>

#define LOCAL_PI 3.1415926535897932385 

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CTravelMode_ClassifierDoc

IMPLEMENT_DYNCREATE(CTravelMode_ClassifierDoc, CDocument)

BEGIN_MESSAGE_MAP(CTravelMode_ClassifierDoc, CDocument)
	ON_COMMAND(ID_TRAVELMODEANALYSIS_GPSDATA, &CTravelMode_ClassifierDoc::OnTravelmodeanalysisGpsdata)
	ON_COMMAND(ID_TRAVELMODEANALYSIS_MOVINGWINDOW, &CTravelMode_ClassifierDoc::OnTravelmodeanalysisMovingwindow)
END_MESSAGE_MAP()


// CTravelMode_ClassifierDoc 构造/析构

CTravelMode_ClassifierDoc::CTravelMode_ClassifierDoc()
{
	// TODO: 在此添加一次性构造代码

}

CTravelMode_ClassifierDoc::~CTravelMode_ClassifierDoc()
{
}

BOOL CTravelMode_ClassifierDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CTravelMode_ClassifierDoc 序列化

void CTravelMode_ClassifierDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CTravelMode_ClassifierDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CTravelMode_ClassifierDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:  strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CTravelMode_ClassifierDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CTravelMode_ClassifierDoc 诊断

#ifdef _DEBUG
void CTravelMode_ClassifierDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTravelMode_ClassifierDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CTravelMode_ClassifierDoc 命令


void CTravelMode_ClassifierDoc::OnTravelmodeanalysisGpsdata()
{

//	double a=42.2329942-42.23240817;
//	double b=-71.78907345+71.78890028;
//	double c=sqrt(a*a+b*b);
	// TODO: 在此添加命令处理程序代码
	CDialogPara dlg;
	CString target;
	float Vt, Vs, At, T1, T2, T3;
	if (dlg.DoModal()==IDOK)            //get data from dialog
	{
		target=dlg.m_inputfile_name;
		Vt=dlg.m_Vt;
		Vs=dlg.m_Vs;
		T1=dlg.m_T1;
		T2=dlg.m_T2;
		T3=dlg.m_T3;
	}
	else
		return;

	ifstream infile;                   //read CSV file
	infile.open(target);
	string line;
	int line_num=0;
	
	vector<GPoint> AllData;
	getline(infile,line);
	while (getline(infile,line))
	{
        line_num++;
		string ele;
		string datastr[6];
		char delim=',';
		stringstream stream(line);
		
		int i=0;
		while (std::getline(stream,ele,delim))
		{
           datastr[i]=ele; 
		   i++;
		}
        int ID=stoi(datastr[0]);
		string date=datastr[1];
		string time=datastr[2];


		string timestr[3];           //convert time from string to value
		delim=':';
		stringstream timestream(time);
		i=0;
		while (std::getline(timestream,ele,delim))
		{
			timestr[i]=ele; 
			i++;
		}
		float hour=stod(timestr[0]);
		float minute=stod(timestr[1]);
		float second=stod(timestr[2]);
		float t_v=hour+minute/60+second/3600;



		double lat=stod(datastr[3]);
		double lon=stod(datastr[4]);
		float speed=stod(datastr[5]);
		GPoint point(ID,date,time,t_v,lat,lon,speed);
		AllData.push_back(point);
	}                                                //copy data to ALLDATA

	infile.close();

	AllData[0].dist=0;
	for (int i=1;i<AllData.size();i++)
	{
//		double x=AllData[i].Lon-AllData[i-1].Lon;
//		double y=AllData[i].Lat-AllData[i-1].Lat;
//		AllData[i].dist=1000*sqrt(x*x+y*y);      //multiply 1000
		AllData[i].dist=DirectDistance(AllData[i],AllData[i-1]);
		if (AllData[i].dist==0)
		{
			AllData[i].Speed=0;
		}
		if(AllData[i].dist>500) //set a proper threshold,unit is meter,350 is good
		{
			//MessageBox(NULL,_T("Drift point has been detected."),_T("Error Message"),MB_OK);
			CString strmsg;
			strmsg.Format(_T("Drift point has been detected: %d"),i);
			AfxMessageBox(strmsg,MB_OK);
//			AfxMessageBox(_T("Drift point has been detected"),MB_OK);  
		}   
	}


	vector<vector<GPoint> > Segments;
	vector<GPoint> temp;

	temp.push_back(AllData[0]);

	for (int i=1;i<AllData.size();i++)
	{
		if (AllData[i-1].Speed<=Vs&&AllData[i].Speed<=Vs)
		{
			temp.push_back(AllData[i]);
		}else 
		if (AllData[i-1].Speed>=Vt&&AllData[i].Speed>=Vt)
		{
			temp.push_back(AllData[i]);
		}else 
		if (Vs<AllData[i-1].Speed&&AllData[i-1].Speed<Vt&&Vs<AllData[i].Speed&&AllData[i].Speed<Vt)
		{
			temp.push_back(AllData[i]);
		} 
		else
		{
			Segments.push_back(temp);
			temp.clear();
			temp.push_back(AllData[i]);
		}
	}


	if (!temp.empty())
	{
		Segments.push_back(temp);
	}

	int num1=Segments.size();
	
	vector<vector<GPoint> > Segments_2;                   //merge by using threshold_1
	Segments_2.push_back(Segments[0]);

	for (int i=1;i<Segments.size();i++)
	{
		if(Segments[i].size()<=T1)
		{
			vector<vector<GPoint> >::iterator it;
			it=Segments_2.end()-1;
			it->insert(it->end(),Segments[i].begin(),Segments[i].end());
		}
		else
		{
			Segments_2.push_back(Segments[i]);
		}

	}

	int num2=Segments_2.size();

	vector<CSegment> CSeg;
	for (int i=0;i<Segments_2.size();i++)
	{
		CSegment s;
		s.Seg=Segments_2[i];
		s.nCount=Segments_2[i].size();
		s.HCR=s.GetHCR(T2);
		if (Segments_2[i][0].Speed<=Vs)                  //set stat
		{
			s.stat='1';
		}else if (Vs<Segments_2[i][0].Speed&&Segments_2[i][0].Speed<Vt)
		{
			s.stat='2';
		}else
		{
            s.stat='3';
		}
		CSeg.push_back(s);
	}

for (int i=0;i<CSeg.size();i++)                       //set label
{
	int n=CSeg[i].nCount;
	float start_t=CSeg[i].Seg[0].T_V;
	float end_t=CSeg[i].Seg[n-1].T_V;
	double duration=CSeg[i].SetTime();
	if (CSeg[i].stat=="1")
	{
		
		if (duration>=0.5)
		{
			CSeg[i].Lable="Indoor Static";
		}else
		if (start_t<23&&23<end_t)
		{
		    CSeg[i].Lable="Indoor Static";	
		}else
		if (start_t<4.5&&4.5<end_t)
		{
			CSeg[i].Lable="Indoor Static";
		}else
		{
			CSeg[i].Lable="Outdoor Static";
		}
		
	}
	if (CSeg[i].stat=="2")
	{
		if (CSeg[i].HCR>=T3)
		{
			CSeg[i].Lable="Indoor Walking";
		} 
		else
		{
			CSeg[i].Lable="Outdoor Walking";
		}
	}
	if (CSeg[i].stat=="3")
	{
		CSeg[i].Lable="Driving";
	}
}


//merge happens if two or more successive segments are the same travel mode-pass2
vector<vector<GPoint> > Segments_3;                  
Segments_3.push_back(CSeg[0].Seg);

for (int i=1;i<CSeg.size();i++)
{
	if(CSeg[i-1].Lable==CSeg[i].Lable)
	{
		vector<vector<GPoint> >::iterator it;
		it=Segments_3.end()-1;
		it->insert(it->end(),CSeg[i].Seg.begin(),CSeg[i].Seg.end());
	}
	else
	{
		Segments_3.push_back(CSeg[i].Seg);
	}

}

vector<CSegment> CSeg_2;
for (int i=0;i<Segments_3.size();i++)
{
	CSegment s;
	s.Seg=Segments_3[i];
	s.nCount=Segments_3[i].size();
	s.HCR=s.GetHCR(T2);
	if (Segments_3[i][0].Speed<=Vs)                  //set stat
	{
		s.stat='1';
	}else if (Vs<Segments_3[i][0].Speed&&Segments_3[i][0].Speed<Vt)
	{
		s.stat='2';
	}else
	{
		s.stat='3';
	}
	CSeg_2.push_back(s);
}

for (int i=0;i<CSeg_2.size();i++)                       //set label
{
	int n=CSeg_2[i].nCount;
	float start_t=CSeg_2[i].Seg[0].T_V;
	float end_t=CSeg_2[i].Seg[n-1].T_V;
	double duration=CSeg_2[i].SetTime();
	if (CSeg_2[i].stat=="1")
	{
		
		if (duration>=0.5)
		{
			CSeg_2[i].Lable="Indoor Static";
		}else
		if (start_t<23&&23<end_t)
		{
			CSeg_2[i].Lable="Indoor Static";	
		}else
		if (start_t<4.5&&4.5<end_t)
	    {
			CSeg_2[i].Lable="Indoor Static";
		}else
		{
			CSeg_2[i].Lable="Outdoor Static";
		}

	}
	if (CSeg_2[i].stat=="2")
	{
		if (CSeg_2[i].HCR>=T3)
		{
			CSeg_2[i].Lable="Indoor Walking";
		} 
		else
		{
			CSeg_2[i].Lable="Outdoor Walking";
		}
	
	}
	if (CSeg_2[i].stat=="3")
	{
		CSeg_2[i].Lable="Driving";
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////////

//merge happens if two or more successive segments are the same travel mode-pass3
vector<vector<GPoint> > Segments_4;                  
Segments_4.push_back(CSeg_2[0].Seg);

for (int i=1;i<CSeg_2.size();i++)
{
	if(CSeg_2[i-1].Lable==CSeg_2[i].Lable)
	{
		vector<vector<GPoint> >::iterator it;
		it=Segments_4.end()-1;
		it->insert(it->end(),CSeg_2[i].Seg.begin(),CSeg_2[i].Seg.end());
	}
	else
	{
		Segments_4.push_back(CSeg_2[i].Seg);
	}

}

vector<CSegment> CSeg_3;
for (int i=0;i<Segments_4.size();i++)
{
	CSegment s;
	s.Seg=Segments_4[i];
	s.nCount=Segments_4[i].size();
	s.HCR=s.GetHCR(T2);
	if (Segments_4[i][0].Speed<=Vs)                  //set stat
	{
		s.stat='1';
	}else if (Vs<Segments_4[i][0].Speed&&Segments_4[i][0].Speed<Vt)
	{
		s.stat='2';
	}else
	{
		s.stat='3';
	}
	CSeg_3.push_back(s);
}

for (int i=0;i<CSeg_3.size();i++)                       //set label
{
	int n=CSeg_3[i].nCount;
	float start_t=CSeg_3[i].Seg[0].T_V;
	float end_t=CSeg_3[i].Seg[n-1].T_V;
	double duration=CSeg_3[i].SetTime();
	if (CSeg_3[i].stat=="1")
	{
		
		if (duration>=0.5)
		{
			CSeg_3[i].Lable="Indoor Static";
		}else
			if (start_t<23&&23<end_t)
			{
				CSeg_3[i].Lable="Indoor Static";	
			}else
				if (start_t<4.5&&4.5<end_t)
				{
					CSeg_3[i].Lable="Indoor Static";
				}else
				{
					CSeg_3[i].Lable="Outdoor Static";
				}

	}
	if (CSeg_3[i].stat=="2")
	{
		if (CSeg_3[i].HCR>=T3)
		{
			CSeg_3[i].Lable="Indoor Walking";
		} 
		else
		{
			CSeg_3[i].Lable="Outdoor Walking";
		}

	}
	if (CSeg_3[i].stat=="3")
	{
		CSeg_3[i].Lable="Driving";
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////////

	ofstream out_file;                                 //output table1
	out_file.open("D:\\Table_1.csv");
	out_file<<"nCount"<<','<<"Status"<<','<<"HCR"<<','<<"Label"<<','<<"Start_time"<<','<<"End_time"<<','<<"Duration"<<
		','<<"x_std"<<','<<"y_std"<<','<<"x_mean"<<','<<"y_mean"<<endl;
	if (out_file.is_open())
	{
		auto it=CSeg.begin();
		while (it!=CSeg.end())
		{
			it->Average();
			it->stdeviation();
			out_file<<it->MytoString()<<endl;
			++it;
		}
		out_file.close();
	}


	ofstream out_file_2;                                 //output table2
	out_file_2.open("D:\\Table_2.csv");
	out_file_2<<"ID"<<','<<"Long"<<','<<"Lat"<<','<<"Speed"<<','<<"Distance"<<','<<"Lable"<<','<<"Seg_ID"<<endl;
	if (out_file_2.is_open())
	{
		auto it=CSeg.begin();
		int j=1;
		while (it!=CSeg.end())
		{
			for (int i=0;i<it->Seg.size();i++)
			{
				GPoint p=it->Seg[i];
				out_file_2<<it->MyPointoString(p)<<','<<j<<endl;
			}
			++it;
			++j;
		}
		out_file_2.close();
	}
////////////////////////////////////////////////////////////////////////////////////////////////////////
	ofstream out_file_3;                                 //output table3
	out_file_3.open("D:\\Table_3.csv");
	out_file_3<<"nCount"<<','<<"Status"<<','<<"HCR"<<','<<"Label"<<','<<"Start_time"<<','<<"End_time"<<','<<"Duration"<<
		','<<"x_std"<<','<<"y_std"<<','<<"x_mean"<<','<<"y_mean"<<endl;
	if (out_file_3.is_open())
	{
		auto it=CSeg_2.begin();

		while (it!=CSeg_2.end())
		{
			it->Average();
			it->stdeviation();
			out_file_3<<it->MytoString()<<endl;
			++it;
		}
		out_file_3.close();
	}


	ofstream out_file_4;                                 //output table4
	out_file_4.open("D:\\Table_4.csv");
	out_file_4<<"ID"<<','<<"Long"<<','<<"Lat"<<','<<"Speed"<<','<<"Distance"<<','<<"Lable"<<','<<"Seg_ID"<<endl;
	if (out_file_4.is_open())
	{
		auto it=CSeg_2.begin();
		int j=1;
		while (it!=CSeg_2.end())
		{
			for (int i=0;i<it->Seg.size();i++)
			{
				GPoint p=it->Seg[i];
				out_file_4<<it->MyPointoString(p)<<','<<j<<endl;
			}
			++it;
			++j;
		}
		out_file_4.close();
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////


	ofstream out_file_5;                                 //output table5
	out_file_5.open("D:\\Table_5.csv");
	out_file_5<<"nCount"<<','<<"Status"<<','<<"HCR"<<','<<"Label"<<','<<"Start_time"<<','<<"End_time"<<','<<"Duration"<<
		','<<"x_std"<<','<<"y_std"<<','<<"x_mean"<<','<<"y_mean"<<endl;
	if (out_file_5.is_open())
	{
		auto it=CSeg_3.begin();

		while (it!=CSeg_3.end())
		{
			it->Average();
			it->stdeviation();
			out_file_5<<it->MytoString()<<endl;
			++it;
		}
		out_file_5.close();
	}


	ofstream out_file_6;                                 //output table6
	out_file_6.open("D:\\Table_6.csv");
	out_file_6<<"ID"<<','<<"Long"<<','<<"Lat"<<','<<"Speed"<<','<<"Distance"<<','<<"Lable"<<','<<"Seg_ID"<<endl;
	if (out_file_6.is_open())
	{
		auto it=CSeg_3.begin();
		int j=1;
		while (it!=CSeg_3.end())
		{
			for (int i=0;i<it->Seg.size();i++)
			{
				GPoint p=it->Seg[i];
				out_file_6<<it->MyPointoString(p)<<','<<j<<endl;
			}
			++it;
			++j;
		}
		out_file_6.close();
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////

/*	FILE *stream;
	stream=fopen("D:\\Table_7.csv","w");
	fprintf(stream,"%s,%s,%s,%s,%s,%s\n","ID","Lat","Lon","Speed","Label","Seg_ID");
	auto it=CSeg_3.begin();
	int j=1;
	while (it!=CSeg_3.end())
	{
		for (int i=0;i<it->Seg.size();i++)
		{
			GPoint p=it->Seg[i];
			string str=it->Lable;
			const char *c=str.c_str();
			fprintf(stream,"%d,%.8f,%.8f,%6f,%d,%s\n",p.ID,p.Lat,p.Lon,p.Speed,j,c);
		}
		++it;
		++j;
	}
	fclose(stream);*/


}

void CTravelMode_ClassifierDoc::OnTravelmodeanalysisMovingwindow()
{
	// TODO: 在此添加命令处理程序代码
/*	GPoint P_1,P_2;
	P_1.Lat=0;
	P_1.Lon=0;
	P_2.Lat=90;
	P_2.Lon=0;
	double d=DirectDistance(P_1,P_2); */

}


double CTravelMode_ClassifierDoc::DirectDistance(GPoint p1, GPoint p2)
{
	double earthRadius = 3958.75;
	double dLat = ToRadians(p1.Lat-p2.Lat);
	double dLng = ToRadians(p1.Lon-p2.Lon);
	double a = sin(dLat/2) * sin(dLat/2) + 
		cos(ToRadians(p1.Lat)) * cos(ToRadians(p2.Lat)) * 
		sin(dLng/2) * sin(dLng/2);
	double c = 2 * atan2(sqrt(a), sqrt(1-a));
	double dist = earthRadius * c;
	double meterConversion = 1609.00;
	return dist * meterConversion;

}


double CTravelMode_ClassifierDoc::ToRadians(double degrees)
{
	double radians = degrees * LOCAL_PI / 180;
	return radians;
}
