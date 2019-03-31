#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n, m;
int a, b, c, d;

const int possible = 2000000003;

vector<pii> vec1[20];
vector<pii> vec2[20];

//set<int, greater<int>> s1;
//set<int, greater<int>> s2;
set<int> s1;
set<int> s2;

void dfs1(int num, int sum)
{
	if (num == n)
	{
		s1.insert(sum);
		return;
	}
	for (int i = 0; i < vec1[num].size(); i++)
	{
		int end = vec1[num][i].first;
		int cost = vec1[num][i].second;
		dfs1(end, sum + cost);
	}
}
void dfs2(int num, int sum)
{
	if (num == n)
	{
		s2.insert(sum);
		return;
	}
	for (int i = 0; i < vec2[num].size(); i++)
	{
		int end = vec2[num][i].first;
		int cost = vec2[num][i].second;
		dfs2(end, sum + cost);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c >> d;
		vec1[a].push_back(make_pair(b, c));
		vec2[a].push_back(make_pair(b, d));
	}

	dfs1(1, 0);
	dfs2(1, 0);

	int minNum = 2000000003;

	for (int i : s1)
	{
		for (int j : s2)
		{
			if (i == j)
			{
				minNum = min(minNum, i);
			}
		}
	}
	
	if (minNum == 2000000003)
		cout << "IMPOSSIBLE" << endl;
	else
		cout << minNum << endl;
	return 0;
}