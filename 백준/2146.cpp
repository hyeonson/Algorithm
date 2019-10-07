#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int n;
int arr[103][103];
int temp[103][103];
bool visited[103][103];
int ans;
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
int totalCnt;
queue<pair<int, int> > qu;

void bfs(int y, int x, int idx) {
	qu.push({ y, x });
	while (!qu.empty()) {
		int curY = qu.front().first;
		int curX = qu.front().second;
		visited[curY][curX] = true;
		qu.pop();
		for (int i = 0; i < 4; i++) {
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];
			if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < n && temp[nextY][nextX] == 1 && !visited[nextY][nextX]) {
				visited[nextY][nextX] = true;
				temp[nextY][nextX] = idx;
				qu.push({ nextY, nextX });
			}
		}

	}

}

void bfs2(int idx) {
	memset(visited, false, sizeof(visited));
	int depth = 0;
	while (!qu.empty()) {
		depth++;
		int quSize = qu.size();
		for (int s = 0; s < quSize; s++) {
			int curY = qu.front().first;
			int curX = qu.front().second;
			visited[curY][curX] = true;
			qu.pop();
			for (int i = 0; i < 4; i++) {
				int nextY = curY + dy[i];
				int nextX = curX + dx[i];
				if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < n && !visited[nextY][nextX]) {
					if (temp[nextY][nextX] > 0 && temp[nextY][nextX] != idx) {
						ans = min(ans, depth);
						while (!qu.empty()) qu.pop();
						return;
					}
					else if (temp[nextY][nextX] == 0) {
						qu.push({ nextY, nextX });
						visited[nextY][nextX] = true;
						/*
						for (int k = 0; k < n; k++) {
							for (int l = 0; l < n; l++) {
								if (l == n - 1) cout << visited[k][l] << endl;
								else cout << visited[k][l];
							}
						}
						cout << endl;
						*/
						
					}
				}
			}
		}

	}

}

int getTotalCnt() {
	int totalSum = 0;
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (temp[i][j] == 1 && !visited[i][j]) {
				temp[i][j] = totalSum + 1;
				bfs(i, j, totalSum + 1);
				totalSum++;
			}
		}
	}
	return totalSum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ans = 2e9;
	totalCnt = 0;


	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	memcpy(temp, arr, sizeof(arr));

	totalCnt = getTotalCnt();
	/*
	cout << totalCnt << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j == n - 1) cout << temp[i][j] << endl;
			else cout << temp[i][j];
		}
	}
	cout << endl;
	*/

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (temp[i][j] == 0) {
				for (int k = 0; k < 4; k++) {
					int nextI = i + dy[k];
					int nextJ = j + dx[k];
					if (nextI >= 0 && nextI < n && nextJ >= 0 && nextJ < n && temp[nextI][nextJ] != 0) {
						while (!qu.empty()) qu.pop();
						qu.push({ i, j });
						bfs2(temp[nextI][nextJ]);
						break;
					}
				}
				
			}
		}
	}

	cout << ans << endl;

	return 0;
}