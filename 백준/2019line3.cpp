#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_NUM 151
using namespace std;
int sum[MAX_NUM];

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return a.second < b.second;
	else return a.first < b.first;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b; cin >> a >> b;
		for (int i = a; i < b; i++) {
			sum[i]++;
		}
	}
	int ans = 0;
	for (int i = 0; i < MAX_NUM; i++) {
		ans = max(ans, sum[i]);
	}

	cout << ans << "\n";
	return 0;
}