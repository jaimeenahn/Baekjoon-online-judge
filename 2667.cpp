#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int graph[25][25];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int N;
int cnt = 0;
void numbering(int x, int y)
{
	graph[x][y] = 0;
	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx >= 0 && xx < N && yy >= 0 && yy < N)
		{
			if (graph[xx][yy] == 1)
			{
				cnt++;
				numbering(xx, yy);
			}
		}
	}
}

int main() {
	
	scanf("%d", &N);
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%1d", &graph[i][j]);
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (graph[i][j] == 1)
			{
				cnt = 1;
				numbering(i, j);
				v.push_back(cnt);
			}
		}
	}
	sort(v.begin(), v.end());
	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++)
	{
		printf("%d\n", v[i]);
	}

	return 0;

}
