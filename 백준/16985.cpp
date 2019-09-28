#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int arr[5][5][5];
int arr2[5][5][5];
bool visited[5][5][5];
int seq[5] = {0, 1, 2, 3, 4};
int dz[6] = {1, 0, 0, 0, 0, -1};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dx[6] = { 0, 0, 1, 0, -1, 0 };

int ans = 2e9;

struct zyx {
	int z;
	int y;
	int x;
};

queue<zyx> qu;

void rotate(int z) {
	int temp[5][5];
	memcpy(temp, arr2[z], sizeof(arr2[z]));
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			arr2[z][j][4 - i] = temp[i][j];
		}
	}
}

void solve() {
	memset(visited, false, sizeof(visited));
	visited[0][0][0] = true;
	while (!qu.empty()) qu.pop();
	qu.push({ 0, 0, 0 });
	int depth = 0;
	while (!qu.empty()) {
		int qSize = qu.size();
		for (int s = 0; s < qSize; s++) {
			int curZ = qu.front().z;
			int curY = qu.front().y;
			int curX = qu.front().x;
			qu.pop();
			if (curZ == 4 && curY == 4 && curX == 4) {
				ans = min(ans, depth);
				return;
			}
			
			for (int i = 0; i < 6; i++) {
				int nextZ = curZ + dz[i];
				int nextY = curY + dy[i];
				int nextX = curX + dx[i];

				if (nextZ >= 0 && nextZ < 5 && nextY >= 0 && nextY < 5 && nextX >= 0 && nextX < 5
					&& !visited[nextZ][nextY][nextX] && arr2[nextZ][nextY][nextX] != 0) {
					visited[nextZ][nextY][nextX] = true;
					qu.push({ nextZ, nextY, nextX });
				}
			}
		}
		depth++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("input.txt", "r", stdin);

	for (int z = 0; z < 5; z++) {
		for (int y = 0; y < 5; y++) {
			for (int x = 0; x < 5; x++) {
				cin >> arr[z][y][x];
			}
		}
	}
	do {
		for (int i = 0; i < 5; i++) {
			memcpy(arr2[seq[i]], arr[i], sizeof(arr[i]));
		}
		//0Ãþ È¸Àü
		for (int i = 0; i < 4; i++) {
			rotate(0);
			//1Ãþ È¸Àü
			if (arr2[0][0][0] == 0) {
				continue;
			}
			for (int j = 0; j < 4; j++) {
				rotate(1);
				//2Ãþ È¸Àü
				for (int k = 0; k < 4; k++) {
					rotate(2);
					//3Ãþ È¸Àü
					for (int l = 0; l < 4; l++) {
						rotate(3);
						//3Ãþ È¸Àü
						for (int m = 0; m < 4; m++) {
							rotate(4);
							//4Ãþ È¸Àü
							solve();
						}
					}
				}
			}
		}
	} while (next_permutation(seq, seq + 5));

	if (ans == 2e9)
		cout << -1 << endl;
	else
		cout << ans << endl;

	return 0;
}