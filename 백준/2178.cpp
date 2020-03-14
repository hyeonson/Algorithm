#include <iostream>
#include <cstring>
#include <queue>
#include <string>

using namespace std;

int n, m;
int arr[103][103];
int visited[103][103];
queue<pair<int, int> > qu;
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s.at(j) - '0';
		}
	}
	memset(visited, 0, sizeof(visited));
	qu.push({ 0, 0 });
	visited[0][0] = 1;
	while (!qu.empty()) {
		int curY = qu.front().first;
		int curX = qu.front().second;
		qu.pop();
		for (int i = 0; i < 4; i++) {
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];
			if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < m && visited[nextY][nextX] == 0 && arr[nextY][nextX] == 1) {
				visited[nextY][nextX] = visited[curY][curX] + 1;
				qu.push({ nextY, nextX });
			}
		}
	}
	cout << visited[n - 1][m - 1] << endl;

	return 0;
}