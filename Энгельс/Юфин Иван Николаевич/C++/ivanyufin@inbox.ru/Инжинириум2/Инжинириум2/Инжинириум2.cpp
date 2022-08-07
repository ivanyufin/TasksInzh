#include <iostream>
#include <ctime>

using namespace std;
class Matrix
{
private:
	int n;
	int direction;
	int** mtrx;
	int i = 0, j = 0, k = 1, z = 0;
	/// <summary>
	/// Число, начиная от которого будут генерироваться случайные числа
	/// </summary>
	int left_border;
	/// <summary>
	/// Число, до которого будут генерироваться случайные числа
	/// </summary>
	int right_border;
public:
	void Create()
	{
		mtrx = new int* [n];
		for (int i = 0; i < n; i++)
			mtrx[i] = new int[n];
	}

	void Filling()
	{
		if (direction)
		{
			while (k < n * n)
			{
				while (j < n - z - 1)
				{
					mtrx[i][j] = k++;
					j++;
				}
				while (i < n - z - 1)
				{
					mtrx[i][j] = k++;
					i++;
				}
				while (j > z)
				{
					mtrx[i][j] = k++;
					j--;
				}
				while (i > z + 1)
				{
					mtrx[i][j] = k++;
					i--;
				}
				z++;
			}
		}
		else
		{
			while (k < n * n)
			{
				while (i < n - z - 1)
				{
					mtrx[i][j] = k++;
					i++;
				}
				while (j < n - z - 1)
				{
					mtrx[i][j] = k++;
					j++;
				}
				while (i > z)
				{
					mtrx[i][j] = k++;
					i--;
				}
				while (j > z + 1)
				{
					mtrx[i][j] = k++;
					j--;
				}
				z++;
			}
		}
		mtrx[i][j] = k;
	}

	void Display()
	{
		system("cls");
		for (int e = 0; e < n; e++)
		{
			for (int q = 0; q < n; q++)
				cout << mtrx[e][q] << " ";
			cout << endl;
		}
	}

	void Delete_Matrix()
	{
		for (int i = 0; i < n; i++)
			delete[] mtrx[i];
		delete[] mtrx;
	}

	Matrix()
	{
		left_border = 3;
		right_border = 10;
		//Учитывая, что left_border не просто указывает от какого числа нужно
		//создавать случайные числа, а смещает диапазон создания от 0, то
		//чтобы сделать генерацию чисел от 3 до 10, нужно из 10 вычесть 3
		//и прибавить 1(чтобы 10 включалось в диапазон)
		n = left_border + rand() % (right_border - left_border + 1);
		//Создается случайное число от 0 до 2(0-1) и от этого определяется направление
		direction = rand() % 2;
		Create();
	}
	
	~Matrix()
	{
		Delete_Matrix();
	}
};

int main()
{
	srand(time(0));
	Matrix* m = new Matrix();
	m->Filling();
	m->Display();
	m->~Matrix();
	return 0;
}