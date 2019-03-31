#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
char arr[50][50];
bool visited[64][50][50];
queue<pair<pair<int, int>, pair<int, int>>> q;
int ans = 2e9;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);
	memset(visited, 0, sizeof(visited));

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == '0')
			{
				q.push({ {i, j},{0, 0} });
				visited[0][i][j] = true;
			}
		}
	}

	while (!q.empty())
	{
		int curY = q.front().first.first;
		int curX = q.front().first.second;
		int key = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nY = curY + dy[i];
			int nX = curX + dx[i];
			if (nY >= 0 && nY < n && nX >= 0 && nX < m && !visited[key][nY][nX])
			{
				int doorNum = arr[nY][nX] - 'A';
				int keyNum = arr[nY][nX] - 'a';

				visited[key][nY][nX] = true;

				//도착지 일때
				if (arr[nY][nX] == '1')
				{
					if (ans > cnt + 1)
					{
						ans = cnt + 1;
					}
				}
				//벽일때
				else if (arr[nY][nX] == '#')
				{
					continue;
				}
				//빈곳일때
				else if (arr[nY][nX] == '.' || arr[nY][nX] == '0')
				{
					q.push({ { nY, nX }, { key, cnt + 1 } });
				}
				//문일때
				else if (doorNum <= 5 && doorNum >= 0)
				{
					if (key & (1<<doorNum))
					{
						q.push({ { nY, nX }, { key, cnt + 1 } });
					}
					else
					{
						continue;
					}
				}
				//열쇠일때
				else
				{
					int newKey = key | (1 << keyNum);
					q.push({ {nY, nX}, {newKey, cnt + 1} });
					visited[newKey][nY][nX] = true;
				}
			}
		}
	}

	if (ans == 2e9)
		cout << -1 << endl;
	else
		cout << ans << endl;

	return 0;
}