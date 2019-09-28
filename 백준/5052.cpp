#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int T;
int n;
bool isConsis;
string tel[10003];

struct Trie
{
	Trie* nextTrie[10];
	bool isEnd;
	Trie()
	{
		//fill(nextTrie, nextTrie + 10, NULL);
		for (int i = 0; i < 10; i++)
			nextTrie[i] = NULL;
		isEnd = false;
	}
	~Trie()
	{
		for (int i = 0; i < 10; i++)
			delete nextTrie[i];
	}
};

Trie* root;
Trie* cur;



void makeTrie(string tel)
{
	int i = 0;
	while (tel[i] != '\0')
	{
		int num = tel[i] - '0';
		if (cur->nextTrie[num] != NULL)
		{
			if (cur->nextTrie[num]->isEnd == true || tel[i + 1] == '\0')
			{
				isConsis = false;
				return;
			}
			cur = cur->nextTrie[num];
		}
		else
		{
			Trie* temp = new Trie();
			cur->nextTrie[num] = temp;
			cur = temp;
			if (tel[i + 1] == '\0')
				cur->isEnd = true;
		}

		i++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		isConsis = true;
		cin >> n;
		root = new Trie();
		for (int i = 0; i < n; i++)
		{
			cin >> tel[i];
			
		}
		for (int i = 0; i < n; i++)
		{
			cur = root;
			makeTrie(tel[i]);
			if (!isConsis)
				break;
		}
		if (isConsis)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		//delete root;
	}
	
	return 0;
}