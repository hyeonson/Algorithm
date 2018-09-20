#include <iostream>

using namespace std;


void ptrArr(int(*ptr)[7])
{
	int(*ptr2)[7] = ptr;
	ptr[1][0] = 1;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (j == 6)
				cout << ptr2[i][j] << endl;
			else
				cout << ptr2[i][j] << " ";
		}
	}
	cout << endl;
}

void valArr(int tmp[][7])
{
	int (*ptr2)[7] = tmp;
	tmp[2][0] = 1;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (j == 6)
				cout << ptr2[i][j] << endl;
			else
				cout << ptr2[i][j] << " ";
		}
	}
	cout << endl;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int arr1[7][7];
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
			cin >> arr1[i][j];
	ptrArr(arr1);
	cout << arr1[1][0] << endl;
	valArr(arr1);
	cout << arr1[2][0] << endl;
	return 0;
}