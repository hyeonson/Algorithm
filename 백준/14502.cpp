#include <iostream>

using namespace std;

int arr[9][9];
int n, m;
int ans;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0,  1 };

int getSize(int (*tmp2)[9])
{
	int(*tmp)[9] = tmp2;
	int num = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (tmp[i][j] == 0) num++;
	/*
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (j == m - 1)
				cout << tmp[i][j] << endl;
			else
				cout << tmp[i][j] << " ";
		}
	}
	cout << endl;
	*/
	
	return num;
}

void virus(int i, int j, int (*tmp2)[9])
{
	int(*tmp)[9] = tmp2;
	if (tmp[i][j] == 2)
	{
		for (int l = 0; l < 4; l++)
		{
			int x = i + dx[l];
			int y = j + dy[l];
			if (x >= 0 && x < n && y >= 0 && y < m && tmp[x][y] == 0)
			{
				tmp[x][y] = 2;
				virus(x, y, tmp);
			}
		}
	}
}

void dfs(int i, int j, int count, int (*tmp2)[9])
{
	int tmp[9][9];
	for (int l = 0; l < n; l++)
		for (int k = 0; k < m; k++)
			tmp[l][k] = tmp2[l][k];
	if (count == 3)
	{
		for (int l = 0; l < n; l++)
			for (int k = 0; k < m; k++)
				virus(l, k, tmp);
		int s = getSize(tmp);
		if (ans < s) ans = s;
		return;
	}
	if (j == m)
	{
		i++;
		j = 0;
	}
	if ((i == n && j == 0) || count > 3)
		return;
	
	dfs(i, j + 1, count, tmp);
	if (tmp[i][j] == 0)
	{
		tmp[i][j] = 1;
		dfs(i, j + 1, count + 1, tmp);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	ans = 0;
	dfs(0, 0, 0, arr);
	cout << ans << endl;

	return 0;
}