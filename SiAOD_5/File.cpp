#include "File.h"

void File::txtToBin(string name, string nameBin)
{
	ifstream ft;
	ofstream fb;
	ft.open(name, ios::in);
	if (!ft) cout << "Файл не открыт\n";
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
	cout << "Номер карты : ";
	cin >> s.cardNum;
	cout << "Код заболевания: ";
	cin >> s.code;
	cout << "Фамилия врача: ";
	cin >> s.docName;
	fb.write((char*)&s, sizeof(patient));
	fb.close();
}

void File::searchLin(string namefile, int key) {
	ifstream fb;
	fb.open(namefile, ios::in | ios::binary);
	patient x;
	if (!fb) cerr << "Файл не открыт\n";
	else {
		fb.read((char*)&x, sizeof(patient));
		while (!fb.eof()) {
			bool flag = true;
			if (x.cardNum != key)
				flag = false;
			if (flag) {
				cout << "Запись с заданным ключом: \n";
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
		cout << "Запись с заданным ключом не найдена \n";
		fb.close();
	}
}

void File::searchByNum(string namefile, int num) {
	ifstream fb;
	fb.open(namefile, ios::in | ios::binary);
	patient x;
	if (!fb) cerr << "Файл не открыт\n";
	else {
		fb.seekg((num - 1) * sizeof(patient), ios::beg);
		fb.read((char*)&x, sizeof(patient));
		cout << "Найенная запись: \n";
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
	if (!fb) cout << "Файл не открыт\n";
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