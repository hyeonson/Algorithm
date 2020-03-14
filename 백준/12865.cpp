#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, k;
struct bag {
	int weight;
	int value;
};

bag bagList[103];
int dp[103][100003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("input.txt", "r", stdin);

	memset(dp, 0, sizeof(dp));

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> bagList[i].weight >> bagList[i].value;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - bagList[i].weight >= 0) {
				dp[i][j] = max(dp[i - 1][j - bagList[i].weight] + bagList[i].value, dp[i][j]);
			}
		}
	}

	cout << dp[n][k] << "\n";

	return 0;
}