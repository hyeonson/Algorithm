#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int arr[9][9];
int temp[9][9];
int temp2[9][9];
bool visited[9][9];
int n, m;
int ans;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0,  1 };

int getSafe() {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp2[i][j] == 0)
				sum++;
		}
	}
	return sum;
}

void virus() {
	memcpy(temp2, temp, sizeof(temp));
	memset(visited, false, sizeof(visited));
	queue<pair<int, int> > qu;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp2[i][j] == 2) {
				qu.push({ i, j });
				visited[i][j] = true;
			}
		}
	}
	while (!qu.empty()) {
		int curY = qu.front().first;
		int curX = qu.front().second;
		qu.pop();
		for (int i = 0; i < 4; i++) {
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];
			if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < m && temp2[nextY][nextX] == 0 && !visited[nextY][nextX]) {
				temp2[nextY][nextX] = 2;
				visited[nextY][nextX] = true;
				qu.push({ nextY, nextX });
			}
		}
	}
	ans = max(ans, getSafe());
}

void dfs(int startY, int startX, int count)
{
	if (count == 3){
		virus();
		return;
	}
	
	if (startX == m) {
		startX = 0;
		startY++;
	}
	if (startY == n) {
		return;
	}
	
	dfs(startY, startX + 1, count);
	/*
	while (temp[startY][startX] != 0) {
		if (startX == m) {
			startX = 0;
			startY++;
		}
		if (startY == n) {
			return;
		}
		startX++;
	}
	*/
	if (temp[startY][startX] == 0) {
		temp[startY][startX] = 1;
		dfs(startY, startX + 1, count + 1);
		temp[startY][startX] = 0;
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			temp[i][j] = arr[i][j];
		}
	}
	ans = 0;
	dfs(0, 0, 0);
	cout << ans << endl;

	return 0;
}