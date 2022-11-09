#include "File.h"
#include "BinTree.h"

using namespace std;

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "rus");
	short problem;
	bool flag = true, flagTree = false;
	string s, fileName = "file.txt", binFileName;
	File files = File();
	BinTree tree = BinTree();
	int n, key, num = 6;
	patient x;
	while (flag)
	{
		system("cls");
		cout << "������������ ������ �5 ����-06-21 �������� �.�. ������� 5" << "\n\n"
			"����\n"
			"0) ����� ����������� ��������� �����.\n"
			"1) �������� ��������� ����� ������� ������������� ����� �� ������� �������������� ������ � ��������� �����.\n"
			"2) ����� � ����� ������ � ����� � ������� ��������� ������.\n"
			"3) ����� ������ �� ���������� ������ � �����.\n"
			"4) ���������� ������ � ����.\n"
			"5) ���������� ������ �� ������������� �����.\n"
			"6) ���������� �������� � ������.\n"
			"7) ����� �� ����� � ������.\n"
			"8) �������� �������� �� ������.\n"
			"9) ����� ������ � ����� ������.\n";
		cout << "��� �����: ";
		cin >> problem;
		switch (problem) {
		case 0:
		{
			cout << "������� �������� ��������� �����: ";
			cin >> binFileName;
			files.printBin(binFileName);
			system("pause");
			break;
		}
		case 1:
		{
			cout << "������� �������� �����, ������� ������ �������: \n";
			cin >> binFileName;
			files.txtToBin(fileName, binFileName);
			system("pause");
			break;
		}
		case 2:
		{
			cout << "������� �������� ��������� �����: ";
			cin >> binFileName;
			cout << "������� ����, ������ � ������� ������ ����� � �����: ";
			cin >> key;
			files.searchLin(binFileName, key);
			system("pause");
			break;
		}
		case 3:
		{
			cout << "������� �������� ��������� �����: ";
			cin >> binFileName;
			cout << "������� ����� ������, ������� ������ �����: ";
			cin >> n;
			files.searchByNum(binFileName, n);
			system("pause");
			break;
		}
		case 4:
		{
			cout << "������� �������� ��������� �����: ";
			cin >> binFileName;
			files.addToBin(binFileName);
			system("pause");
			break;
		}
		case 5:
		{
			cout << "������� �������� ��������� �����: ";
			cin >> binFileName;
			tree.createTree(binFileName);
			system("pause");
			break;
		}
		case 6:
		{
			cout << "������� ����, ������� ������ �������� � ������: ";
			cin >> key;
			if (key > tree.key) {
				tree.addEl(tree.rightBranch, key, n);
			}
			else {
				tree.addEl(tree.leftBranch, key, n);
			}
			num++;
			system("pause");
			break;
		}
		case 7:
		{
			cout << "������� ����, ������: ";
			cin >> key;
			int i = tree.searchByKey(key);
			if (i != -1) {
				files.searchByNum(binFileName, i + 1);
			}
			system("pause");
			break;
		}
		case 8:
		{
			cout << "������� ����, ������: ";
			cin >> key;
			tree.delEl(key, binFileName, flagTree);
			flagTree = true;
			system("pause");
			break;
		}
		case 9:
		{
			tree.outTree();
			system("pause");
			break;
		}
		break;
		default:
			cout << "��������, � �� ������ �������, ��� �� ������ �������. ���������� � ������ ���.\n";
			system("pause");
			break;
		}
	}
	return 0;
}