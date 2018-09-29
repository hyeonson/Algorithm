#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
bool visited[503][503];
int arr[503][503];
int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { 1, 0, -1, 0 };
int max_num;

void dfs(int count, int r, int c, int sum)
{
	visited[r][c] = 1;
	sum += arr[r][c];
	count += 1;

	if (count == 4)
	{
		max_num = max(max_num, sum);
		visited[r][c] = 0;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nextR = r + dr[i];
		int nextC = c + dc[i];
		if (nextR >= 0 && nextR < n && nextC >= 0 && nextC < m)
			if (!visited[nextR][nextC])
				dfs(count, nextR, nextC, sum);
	}
	visited[r][c] = 0;
}

void findOh()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if ((i == 0 && j == m - 1) || (i == 0 && j == 0) || (i == n - 1 && j == 0) || (i == n - 1 && j == m - 1))
				continue;
			else if (i == 0)
				max_num = max(max_num, arr[i][j] + arr[i][j - 1] + arr[i][j + 1] + arr[i + 1][j]);
			else if (i == n - 1)
				max_num = max(max_num, arr[i][j] + arr[i][j - 1] + arr[i][j + 1] + arr[i - 1][j]);
			else if (j == 0)
				max_num = max(max_num, arr[i][j] + arr[i - 1][j] + arr[i + 1][j] + arr[i][j + 1]);
			else if (j == m - 1)
				max_num = max(max_num, arr[i][j] + arr[i - 1][j] + arr[i + 1][j] + arr[i][j - 1]);
			else
			{
				int sum = arr[i][j];
				for (int k = 0; k < 4; k++)
					sum += arr[i + dr[k]][j + dc[k]];
				for (int k = 0; k < 4; k++)
					max_num = max(max_num, sum - arr[i + dr[k]][j + dc[k]]);
			}
		}
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
	max_num = 0;
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			dfs(0, i, j, 0);
	findOh();
	
	cout << max_num << endl;
}