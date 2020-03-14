#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int n, m;
int arr[1003][1003];
int visited[1003][1003][2];

struct map {
	int y;
	int x;
	int wall;
};
queue<map> qu;

int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, 1, 0, -1 };

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
	qu.push({ 0, 0, 0 });

	while (!qu.empty()) {
		int curY = qu.front().y;
		int curX = qu.front().x;
		int curWall = qu.front().wall;
		qu.pop();
		for (int i = 0; i < 4; i++) {
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];
			if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n && !(nextY == 0 && nextX == 0)) {
				//다음 지역이 벽일때
				if (arr[nextY][nextX] == 1 && visited[nextY][nextX][1] == 0) {
					if (curWall == 0) {
						visited[nextY][nextX][1] = visited[curY][curX][0] + 1;
						qu.push({ nextY, nextX, 1 });
					}
				}
				//다음 지역이 벽이 아닐때
				else {
					if (visited[nextY][nextX][curWall] == 0) {
						visited[nextY][nextX][curWall] = visited[curY][curX][curWall] + 1;
						qu.push({ nextY, nextX, curWall });
					}
				}
			}
		}
	}
	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j == m - 1) cout << visited[i][j][0] << endl;
			else cout << visited[i][j][0] << " ";
		}
	}
	cout << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j == m - 1) cout << visited[i][j][1] << endl;
			else cout << visited[i][j][1] << " ";
		}
	}
	cout << endl;
	*/
	if (n == 1 && m == 1) cout << 1 << endl;
	else if (visited[n - 1][m - 1][0] || visited[n - 1][m - 1][1]) {
		if (visited[n - 1][m - 1][0] == 0) cout << visited[n - 1][m - 1][1] + 1 << endl;
		else if (visited[n - 1][m - 1][1] == 0) cout << visited[n - 1][m - 1][0] + 1 << endl;
		else cout << min(visited[n - 1][m - 1][0], visited[n - 1][m - 1][1]) + 1 << endl;
	}
	else {
		cout << -1 << endl;
	}

}
