#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define INF 2e9

typedef pair<int, int> point;

int g[20003];
vector<point> adj[20003];
int v;
int e;
int start;

struct cmp {
	bool operator()(point t, point u) {
		return t.first > u.first;
	}
};
priority_queue<point, vector<point>, greater<point>> pq;
//priority_queue<point, vector<point>, cmp> pq;

int main()
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> v >> e >> start;

	//memset(g, INF, sizeof(g));
	fill(g, g + v + 1, INF);
	/*
	for (int i = 1; i <= v; i++)
	{
		g[i] = INF;
	}
	*/

	g[start] = 0;
	for (int i = 1; i <= e; i++)
	{
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		adj[v1].push_back(make_pair(v2, w));
	}

	pq.push(make_pair(0, start));

	while (!pq.empty())
	{
		int cost = pq.top().first;
		int min = pq.top().second;
		pq.pop();

		for (int i = 0; i < adj[min].size(); i++)
		{
			int v2 = adj[min][i].first;
			int w = adj[min][i].second;
			if (g[v2] > cost + w)
			{
				g[v2] = cost + w;
				pq.push({ g[v2], v2 });
			}
		}
	}

	for (int i = 1; i <= v; i++)
	{
		if (g[i] == INF)
			cout << "INF\n";
		else
		{
			cout << g[i] << "\n";
		}
	}

	return 0;
}

