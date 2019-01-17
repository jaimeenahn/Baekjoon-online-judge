#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int graph[100][100];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
queue<pair<pair<int, int>, int>> q;
int N, M;
int cnt = 0;
void bfs()
{
	int count;
	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		count = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx == N-1 && yy == M-1)
			{
				printf("%d\n", count + 1);
				return;
			}
			else if (xx >= 0 && xx < N && yy >= 0 && yy < M)
			{
				if (graph[xx][yy] == 1)
				{
					graph[xx][yy] = 0;
					q.push(make_pair(make_pair(xx, yy),count+1));
				}
			}
		}
	}
	printf("0\n");
}

int main() {
	
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &graph[i][j]);
		}
	}
	graph[0][0] = 0;
	q.push(make_pair(make_pair(0, 0), ++cnt));
	bfs();

	return 0;
}

