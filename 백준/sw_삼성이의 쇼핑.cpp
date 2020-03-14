#include <iostream>
#include <vector>

using namespace std;

int T;
int n, m;
struct cloth {
	int p;
	int s;
};
cloth arr[26];

vector<int> ans;
int maxS;

void dfs(int idx, vector<int> cur, int sum1, int sum2)
{
	if (idx == m)
	{
		if (maxS < sum2)
		{
			maxS = sum2;
			ans.clear();
			ans = cur;
		}
		return;
	}
	dfs(idx + 1, cur, sum1, sum2);
	if (n >= sum1 + arr[idx].p)
	{
		cur.push_back(idx);
		dfs(idx + 1, cur, sum1 + arr[idx].p, sum2 + arr[idx].s);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		ans.clear();
		maxS = 0;
		vector<int> temp;

		cin >> n >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> arr[i].p >> arr[i].s;
		}
		dfs(0, temp, 0, 0);
		cout << "#" << t << " ";
		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i] << " ";
		}
		cout << maxS << endl;
	}

	return 0;
}