#include "StdAfx.h"
#include "GPoint.h"


GPoint::GPoint(void)
{
}


GPoint::GPoint(int id, string d, string t,float t_v, double lat, double lon, float speed)
{
	ID=id;
	this->D = d;
	this->T = t;
	T_V=t_v;
	Lat=lat;
	Lon=lon;
	Speed=speed;
}

GPoint::~GPoint(void)
{
}
