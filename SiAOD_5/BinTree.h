#pragma once
#include "File.h"

class BinTree {
public:
	int key;
	int n;
	BinTree* leftBranch;
	BinTree* rightBranch;
	BinTree(int key, int n);
	BinTree();
	void createTree(string namefile);
	void addEl(BinTree*& root, int key, int n);
	int searchByKey(int key);
	void searchBranch(BinTree*& root, int key);
	void delEl(int key, string fileName, bool flag);
	void outTree();
	void outLeftBranch(BinTree* root, int n);
	void outRightBranch(BinTree* root, int n);
};