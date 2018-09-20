#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
int n, m;
int arr[53][53];
vector<pii> home;
vector<pii> chicken;
int ans;

void dfs(int idx, int count, vector<pii> v)
{
	if (count == m)
	{
		int sum = 0;
		for (pii i : home)
		{
			int shortest = 103;
			for (pii j : v)
				shortest = min(shortest, abs(i.first - j.first) + abs(i.second - j.second));
			sum += shortest;
		}
		ans = min(ans, sum);
		return;
	}
	if (idx == chicken.size())
		return;
	dfs(idx + 1, count, v);
	v.push_back(chicken[idx]);
	dfs(idx + 1, count + 1, v);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1) home.push_back(pii(i, j));
			else if (arr[i][j] == 2) chicken.push_back(pii(i, j));
		}
	}
	ans = 1000000003;
	vector<pii> v;
	dfs(0, 0, v);
	cout << ans << endl;
}
