#include <iostream>
#include <string>
#include <set>

using namespace std;

int n;
char arr[20][20];
set<string> s[20];
set<string> ans;
/*
void verify(int curY, int curX, string curS, int cnt)
{
	if (arr[curY][curX] != curS[cnt])
		return;
	if (cnt == 0) //¶Ç´Â curY == n - 1 && curX == n - 1
	{
		s.insert(curS);
	}
	else
	{
		if (curY + 1 < n)
			verify(curY + 1, curX, curS, cnt - 1);
		if (curX + 1 < n)
			verify(curY, curX + 1, curS, cnt - 1);
	}
}
*/
void dfs1(int curY, int curX, string curS)
{
	curS.push_back(arr[curY][curX]);
	if (curY + curX + 1 == n)
	{
		s[curY].insert(curS);
	}
	else
	{
		if(curY + 1 < n)
			dfs1(curY + 1, curX, curS);
		if(curX + 1 < n)
			dfs1(curY, curX + 1, curS);
	}
}
void dfs2(int curY, int curX, string curS)
{
	curS.push_back(arr[curY][curX]);
	if (curY + curX + 1 == n)
	{
		if (s[curY].count(curS))
			ans.insert(curS);
	}
	else
	{
		if (curY - 1 >= 0)
			dfs2(curY - 1, curX, curS);
		if (curX - 1 >= 0)
			dfs2(curY, curX - 1, curS);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("input.txt", "r", stdin);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	
	dfs1(0, 0, "");
	dfs2(n - 1, n - 1, "");
	//cout << s.size() << endl;
	cout << ans.size() << endl;

	return 0;
}