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

	Matrix()
	{
		srand(time(0));
		n = 3 + rand() % (10 - 3 + 1);
		direction = rand() % 2;
		Create();
	}
};

int main()
{
	Matrix m;
	m.Filling();
	m.Display();

	return 0;
}

