#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

int Answer;
int n1, n2;
int dp[1000003];

int main(int argc, char** argv)
{
	//setbuf(stdout, NULL);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, test_case;
	
	for (int i = 1; i <= 1000000; i++)
	{
		int cur = i;
		int cnt = 0;
		while (1)
		{
			if (dp[cur] != 0 || cur == 1)
			{
				dp[i] = cnt + dp[cur];
				break;
			}
			else
			{
				if (cur % 2 == 0)
				{
					cur /= 2;
				}
				else
				{
					cur++;
				}
				cnt++;
			}

		}
	}

	//freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		
		cin >> n1 >> n2;
		for (int i = n1; i <= n2; i++)
		{
			Answer += dp[i];
		}
		 // Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << "\n";
		//printf("Case #%d\n", test_case + 1);
		cout << Answer << "\n";
		//printf("%d\n", Answer);
	}

	return 0;//Your program should return 0 on normal termination.
}