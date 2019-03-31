#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int T;
int N;
int arr[21][21];
int ans;
vector<int> v;

void dfs(int state, int startY, int startX, int curY, int curX, int onemore, int kind)
{
	if (startY == curY && startX == curX && state == 3) //(state == 4)
	{
		ans = max(ans, kind);
		return;
	}
	for (int kinds : v)
	{
		if (kinds == arr[curY][curX])
			return;
	}
	v.push_back(arr[curY][curX]);
	kind++;

	if (state == 0 && curY + 1 < N && curX + 1 < N)
	{
		dfs(state, startY, startX, curY + 1, curX + 1, onemore + 1, kind);
	}
	if (state == 0 && onemore >= 1 && curY + 1 < N && curX - 1 >= 0)
	{
		dfs(state + 1, startY, startX, curY + 1, curX - 1, 0, kind);
	}

	if (state == 1 && curY + 1 < N && curX - 1 >= 0)
	{
		dfs(state, startY, startX, curY + 1, curX - 1, onemore + 1, kind);
	}
	if (state == 1 && curY - 1 >= 0 && curX - 1 >= 0)
	{
		dfs(state + 1, startY, startX, curY - 1, curX - 1, 0, kind);
	}

	if (state == 2 && curY - 1 >= 0 && curX - 1 >= 0)
	{
		dfs(state, startY, startX, curY - 1, curX - 1, onemore + 1, kind);
	}
	if (state == 2 && curY - 1 >= 0 && curX + 1 < N)
	{
		dfs(state + 1, startY, startX, curY - 1, curX + 1, 0, kind);
	}

	if (state == 3 && curY - 1 >= 0 && curX + 1 < N)
	{
		dfs(state, startY, startX, curY - 1, curX + 1, onemore + 1, kind);
	}
	v.pop_back();
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
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> arr[i][j];
		ans = -1;
		
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				dfs(0, i, j, i, j, 0, 0);
				v.clear();
			}
		}
	

		cout << "#" << test_case << " " << ans << endl;
	}

	return 0;
}