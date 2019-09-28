#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include <cstdio>
#include <queue>

using namespace std;

int dictNum;
int queryNum;

struct Trie
{
	Trie* next[26];
	bool isEnd;
	bool hasChild;
	int childNum;
	Trie()
	{
		/*
		for (int i = 0; i < 26; i++)
			next[i] = NULL;
		*/
		memset(next, NULL, sizeof(next));
		isEnd = false;
		hasChild = false;
		childNum = 0;
	}
	~Trie()
	{
		for (int i = 0; i < 26; i++)
			delete next[i];
	}
};

Trie* root;
queue<pair<Trie*, int>> qu;

void insert(string s)
{
	Trie* cur = root;
	int leng = s.length();
	for (int i = 0; i < leng; i++)
	{
		if (cur->next[s.at(i) - 'a'] == NULL)
		{
			Trie* nextTrie = new Trie();
			cur->next[s.at(i)-'a'] = nextTrie;
			cur->hasChild = true;
			cur->childNum++;
		}
		if (i == leng - 1)
			cur->next[s.at(i) - 'a']->isEnd = true;

		cur = cur->next[s.at(i) - 'a'];
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	cout << fixed;
	cout.precision(2);

	while (scanf("%d", &dictNum) > 0)
	{
		root = new Trie();
		for (int i = 0; i < dictNum; i++)
		{
			string s;
			cin >> s;
			insert(s);
		}
		double sum = 0;

		for (int i = 0; i < 26; i++)
		{
			if (root->next[i] != NULL)
			{
				qu.push({ root->next[i], 1 });
			}
		}
		while (!qu.empty())
		{
			Trie* cur = qu.front().first;
			int depth = qu.front().second;
			qu.pop();

			if (cur->isEnd)
			{
				sum += depth;
			}
			if (cur->hasChild)
			{
				if(cur->childNum > 1 || cur->isEnd)
				{
					depth += 1;
				}
				for (int i = 0; i < 26; i++)
				{
					if (cur->next[i] != NULL)
					{
						qu.push(make_pair(cur->next[i], depth));
						//cout << "i : " << char(i + 'a') << " " << depth << endl;
					}
				}
			}
		}
		cout << sum / (double)dictNum << endl;
	}

	return 0;
}