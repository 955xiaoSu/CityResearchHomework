#include "City.h"
#include "Load.cpp" // ʵ�ֶ�txt�ļ��Ķ�ȡ
#include <iostream>
using namespace std;

void searchInterface();

void Init() {
	// ע�⣺map���ܳ�Ϊcity��������ݳ�Ա�������γɻ�������ѭ������
	corProvince.clear();
	corAbbreviation.clear();
	corCityName.clear();
	corZoneDiscription.clear();
	corPostalCode.clear();
}

int main() {
	Init(); // Init()��loadTxt()���Ⱥ�˳������Ҫ�ģ��������е�mapӳ�䶼ֻ��ӳ�䵽��һ������
	loadTxt();
	searchInterface();
	return 0;
}

void print(int sub) {
	cout << endl;
	cout << "ʡ�ݣ�\t" << allCity[sub].getProvince() << endl
		<< "��ƣ�\t" << allCity[sub].getAbbreviation() << endl
		<< "���У�\t" << allCity[sub].getCityName() << endl
		<< "���ţ�\t" << allCity[sub].getZoneDiscription() << endl
		<< "�������룺\t" << allCity[sub].getPostalCode() << endl;
	return;
}

// ������������
void searchInterface() {
	cout << "Welcome to search system!" << endl
		<< "Dear user, you can choose and input one way to search the information you need." << endl
		<< "1.\tSearch by province." << endl
		<< "2.\tSearch by abbreviation." << endl
		<< "3.\tSearch by city" << endl
		<< "4.\tSearch by zone discription." << endl
		<< "5.\tSearch by postal code." << endl
		<< "$ ";

	string s;	
	while (1) {
		getline(cin, s);	cout << endl;
		if (s == "Search by province") { 
			cout << "Please input the province:" << endl
				<< "$ ";
			string province;	getline(cin, province);
			print(corProvince[province]);  
			break; 
		}
		if (s == "Search by abbreviation") {
			cout << "Please input the abbreviation:" << endl
				<< "$ ";
			string abbreviation;	getline(cin, abbreviation);
			print(corAbbreviation[abbreviation]);
			break;
		}
		if (s == "Search by city") {
			cout << "Please input the city:" << endl
				<< "$ ";
			string city;	getline(cin, city);
			print(corCityName[city]);
			break;
		}
		if (s == "Search by zone discription") {
			cout << "Please input the zone discription:" << endl
				<< "$ ";
			int zoneDiscription;	cin >> zoneDiscription;
			print(corZoneDiscription[zoneDiscription]);
			break;
		}
		if (s == "Search by postal code") {
			cout << "Please input the postal code:" << endl
				<< "$ ";
			int postalCode;		cin >> postalCode;
			print(corPostalCode[postalCode]);
			break;
		}

		// ��������˾������ϵ���䣬��ô�׳��쳣����������
		if (s != "Search by province" &&
			s != "Search by abbreviation" &&
			s != "Search by city" &&
			s != "Search by zone discription" &&
			s != "Search by postal code") {
				cerr << "Error : Fail to search. Please input again.";
				cout << endl << "$ ";
		}
			
	}
	return;
}