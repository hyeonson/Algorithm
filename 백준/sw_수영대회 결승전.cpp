#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

int T, N, a, b, c, d;
int arr[16][16];
int visited[16][16];

int dx[] = {1, 0, -1, 0, 0};
int dy[] = {0, 1, 0, -1, 0};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);

	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		memset(visited, 0, sizeof(visited));
		bool ans = false;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> arr[i][j];
			}
		}
		cin >> a >> b;
		cin >> c >> d;

		int time = 0;
		queue<pii> q;
		q.push({ a, b });
		while (!q.empty())
		{
			int size = q.size();
			for (int i = 0; i < size; i++)
			{
				int curY = q.front().first;
				int curX = q.front().second;
				q.pop();
				if (curY == c && curX == d)
				{
					ans = true;
					break;
				}
				for (int j = 0; j < 5; j++)
				{
					int nextY = curY + dy[j];
					int nextX = curX + dx[j];
					if (nextY >= 0 && nextY < N && nextX >= 0 && nextX < N && (arr[nextY][nextX] == 0 || (arr[nextY][nextX] == 2 && time % 3 == 2) || (j == 4 && arr[nextY][nextX] == 2 && visited[nextY][nextX] != 0)) && (visited[nextY][nextX] == 0 || (j == 4 && visited[nextY][nextX] <= 3)))
					{
						visited[nextY][nextX]++;
						q.push({ nextY, nextX });
					}
				}
			}
			if (ans) break;
			time++;
		}
		cout << "#" << t << " ";
		if (!ans) cout << -1 << endl;
		else cout << time << endl;
	}

	return 0;
}