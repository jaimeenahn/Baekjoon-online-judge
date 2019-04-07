#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int map[8][8];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
queue<pair<int, int>> q;

int bfs(int cnt)
{
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx >= 0 && xx < n && yy >= 0 && yy < m)
			{
				if (map[xx][yy] == 0)
				{
					map[xx][yy] = 2;
					q.push(make_pair(xx, yy));
					cnt--;
					/*cout << "===========================" << endl;
					for (int o = 0; o < n; o++)
					{
						for (int p = 0; p < m; p++)
						{
							cout << map[o][p] << " ";
						}
						cout << endl;
					}*/
				}
			}
		}
	}
	return cnt;
}
int main()
{
	scanf("%d %d", &n, &m);
	int cnt = 0;
	int max_safe = 0;
	vector<int> v;
	vector<pair<int, int>> virus;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int tmp;
			scanf("%d", &tmp);
			v.push_back(tmp);

		}
	}
	int idx = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			map[i][j] = v[idx];
			idx++;
			if (map[i][j] == 0)
				cnt++;
			else if (map[i][j] == 2)
			{
				virus.push_back(make_pair(i, j));
			}
		}
	}
	
	for (int i = 0; i < n*m; i++)
	{	
		int x1 = i % n;
		int y1 = (i / n) % m;
		for (int j = i+1; j < n*m; j++)
		{	
			int x2 = j % n;
			int y2 = (j / n) % m;
			for (int k = j+1; k < n*m; k++)
			{
				int x3 = k % n;
				int y3 = (k / n) % m;
				idx = 0;
				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < m; j++)
					{
						map[i][j] = v[idx];
						idx++;
					}
				}
				if (map[x1][y1] == 0 && map[x2][y2] == 0 && map[x3][y3] == 0)
				{
					map[x1][y1] = 1;
					map[x2][y2] = 1;
					map[x3][y3] = 1;
					/*cout << x1 << " " << y1 << endl;
					cout << x2 << " " << y2 << endl;
					cout << x3 << " " << y3 << endl;*/
					for (int a = 0; a < virus.size(); a++)
					{
						q.push(virus[a]);
					}
					int safe = bfs(cnt-3);
					/*if (safe > max_safe)
					{
						for (int o = 0; o < n; o++)
						{
							for (int p = 0; p < m; p++)
							{
								cout << map[o][p] << " ";
							}
							cout << endl;
						}
					}*/
					max_safe = max(max_safe, safe);
					
				}
				
			}
		}
	}
	cout << max_safe << endl;

	return 0;
}
