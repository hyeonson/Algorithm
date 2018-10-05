#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
typedef pair<int, int> pii;

int arr[9][9];
vector<pii> v;
bool isAns;
bool visited[10];
bool visited2[10];

bool check2()
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if (arr[i][j] == 0)
				return false;
	return true;
}

bool check(int y, int x)
{
	memset(visited, 0, sizeof(visited));
	memset(visited2, 0, sizeof(visited2));
	for (int i = 0; i < 9; i++)
	{
		if(arr[y][i])
			if (visited[arr[y][i]])
				return false;
		if(arr[i][x])
			if (visited2[arr[i][x]])
				return false;
		visited[arr[y][i]] = 1;
		visited2[arr[i][x]] = 1;
	}
	int int_y = y / 3 * 3;
	int int_x = x / 3 * 3;
	memset(visited, 0, sizeof(visited));
	for (int i = int_y; i < int_y + 3; i++)
	{
		for (int j = int_x; j < int_x + 3; j++)
		{
			if(arr[i][j])
				if (visited[arr[i][j]])
					return false;
			visited[arr[i][j]] = 1;
		}
	}
	return true;
}

void dfs(int idx)
{
	int r = v[idx].first;
	int c = v[idx].second;
	for (int j = 1; j <= 9 && !isAns; j++)
	{
		arr[r][c] = j;
		if (idx >= v.size() - 1)
		{
			if (check(r, c) && check2())
			{
				isAns = true;
				return;
			}
		}
		if (!isAns && (idx < v.size() - 1) && check(r, c))
			dfs(idx + 1);
		if(!isAns)
			arr[r][c] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 0)
				v.push_back(pii(i, j));
		}
	}
	isAns = false;
	dfs(0);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (j == 8) cout << arr[i][j] << endl;
			else cout << arr[i][j] << " ";
		}
	}
	return 0;
}