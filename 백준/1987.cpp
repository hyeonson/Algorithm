#include <iostream>
#include <cstring>

using namespace std;

int r, c;
short arr[20][20];
bool visited[26];
int cnt;
char ch;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

void dfs(int y, int x, int leng)
{
	visited[arr[y][x]] = 1;
	leng += 1;
	if (leng > cnt) cnt = leng;
	for (int i = 0; i < 4; i++)
	{
		int nextY = y + dy[i];
		int nextX = x + dx[i];
		if (nextY < r && nextY >= 0 && nextX < c && nextX >= 0 && !visited[arr[nextY][nextX]])
		{
			dfs(nextY, nextX, leng);
		}
	}
	visited[arr[y][x]] = 0;

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> ch;
			arr[i][j] = ch - 'A';
		}
	}
	cnt = 0;
	memset(visited, 0, sizeof(visited));
	dfs(0, 0, 0);
	cout << cnt << endl;
	return 0;	
}