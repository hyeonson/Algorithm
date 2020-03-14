#include <iostream>
#include <algorithm>

using namespace std;

int Answer;
int N;
int arr1[5003];
int arr2[5003];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, test_case;
	
	freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> arr1[i];
		for (int i = 0; i < N; i++)
			cin >> arr2[i];

		for (int idx1 = 0; idx1 < N; idx1++)
		{
			for (int idx2 = idx1; idx2 < N; idx2++)
			{
				int sum = 0;
				for (int i = 0; i < idx1; i++)
				{
					if (arr1[i] == arr2[i])
						sum++;
				}
				for (int i = idx2 + 1; i < N; i++)
				{
					if (arr1[i] == arr2[i])
						sum++;
				}
				for (int i = idx1; i <= idx2; i++)
				{
					if (arr1[i] == arr2[idx1 + idx2 - i])
						sum++;
					
				}
				Answer = max(Answer, sum);
			}
		}

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}