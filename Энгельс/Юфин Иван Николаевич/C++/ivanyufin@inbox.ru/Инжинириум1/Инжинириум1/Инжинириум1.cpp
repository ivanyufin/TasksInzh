// Инжинириум1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <list>

using namespace std;

int*** Initialize_Matrix(int*** matrix, const int l, const int m, const int n);
void Fill_Matrix(int*** matrix, const int l, const int m, const int n);
void Delete_Matrix(int*** matrix, const int l, const int m, const int n);
void Print_Vector(vector<vector<int>> resultVector);
void Delete_Vector(vector<vector<int>> &resultVector);
vector<vector<int>> Find_Number_In_Matrix(int*** mtrx, const int l, const int m, const int n, const int z);

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "");
	int*** matrix = 0;
	int l = 0, m = 0, n = 0;
	int z = 0;

	cout << "Введите l, m, n, z\n";
	cin >> l >> m >> n >> z;

	matrix = Initialize_Matrix(matrix, l, m, n);

	Fill_Matrix(matrix, l, m, n);

	vector<vector<int>> resultVector = Find_Number_In_Matrix(matrix, l, m, n, z);

	Print_Vector(resultVector);

	Delete_Vector(resultVector);

	Delete_Matrix(matrix, l, m, n);

	return 0;
}

/// <summary>
/// Выделение памяти под матрицу
/// </summary>
int*** Initialize_Matrix(int*** matrix, const int l, const int m, const int n)
{
	//Если память уже выделена
	if (matrix)
		Delete_Matrix(matrix, l, m, n);//То удаляем ее

	//И выделяем память под матрицу
	matrix = new int** [l];
	for (int i = 0; i < l; i++)
	{
		matrix[i] = new int* [m];
		for (int j = 0; j < m; j++)
			matrix[i][j] = new int[n];
	}

	return matrix;
}

/// <summary>
/// Заполнение матрицы случайными числами
/// </summary>
void Fill_Matrix(int*** matrix, const int l, const int m, const int n)
{
	int left_border = 1;//Число, начиная от которого будут генерироваться случайные числа
	int right_border = 10;//Число, до которого будут генерироваться случайные числа
	for (int i = 0; i < l; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < n; k++)
				matrix[i][j][k] = left_border + rand() % right_border;
}

/// <summary>
/// Удаление матрицы из памяти
/// </summary>
void Delete_Matrix(int*** matrix, const int l, const int m, const int n)
{
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < m; j++)
			delete[] matrix[i][j];
		delete[] matrix[i];
	}
	delete[] matrix;
}

/// <summary>
/// Вывод значений вектора на экран
/// </summary>
void Print_Vector(vector<vector<int>> resultVector)
{
	for (int i = 0; i < resultVector.size(); i++)
	{
		for (int j = 0; j < resultVector[i].size(); j++)
			cout << resultVector[i][j] << " ";
		cout << "\n";
	}
}

/// <summary>
/// Удаление вектора из памяти
/// </summary>
void Delete_Vector(vector<vector<int>> &resultVector)
{
	resultVector.shrink_to_fit();
	vector<vector<int>>().swap(resultVector);
}

/// <summary>
/// Нахождение "координат" искомого числа в матрице
/// </summary>
vector<vector<int>> Find_Number_In_Matrix(int*** mtrx, const int l, const int m, const int n, const int z)
{
	vector<vector<int>> result;

	//Проходимся по матрице
	for (int i = 0; i < l; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < n; k++)
			{
				//Если текущий элемент равен z
				if (mtrx[i][j][k] == z)
				{
					//Добавляем его "координаты" в результирующий массив
					vector<int> tmp = { i, j, k };
					result.push_back(tmp);
				}
			}
	return result;
}