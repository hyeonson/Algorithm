#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int arr[9][9];
bool ans = 0;

bool verify(int y, int x)
{
	bool visited[10];
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < 9; i++)
	{
		if (arr[y][i] != 0)
		{
			if (visited[arr[y][i]] == 1)
				return false;
			visited[arr[y][i]] = 1;
		}
	}
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < 9; i++)
	{
		if (arr[i][x] != 0)
		{
			if (visited[arr[i][x]] == 1)
				return false;
			visited[arr[i][x]] = 1;
		}
	}
	memset(visited, 0, sizeof(visited));
	int startY = ((int)(y / 3)) * 3;
	int startX = ((int)(x / 3)) * 3;
	for (int i = startY; i < startY + 3; i++)
	{
		for (int j = startX; j < startX + 3; j++)
		{
			if (arr[i][j] != 0)
			{
				if (visited[arr[i][j]] == 1)
					return false;
				visited[arr[i][j]] = 1;
			}
		}
	}
	return true;
}

void dfs(int y, int x)
{
	if (x >= 9)
	{
		x = 0;
		y = y + 1;
	}
	if (y == 9 && x == 0)
	{
		ans = 1;
		return;
	}
	if (arr[y][x] == 0)
	{
		for (int i = 1; i <= 9; i++)
		{
			arr[y][x] = i;
			if (verify(y, x) == 1)
				dfs(y, x + 1);
			if (ans == 1) return;
		}
		arr[y][x] = 0;
	}
	else
	{
		dfs(y, x + 1);
		if (ans == 1) return;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			scanf("%1d", &arr[i][j]);

	dfs(0, 0);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (j == 8) cout << arr[i][j] << endl;
			else cout << arr[i][j];
		}
	}
	return 0;
}