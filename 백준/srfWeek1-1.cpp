#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <map>
#include <math.h>

using namespace std;

int n;
int maxNum;
char honi[4] = {'H', 'O', 'N', 'I'};
int lastIdx[4];
string s;
char s2[1000003];

//처음 시작 dfs(0, 0, 0)
/*
void dfs(int idx, int stage, int num)
{
	//maxNum = max(num, maxNum);
	if (stage == 4)
	{
		maxNum = max(num + 1, maxNum);
		//dfs(idx, 0, num + 1);
		//return;
		stage = 0;
		num += 1;
	}
	if (lastIdx[stage] < idx)
		return;
	if (idx >= n)
	{
		//maxNum = max(num, maxNum);
		return;
	}

	for (int i = idx; i < n; i++)
	{
		if (lastIdx[stage] < i)
			break;
		if (s2[i] == honi[stage])
		{
			dfs(i + 1, stage + 1, num);
		}
	}
	return;
	//maxNum = max(num, maxNum);
};
*/

void dfs(int idx, int stage, int num)
{
	//maxNum = max(num, maxNum);
	if (stage == 4)
	{
		maxNum = max(num + 1, maxNum);
		//dfs(idx, 0, num + 1);
		//return;
		stage = 0;
		num += 1;
	}
	if (lastIdx[stage] < idx)
		return;
	if (idx >= n)
	{
		//maxNum = max(num, maxNum);
		return;
	}

	for (int i = idx; i < n; i++)
	{
		if (lastIdx[stage] < i)
			return;
		if (s2[i] == honi[stage])
		{
			dfs(i + 1, stage + 1, num);
			return;
		}
	}
	return;
	//maxNum = max(num, maxNum);
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);
	
	
	int i = 0;
	while (1)
	{
		s2[i++] = getchar();
		if (s2[i - 1] == EOF)
			break;
		bool isIn = false;
		for (int j = 0; j < 4; j++)
		{
			if (s2[i - 1] == honi[j])
			{
				isIn = true;
				break;
			}
		}
		if (isIn == false)
		{
			i--;
		}
	}
	s2[i - 1] = NULL;
	//cout << s2 << endl;
	//cout << i << endl;
	n = i - 1;
	//cout << n << endl;
	
	//getline(cin, s);

	//n = s.length();
	maxNum = 0;

	memset(lastIdx, 0, sizeof(lastIdx));
	
	for (int i = n - 1; i >= 0; i--)
	{
		if (lastIdx[0] == 0 && s2[i] == 'H')
			lastIdx[0] = i;
		if (lastIdx[1] == 0 && s2[i] == 'O')
			lastIdx[1] = i;
		if (lastIdx[2] == 0 && s2[i] == 'N')
			lastIdx[2] = i;
		if (lastIdx[3] == 0 && s2[i] == 'I')
			lastIdx[3] = i;
	}
	

	dfs(0, 0, 0);
	cout << maxNum << endl;

	return 0;
}