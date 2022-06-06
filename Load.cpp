#pragma once
#ifndef LOAD_H_
#define LOAD_H_
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

extern city* allCity = nullptr;

map<std::string, int> corProvince;
map<std::string, int> corAbbreviation;
map<std::string, int> corCityName;
map<int, int> corZoneDiscription;
map<int, int> corPostalCode;

// ���ܣ���ȡ�ַ����е�����
// �������ַ���
// ���أ�int��������
int transNum(string& s) {
	// ����"���ţ�01"
	// ��һ��ʵ�����ֲ��ֵĽضϣ�����ȡASCii����ʽ��01
	// �ڶ����ٽ�ASCii����ʽ������01ת��Ϊint���͵�����01
	
	// ��һ�������ַ�����substr()�������ַ������нض�
	// ������Ӣ���ַ���ͬ��Ե�ʣ����Խ�ȡʱ����Ҫ+ 2
	string temp;
	size_t pos = s.find("��");    
	temp = s.substr(pos + 2);     

	// �ڶ�����ÿ���ַ����д���ת��Ϊ������ʽ
	int ans = 0; 
	int sub = 0; // ���temp���±�
	int digit = 0; // ���ÿ���ַ�ת��Ϊ���ֵ���ʽ
	while (sub + 1 <= temp.length()) {
		digit = temp[sub++] - '0';
		ans = ans * 10 + digit;
	}
	return ans;
}

// ���ܣ���ȡ�ַ���������Ҫ�������ַ�
// �������ַ���
// ���أ��ַ���
string transString(string& s) {
	string temp = " ";	string ans = " ";
	size_t pos = s.find("��");
	temp = s.substr(pos + 2);
	return temp;
}

// ���ܣ�ͳ���ı�������
// ������ifstream����
// ���أ��ı�����
int lineCount(ifstream& temp) {
	char c;
	int count = 0;
	while (temp.get(c)) {
		if (c == '\n')
			count++;
	}
	return count + 1; // txt�ļ����һ��û��'\n'������ͳ��ʱҪ+ 1
}

// ���ܣ����ı����ݴ洢��allCity��ָ����ָ����ڴ�
// ������ifstream����
// ���أ�void
void readData(ifstream& temp) {
	// ��ȡ�ı������������ڴ�
	int totalLines = lineCount(temp);
	allCity = new city[totalLines];

	temp.clear(); // ����ͳ����������ʹ�ļ�ָ��ָ�����ļ�ĩβ����������ļ���״̬
	temp.seekg(0, ios::beg); // ��λص��ļ�����ʼλ��

	// �𲽶�ȡ���ݲ��洢
	std::string s = " ";	int occa = 0;	int sub = 0;
	while (!temp.eof()) {
		// EOF��һ���꣬��������-1���ֵ��������ļ����ж�����0xff���ߵ����ļ�ĩβ��
		// �ļ��ṹָ�������flags�ֽڵ�_F_EOFλ���ᱻ��Ϊ1����һλ����Ϊ1���⺯���ͻ���Ϊ�����ļ�ĩβ�ˡ�
		// ����feof()��ʵ��һ���ຯ���꣬��������ͨ�����ļ��ṹָ���flags�ֽڸ�_F_EOF���������������_F_EOF�Ƿ�Ϊ1�����ж��Ƿ����ļ�ĩβ�ġ�
		temp >> s;	s = transString(s);  corProvince[s] = sub;      allCity[sub].setProvince(s);
		temp >> s;	s = transString(s);  corAbbreviation[s] = sub;  allCity[sub].setAbbreviation(s);
		temp >> s;	s = transString(s);  corCityName[s] = sub;      allCity[sub].setCityName(s);

		// ��ȡ�ַ����е����ֲ����д洢
		temp >> s;	occa = transNum(s);  corZoneDiscription[occa] = sub;  allCity[sub].setZoneDiscription(occa);
		temp >> s;	occa = transNum(s);  corPostalCode[occa] = sub;       allCity[sub].setPostalCode(occa);
		sub++;
	}
}

// ���ܣ�ʵ�ֶ���txt��ʽ�洢���ļ�����ȡ�ı����ݲ��洢
// ������void
// ���أ�void
void loadTxt() {
	ifstream fin;

	// ���ļ��Ƿ�ɹ��򿪽����ж�
	fin.open("D:/Temp.txt", ios::in);
	if (!fin) {
		cerr << "Error : fail to open the file." << endl;
		exit(1);
	}

	readData(fin);
	fin.close();
}

#endif
