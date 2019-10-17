#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[23][23];
int team[23];
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);

	ans = 2e9;

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		if (i < n / 2) {
			team[i] = 0;
		}
		else {
			team[i] = 1;
		}
	}

	do {
		int sum[2];
		sum[0] = 0;
		sum[1] = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					continue;
				}
				else {
					if (team[i] == team[j]) {
						sum[team[i]] += arr[i][j];
					}
				}
			}
		}
		ans = min(ans, abs(sum[0] - sum[1]));

	} while (next_permutation(team, team + n));

	cout << ans << endl;

	return 0;
}
