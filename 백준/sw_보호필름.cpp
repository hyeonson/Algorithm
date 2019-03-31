#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int T;
int d, w, k;
int ans;
int arr[15][21];
int temp[15][21];
int minNum;
int maxNum;

vector<int> v;

bool isPossible;

bool check()
{
	for (int i = 0; i < w; i++)
	{
		int maxSum = 1;
		int sum = 1;
		for (int j = 1; j < d; j++)
		{
			if (arr[j][i] != arr[j - 1][i])
			{
				maxSum = max(maxSum, sum);
				sum = 1;
			}
			else
			{
				sum++;
				maxSum = max(maxSum, sum);
			}
		}
		if (maxSum < k)
			return false;
	}
	return true;
}

void dfs2(int idx, int limit)
{
	if (idx == limit)
	{
		if(check() == true)
			isPossible = true;
		return;
	}
	for (int i = 0; i < w; i++)
	{
		arr[v.at(idx)][i] = 0;
	}
	dfs2(idx + 1, limit);

	//if (isPossible == true) return;

	for (int i = 0; i < w; i++)
	{
		arr[v.at(idx)][i] = 1;
	}
	dfs2(idx + 1, limit);

	//if (isPossible == true) return;

	for (int i = 0; i < w; i++)
	{
		arr[v.at(idx)][i] = temp[v.at(idx)][i];
	}
	
}

void dfs(int idx, int cnt, int limit)
{
	if (cnt == limit)
	{
		dfs2(0, limit);
		return;
	}

	if (idx >= d || cnt > limit)
		return;
	dfs(idx + 1, cnt, limit);
	if (isPossible == true) return;
	v.push_back(idx);
	dfs(idx + 1, cnt + 1, limit);
	if (isPossible == true) return;
	v.pop_back();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);

	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		cin >> d >> w >> k;
		for (int i = 0; i < d; i++)
			for (int j = 0; j < w; j++)
				cin >> arr[i][j];
		for (int i = 0; i < d; i++)
			for (int j = 0; j < w; j++)
				temp[i][j] = arr[i][j];
		minNum = 0;
		maxNum = d;
		int avr;
		while (minNum <= maxNum)
		{
			isPossible = false;
			avr = (maxNum + minNum) / 2;
			//cout << "avr : " << avr << endl;
			dfs(0, 0, avr);
			v.clear();
			//가능하면
			if (isPossible)
			{
				ans = avr;
				maxNum = avr - 1;
			}
			//불가능하면
			else
			{
				minNum = avr + 1;
			}
		}

		cout << "#" << test_case << " " << ans << endl;
		/*
		for (int i = 0; i < d; i++)
			for (int j = 0; j < w; j++)
			{
				if (j == w - 1) cout << arr[i][j] << endl;
				else cout << arr[i][j] << " ";
			}
			*/
	}

	return 0;
}