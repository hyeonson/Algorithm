#include <iostream>
#include <cstring>
#include <math.h>
#include <iomanip>

using namespace std;

int n;
bool visited[29][29];
int statics[4];
double sum;
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };

void dfs(int cnt, int r, int c, double _sum)
{
	if (cnt == n)
	{
		sum += _sum;
		return;
	}
	visited[r][c] = 1;
	for (int i = 0; i < 4; i++)
	{
		int nextR = r + dr[i];
		int nextC = c + dc[i];
		if (visited[nextR][nextC] == 0)
			dfs(cnt + 1, nextR, nextC, _sum * statics[i] * 0.01);
	}
	visited[r][c] = 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < 4; i++)
		cin >> statics[i];
	memset(visited, 0, sizeof(visited));
	sum = 0;
	dfs(0, 14, 14, 1);
	cout << fixed;
	cout << setprecision(10) << sum << endl;

	return 0;
}