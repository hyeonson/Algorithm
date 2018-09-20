#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int n, m, v;

vector<int> g[1003];
vector<int> ans1;
vector<int> ans2;
bool visited[1003];
queue<int> q;

void dfs(int start)
{
	visited[start] = 1;
	ans1.push_back(start);
	for (int i : g[start])
	{
		if (!visited[i])
			dfs(i);
	}
}

void bfs(int start)
{
	q.push(start);
	while (!q.empty())
	{
		int tmp = q.front();
		if (!visited[tmp])
		{
			visited[tmp] = 1;
			ans2.push_back(tmp);
			for (int i : g[tmp])
				if (!visited[i])
					q.push(i);
		}
		q.pop();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		if (find(g[n1].begin(), g[n1].end(), n2) == g[n1].end())
		{
			g[n1].push_back(n2);
			g[n2].push_back(n1);
		}
	}
	for (int i = 1; i <= n; i++)
		sort(g[i].begin(), g[i].end());

	memset(visited, 0, sizeof(visited));
	dfs(v);
	for (int i : ans1)
		cout << i << " ";
	cout << endl;

	memset(visited, 0, sizeof(visited));
	bfs(v);
	for (int i : ans2)
		cout << i << " ";
	cout << endl;

	return 0;
}