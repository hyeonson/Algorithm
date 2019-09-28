#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n;
int p1, p2;
int m;
int x, y;

vector<int> adj[103];
queue<int> qu;
bool visited[103];

int depth = 0;
int ans = -1;

void findDepth() {
	while (!qu.empty()) {
		int quSize = qu.size();
		depth++;
		for (int i = 0; i < quSize; i++) {
			int cur = qu.front();
			qu.pop();
			for (int next : adj[cur]) {
				if (!visited[next]) {
					visited[next] = true;
					if (next == p2) {
						ans = depth;
						return;
					}
					else {
						qu.push(next);
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	cin >> n;
	cin >> p1 >> p2;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	memset(visited, false, sizeof(visited));
	visited[p1] = true;
	qu.push(p1);
	
	findDepth();
	cout << ans << endl;

	return 0;
}



