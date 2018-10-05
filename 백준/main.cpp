#include <iostream>
#include <cstring>

using namespace std;

bool visited[10];
bool visited2[10];
int arr[9][9];

bool check()
{
	for (int i = 0; i < 9; i++)
	{
		memset(visited, 0, sizeof(visited));
		memset(visited2, 0, sizeof(visited2));
		for (int j = 0; j < 9; j++)
		{
			if (arr[i][j])
			{
				if (visited[arr[i][j]])
					return false;
				if (visited2[arr[j][i]])
					return false;
				visited[arr[i][j]] = 1;
				visited2[arr[j][i]] = 1;
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			memset(visited, 0, sizeof(visited));
			for (int k = 3 * i; k < 3 * i + 3; k++)
			{
				for (int l = 3 * j; l < 3 * j + 3; l++)
				{
					if (arr[k][l])
					{
						if (visited[arr[k][l]])
							return false;
						visited[arr[k][l]] = 1;
					}
				}
			}
		}
	}
	return true;
}

int main()
{
	freopen("input.txt", "r", stdin);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << check() << endl;

	return 0;
}