#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

int	land[11][11];
int	nutrient[11][11];//각 땅에 더해지는 양분
int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int n, m, k;

deque<int> pq[11][11];
queue<pair<int, int>> intercourse;

int main()
{
	
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &nutrient[i][j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			land[i][j] = 5;
		}
	}
	int idx = 0;
	for (int i = 0; i < m; i++)
	{
		int x, y, age;
		scanf("%d %d %d", &x, &y, &age);
		pq[x - 1][y - 1].push_back(age);
	}
	while (k--)
	{
		//cout << k << endl;
		//spring
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int pqsize = pq[i][j].size();
				bool flag = true;
				for (int t = 0; t < pqsize; t++)
				{
					int age = pq[i][j].front();
					//cout << i << " " << j << " " << age << endl;
					pq[i][j].pop_front();
					if (flag)
					{
						if (age <= land[i][j])
						{
							land[i][j] -= age;
							pq[i][j].push_back(age + 1);
							if((age+1)%5==0)
								intercourse.push(make_pair(i, j));
						}
						else {
							flag = false;
							land[i][j] += age / 2;
						}
					}
					else
					{
						land[i][j] += age / 2;
						
					}
						
				}
			}
		}
		//summer
		//fall
		while (!intercourse.empty())
		{
			pair<int, int> tree = intercourse.front();
			intercourse.pop();
			for (int i = 0; i < 8; i++)
			{
				int xx = tree.first + dx[i];
				int yy = tree.second + dy[i];
				if (xx >= 0 && xx < n && yy >= 0 && yy < n)
				{
					pq[xx][yy].push_front(1);
				}
			}
		}
		//winter
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				land[i][j] += nutrient[i][j];
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cnt += pq[i][j].size();
		}
	}
	printf("%d\n", cnt);
	return 0;

}