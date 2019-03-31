#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int h, w, n;
char arr[1003][1003];
int visited[1003][1003];
int minTime = 2000000003;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int cur;
int total;
queue<pii> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	//freopen("input.txt", "r", stdin);

	memset(visited, 0, sizeof(visited));

	cin >> h >> w >> n;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'S')
			{
				q.push(make_pair(i, j));
				visited[i][j] = 1;
			}
		}
	}
	cur = 1;
	total = 0;
	while (cur != n + 1)
	{
		while (!q.empty())
		{
			int curY = q.front().first;
			int curX = q.front().second;
			q.pop();

			if (arr[curY][curX] == '0' + cur)
			{
				cur++;
				while (!q.empty()) q.pop();
				total += visited[curY][curX] - 1;
				q.push(make_pair(curY, curX));
				memset(visited, 0, sizeof(visited));
				visited[curY][curX] = 1;
				break;
			}
			for (int i = 0; i < 4; i++)
			{
				int nextX = curX + dx[i];
				int nextY = curY + dy[i];
				if (nextX >= 0 && nextX < w && nextY >= 0 && nextY < h && arr[nextY][nextX] != 'X' && visited[nextY][nextX] == 0)
				{
					q.push(make_pair(nextY, nextX));
					visited[nextY][nextX] = visited[curY][curX] + 1;
				}
			}
		}
	}
	cout << total << endl;
	//dfs(startY, startX, 1, 0);

}