#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdio.h>

using namespace std;

int Answer;
int n1, n2;
int minAns;

void getNum(int num, int count)
{
	if (num == 0)
		minAns = min(minAns, count);
	if (num < 0)
		return;

	int end = int((-1.0 + sqrt(double(1 + 8 * num))) / 2.0);
	for (int i = 1; i <= end; i += 2)
	{
		getNum(num - i * (i + 1) / 2, count + i);
		if (i + 1 <= end)
		{
			getNum(num - (i + 1) * (i + 2) / 2, count + i + 1);
		}
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//setbuf(stdout, NULL);
	int T, test_case;

	//freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		cin >> n1 >> n2;
		for (int i = n1; i <= n2; i += 2)
		{
			minAns = 2e9;
			getNum(i, 0);
			Answer = max(minAns, Answer);
			if (i + 1 <= n2)
			{
				Answer = max(minAns + 1, Answer);
			}
		}

		cout << "Case #" << test_case + 1 << "\n";
		cout << Answer << "\n";
		//printf("Case #%d\n", test_case + 1);
		//printf("%d\n", Answer);
	}

	return 0;//Your program should return 0 on normal termination.
}