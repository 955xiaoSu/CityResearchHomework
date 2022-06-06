#pragma once
#ifndef CITY_H_
#define CITY_H_
#include <string>

class city {

private:
	std::string province; // ʡ��
	std::string abbreviation; // ���
	std::string cityName; // ��������
	int zoneDiscription; // ����
	int postalCode; // ��������

public:
	// ������г�ʼ��
	city();
	city(std::string &p, std::string &a, std::string &c, int &z, int &po) : 
		province(p), abbreviation(a), cityName(c), zoneDiscription(z), postalCode(po) {}

	// ��Ӧ���Ա�Ĺ��캯��
	void setProvince(std::string & p);
	void setAbbreviation(std::string & a);
	void setCityName(std::string & c);
	void setZoneDiscription(int & z);
	void setPostalCode(int & po);

	// Ϊ�˴ﵽ���ݷ�װĿ�ģ��ṩ�ӿں���ʵ�ֶ����Ա�ķ���
	std::string getProvince();
	std::string getAbbreviation();
	std::string getCityName();
	int getZoneDiscription();
	int getPostalCode();
};

#endif
