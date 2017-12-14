
#pragma once

#include <string>

using namespace std;

class GPoint
{
public:
	GPoint(void);
	GPoint(int id, std::string d, std::string t, float t_v,double lat, double lon, float speed);
	~GPoint(void);
	int ID;
	string D;
	string T;
	float T_V;
	double Lat;
	double Lon;
	float Speed;
	double dist;//distance to the last point
};

