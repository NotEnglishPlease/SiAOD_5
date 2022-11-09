#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct patient
{
	int cardNum;
	int code;
	string docName;
};

class File {
public:
	void txtToBin(string name, string nameBin); 
	void searchLin(string namefile, int key);
	void searchByNum(string namefile, int num);
	void addToBin(string name);
	void printBin(string name);
};