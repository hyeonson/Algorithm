#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int x;
int dp[1000003];
/*
void dfs(int n, int sum) {
	if (n <= 1) {
		return;
	}
	if (n % 3 == 0) {
		if (dp[n / 3] == -1) {
			dp[n / 3] = sum + 1;
			dfs(n / 3, sum + 1);
		}
		else {
			if (dp[n / 3] > sum + 1) {
				dp[n / 3] = sum + 1;
				dfs(n / 3, sum + 1);
			}
		}
	}
	if (n % 2 == 0) {
		if (dp[n / 2] == -1) {
			dp[n / 2] = sum + 1;
			dfs(n / 2, sum + 1);
		}
		else {
			if (dp[n / 2] > sum + 1) {
				dp[n / 2] = sum + 1;
				dfs(n / 2, sum + 1);
			}
		}
	}
	if (n - 1 >= 1) {
		if (dp[n - 1] == -1) {
			dp[n - 1] = sum + 1;
			dfs(n - 1, sum + 1);
		}
		else {
			if (dp[n - 1] > sum + 1) {
				dp[n - 1] = sum + 1;
				dfs(n - 1, sum + 1);
			}
		}
	}
}
*/
//top down
int dfs(int n) {
	if (n == 1) {
		return 0;
	}
	if (dp[n] != -1) {
		return dp[n];
	}
	else{
		int result = dfs(n - 1) + 1;
		if (n % 3 == 0) {
			result = min(dfs(n / 3) + 1, result);
		}
		if (n % 2 == 0) {
			result = min(dfs(n / 2) + 1, result);
		}
		return dp[n] = result;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(dp, -1, sizeof(dp));

	cin >> x;

	//dfs(x, 0);
	dfs(x);

	//cout << dp[1] << endl;
	cout << dfs(x) << endl;

	return 0;
}