#include <iostream>
#include <string>

using namespace std;

string ans[3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	string s;
	cin >> n;
	cin >> s;
	int len = s.length();
	//getline(cin, s);
	
	if (len == 0)
	{
		cout << endl;
		cout << endl;
		cout << endl;
		return 0;
	}
	
	if (n == 2)
	{
		ans[1] = s;
		for (int i = 1; i < len - 1; i++)
		{
			if (s.at(i) == '_')
			{
				s.at(i) = (char)(s.at(i + 1) - 32);
				for (int j = i + 1; j < len - 1; j++)
				{
					s.at(j) = s.at(j + 1);
				}
				s.at(len - 1) = '\0';
				len--;
			}
		}
		s.resize(len);
		ans[0] = s;
		s.at(0) = (char)(s.at(0) - 32);
		ans[2] = s;
	}
	else
	{
		if(s.at(0) >= 'A' && s.at(0) <= 'Z')
			s.at(0) = (char)(s.at(0) + 32);
		ans[0] = s;
		for (int i = 1; i < len; i++)
		{
			if (s.at(i) >= 'A' && s.at(i) <= 'Z')
			{
				s.resize(len + 1);
				for (int j = len; j > i + 1; j--)
				{
					s.at(j) = s.at(j - 1);
				}
				s.at(i + 1) = (char)(s.at(i) + 32);
				s.at(i) = '_';
				len++;
			}
		}
		s.resize(len);
		ans[1] = s;
		ans[2] = ans[0];
		ans[2].at(0) = (char)(ans[2].at(0) - 32);
	}
	
	for (int i = 0; i < 3; i++)
		cout << ans[i] << endl;
	
	return 0;
}