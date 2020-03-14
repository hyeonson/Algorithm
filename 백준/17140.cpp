#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int r, c, k;
int arr[203][203];
int numNum[203];
int maxW;
int maxH;
int ans;

bool cmp(int n1, int n2) {
	if (numNum[n1] == numNum[n2]) {
		return n1 < n2;
	}
	return numNum[n1] < numNum[n2];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);

	cin >> r >> c >> k;
	r--;
	c--;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}
	maxW = 3;
	maxH = 3;
	ans = 0;
	while (true) {
		if (ans > 100) {
			cout << -1 << endl;
			return 0;
		}
		if (r < maxH && c < maxW) {
			if (arr[r][c] == k) {
				cout << ans << endl;
				return 0;
			}
		}

		if (maxH >= maxW) {
			//r연산
			for (int i = 0; i < maxH; i++) {
				memset(numNum, 0, sizeof(numNum));
				for (int j = 0; j < maxW; j++) {
					if (arr[i][j] != 0) {
						numNum[arr[i][j]]++;
					}
				}
				vector<int> numList;
				for (int j = 1; j < 203; j++) {
					if (numNum[j] != 0) {
						numList.push_back(j);
					}
				}
				sort(numList.begin(), numList.end(), cmp);
				int idx = 0;
				for (int j : numList) {
					arr[i][idx] = j;
					arr[i][idx + 1] = numNum[j];
					idx += 2;
				}
				maxW = max(maxW, idx);
				for (int j = idx; j < 203; j++) {
					arr[i][j] = 0;
				}
			}
		}
		else {
			//c연산
			for (int i = 0; i < maxW; i++) {
				memset(numNum, 0, sizeof(numNum));
				for (int j = 0; j < maxH; j++) {
					if (arr[j][i] != 0) {
						numNum[arr[j][i]]++;
					}
				}
				vector<int> numList;
				for (int j = 1; j < 203; j++) {
					if (numNum[j] != 0) {
						numList.push_back(j);
					}
				}
				sort(numList.begin(), numList.end(), cmp);
				int idx = 0;
				for (int j : numList) {
					arr[idx][i] = j;
					arr[idx + 1][i] = numNum[j];
					idx += 2;
				}
				maxH = max(maxH, idx);
				for (int j = idx; j < 203; j++) {
					arr[j][i] = 0;
				}
			}
		}

		ans++;
	}


	return 0;
}