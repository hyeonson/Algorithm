#include <iostream>
#include <math.h>

using namespace std;

int T;
int X1, X2, Y1, Y2;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> X1 >> Y1 >> X2 >> Y2;
		int xGap = abs(X1 - X2);
		int yGap = abs(Y1 - Y2);
		if (abs(xGap - yGap) <= 1) {
			cout << "#" << t << " " << xGap + yGap << endl;
		}
		else {
			if (abs(xGap - yGap) % 2 == 0) {
				cout << "#" << t << " " << xGap + yGap + abs(xGap - yGap) << endl;
			}
			else {
				cout << "#" << t << " " << xGap + yGap + abs(xGap - yGap) - 1 << endl;
			}
		}
	}

	return 0;
}