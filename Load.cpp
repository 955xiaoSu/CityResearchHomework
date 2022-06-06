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

// 功能：提取字符串中的数字
// 参数：字符串
// 返回：int类型数字
int transNum(string& s) {
	// 例："区号：01"
	// 第一步实现数字部分的截断，即提取ASCii码形式的01
	// 第二步再将ASCii码形式的数字01转换为int类型的数字01
	
	// 第一步利用字符串的substr()函数对字符串进行截断
	// 由于中英文字符不同的缘故，所以截取时长度要+ 2
	string temp;
	size_t pos = s.find("：");    
	temp = s.substr(pos + 2);     

	// 第二步对每个字符进行处理转换为数字形式
	int ans = 0; 
	int sub = 0; // 标记temp的下标
	int digit = 0; // 标记每个字符转化为数字的形式
	while (sub + 1 <= temp.length()) {
		digit = temp[sub++] - '0';
		ans = ans * 10 + digit;
	}
	return ans;
}

// 功能：提取字符串中所需要的有用字符
// 参数：字符串
// 返回：字符串
string transString(string& s) {
	string temp = " ";	string ans = " ";
	size_t pos = s.find("：");
	temp = s.substr(pos + 2);
	return temp;
}

// 功能：统计文本的行数
// 参数：ifstream对象
// 返回：文本行数
int lineCount(ifstream& temp) {
	char c;
	int count = 0;
	while (temp.get(c)) {
		if (c == '\n')
			count++;
	}
	return count + 1; // txt文件最后一行没有'\n'，所以统计时要+ 1
}

// 功能：将文本数据存储到allCity类指针所指向的内存
// 参数：ifstream对象
// 返回：void
void readData(ifstream& temp) {
	// 获取文本行数并分配内存
	int totalLines = lineCount(temp);
	allCity = new city[totalLines];

	temp.clear(); // 由于统计了行数，使文件指针指向了文件末尾，首先清除文件流状态
	temp.seekg(0, ios::beg); // 其次回到文件的起始位置

	// 逐步读取数据并存储
	std::string s = " ";	int occa = 0;	int sub = 0;
	while (!temp.eof()) {
		// EOF是一个宏，它代表了-1这个值，如果在文件当中读到了0xff或者到了文件末尾，
		// 文件结构指针里面的flags字节的_F_EOF位都会被置为1，这一位被置为1，库函数就会认为到了文件末尾了。
		// 函数feof()其实是一个类函数宏，这个宏就是通过把文件结构指针的flags字节跟_F_EOF进行与运算来检测_F_EOF是否为1，并判断是否到了文件末尾的。
		temp >> s;	s = transString(s);  corProvince[s] = sub;      allCity[sub].setProvince(s);
		temp >> s;	s = transString(s);  corAbbreviation[s] = sub;  allCity[sub].setAbbreviation(s);
		temp >> s;	s = transString(s);  corCityName[s] = sub;      allCity[sub].setCityName(s);

		// 提取字符串中的数字并进行存储
		temp >> s;	occa = transNum(s);  corZoneDiscription[occa] = sub;  allCity[sub].setZoneDiscription(occa);
		temp >> s;	occa = transNum(s);  corPostalCode[occa] = sub;       allCity[sub].setPostalCode(occa);
		sub++;
	}
}

// 功能：实现对以txt形式存储的文件，读取文本数据并存储
// 参数：void
// 返回：void
void loadTxt() {
	ifstream fin;

	// 对文件是否成功打开进行判断
	fin.open("D:/Temp.txt", ios::in);
	if (!fin) {
		cerr << "Error : fail to open the file." << endl;
		exit(1);
	}

	readData(fin);
	fin.close();
}

#endif
