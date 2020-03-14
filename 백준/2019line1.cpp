#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int mesNum;
int conNum;
queue<int> qu;
int con[11];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);

	cin >> mesNum;
	cin >> conNum;

	for (int i = 0; i < mesNum; i++) {
		int mesLeng;
		cin >> mesLeng;
		qu.push(mesLeng);
	}

	while (!qu.empty()) {
		int mesLeng = qu.front();
		qu.pop();

		sort(con, con + conNum);
		con[0] += mesLeng;
	}

	sort(con, con + conNum);
	cout << con[conNum - 1] << endl;

	return 0;
}