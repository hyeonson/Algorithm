#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>

using namespace std;

int T;
int N;
int oper[4];
int arr[13];
int minVal, maxVal;

void dfs(int plus, int minus, int multiple, int divide, int idx, int val)
{
	if (idx >= N)
	{
		minVal = min(minVal, val);
		maxVal = max(maxVal, val);
		return;
	}
	if (plus + 1 <= oper[0])
		dfs(plus + 1, minus, multiple, divide, idx + 1, val + arr[idx]);
	if (minus + 1 <= oper[1])
		dfs(plus, minus + 1, multiple, divide, idx + 1, val - arr[idx]);
	if (multiple + 1 <= oper[2])
		dfs(plus, minus, multiple + 1, divide, idx + 1, val * arr[idx]);
	if (divide + 1 <= oper[3])
		dfs(plus, minus, multiple, divide + 1, idx + 1, val / arr[idx]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		cin >> N;
		for (int i = 0; i < 4; i++)
			cin >> oper[i];
		for (int i = 0; i < N; i++)
			cin >> arr[i];

		maxVal = -100000000;
		minVal = 100000000;

		dfs(0, 0, 0, 0, 1, arr[0]);
		cout << "#" << test_case << " " << abs(maxVal - minVal) << endl;
	}

	return 0;
}