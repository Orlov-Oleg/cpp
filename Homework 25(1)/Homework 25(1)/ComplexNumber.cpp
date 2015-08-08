#include<iostream>
using namespace std;

class ComplexNumber{
	int a;
	int b;
public:
	ComplexNumber(){
		a = 1;
		b = 1;
	}
	ComplexNumber(int a1, int b1){
		a = a1;
		b = b1;
	}
	ComplexNumber operator+(ComplexNumber&CN){
		ComplexNumber temp;
		temp.a = a + CN.a;
		temp.b = b + CN.b;

		return temp;
	}
	ComplexNumber operator-(ComplexNumber&CN){
		ComplexNumber temp;
		temp.a = a - CN.a;
		temp.b = b - CN.b;
		return temp;
	}
	ComplexNumber operator*(ComplexNumber&CN){
		ComplexNumber temp;
		temp.a = a*CN.a + (-b*CN.b);
		temp.b = b*CN.a - (-a*CN.b);
		return temp;
	}
	ComplexNumber operator/(ComplexNumber&CN){
		ComplexNumber temp;
		if (CN.b < 0)
		{
			temp.a = a*CN.a - b*(-CN.b);
			temp.b = b*CN.a - a*CN.b;
			int d = CN.a *CN.a + CN.b *CN.b;
			temp.a /= d;
			temp.b /= d;
		}
		else
		{
			temp.a = a*CN.a - b*CN.b;
			temp.b = b*CN.a - a*CN.b;
			int d = CN.a*CN.a - CN.b*CN.b;
			temp.a /= d;
			temp.b /= d;
		}

		return temp;
	}
	void Show(){
		if (a == 0)
		{
			cout << b << 'i' << endl;
		}
		else
		{
			cout << a;
			if (b == 0)
			{
				cout << endl;
			}
			else if (b < 0)
			{
				cout << b << 'i' << endl;
			}
			else
			{
				cout << "+" << b << "i" << endl;
			}
		}
		cout << endl;
	}
};

int main(){
	ComplexNumber A(13, 1);
	cout << "A = ";
	A.Show();
	ComplexNumber B(7, -6);
	cout << "B = ";
	B.Show();
	ComplexNumber C;
	cout << "C = ";
	C.Show();

	C = A + B;
	cout << "A = ";
	A.Show();
	cout << "B = ";
	B.Show();
	cout << "C = ";
	C.Show();

	A = B - C;
	cout << "A = ";
	A.Show();
	cout << "B = ";
	B.Show();
	cout << "C = ";
	C.Show();

	C = A * B;
	cout << "A = ";
	A.Show();
	cout << "B = ";
	B.Show();
	cout << "C = ";
	C.Show();

	C = A / B;
	cout << "A = ";
	A.Show();
	cout << "B = ";
	B.Show();
	cout << "C = ";
	C.Show();

	return 0;
}