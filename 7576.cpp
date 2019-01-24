#include <iostream>	
#include <queue>
using namespace std;

int graph[1000][1000];
queue<pair<int, int>> q;
int N, M;
int yet = 0;
int days = 0;
int dx[] = { 1, -1, 0,0 };
int dy[] = { 0,0,1,-1 };


int main() {
	scanf("%d %d", &M, &N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int input;
			scanf("%d", &input);
			graph[i][j] = input;
			if (input == 0)
				yet++;
			else if (input == 1)
				q.push(make_pair(i, j));
		}
	}
	while (!q.empty())
	{
		pair<int, int> x = q.front();
		q.pop();
		for (int i = 0; i <4; i++)
		{
			int xx = x.first + dx[i];
			int yy = x.second + dy[i];
			if (xx >= 0 && xx < N && yy >= 0 && yy < M)
			{
				if (graph[xx][yy] == 0)
				{
					yet--;
					graph[xx][yy] = graph[x.first][x.second] + 1;
					//for (int k = 0; k < N; k++)
					//{
					//	for (int j = 0; j < M; j++)
					//	{
					//		cout << graph[k][j] << " ";
					//	}
					//	cout << endl;
					//}
					if (graph[xx][yy] > days)
						days = graph[xx][yy];
					q.push(make_pair(xx, yy));
				}
			}
		}
	}
	if (yet != 0)
		printf("-1\n");
	else
	{
		if (days == 0)
			printf("0\n");
		else
			printf("%d\n", days-1);
	}
	return 0;

}