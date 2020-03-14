#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int T;
int arr[503];
int adj[503][503];
bool visited[503];
int N;
int M;
int startNum, endNum;

void updateIntializeDFS(int start, int end) {
	if(start)
	for (int i = 0; i < N; i++) {
		if (adj[start][i] == 1) {

		}
	}
}

void update(int start, int end) {
	memset(visited, false, sizeof(visited));
	//visited[start] = true;
	visited[end] = true;
	//adj[start][end] = 1;
	updateIntializeDFS(start, end);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for (int t = 0; t < T; t++) {
		memset(adj, 0, sizeof(adj));
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		cin >> M;
		for (int i = 0; i < M; i++) {
			cin >> startNum >> endNum;
			//update(startNum, endNum);
			if (!isValid()) {
				cout << "IMPOSSIBLE" << endl;
				//return 0;
			}
		}
		//정답출력
	}

}