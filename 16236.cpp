#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };

int n, steps;
int shark_size = 2;
int eat = 0;
bool no_more = false;
pair<int, int> shark_loc;

int sea[21][21];
bool chk[21][21];


void calculate_distance(pair<int, int> node)
{
	queue<pair<pair<int, int>, int>> q;
	vector<pair<int, int>> next_loc;
	chk[node.first][node.second] = true;
	int distance = 10000;
	q.push(make_pair(make_pair(node.first, node.second), 0));
	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dist = q.front().second;
		q.pop();
		if (dist >= distance)
			break;
		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx >= 0 && xx < n && yy >= 0 && yy < n)
			{
				
				if (chk[xx][yy] == false)
				{
					if (sea[xx][yy] <= shark_size)
					{
						chk[xx][yy] = true;
						if (sea[xx][yy] < shark_size && sea[xx][yy] >0) 
						{	
							//cout << xx << " " << yy << endl;
							distance = dist+1;
							next_loc.push_back(make_pair(xx, yy));
						}
						else
							q.push(make_pair(make_pair(xx, yy), dist + 1));
					}
				}
			}
		}

	}
	if (next_loc.size())
	{
		sort(next_loc.begin(), next_loc.end());
		sea[shark_loc.first][shark_loc.second] = 0;
		shark_loc = make_pair(next_loc[0].first, next_loc[0].second);
		//cout << shark_loc.first << " " << shark_loc.second << endl;
		eat += 1;
		sea[next_loc[0].first][next_loc[0].second] = 9;
		if (shark_size == eat)
		{
			shark_size = shark_size + 1;
			eat = 0;
		}
		steps += (distance);
		return;
	}
	else
		no_more = true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &sea[i][j]);
			if (sea[i][j] == 9)
			{
				shark_loc = make_pair(i, j);
				sea[i][j] = 0;
			}

		}
	}
	while (!no_more)
	{
		for (int i = 0; i < n; i++)
		{
			memset(chk[i], false, sizeof(bool)*(n+1));
		}
		
		calculate_distance(shark_loc);

	}
	
	if (no_more)
		cout << steps << endl;
}