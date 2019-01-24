#include <iostream>
#include <queue>

using namespace std;

int graph[100][100];
bool chk[100][100];
int dis[100][100];
queue <pair<int, int>> q;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int bridge;
int N;

void numbering(pair<int, int> node, int cnt) {
	int x = node.first;
	int y = node.second;
	q.push(node);
	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx >= 0 && xx < N && yy >= 0 && yy < N) {
			if (chk[xx][yy] == false && graph[xx][yy] == 1)
			{
				chk[xx][yy] = true;
				graph[xx][yy] = cnt;
				numbering(make_pair(xx, yy), cnt);
			}
				
		}
	}
	
}
void build()
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
			if (xx >= 0 && xx < N && yy >= 0 && yy < N) {
				if (graph[xx][yy] == 0)
				{
					graph[xx][yy] = graph[x][y];
					dis[xx][yy] = dis[x][y] + 1;
					q.push(make_pair(xx, yy));
				}
				else if (graph[xx][yy] != graph[x][y])
				{
					int distance = dis[xx][yy] + dis[x][y];
					if (distance < bridge)
						bridge = distance;
				}
			}
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int x;
			scanf("%d", &x);
			graph[i][j] = x;
			chk[i][j] = false;
			dis[i][j] = 0;
		}
	}
	int cnt = 1;
	bridge = 100000;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (graph[i][j] == 1 && chk[i][j]==false)
			{
				chk[i][j] = true;
				graph[i][j]=cnt;
				numbering(make_pair(i, j), cnt);
				cnt++;
			}
		}
	}
	build();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << dis[i][j] << " ";
		}
		cout << endl;
	}
	cout << bridge << endl;

	return 0;

}