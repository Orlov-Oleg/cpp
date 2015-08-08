#include<iostream>
using namespace std;

class Matrix{
	int size = 2;
	int **m = nullptr;
public:
	Matrix() = default;
	Matrix(int size_){
		m = new int *[size_];
		for (int i = 0; i < size_; i++)
		{
			m[i] = new int[size_];
		}
	}
	void init()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				m[i][j] = rand() % 10;
			}
		}
	}
	void initZero(){
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				m[i][j] = 0;
			}
		}
	}
	void print(){
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cout << m[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl;
	}
	void transponirovanie(){
		Matrix transMatrix(size);
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cout << m[j][i] << ' ';
			}
			cout << endl;
		}
		cout << endl;
	}
	void getCell(int row, int col){
		if (row < 0 || row - 1 >= size)
		{
			cout << "This cell not found" << endl;
		}
		else if (col < 0 || col - 1 >= size)
		{
			cout << "This cell not found" << endl;
		}
		else
		{
			cout << m[row - 1][col - 1] << endl;
		}
	}
	void setCell(int row, int col, int num){
		if (row < 0 || row - 1 >= size)
		{
			cout << "This cell not found" << endl;
		}
		else if (col < 0 || col - 1 >= size)
		{
			cout << "This cell not found" << endl;
		}
		else
		{
			m[row - 1][col - 1] = num;
		}
	}
	Matrix operator+(const Matrix &M){
		Matrix newMatrix(size);
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				newMatrix.m[i][j] = m[i][j] + M.m[i][j];
			}
		}
		return newMatrix;
	}
	Matrix operator*(const Matrix &M){
		Matrix newMatrix(size);
		newMatrix.initZero();
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				for (int k = 0; k < size; k++)
				{
					newMatrix.m[i][j] += m[i][k] * M.m[k][j];
				}
			}
		}
		return newMatrix;
	}
	Matrix operator=(const Matrix &M){
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				m[i][j] = M.m[i][j];
			}
		}
		return **m;
	}

};

int main(){
	Matrix m1(2);
	m1.init();
	m1.print();
	Matrix m2(2);
	m2.init();
	m2.print();
	Matrix m3(2);
	m3 = (m1 + m2);
	m3.print();

	Matrix m4(2);
	m4 = (m1 * m2);
	m4.print();

	m1.transponirovanie();

	m1 = m2;
	m1.print();
	m2.print();

	m1.getCell(2, 2);
	m1.getCell(3, 3);
	m1.setCell(2, 2, 2);
	m1.setCell(3, 3, 5);

	m1.print();
	m2.print();

	return 0;
}