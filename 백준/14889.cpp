#include <iostream>
#include <vector>

using namespace std;

int n;
int arr[21][21];
int ans;

void dfs(int idx, int count1, int count2, int sum1, int sum2, vector<int> v1, vector<int> v2)
{
	if ((idx == n) && (count1 + count2 == n))
	{
		if (ans > abs(sum1 - sum2))
			ans = abs(sum1 - sum2);
		return;
	}
	if ((idx >= n) || (count1 + count2 >= n))
		return;
	int sum3 = sum1;
	for (int j : v1)
		sum3 += arr[idx][j] + arr[j][idx];
	vector<int> v3 = v1;
	v3.push_back(idx);
	dfs(idx + 1, count1 + 1, count2, sum3, sum2, v3, v2);
	v2.push_back(idx);
	for (int j : v2)
		sum2 += arr[idx][j] + arr[j][idx];
	dfs(idx + 1, count1, count2 + 1, sum1, sum2, v1, v2);
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
	vector<int> v1;
	vector<int> v2;
	dfs(0, 0, 0, 0, 0, v1, v2);
	cout << ans << endl;

	return 0;
}