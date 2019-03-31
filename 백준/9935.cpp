#include <iostream>
#include <string>

using namespace std;

string str1;
string str2;
char ans[1000003];

int leng1;
int leng2;
int idx = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);

	cin >> str1 >> str2;

	leng1 = str1.length();
	leng2 = str2.length();

	for (int i = 0; i < leng1; i++)
	{
		ans[idx++] = str1[i];
		int j = 0;
		//bool isDel = 0;
		while (idx - 1 - j >= 0 && leng2 - 1 - j >= 0 && ans[idx - 1 - j] == str2[leng2 - 1 - j])
		{
			if (leng2 - 1 - j == 0)
			{
				idx -= leng2;
				//i -= leng2 - 1;
				//isDel = 1;
				break;
			}
			j++;
		}
		//if(!isDel) ans[idx++] = str1[i];
	}
	ans[idx] = '\0';
	if (idx == 0) cout << "FRULA" << endl;
	else cout << ans << endl;
	return 0;
}