#include <iostream>
#include <math.h>
#include <cstring>
#include <algorithm>

using namespace std;

int endC;
int startC;
bool isWork[10];
int notWorkNum;
int ans;

void bruteForce()
{
	for (int i = 0; i <= 1000003; i++)
	{
		if (i == 0 && isWork[i])
			ans = min(ans, endC + 1);
		int count = 0;
		int num = i;
		bool check = true;
		if(i != 0)
		{
			while (num)
			{
				int tmp = num % 10;
				if (!isWork[tmp])
				{
					check = false;
					break;
				}
				num /= 10;
				count++;
			}
			if (check)
				ans = min(ans, abs(i - endC) + count);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("input.txt", "r", stdin);
	cin >> endC;
	startC = 100;
	cin >> notWorkNum;
	memset(isWork, 1, sizeof(isWork));
	for (int i = 0; i < notWorkNum; i++)
	{
		int notWork;
		cin >> notWork;
		isWork[notWork] = 0;
	}
	ans = abs(startC - endC);
	bruteForce();
	cout << ans << endl;
	return 0;
}