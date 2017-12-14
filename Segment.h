#pragma once
#include "GPoint.h"
#include "math.h"
#include <vector>
using std::vector;

#define PI 3.14159


class CSegment
{
public:
	CSegment(void);
	CSegment(int num,vector<GPoint> vec,double h, double s, double v);
	double GetHCR(float Threshold);
	double GetAngle(GPoint p1,GPoint p2);
	double SetTime();
	void Average();
	void stdeviation();
	void   GetStd_XY();
	string MytoString();
	string MyPointoString(GPoint p);
	~CSegment(void);

	int nCount;
	vector<GPoint> Seg;
	double HCR;
	double SR;
	double VCR;
	double Duration;
	double start_time;
	double end_time;
	double x_mean,y_mean;
	double x_std,y_std;
	string stat; //1 indicates v<vs, 2 indicates vs<v<vt, 3 indicates v>vt
	string Lable;

 

};

