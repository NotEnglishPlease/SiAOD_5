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
		cout << "Практическая работа №5 ИКБО-06-21 Эрднеева Н.Д. Варинат 5" << "\n\n"
			"Меню\n"
			"0) Вывод содержимого бинарного файла.\n"
			"1) Создание двоичного файла записей фиксированной длины из заранее подготовленных данных в текстовом файле.\n"
			"2) Поиск и вывод записи в файле с помощью линейного поиска.\n"
			"3) Вывод записи по известному адресу в файле.\n"
			"4) Добавление записи в файл.\n"
			"5) Построение дерева по существующему файлу.\n"
			"6) Добавление элемента в дерево.\n"
			"7) Поиск по ключу в дереве.\n"
			"8) Удаление элемента из дерева.\n"
			"9) Вывод дерева в форме дерева.\n";
		cout << "Ваш выбор: ";
		cin >> problem;
		switch (problem) {
		case 0:
		{
			cout << "Введите название бинарного файла: ";
			cin >> binFileName;
			files.printBin(binFileName);
			system("pause");
			break;
		}
		case 1:
		{
			cout << "Введите название файла, который хотите создать: \n";
			cin >> binFileName;
			files.txtToBin(fileName, binFileName);
			system("pause");
			break;
		}
		case 2:
		{
			cout << "Введите название бинарного файла: ";
			cin >> binFileName;
			cout << "Введите ключ, запись с которым хотите найти в файле: ";
			cin >> key;
			files.searchLin(binFileName, key);
			system("pause");
			break;
		}
		case 3:
		{
			cout << "Введите название бинарного файла: ";
			cin >> binFileName;
			cout << "Введите номер записи, которую хотите найти: ";
			cin >> n;
			files.searchByNum(binFileName, n);
			system("pause");
			break;
		}
		case 4:
		{
			cout << "Введите название бинарного файла: ";
			cin >> binFileName;
			files.addToBin(binFileName);
			system("pause");
			break;
		}
		case 5:
		{
			cout << "Введите название бинарного файла: ";
			cin >> binFileName;
			tree.createTree(binFileName);
			system("pause");
			break;
		}
		case 6:
		{
			cout << "Введите ключ, который хотите вставить в дерево: ";
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
			cout << "Введите ключ, записи: ";
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
			cout << "Введите ключ, записи: ";
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
			cout << "Извините, я не совсем понимаю, что вы хотите сделать. Попробуйте в другой раз.\n";
			system("pause");
			break;
		}
	}
	return 0;
}