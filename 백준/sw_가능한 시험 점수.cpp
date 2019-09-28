#include <iostream>
#include <cstring>

using namespace std;

int T;
int n;
int arr[103];
bool dp[10003];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("input.txt", "r", stdin);
	
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		memset(dp, 0, sizeof(dp));

		dp[0] = 1;
		int sum = 0;

		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			sum += arr[i];
			for (int j = sum; j >= 0; j--)
			{
				if (dp[j] > 0)
				{
					dp[j + arr[i]] = 1;
				}
			}
			dp[arr[i]] = 1;

		}
		int cnt = 0;
		for (int i = 0; i < 10001; i++)
			if (dp[i] > 0)
				cnt++;



		cout << "#" << t << " " << cnt << endl;
	}

	return 0;
}