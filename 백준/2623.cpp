#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int n, m, k;
int indegree[1003];
int result[1003];
vector<int> adj[1003];
queue<int> qu;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);

	memset(indegree, 0, sizeof(indegree));

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> k;
		int cur, next;
		cin >> cur;
		for (int j = 1; j < k; j++)
		{
			cin >> next;
			indegree[next]++;
			adj[cur].push_back(next);
			cur = next;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0)
		{
			qu.push(i);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (qu.empty())
		{
			cout << 0 << endl;
			return 0;
		}
		int cur = qu.front();
		qu.pop();
		result[i] = cur;
		for (int next : adj[cur])
		{
			if (--indegree[next] == 0)
			{
				qu.push(next);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << result[i] << endl;
	}

	return 0;
}