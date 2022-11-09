#include "File.h"

void File::txtToBin(string name, string nameBin)
{
	ifstream ft;
	ofstream fb;
	ft.open(name, ios::in);
	if (!ft) cout << "���� �� ������\n";
	fb.open(nameBin, ios::out | ios::binary | ios::trunc);
	while (!ft.eof())
	{
		patient newS;
		ft >> newS.cardNum;
		ft >> newS.code;
		ft >> newS.docName;
		if (!ft.eof()) {
			ft.get();
			fb.write((char*)&newS, sizeof(patient));
		}
	}
	ft.close();
	fb.close();
}

void File::addToBin(string name) {
	ofstream fb;
	fb.open(name, ios::out | ios::binary);
	patient s;
	cout << "����� ����� : ";
	cin >> s.cardNum;
	cout << "��� �����������: ";
	cin >> s.code;
	cout << "������� �����: ";
	cin >> s.docName;
	fb.write((char*)&s, sizeof(patient));
	fb.close();
}

void File::searchLin(string namefile, int key) {
	ifstream fb;
	fb.open(namefile, ios::in | ios::binary);
	patient x;
	if (!fb) cerr << "���� �� ������\n";
	else {
		fb.read((char*)&x, sizeof(patient));
		while (!fb.eof()) {
			bool flag = true;
			if (x.cardNum != key)
				flag = false;
			if (flag) {
				cout << "������ � �������� ������: \n";
				cout << x.cardNum << '\n';
				cout << x.code << '\n';
				cout << x.docName<< '\n';
				fb.close();
				return;
			}
			else {
				fb.read((char*)&x, sizeof(patient));
			}
		}
		cout << "������ � �������� ������ �� ������� \n";
		fb.close();
	}
}

void File::searchByNum(string namefile, int num) {
	ifstream fb;
	fb.open(namefile, ios::in | ios::binary);
	patient x;
	if (!fb) cerr << "���� �� ������\n";
	else {
		fb.seekg((num - 1) * sizeof(patient), ios::beg);
		fb.read((char*)&x, sizeof(patient));
		cout << "�������� ������: \n";
		cout << x.cardNum << '\n';
		cout << x.code << '\n';
		cout << x.docName << '\n';
	}
	fb.close();
}

void File::printBin(string name)
{
	ifstream fb;
	fb.open(name, ios::in | ios::binary);
	if (!fb) cout << "���� �� ������\n";
	patient x;
	fb.read((char*)&x, sizeof(patient));
	while (!fb.eof())
	{
		cout << x.cardNum << '\n';
		cout << x.code << '\n';
		cout << x.docName << '\n';
		fb.read((char*)&x, sizeof(patient));
	}
	fb.close();
}