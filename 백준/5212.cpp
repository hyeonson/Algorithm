#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


vector<pair<int, int>> vec;
int r, c;
char arr[13][13];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int minX = 13;
int minY = 13;

int maxX = 0;
int maxY = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);

	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> arr[i][j];

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (arr[i][j] == 'X')
			{
				int num = 0;
				for (int k = 0; k < 4; k++)
				{
					int nextY = i + dy[k];
					int nextX = j + dx[k];

					if (nextX < 0 || nextX >= c || nextY < 0 || nextY >= r)
						num++;
					
					if (nextY >= 0 && nextY < r && nextX >= 0 && nextX < c && arr[nextY][nextX] == '.')
						num++;
				}
				if (num >= 3)
				{
					vec.push_back(make_pair(i, j));
				}
			}
		}
	}
	for (auto i : vec)
	{
		arr[i.first][i.second] = '.';
	}
	
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (arr[i][j] == 'X')
			{
				if (i <= minY)
					minY = i;
				if (i >= maxY)
					maxY = i;
				if (j <= minX)
					minX = j;
				if (j >= maxX)
					maxX = j;
			}
		}
	}

	for (int i = minY; i <= maxY; i++)
	{
		for (int j = minX; j <= maxX; j++)
		{
			if (j == maxX)
				cout << arr[i][j] << endl;
			else
				cout << arr[i][j];
		}
	}


	return 0;
}