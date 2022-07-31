// Инжинириум1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <list>

using namespace std;

vector<vector<int>> findRes(int*** mtrx, int l, int m, int n, int z);

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "");
	int*** mtrx;
	int l = 0, m = 0, n = 0;
	int z = 0;

	cout << "Введите l, m, n, z\n";
	cin >> l >> m >> n >> z;

	mtrx = new int** [l];
	for (int i = 0; i < l; i++)
	{
		mtrx[i] = new int* [m];
		for (int j = 0; j < m; j++)
			mtrx[i][j] = new int[n];
	}

	for (int i = 0; i < l; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < n; k++)
				mtrx[i][j][k] = rand() % 10 + 1;

	vector<vector<int>> vec = findRes(mtrx, l, m, n, z);
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec[i].size(); j++)
			cout << vec[i][j] << " ";
		cout << "\n";
	}

	return 0;
}

vector<vector<int>> findRes(int*** mtrx, int l, int m, int n, int z)
{
	vector<vector<int>> result;

	for (int i = 0; i < l; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < n; k++)
			{
				if (mtrx[i][j][k] == z)
				{
					vector<int> tmp = { i, j, k };
					result.push_back(tmp);
				}
			}
	return result;
}