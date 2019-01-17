#include <iostream>

using namespace std;
int a, b;
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { 1, 0, -1, 1, -1, 1, 0 ,-1 };
int island = 0;

void search(int x,int y, int graph[50][50])
{
	graph[x][y] = 0;
	for (int i = 0; i < 8; i++)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx >= 0 && xx < b && yy >= 0 && yy < a)
		{
			if (graph[xx][yy] == 1)
			{
				search(xx, yy, graph);
			}
		}
	}
}
int main()
{
	while (1)
	{
		island = 0;
		scanf("%d %d", &a, &b);
		
		if (a == 0 && b == 0)
			return 0;


		int graph[50][50];
		for (int i = 0; i < b; i++)
		{
			for (int j = 0; j < a; j++)
			{
				scanf("%d", &graph[i][j]);
			}
		}
		for (int i = 0; i < b; i++)
		{
			for (int j = 0; j < a; j++)
			{
				if (graph[i][j] == 1)
				{
					search(i, j, graph);
					island++;
				}
			}
		}
		printf("%d\n", island);
	}
	return 0;
}