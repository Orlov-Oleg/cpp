#include<iostream>
#include<io.h>
//#include<stdlib.h>
using namespace std;

#define MAX_NAME_LEN 32			// Максимальная длина имена абонента
#define PATH_OF_BASE "Base.dat"	// Путь к файлу с базой

struct PhoneBook {
	char Name[MAX_NAME_LEN];	// Имя абонента
	int Number;		// Номер абонента

	PhoneBook*left, *right, *parent;
};

class Tree {
	PhoneBook*root;
public:
	Tree();
	~Tree();
	void AddMenu();
	void Add(PhoneBook*pb);
	void PrintMenu();
	void Print(PhoneBook*Node);
	void DelMenu();
	void Del(PhoneBook*pb = 0);
	PhoneBook*Next(PhoneBook*Node);
	PhoneBook*Min(PhoneBook*Node);
	PhoneBook*GetRoot();
	void SearchMenu();
	PhoneBook*Search(PhoneBook*Node, char*Name);
	//PhoneBook*Search(PhoneBook*Node, int Number);
	void Save();
	void FileWrite();
	void FileWrite(PhoneBook*Node);
	void FileAdd();
	void Read();
};

Tree t;

Tree::Tree() {
	root = NULL;
}
Tree::~Tree() {
	Del();
}
void Tree::AddMenu() {
	PhoneBook*newPhoneBook = new PhoneBook;
	cin.ignore(10, '\n');
	cout << "Введите имя абонента: ";
	cin >> newPhoneBook->Name;
	cout << "Введите номер абонента: ";
	cin >> newPhoneBook->Number;
	Add(newPhoneBook);
}
void Tree::Add(PhoneBook*pb) {
	pb->left = NULL;
	pb->right = NULL;

	PhoneBook*y = NULL;
	PhoneBook*Node = root;

	while(Node != 0) {
		y = Node;
		if(strcmp(pb->Name, Node->Name) < 0) {
			Node = Node->left;
		}
		else {
			Node = Node->right;
		}
	}
	pb->parent = y;

	if(y == 0) {
		root = pb;
	}
	else if(strcmp(pb->Name, y->Name) < 0) {
		y->left = pb;
	}
	else {
		y->right = pb;
	}
}
void Tree::PrintMenu() {
	char answerPrint;
	cout << "\na или 1 - Для вывода сведений обо всех абонентах"
		"\nn или 2 - НЕ РАБОТАЕТ!!! Для вывода сведений из диапазона имен"
		"\nt или 3 - НЕ РАБОТАЕТ!!! Для вывода сведений из диапазона номеров"
		"\nx или 8 - Вернуться назад"
		"\nВаш выбор: ";
	cin >> answerPrint;
	switch(answerPrint) {
	case 'a':
	case '1':
		cout << "\nВывод сведений обо всех абонентах\n";
		t.Print(GetRoot());
		break;
	case 'n':
	case '2':
		cout << "\nВывод сведений по именам\n";

		break;
	case 't':
	case '3':
		cout << "\nВывод сведений по номерам\n";

		break;
	case 'x':
	case '8':
		cout << "\nНазад\n";
		break;
	default:
		break;
	}
}
void Tree::Print(PhoneBook*Node) {
	if(Node != 0) {
		Print(Node->left);
		cout << Node->Name
			<< " - "
			<< Node->Number
			<< endl;
		Print(Node->right);
	}
}
void Tree::DelMenu() {
	char answerDel;
	cout << "\na или 1 - Для удаления всех абонентов"
		"\nn или 2 - НЕ РАБОТАЕТ!!! Для удаления абонента по имени"
		"\nt или 3 - НЕ РАБОТАЕТ!!! Для удаления абонента по телефону"
		"\nx или 8 - Вернуться назад"
		"\nВаш выбор: ";
	cin >> answerDel;
	switch(answerDel) {
	case 'a':
	case '1':
		cout << "\nУдаление всех абонентов\n";
		// Вызываем функцию Del с параметром по умолчанию 0
		t.Del();
		break;
	case 'n':
	case '2':
		cout << "\nУдаление абонента по имени\n";

		break;
	case 't':
	case '3':
		cout << "\nУдаление абонента по телефону\n";

		break;
	case 'x':
	case '8':
		cout << "\nНазад\n";
		break;
	default:
		cout << "\nНеизвестная команда\n";
		break;
	}
}
void Tree::Del(PhoneBook*pb) {
	if(pb != 0) {
		PhoneBook*Node, *y;

		if(pb->left == 0 || pb->right == 0) {
			y = pb;
		}
		else
			y = Next(pb);

		if(y->left != 0) {
			Node = y->left;
		}
		else {
			Node = y->right;
		}

		if(Node != 0) {
			Node->parent = y->parent;
		}
		if(y->parent == 0) {
			root = Node;
		}
		else if(y == y->parent->left) {
			y->parent->left = Node;
		}
		else {
			y->parent->right = Node;
		}

		if(y != pb) {
			strcpy(pb->Name, y->Name);
			pb->Number = y->Number;
		}

		delete y;
	}
	else {	// Удаление всего дерева
		while(root != 0) {
			Del(root);
		}
	}
}
PhoneBook*Tree::Next(PhoneBook*Node) {
	PhoneBook*y = 0;
	if(Node != 0) {
		if(Node->right != 0) {
			return Min(Node->right);
		}
		while(y != 0 && Node == y->right) {
			Node = y;
		}
	}
}
PhoneBook*Tree::Min(PhoneBook*Node) {
	if(Node != 0) {
		while(Node->left != 0) {
			Node = Node->left;
		}
	}
	return Node;
}
PhoneBook*Tree::GetRoot() {
	return root;
}
void Tree::SearchMenu() {
	char answerSearch;
	cout << "\nn или 1 - Поиск абонента по имени"
		"\nt или 2 - Поиск абонента по номеру"
		"\nx или 8 - Назад"
		"\nВаш выбор:";
	cin >> answerSearch;
	switch(answerSearch) {
	case 'n':
	case '1':
		cout << "\nПоиск абонента по имени\n";
		char NameSearch[MAX_NAME_LEN];
		cout << "\nВведите имя абонента\n";
		//cin >> NameSearch;
		// ПОЧЕМУ-ТО НЕ ПРЕДЛАГАЕТ ВВЕСТИ ДАННЫЕ, А ПРОСТО ИДЕТ ДАЛЬШЕ
		cin.getline(NameSearch, MAX_NAME_LEN);
		Search(GetRoot(), NameSearch);
		break;
	case 't':
	case '2':
		cout << "\nПоиск абонента по телефону\n";

		break;
	case 'x':
	case '8':
		cout << "\nНазад\n";
		break;
	default:
		cout << "\nНеизвестная команда\n";
		break;
	}
}
PhoneBook*Tree::Search(PhoneBook*Node, char*Name) {
	while(Node != 0 && strcmp(Name, Node->Name) != 0) {
		if(strcmp(Name, Node->Name) < 0) {
			Node = Node->left;
		}
		else {
			Node = Node->right;
		}
	}
	return Node;
}
void Tree::Save() {
	//char source[_MAX_PATH];
	char answerSave;

	/*cout << "\nВведите путь и название файла с базой:\n";
	cin.getline(PATH_OF_BASE, _MAX_PATH);*/

	if(_access(PATH_OF_BASE, 00) == 0) {
		cout << "\nТакой файл уже существует!"
			"\nw или 1 - Перезаписать файл"
			//"\na или 2 - Дописать в файл"
			"\nx или 8 - Назад"
			"\nВаш выбор:";
		cin >> answerSave;
		switch(answerSave) {
		case 'w':
		case '1':
			FileWrite();
			cout << "\nФайл перезаписан\n";
			break;
		/*case 'a':
		case '2':
			cout << "\nИнформация будет дописана в файл\n";
			FileAdd();
			break;*/
		case 'x':
		case '8':
			cout << "\nНазад\n";
			break;
		default:
			break;
		}
		//cin.getline(answerSave, 2);
		//if(!strcmp(answerSave,"2")||(!strcmp(answerSave,"y"))) {
		//	cout << "\nДописать в существующий файл (y или 1 - Да/ n или 2 - Нет)?\n";
		//	cin >> answerSave2;
		//	//cin.getline(answerSave2, 2);
		//	if(strcmp(answerSave2,"1")||strcmp(answerSave2,"y")) {
		//		cout << "\nОтмена\n";
		//	}
		//	else if(strcmp(answerSave,"1")||strcmp(answerSave,"y")) {
		//		cout << "\nНеправильный ввод\n";
		//	}
		//	else if(!strcmp(answerSave,"1")||(!strcmp(answerSave,"y"))) {
		//		cout << "\nФайл удален\n";
		//		FILE*f = fopen(PATH_OF_BASE, "w");
		//		fclose(f);
		//	}
		//	if(_access(PATH_OF_BASE, 02) == -1) {
		//		cout << "\nНет доступа к записи\n";
		//	}
		//}
	}
	else {
		cout << "\nДанные записаны в файл\n";
		FileWrite();
	}

	/*FILE*f = fopen(PATH_OF_BASE, "a");
	if(!f) {
		exit(0);
	}

	fwrite(GetRoot(), sizeof(PhoneBook), 1, f);
	fclose(f);*/
}
void Tree::FileWrite() {
	FILE*f = fopen(PATH_OF_BASE, "w+");
	if(!f) {
		exit(0);
	}
	PhoneBook*Node = GetRoot();
	FileWrite(Node);
	fclose(f);
}
void Tree::FileWrite(PhoneBook*Node) {
	FILE*f = fopen(PATH_OF_BASE, "a+");
	if(!f) {
		exit(0);
	}
	if(Node != 0) {
		FileWrite(Node->left);
		fwrite(Node, sizeof(PhoneBook), 1, f);
		FileWrite(Node->right);
	}
	fclose(f);
}
void Tree::FileAdd() {
	FILE*f = fopen(PATH_OF_BASE, "a");
	fclose(f);
}
void Tree::Read() {
	FILE*f = fopen(PATH_OF_BASE, "r+");
	if(f == 0) {
		cout << "\nФайл открыть не получилось\n";
		return;
	}
	if(_access(PATH_OF_BASE, 00) == -1) {
		cout << "\nНе получилось получить доступ к файлу\n";
		return;
	}
	// Удаляем текущее дерево абонентов
	// По умолчанию вызывается функция Del с параметром 0
	Del();
	PhoneBook*newPhoneBook = new PhoneBook;
	while(fread(newPhoneBook, sizeof(PhoneBook), 1, f)) {
		Add(newPhoneBook);
	}
	fclose(f);
}
int main() {
	setlocale(0, "rus");

	char answerMain;
	while(true) {
		cout << "\na или 1 - Добавление нового абонента"
			"\nd или 2 - Удаление абонентов"
			"\nm или 3 - НЕ РАБОТАЕТ!!! Изменение данных абонента"
			"\nf или 4 - НЕ РАБОТАЕТ!!! Поиск абонента по номеру или имени"
			"\np или 5 - Вывести сведения о всех абонентах"
			"\nw или 6 - Записать все данные в файл"
			"\nr или 7 - НЕ РАБОТАЕТ!!! Прочитать все данные из файла"
			"\nx или 8 - Выход"
			"\nВаш выбор: ";
		cin >> answerMain;
		switch(answerMain) {
		case 'a':
		case '1':
			cout << "\nДобавление абонента\n";
			t.AddMenu();
			break;
		case 'd':
		case '2':
			cout << "\nУдаление абонентов\n";
			t.DelMenu();
			break;
		case 'm':
		case '3':
			cout << "\nИзменение данных абонента\n";

			break;
		case 'f':
		case '4':
			cout << "\nПоиск абонента по номеру или имени\n";
			t.SearchMenu();
			break;
		case 'p':
		case '5':
			cout << "\nВывод сведений\n";
			t.PrintMenu();
			break;
		case 'w':
		case '6':
			cout << "\nЗапись данных\n";
			t.Save();
			break;
		case 'r':
		case '7':
			cout << "\nЧтение данных\n";
			t.Read();
			break;
		case 'x':
		case '8':
			cout << "\nВыход\n";
			exit(0);
			break;
		default:
			cout << "\nНеизвестная команда\n";
			break;
		}
	}
	return 0;
}