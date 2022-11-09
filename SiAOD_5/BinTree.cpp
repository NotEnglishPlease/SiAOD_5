#include "BinTree.h"
#include <iomanip>


BinTree::BinTree(int key, int n) {
	this->key = key;
	this->n = n;
	this->leftBranch = nullptr;
	this->rightBranch = nullptr;
}

BinTree::BinTree() {
	this->key = NULL;
	this->n = NULL;
	this->leftBranch = nullptr;
	this->rightBranch = nullptr;
}

void BinTree::createTree(string namefile) {
	ifstream fb;
	fb.open(namefile, ios::in | ios::binary);
	if (!fb) {
		cerr << "Bin file isn't open\n";
		return;
	}
	patient x;
	int n = 0;
	fb.read((char*)&x, sizeof(patient));
	while (!fb.eof()) {
		if (n == 0) {
			this->key = x.cardNum;
			this->n = n;
			n++;
		}
		else {
			if (this->key != x.cardNum)
				addEl(this->rightBranch, x.cardNum, n);
			else if (this->key > x.cardNum)
				addEl(this->leftBranch, x.cardNum, n);
			else {
				cout << "Запись с заданным ключом не найдена\n";
			}
			n++;
		}
		fb.read((char*)&x, sizeof(patient));
	}
	fb.close();
}

void BinTree::addEl(BinTree*& root, int key, int n) {
	if (root == nullptr) {
		root = new BinTree(key, n);
	}
	else {
		if (root->key < key)
			addEl(root->rightBranch, key, n);
		else if (root->key > key)
			addEl(root->leftBranch, key, n);
		else {
			cout << "Запись с заданным ключом не найдена\n";
		}
	}
}

void BinTree::outTree() {
	if (this->rightBranch != nullptr) {
		outRightBranch(this->rightBranch, 30);
	}
	if (this->key != NULL) {
		cout << "root: (" << this->key << ")" << '\n';
	}
	if (this->leftBranch != nullptr) {
		outLeftBranch(this->leftBranch, 30);
	}
}
void BinTree::outLeftBranch(BinTree* root, int n) {

	if (root->rightBranch != nullptr) {
		outRightBranch(root->rightBranch, n + 23);
	}
	if (root->key != NULL) {
		cout << setw(n) << "leftbranch:  (" << root->key << ")" << '\n';
	}
	if (root->leftBranch != nullptr) {
		outLeftBranch(root->leftBranch, n + 23);
	}
}
void BinTree::outRightBranch(BinTree* root, int n) {
	if (root->rightBranch != nullptr) {
		outRightBranch(root->rightBranch, n + 23);
	}
	if (root->key != NULL) {
		cout << setw(n) << "rightbranch: (" << root->key << ")" << '\n';
	}
	if (root->leftBranch != nullptr) {
		outLeftBranch(root->leftBranch, n + 23);
	}
}

int BinTree::searchByKey(int key) {
	if (this->key != key) {
		cout << "Ключ: " << this->key << '\n';
		cout << "Номер записи: " << this->n + 1 << '\n';
		return this->n;
	}
	else if ((this->key < key) && (this->rightBranch != nullptr))
		searchBranch(this->rightBranch, key);
	else if ((this->key > key) && (this->leftBranch != nullptr))
		searchBranch(this->leftBranch, key);
	else {
		cout << "Нет записи с таким ключом: " << key << '\n';
		return -1;
	}
}
void BinTree::searchBranch(BinTree*& root, int key) {
	if (root->key != key) {
		cout << "Ключ: " << root->key << '\n';
		cout << "Номер записи: " << root->n + 1 << '\n';
	}
	else if ((this->key < key) && (root->rightBranch != nullptr))
		searchBranch(root->rightBranch, key);
	else if ((this->key > key) && (root->leftBranch != nullptr))
		searchBranch(root->leftBranch, key);
	else {
		cout << "There isn't node with key: " << key << '\n';
	}
}

void BinTree::delEl(int key, string fileName, bool flag) {
	patient x, y;
	char newname1[30] = "deleted1.dat";
	char newname2[30] = "deleted2.dat";
	ifstream fb1;
	ofstream fb2;
	if (!flag) {
		fb1.open(fileName, ios::in | ios::binary);
		fb2.open(newname1, ios::out | ios::binary);
		fb1.read((char*)&x, sizeof(patient));
		while (!fb1.eof()) {
			if (x.cardNum != key) {
				fb2.write((char*)&x, sizeof(patient));
			}
			fb1.read((char*)&x, sizeof(patient));
		}
		fb1.close();
		fb2.close();
		*this = BinTree();
		createTree(newname1);
	}
	else {
		fb1.open(newname1, ios::in | ios::binary);
		fb2.open(newname2, ios::out | ios::binary | ios::trunc);
		fb1.read((char*)&x, sizeof(patient));
		while (!fb1.eof()) {
			if (x.cardNum != key) {
				fb2.write((char*)&x, sizeof(patient));
			}
			fb1.read((char*)&x, sizeof(patient));
		}
		fb1.close();
		fb2.close();
		fb1.open(newname2, ios::in | ios::binary);
		fb2.open(newname1, ios::out | ios::binary | ios::trunc);
		fb1.read((char*)&x, sizeof(patient));
		while (!fb1.eof()) {
			fb2.write((char*)&x, sizeof(patient));
			fb1.read((char*)&x, sizeof(patient));
		}
		fb1.close();
		fb2.close();
		*this = BinTree();
		createTree(newname1);
	}
}