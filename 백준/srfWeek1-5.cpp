#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int n, m;

int arr[1003][1003][3];
int ans = -1;
int depth = 0;
queue<pii> q;
int soft = 0;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	memset(arr, 0, sizeof(arr));

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j][0];

	q.push(pii(0, 0));
	while (!q.empty())
	{
		int sz = q.size();
		depth++;
		for (int z = 0; z < sz; z++)
		{
			int curY = q.front().first;
			int curX = q.front().second;
			if (curY == n - 1 && curX == m - 1)
			{
				cout << depth << endl;
				return 0;
			}
			q.pop();
			//비누를 밟았을 때
			if (arr[curY][curX][0] == 4)
			{
				int nextY = curY + dy[arr[curY][curX][2]];
				int nextX = curX + dx[arr[curY][curX][2]];
				if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < m && arr[nextY][nextX][0] != 0 && arr[nextY][nextX][0] != 3)
				{
					arr[nextY][nextX][1] = 0;
					arr[nextY][nextX][2] = arr[curY][curX][2];
					q.push(pii(nextY, nextX));
					
				}
			}
			else
			{
				if (arr[curY][curX][0] == 2)
					arr[curY][curX][1] = 1;
				for (int i = 0; i < 4; i++)
				{
					int nextY = curY + dy[i];
					int nextX = curX + dx[i];
					if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < m && arr[nextY][nextX][0] != 0)
					{
						if (arr[curY][curX][1] == 0 && arr[nextY][nextX][0] == 3)
						{
							continue;
						}
						else
						{
							arr[nextY][nextX][1] = arr[curY][curX][1];
							arr[nextY][nextX][2] = i;
							q.push(pii(nextY, nextX));
						}
					}
				}
			}
		}

	}

	cout << -1 << endl;

	return 0;
}