#pragma once
#ifndef CITY_H_
#define CITY_H_
#include <string>

class city {

private:
	std::string province; // 省份
	std::string abbreviation; // 简称
	std::string cityName; // 城市名称
	int zoneDiscription; // 区号
	int postalCode; // 邮政编码

public:
	// 对类进行初始化
	city();
	city(std::string &p, std::string &a, std::string &c, int &z, int &po) : 
		province(p), abbreviation(a), cityName(c), zoneDiscription(z), postalCode(po) {}

	// 相应类成员的构造函数
	void setProvince(std::string & p);
	void setAbbreviation(std::string & a);
	void setCityName(std::string & c);
	void setZoneDiscription(int & z);
	void setPostalCode(int & po);

	// 为了达到数据封装目的，提供接口函数实现对类成员的访问
	std::string getProvince();
	std::string getAbbreviation();
	std::string getCityName();
	int getZoneDiscription();
	int getPostalCode();
};

#endif
