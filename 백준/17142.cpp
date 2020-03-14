#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int arr[53][53];
int temp[53][53];
int visited[53][53];
vector<pair<int, int> > virusList;
vector<int> selectList;
int emptyNum;
int ans;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

void bfs() {
	memset(visited, 0, sizeof(visited));
	queue<pair<int, int> > qu;
	
	for (int i : selectList) {
		qu.push({ virusList[i].first, virusList[i].second });
		visited[virusList[i].first][virusList[i].second] = 1;
	}
	
	int depth = 0;
	int remainNum = emptyNum;
	while (!qu.empty()) {
		if (remainNum == 0) {
			ans = min(depth, ans);
			return;
		}
		int curSize = qu.size();
		for (int s = 0; s < curSize; s++) {
			int curY = qu.front().first;
			int curX = qu.front().second;
			qu.pop();
			for (int i = 0; i < 4; i++) {
				int nextY = curY + dy[i];
				int nextX = curX + dx[i];
				if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < n && visited[nextY][nextX] == 0 && temp[nextY][nextX] != 1) {
					if (temp[nextY][nextX] == 0) {
						remainNum--;
					}
					qu.push({ nextY, nextX });
					visited[nextY][nextX] = 1;
				}
			}
		}
		depth++;
	}
	
}

void dfs(int idx, int sum) {
	if (sum == m) {
		bfs();
		return;
	}
	if (sum > m) {
		return;
	}
	if (idx >= virusList.size()) {
		return;
	}
	dfs(idx + 1, sum);
	selectList.push_back(idx);
	dfs(idx + 1, sum + 1);
	selectList.pop_back();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	freopen("input.txt", "r", stdin);

	cin >> n >> m;

	emptyNum = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			temp[i][j] = arr[i][j];
			if (arr[i][j] == 2) {
				virusList.push_back({ i, j });
			}
			if (arr[i][j] == 0) {
				emptyNum++;
			}
		}
	}
	ans = 2e9;
	dfs(0, 0);
	if (ans == 2e9) {
		cout << -1 << "\n";
	}
	else {
		cout << ans << "\n";
	}

	return 0;
}