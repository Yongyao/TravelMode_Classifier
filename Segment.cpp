#include "StdAfx.h"
#include "Segment.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


CSegment::CSegment(void)
{
	HCR=0;
	SR=0;
	VCR=0;
//	In_Out=0;
//	W_N=0;
}

CSegment::CSegment(int num,vector<GPoint> vec,double h, double s, double v) //reload constructor
{
   nCount=num;
   Seg=vec;
   HCR=h;
   SR=s;
   VCR=v;
}

string CSegment::MytoString()
{
	ostringstream convert;
	convert<<nCount<<','<<stat<<','<<HCR<<','<<Lable<<','<<start_time<<','<<end_time<<','<<Duration<<','<<x_std<<','<<y_std<<','<<x_mean<<','<<y_mean;
	string para=convert.str();
	return para;
}

string CSegment::MyPointoString(GPoint p)
{
	GPoint GP=p;
	ostringstream convert;
	convert.precision(10);
	convert<<GP.ID<<','<<GP.Lon<<','<<GP.Lat<<','<<GP.Speed<<','<<GP.dist<<','<<Lable;   //setprecision
	string para=convert.str();
	return para;
}

double CSegment::SetTime()
{
	start_time=Seg[0].T_V;
	end_time=Seg[nCount-1].T_V;
	Duration=end_time-start_time;
	return Duration;
}

void CSegment::Average()
{
	x_mean=0;
	y_mean=0;
	for (int i=0;i<nCount;i++)
	{
		x_mean+=Seg[i].Lon;
		y_mean+=Seg[i].Lat;
	}
	x_mean=x_mean/nCount;
	y_mean=y_mean/nCount;
}

void CSegment::stdeviation()
{
	x_std=0;
	y_std=0;
	for (int i=0;i<nCount;i++)
	{
		x_std+=(Seg[i].Lon-x_mean)*(Seg[i].Lon-x_mean);
		y_std+=(Seg[i].Lat-y_mean)*(Seg[i].Lat-y_mean);
	}
	x_std=sqrt(x_std/nCount);
	y_std=sqrt(y_std/nCount);
}

double CSegment::GetHCR(float Threshold)      //Calculate HCR of each segment
{
	float T=Threshold;
	vector<double> Angle_Point;
	Angle_Point.push_back(0);
	int num_above_T=0;
	for (int i=1;i<Seg.size();i++)
	{
		double a=GetAngle(Seg[i-1],Seg[i]);
		Angle_Point.push_back(a);
	}
	vector<double> Angle_Change;
	Angle_Change.push_back(0);
	Angle_Change.push_back(0);
	for (int j=2;j<Angle_Point.size();j++)
	{
		double b=abs(Angle_Point[j]-Angle_Point[j-1]);
		if (b>PI)
		{
			b=2*PI-b;
		}
		Angle_Change.push_back(b);

	}

	for (int j=0;j<Angle_Change.size();j++)
	{
		if (Angle_Change[j]>T)
		{
			num_above_T++;
		}
	}
	HCR=double(num_above_T)/double(Angle_Change.size()-2);
	return HCR;
   
}
double CSegment::GetAngle(GPoint p1,GPoint p2)  //Calculate the clockwise direction between two points based on positive X axis
{
	double x=p2.Lon-p1.Lon;
	double y=p2.Lat-p1.Lat;
	double angle;
	
	if (x==0)    //when x is equal to 0, arctan() can't be calculated
	{
		if (y==0)
		{
			angle=0;
		} 
		else if (y>0)
		{
			angle=PI/2;
		} 
		else
		{
			angle=3*PI/2;
		}
		
	}
	else
	{
		angle=atan2(y,x);
		if (angle>0)
		{
			if (x<0)
			{
				angle=angle+PI;
			}
		}
		else if (angle<0)
		{
			if (x>0)
			{
				angle=angle+2*PI;
			}
			else
			{
				angle=angle+PI;
			}
		}

	}

	return angle;
}

CSegment::~CSegment(void)
{
}
