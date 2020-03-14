#include <iostream>
#include <cstring>
#include <algorithm>


using namespace std;

int N;
int dp[1003][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("input.txt", "r", stdin);

	memset(dp, 0, sizeof(dp));

	cin >> N;

	cin >> dp[0][0] >> dp[0][1] >> dp[0][2];

	for (int i = 1; i < N; i++) {
		int r, g, b;
		cin >> r >> g >> b;
		dp[i][0] += r + min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] += g + min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] += b + min(dp[i - 1][0], dp[i - 1][1]);

	}

	cout << min(dp[N - 1][0], min(dp[N - 1][1], dp[N - 1][2])) << endl;

	return 0;
}