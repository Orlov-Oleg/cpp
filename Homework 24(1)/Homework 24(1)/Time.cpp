#include<iostream>
using namespace std;

class Time{
	int hour;
	int min;
public:
	Time(){
		hour = 0;
		min = 0;
	}
	~Time(){
	}
	Time(int hour_, int min_){
		hour = hour_;
		min = min_;
	}
	void vvod(){
		do
		{
			cout << "\nVvedite hour: ";
			cin >> hour;
			if (hour > 23 || hour < 0)
			{
				cout << "Incorrect hour" << endl;
			}
			else
			{
				break;
			}
		} while (true);

		do
		{
			cout << "\nVvedite min: ";
			cin >> min;
			if (min > 59 || min < 0)
			{
				cout << "Incorrect min" << endl;
			}
			else
			{
				break;
			}
		} while (true);
	}
	void print(){
		cout << hour << ":" << min << endl;
	}

	Time operator+(const Time &T){
		Time temp;
		temp.min = min + T.min;
		if (temp.min >= 60)
		{
			temp.min -= 60;
			temp.hour = hour + T.hour + 1;
			if (temp.hour >= 24)
			{
				temp.hour -= 24;
			}
		}
		else
		{
			temp.hour = hour + T.hour;
			if (temp.hour >= 24)
			{
				temp.hour -= 24;
			}
		}

		return temp;
	}
	Time operator-(const Time &T){
		Time temp;
		temp.min = min - T.min;
		if (temp.min < 0)
		{
			temp.min += 60;
			temp.hour = hour - T.hour - 1;
			if (temp.hour < 0)
			{
				temp.hour += 24;
			}
		}
		else
		{
			temp.hour = hour - T.hour;
			if (temp.hour < 0)
			{
				temp.hour += 24;
			}
		}
		return temp;
	}
	//операция сравнения
	bool Time::operator==(const Time &T){
		if (hour != T.hour)
		{
			return false;
		}
		else if (min != T.min)
		{
			return false;
		}
		return true;
	}
	void translate(){
		if (hour > 12)
		{
			hour -= 12;
			cout << hour << ":" << min << "PM" << endl;
		}
		else
		{
			cout << hour << ":" << min << "AM" << endl;
		}
	}
};

int main(){
	Time t1;
	t1.print();

	t1.vvod();

	t1.print();

	Time t2(12, 12);
	Time t3;

	t3 = t1 + t2;

	t3.print();

	Time t4;
	t4 = t1 - t2;

	t4.print();

	t1.print();
	t1.translate();

	bool b;
	b = t1 == t2;

	if (b == 0){
		cout << "\nDifferent time" << endl;
	}
	else{
		cout << "\nThe same time" << endl;
	}

	return 0;
}