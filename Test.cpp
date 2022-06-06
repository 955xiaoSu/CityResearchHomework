#include "City.h"
#include "Load.cpp" // 实现对txt文件的读取
#include <iostream>
using namespace std;

void searchInterface();

void Init() {
	// 注意：map不能成为city本身的数据成员，否则形成会对自身的循环调用
	corProvince.clear();
	corAbbreviation.clear();
	corCityName.clear();
	corZoneDiscription.clear();
	corPostalCode.clear();
}

int main() {
	Init(); // Init()与loadTxt()的先后顺序是重要的，否则所有的map映射都只能映射到第一条数据
	loadTxt();
	searchInterface();
	return 0;
}

void print(int sub) {
	cout << endl;
	cout << "省份：\t" << allCity[sub].getProvince() << endl
		<< "简称：\t" << allCity[sub].getAbbreviation() << endl
		<< "城市：\t" << allCity[sub].getCityName() << endl
		<< "区号：\t" << allCity[sub].getZoneDiscription() << endl
		<< "邮政编码：\t" << allCity[sub].getPostalCode() << endl;
	return;
}

// 交互界面的设计
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

		// 如果输入了均不符合的语句，那么抛出异常并重新输入
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