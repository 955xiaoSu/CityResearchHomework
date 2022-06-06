#pragma once
#ifndef CITY_CPP_
#define CITY_CPP_
#include "City.h"

city::city() {
	province = abbreviation = cityName = " ";
	zoneDiscription = postalCode = 0;
}

// 类成员数据的初始化
void city::setProvince(std::string& p) { province = p; }
void city::setAbbreviation(std::string& a) { abbreviation = a; }
void city::setCityName(std::string& c) { cityName = c; }
void city::setZoneDiscription(int& z) { zoneDiscription = z; }
void city::setPostalCode(int& po) { postalCode = po; }

std::string city::getProvince() { return province; }
std::string city::getAbbreviation() { return abbreviation; }
std::string city::getCityName() { return cityName; }

int city::getZoneDiscription() { return zoneDiscription; }
int city::getPostalCode() { return postalCode; }

#endif 
