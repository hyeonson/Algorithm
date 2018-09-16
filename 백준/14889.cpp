#include <iostream>

using namespace std;

int n;
int arr[21][21];
int ans;

void dfs(int idx, int count1, int count2, int sum1, int sum2)
{
	if ((count1 == int(n / 2)) && (count2 == int(n / 2)))
	{
		if (ans > abs(sum1 - sum2))
			ans = abs(sum1 - sum2);
		return;
	}
	if ((idx >= n) || (count1 >= int(n / 2)) || (count2 >= int(n / 2)))
		return;
	for (int i = 0; i < n; i++)
	{
		if (i == idx)
			continue;
		dfs(idx + 1, count1 + 1, count2, sum1 + arr[idx][i] + arr[i][idx], sum2);
	}
	for (int i = 0; i < n; i++)
	{
		if (i == idx)
			continue;
		dfs(idx + 1, count1, count2 + 1, sum1, sum2 + arr[idx][i] + arr[i][idx]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	ans = 200000;
	dfs(0, 0, 0, 0, 0);
	cout << ans << endl;

	return 0;
}