#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[9];
vector<int> ans;

void dfs(int idx, int sum, vector<int> tmp, int count)
{
	if (sum == 100 && count == 7)
		ans = tmp;
	if (idx < 9)
	{
		dfs(idx + 1, sum, tmp, count);
		sum += arr[idx];
		tmp.push_back(arr[idx]);
		dfs(idx + 1, sum, tmp, count + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);
	for (int i = 0; i < 9; i++)
		cin >> arr[i];
	vector<int> v;
	dfs(0, 0, v, 0);
	sort(ans.begin(), ans.end());
	for (int i : ans)
		cout << i << endl;

	return 0;
}