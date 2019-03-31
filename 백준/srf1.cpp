#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <string>

using namespace std;

typedef pair<int, int> pii;

queue<pii> q;

int T;
int N;
char arr[21][21];
bool visited[21][21];
int cnt[26];
//bool checkCnt[26];
bool visitedCh[26];
int kindCnt;
bool cond1, cond2, cond3;
bool redT;
bool redT2;


int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };


class Rec
{
public:
	Rec() {}
	Rec(int x1, int y1, int x2, int y2)
	{
		this->x1 = x1;
		this->x2 = x2;
		this->y1 = y1;
		this->y2 = y2;
	}
	int x1;
	int y1;
	int x2;
	int y2;
};

vector<Rec> vec;

void dfs2(int x, int y, int x1, int y1, int x2, int y2)
{
	if (!visited[y][x])
	{
		visited[y][x] = true;
		int chnum = arr[y][x] - 'A';
		if (!visitedCh[chnum])
		{
			visitedCh[chnum] = true;
			kindCnt++;
			if (kindCnt == 3)
			{
				redT2 = true;
				return;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= x1 && nx <= x2 && ny >= y1 && ny <= y2)
			{
				if ((arr[ny][nx] == arr[y][x]) && !visited[ny][nx])
				{
					dfs2(nx, ny, x1, y1, x2, y2);
				}
			}
		}
	}
	return;
}


void verify(int x1, int y1, int x2, int y2)
{
	redT = false;
	redT2 = false;
	memset(visited, 0, sizeof(visited));
	memset(cnt, 0, sizeof(cnt));
	//memset(checkCnt, 0, sizeof(checkCnt));
	memset(visitedCh, 0, sizeof(visitedCh));
	kindCnt = 0;
	cond1 = false;
	cond2 = false;
	cond3 = false;

	for (int y = y1; y <= y2; y++)
	{
		for (int x = x1; x <= x2; x++)
		{
			if (!visited[y][x])
			{
				cnt[arr[y][x] - 'A']++;

				dfs2(x, y, x1, y1, x2, y2);
				if (redT2)
					break;
				/*
				q.push(make_pair(x, y));
				while (!q.empty())
				{
					int cx = q.front().first;
					int cy = q.front().second;
					q.pop();

					if (!visited[cy][cx])
					{
						visited[cy][cx] = true;
						int chnum = arr[cy][cx] - 'A';
						if (!visitedCh[chnum])
						{
							visitedCh[chnum] = true;
							kindCnt++;
						}
						for (int i = 0; i < 4; i++)
						{
							int nx = cx + dx[i];
							int ny = cy + dy[i];
							if (nx >= x1 && nx <= x2 && ny >= y1 && ny <= y2)
							{
								if ((arr[ny][nx] == arr[cy][cx]) && !visited[ny][nx])
								{
									q.push(make_pair(nx, ny));
								}
							}
						}
					}

				}
				*/
			}
		}
		if (redT2)
			break;
	}
	if (kindCnt == 2)
	{
		cond1 = true;
		for (int i = 0; i < 26; i++)
		{
			if (cnt[i] == 1)
				cond2 = true;
			else if (cnt[i] >= 2)
				cond3 = true;
		}
	}
	if (cond1 && cond2 && cond3)
	{
		bool isIn = false;
		redT = true;
		/*
		for (Rec rec : vec)
		{
			if (x1 >= rec.x1 && x2 <= rec.x2 && y1 >= rec.y1 && y2 <= rec.y2)
			{
				isIn = true;
			}
			if (rec.x1 >= x1 && rec.x2 <= x2 && rec.y1 >= y1 && rec.y2 <= y2)
			{

			}
		}
		*/
		for (int i = 0; i < vec.size();)
		{
			Rec rec = vec.at(i);
			if (x1 >= rec.x1 && x2 <= rec.x2 && y1 >= rec.y1 && y2 <= rec.y2)
			{
				isIn = true;
				break;
			}
			if (rec.x1 >= x1 && rec.x2 <= x2 && rec.y1 >= y1 && rec.y2 <= y2)
			{
				vec.erase(vec.begin() + i);
			}
			else
			{
				i++;
			}
		}
		if (!isIn)
		{
			Rec rec2(x1, y1, x2, y2);
			vec.push_back(rec2);
		}
	}
	return;
}
/*
void dfs(int x1, int y1, int x2, int y2)
{
	if (x1 > x2 || y1 > y2)
		return;
	verify(x1, y1, x2, y2);
	if (!redT && kindCnt >= 2)
	{
		dfs(x1 + 1, y1, x2, y2);
		dfs(x1, y1 + 1, x2, y2);
		dfs(x1, y1, x2 - 1, y2);
		dfs(x1, y1, x2, y2 - 1);
	}
	return;
}
*/
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);

	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		vec.clear();
		memset(visitedCh, 0, sizeof(visited));
		kindCnt = 0;
		cin >> N;
		/*
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> arr[i][j];
				if (!visitedCh[arr[i][j] - 'A'])
				{
					visitedCh[arr[i][j] - 'A'] = true;
					kindCnt++;
				}
			}
		}
		*/
		for (int i = 0; i < N; i++)
		{
			string s;
			cin >> s;
			for (int j = 0; j < s.length(); j++)
			{
				arr[i][j] = s.at(j);
				if (!visitedCh[arr[i][j] - 'A'])
				{
					visitedCh[arr[i][j] - 'A'] = true;
					kindCnt++;
				}
			}
		}
		if (kindCnt >= 2)
		{
			//dfs(0, 0, N - 1, N - 1);
			for (int y1 = 0; y1 < N; y1++)
			{
				for (int x1 = 0; x1 < N; x1++)
				{
					for (int y2 = N - 1; y2 >= y1; y2--)
					{
						for (int x2 = N - 1; x2 >= x1; x2--)
						{
							verify(x1, y1, x2, y2);
						}
					}
				}
			}
		}

		cout << "Case #" << t << endl;
		cout << vec.size() << endl;
		/*
		for (Rec rec : vec)
		{
			cout << rec.x1 << " " << rec.y1 << " " << rec.x2 << " " << rec.y2 << endl;
		}
		*/

	}


	return 0;
}