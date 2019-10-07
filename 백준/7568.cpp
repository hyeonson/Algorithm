#include <iostream>
#include <cstring>

using namespace std;

int N;

struct person {
	int w;
	int h;
	//int idx;
	int higher;
};


person personList[53];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> personList[i].w >> personList[i].h;
		//personList[i].idx = i;
		personList[i].higher = 0;
	}

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++) {
			if (j == i)
				continue;
			else {
				if (personList[i].w < personList[j].w) {
					if (personList[i].h < personList[j].h) {
						personList[i].higher++;
					}
				}
			}
		}
		if(i == N - 1) cout << personList[i].higher + 1 << endl;
		else cout << personList[i].higher + 1 << " ";
	}
	

	return 0;
}