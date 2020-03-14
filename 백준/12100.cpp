#include <iostream>
#include <math.h>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int n;
int arr[23][23];
bool rowVisited[23];
vector<int> rowVector;
int maxNum = 0;

void dfs(int cnt) {
	if (cnt == 5) {
		/*
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j == n - 1) cout << arr[i][j] << endl;
				else cout << arr[i][j] << " ";
			}
		}
		cout << endl;
		*/
		return;
	}
	int temp[23][23];
	memcpy(temp, arr, sizeof(arr));

	//위
	for (int j = 0; j < n; j++) {
		memset(rowVisited, false, sizeof(rowVisited));
		//rowVector.clear();
		for (int i = 0; i < n; i++) {
			if (arr[i][j] != 0) {
				if (!rowVector.empty() && !rowVisited[rowVector.size() - 1] && rowVector.at(rowVector.size() - 1) == arr[i][j]) {
					rowVector.erase(rowVector.end() - 1);
					rowVector.push_back(arr[i][j] * 2);
					maxNum = max(maxNum, arr[i][j] * 2);
					rowVisited[rowVector.size() - 1] = true;
				}
				else {
					rowVector.push_back(arr[i][j]);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (i >= rowVector.size()) {
				arr[i][j] = 0;
			}
			else {
				arr[i][j] = rowVector.at(i);
			}
		}
		rowVector.clear();
	}
	dfs(cnt + 1);
	memcpy(arr, temp, sizeof(temp));

	//아래
	for (int j = 0; j < n; j++) {
		memset(rowVisited, false, sizeof(rowVisited));
		for (int i = n - 1; i >= 0; i--) {
			if (arr[i][j] != 0) {
				if (!rowVector.empty() && !rowVisited[rowVector.size() - 1] && rowVector.at(rowVector.size() - 1) == arr[i][j]) {
					rowVector.erase(rowVector.end() - 1);
					rowVector.push_back(arr[i][j] * 2);
					maxNum = max(maxNum, arr[i][j] * 2);
					rowVisited[rowVector.size() - 1] = true;
				}
				else {
					rowVector.push_back(arr[i][j]);
				}
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			if (n - i - 1 >= rowVector.size()) {
				arr[i][j] = 0;
			}
			else {
				arr[i][j] = rowVector.at(n - i - 1);
			}
		}
		rowVector.clear();
	}
	dfs(cnt + 1);
	memcpy(arr, temp, sizeof(temp));

	//오른쪽
	for (int i = 0; i < n; i++) {
		memset(rowVisited, false, sizeof(rowVisited));
		for (int j = n - 1; j >= 0; j--) {
			if (arr[i][j] != 0) {
				if (!rowVector.empty() && !rowVisited[rowVector.size() - 1] && rowVector.at(rowVector.size() - 1) == arr[i][j]) {
					rowVector.erase(rowVector.end() - 1);
					rowVector.push_back(arr[i][j] * 2);
					maxNum = max(maxNum, arr[i][j] * 2);
					rowVisited[rowVector.size() - 1] = true;
				}
				else {
					rowVector.push_back(arr[i][j]);
				}
			}
		}
		for (int j = n - 1; j >= 0; j--) {
			if (n - j - 1 >= rowVector.size()) {
				arr[i][j] = 0;
			}
			else {
				arr[i][j] = rowVector.at(n - j - 1);
			}
		}
		rowVector.clear();
	}
	dfs(cnt + 1);
	memcpy(arr, temp, sizeof(temp));

	//왼쪽
	for (int i = 0; i < n; i++) {
		memset(rowVisited, false, sizeof(rowVisited));
		for (int j = 0; j < n; j++) {
			if (arr[i][j] != 0) {
				if (!rowVector.empty() && !rowVisited[rowVector.size() - 1] && rowVector.at(rowVector.size() - 1) == arr[i][j]) {
					rowVector.erase(rowVector.end() - 1);
					rowVector.push_back(arr[i][j] * 2);
					maxNum = max(maxNum, arr[i][j] * 2);
					rowVisited[rowVector.size() - 1] = true;
				}
				else {
					rowVector.push_back(arr[i][j]);
				}
			}
		}
		for (int j = 0; j < n; j++) {
			if (j >= rowVector.size()) {
				arr[i][j] = 0;
			}
			else {
				arr[i][j] = rowVector.at(j);
			}
		}
		rowVector.clear();
	}
	dfs(cnt + 1);
	memcpy(arr, temp, sizeof(temp));
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			maxNum = max(maxNum, arr[i][j]);
		}
	}

	dfs(0);

	cout << maxNum << "\n";

	return 0;
}