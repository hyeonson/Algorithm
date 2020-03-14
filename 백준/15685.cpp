#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int arr[103][103];
vector<pair<int, int> > vec;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };
int endX;
int endY;
int endIdx;

void dfs(int cnt, int g) {
	if (cnt == g) {
		return;
	}
	int vecSize = vec.size();
	int saveX, saveY, saveIdx;
	for (int i = 0; i < vecSize; i++) {
		if (i == endIdx) continue;

		int curX = vec[i].first;
		int curY = vec[i].second;
		int nextX = endY - curY + endX;
		int nextY = (endX - curX) * -1 + endY;
		if (nextX < 0 || nextX > 100 || nextY < 0 || nextY > 100) continue;
		vec.push_back({ nextX, nextY });
		if (i == 0) {
			saveX = nextX;
			saveY = nextY;
			saveIdx = vec.size() - 1;
		}
	}
	endX = saveX;
	endY = saveY;
	endIdx = saveIdx;
	dfs(cnt + 1, g);
}

void start(int x, int y, int d, int g) {
	vec.clear();
	vec.push_back({ x, y });
	int nx = x + dx[d];
	int ny = y + dy[d];
	endX = nx;
	endY = ny;
	endIdx = 1;
	vec.push_back({ nx, ny });
	dfs(0, g);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("input.txt", "r", stdin);

	memset(arr, 0, sizeof(arr));

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		start(x, y, d, g);
		for (auto j : vec) {
			arr[j.first][j.second] = 1;
		}
	}
	int sum = 0;
	
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (arr[j][i] == 1 && arr[j + 1][i] == 1 && arr[j][i + 1] == 1 && arr[j + 1][i + 1] == 1) {
				sum++;
			}
		}
	}
	
	cout << sum << "\n";

	return 0;
}