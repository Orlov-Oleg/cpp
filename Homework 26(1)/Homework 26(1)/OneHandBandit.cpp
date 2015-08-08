#include<iostream>
#include<conio.h>
#include<time.h>
using namespace std;

class QueueRing{
	int qr1[5];
	int qr2[5];
	int qr3[5];

	int MaxLength;
public:
	QueueRing(int n){
		MaxLength = n;
		for (int i = 0; i < 5; i++)
		{
			qr1[i] = qr2[i] = qr3[i] = i + 3;

		}
	}
	~QueueRing(){
		//delete[]qr1;// Должен освобождать память - но почему-то ругается
		//delete[]qr2;
		//delete[]qr3;
	}

	void Show(){
		system("cls");
		cout << "+-----------------+\n";
		cout << "|     |     |     |\n";
		cout << "|  " << qr1[0] << "  |  " << qr2[0] << "  |  " << qr3[0] << "  |\n";
		cout << "|     |     |     |  |\n";
		cout << "+-----------------+  |\n";
		cout << "|     |     |     |  |\n";
		cout << "|  " << qr1[1] << "  |  " << qr2[1] << "  |  " << qr3[1] << "  |  |\n";
		cout << "|     |     |     |  |\n";
		cout << "+-----------------+  |\n";
		cout << "|     |     |     |  |\n";
		cout << "|  " << qr1[2] << "  |  " << qr2[2] << "  |  " << qr3[2] << "  |  |\n";
		cout << "|     |     |     |  |\n";
		cout << "+-----------------+  O\n";
		_sleep(200);
	}
	void Game(){
		int a = rand() % 10;
		int b = rand() % 10;
		int c = rand() % 10;
		int max;
		if (a >= b&&a >= c)
		{
			max = a;
		}
		else if (b >= a&&b >= c)
		{
			max = b;
		}
		else
			max = c;

		for (int i = 0; i < max; i++)
		{
			if (a>i)
			{
				Extract1();
			}
			if (b>i)
			{
				Extract2();
			}
			if (c>i)
			{
				Extract3();
			}
			Show();
		}
		if (qr1[1] == 7 && qr1[1] == qr2[1] && qr1[1] == qr3[1])
		{
			cout << "\n\n\t\t***ДЖЕК ПОТ!!!***";
		}
		else if (qr1[1] == qr2[1] && qr1[1] == qr3[1])
		{
			cout << "\n\n\t\t***Дофига!***";
		}
		else if (qr1[1] == 7 && qr2[1] == 7 || qr2[1] == 7 && qr3[1] == 7)
		{
			cout << "\n\n\t\t***Пол Джекпота!***";
		}
		else if (qr1[1] == qr2[1] || qr2[1] == qr3[1])
		{
			cout << "\n\n\t\tПара";
		}
		else if (qr1[1] == (qr2[1] - 1) && qr1[1] == (qr3[1] - 2))
		{
			cout << "\n\n\t\tНарастающая";
		}
		else if (qr3[1] == (qr2[1] - 1) && qr3[1] == (qr1[1] - 2))
		{
			cout << "\n\n\t\tУбывающая";
		}
		else
		{
			cout << "\n\n\t\tНичего(";
		}
	}
	bool Extract1(){
		int temp = qr1[0];
		for (int i = 1; i < MaxLength; i++)
		{
			qr1[i - 1] = qr1[i];
		}
		qr1[MaxLength - 1] = temp;
		return 1;
	}
	bool Extract2(){
		int temp = qr2[0];
		for (int i = 1; i < MaxLength; i++)
		{
			qr2[i - 1] = qr2[i];
		}
		qr2[MaxLength - 1] = temp;
		return 1;
	}
	bool Extract3(){
		int temp = qr3[0];
		for (int i = 1; i < MaxLength; i++)
		{
			qr3[i - 1] = qr3[i];
		}
		qr3[MaxLength - 1] = temp;
		return 1;
	}
};

void info(){
	cout << "\t\t***Эмитация игры, однорукий бандит***\n\n";
	cout << "+-----------------+\n";
	cout << "|     |     |     |\n";
	cout << "|  a  |  a  |  a  |\n";
	cout << "|     |     |     |\n";
	cout << "+-----------------+  |\n";
	cout << "|     |     |     |  |\n";
	cout << "|  7  |  7  |  7  |  |\n";
	cout << "|     |     |     |  |\n";
	cout << "+-----------------+  |\n";
	cout << "|     |     |     |  |\n";
	cout << "|  b  |  b  |  b  |  |\n";
	cout << "|     |     |     |  |\n";
	cout << "+-----------------+  O\n";

	cout << "\n\nПо нажатию клавиши Enter игра зыпускается, любая другая клавиша приведет\nк выходу из программы\n\n";
	cout << "Нажмите Enter для продолжения";
}

int main(){
	setlocale(0, "RUS");
	srand(time(0));
	info();

	char Vvod;
	QueueRing QR(5);
	Vvod = _getch(); // ожидаем ввода в переменную Vvod
	while (Vvod == 13) // сравниваем Vvod с клавишей Enter
	{
		QR.Game();
		Vvod = _getch();
	}

	return 0;
}