#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int n, m;
int arr[1000003];


int find(int n1) {
	if (arr[n1] == -1) {
		return n1;
	}
	else {
		return arr[n1] = find(arr[n1]);
	}
}

void merge(int n1, int n2) {
	int n1p = find(n1);
	int n2p = find(n2);
	if (n1p != n2p) {
		arr[n1p] = n2p;
	}
}

string isContain(int n1, int n2) {
	if (find(n1) == find(n2)) {
		return "YES";
	}
	else {
		return "NO";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	memset(arr, -1, sizeof(arr));

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int q, a, b;
		cin >> q >> a >> b;
		if (q == 0) {
			merge(a, b);
		}
		else if (q == 1) {
			cout << isContain(a, b) << "\n";
		}
	}

	return 0;
}