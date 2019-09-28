#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int arr[5003];
int dp[5003];
int leng;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("input.txt", "r", stdin);

	memset(dp, 0, sizeof(dp));

	string s;
	cin >> s;
	
	leng = s.length();

	for (int i = 0; i < leng; i++) {
		arr[i] = s.at(i) - '0';
	}
	if (arr[0] == 0) {
		cout << 0 << endl;
		return 0;
	}
	dp[0] = 1;
	for (int i = 1; i < leng; i++) {
		//뒤에꺼 선택 안했을 때
		if(arr[i] != 0)
			dp[i] += dp[i - 1];

		//뒤에꺼 선택
		if ((arr[i - 1] == 1 && arr[i] >= 0 && arr[i] <= 9)
			|| (arr[i - 1] == 2 && arr[i] >= 0 && arr[i] <= 6)) {
			if(i - 2 >= 0) dp[i] = (dp[i] + dp[i - 2]) % 1000000;
			else dp[i] += 1;
		}
	}

	cout << dp[leng - 1] % 1000000 << endl;

	return 0;
}