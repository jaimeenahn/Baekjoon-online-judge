#include <iostream>
#include <stack>
using namespace std;
//0인 경우에는 북쪽을, 1인 경우에는 동쪽을, 2인 경우에는 남쪽을, 3인 경우에는 서쪽
/*	0 [0, -1]
	1 [-1, 0]
	2 [0, 1]
	3 [1, 0]
*/
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };
int map[50][50];
int direction;
pair<int, int> cur_pos;
int r, c;


int cnt = 0;

void dfs(pair<int, int> node)
{
	cur_pos = node;
	int x = node.first;
	int y = node.second;
	if (map[x][y] == 0)
	{
		cnt++;
		map[x][y] = 2;
		/*cout << "=======================" << endl;
		for (int a = 0; a < r; a++)
		{
			for (int b = 0; b < c; b++)
			{
				cout << map[a][b] << " ";

			}
			cout << endl;
		}*/
	}

	int in_dir = direction;

	do {
		
		int xx = x + dx[direction];
		int yy = y + dy[direction];
		if (direction == 0)
			direction = 3;
		else
			direction--;
		if (xx >= 0 && xx < r && yy >= 0 && yy < c)
		{
			if (map[xx][yy] == 0)
			{
				dfs(make_pair(xx, yy));
				break;
			}
			
		}
	} while (direction!=in_dir);
	if (cur_pos == node)
	{
		int xx = x + dx[(direction + 3) % 4];
		int yy = y + dy[(direction + 3) % 4];
		if (xx >= 0 && xx < r && yy >= 0 && yy < c)
		{
			if (map[xx][yy] == 1)
				return;
			else
				dfs(make_pair(xx, yy));

		}
	}
}


int main()
{
	
	scanf("%d %d", &r, &c);
	int x, y;
	int count = 0;
	scanf("%d %d %d", &x, &y, &direction);
	pair<int, int> robot = make_pair(x, y);
	cur_pos = robot;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0)
				count++;

		}
	}

	dfs(robot);
	cout << cnt << endl;

	return 0;
}