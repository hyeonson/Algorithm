#include <iostream>
#include <math.h>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int Answer;
bool prime[30003];
int max1, max2;
void getPrime()
{
	memset(prime, 0, sizeof(prime));

	for (int i = 2; i <= 30000; i++) {
		if (prime[i] == false) {
			for (int j = i * 2; j <= 30000; j += i) {
				prime[j] = true;
			}
		}
	}
	for (int i = 0; i <= 30000; i++) {
		prime[i] = !prime[i];
	}
	prime[1] = 0;
}

void dfs(int num, int sum, int type)
{
	if (prime[num])
		sum++;
	else
		return;
	
	string numToStr = to_string(num);
	if (numToStr.length() == 1)
	{
		if (type == 1)
			max1 = max(max1, sum);
		else
			max2 = max(max2, sum);
		return;
	}
	else
	{
		for (int i = 0; i < numToStr.length(); i++)
		{
			string temp = numToStr;
			temp.replace(i, 1, "");
			int tempToInt = atoi(temp.c_str());
			dfs(tempToInt, sum, type);
		}
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, test_case;

	freopen("input.txt", "r", stdin);

	getPrime();

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		string s1, s2;
		int n1, n2;
		int n1leng, n2leng;
		max1 = 0;
		max2 = 0;
		
		cin >> s1 >> s2;
		n1 = atoi(s1.c_str());
		n2 = atoi(s2.c_str());
		n1leng = s1.length();
		n2leng = s2.length();
		
		if (prime[n1] != prime[n2])
		{
			if (prime[n1])
				Answer = 1;
			else
				Answer = 2;
		}
		else if (!prime[n1] && !prime[n2])
		{
			Answer = 3;
		}
		else
		{
			dfs(n1, 0, 1);
			dfs(n2, 0, 2);
			if (max1 > max2)
				Answer = 1;
			else if(max1 < max2)
				Answer = 2;
			else
				Answer = 3;
		}
		cout << "Case #" << test_case + 1 << endl;
		cout << max1 << " " << max2 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}