#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>

using namespace std;

int arr[4][8];
int start[4];
int rotation[4];
int k;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			scanf("%1d", &arr[i][j]);
			//cin >> arr[i][j];
		}
	}
	
	for (int i = 0; i < 4; i++)
	{
		start[i] = 0;
	}
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		memset(rotation, 1, sizeof(rotation));
		int num, rot;
		cin >> num >> rot;
		num--;
		rotation[num] = rot;
		int tmp = num + 1;
		while (tmp <= 3)
		{
			if (arr[tmp - 1][(start[tmp - 1] + 2) % 8] != arr[tmp][(start[tmp] + 6) % 8])
			{
				rotation[tmp] = rotation[tmp - 1] * -1;
			}
			else
			{
				rotation[tmp] = 0;
			}
			tmp++;
		}
		tmp = num - 1;
		while (tmp >= 0)
		{
			if (arr[tmp + 1][(start[tmp + 1] + 6) % 8] != arr[tmp][(start[tmp] + 2) % 8])
			{
				rotation[tmp] = rotation[tmp + 1] * -1;
			}
			else
			{
				rotation[tmp] = 0;
			}
			tmp--;
		}
		for (int l = 0; l < 4; l++)
		{
			start[l] = (start[l] + rotation[l] * -1 + 8) % 8;
		}
	}
	int sum = 0; 
	for (int i = 0; i < 4; i++)
	{
		if (arr[i][start[i]])
			sum += pow(2, i);
	}
	cout << sum << endl;
	return 0;
}