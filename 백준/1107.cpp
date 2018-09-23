#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int endC;
int startC;
bool isWork[10];
int notWorkNum;
int ans;
string endS;

void dfs(int idx, int len, vector<int> tmp)
{
	if (idx == len)// && tmp.size() == len
	{
		int sum = 0;
		for (int i = 0; i < len; i++)
			sum += tmp[i] * pow(10, (len - i - 1));
		ans = min(ans, abs(sum - startC) + len);
	}
	int endSdigit = endS[idx] - '0';
	if (isWork[endSdigit])
	{
		tmp.push_back(endSdigit);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);
	cin >> endS;
	endC = stoi(endS);
	startC = 100;
	cin >> notWorkNum;
	memset(isWork, 1, sizeof(isWork));
	for (int i = 0; i < notWorkNum; i++)
	{
		int notWork;
		cin >> notWork;
		isWork[notWork] = 0;
	}
	if (notWorkNum == 10)
		ans = abs(startC - endC);
	else if (notWorkNum == 9 && isWork[0] == 1)
		ans = min(abs(startC - endC), abs(endC) + 1);
	else
	{
		ans = abs(startC - endC);
		//dfs
	}
	cout << ans << endl;
	return 0;
}