#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
struct edge{
	int start;
	int end;
	int cost;
};
edge edgeList[100003];
int visited[100003];

bool cmp(edge e1, edge e2) {
	return e1.cost < e2.cost;
}

int find(int idx) {
	if (visited[idx] == -1) {
		return idx;
	}
	else {
		return visited[idx] = find(visited[idx]);
	}
}

void merge(int idx1, int idx2) {
	int find1p = find(idx1);
	int find2p = find(idx2);
	if(find1p != find2p)
		visited[find2p] = find1p;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("input.txt", "r", stdin);

	memset(visited, -1, sizeof(visited));

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edgeList[i].start = a - 1;
		edgeList[i].end = b - 1;
		edgeList[i].cost = c;
	}

	sort(edgeList, edgeList + m, cmp);
	/*
	for (int i = 0; i < m; i++) {
		cout << "test: " << edgeList[i].start << " " << edgeList[i].end << " " << edgeList[i].cost << endl;
	}
	*/

	int sum = 0;

	for (int i = 0; i < m; i++) {
		//한점 이라도 이어져 있지 않을 때
		int find1p = find(edgeList[i].start);
		int find2p = find(edgeList[i].end);
		//cout << find1p << " " << find2p << endl;
		if (find1p != find2p) {
			sum += edgeList[i].cost;
			merge(edgeList[i].start, edgeList[i].end);
		}
	}

	cout << sum << endl;

	return 0;
}