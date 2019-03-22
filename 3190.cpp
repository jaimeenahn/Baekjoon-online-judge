#include <iostream>
#include <vector>

using namespace std;

char time_step[10001];
char map[101][101];
int dx[] = { -1 , 0 , 1 ,0 };
int dy[] = { 0, -1, 0, 1 };

int main()
{
	int size;
	scanf("%d", &size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			map[i][j] = '0';
		}
	}
	map[0][0] = 'S';
	int num_apple;
	scanf("%d", &num_apple);
	vector<pair<int, int>> apple;
	for (int i = 0; i < num_apple; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		map[x - 1][y - 1] = 'A';
	}
	int num_cmd;
	scanf("%d", &num_cmd);
	for (int i = 0; i < num_cmd; i++)
	{
		int x;
		char c;
		cin >> x >> c;
		time_step[x] = c;
	}
	pair<int, int> snake_head = make_pair(0, 0);
	pair<int, int> snake_tail = make_pair(0, 0);
	int snake_length = 1;
	int head_direction = 3;
	int tail_direction = 3;
	int time = 0;
	while (1)
	{
		time++;
		if (time <= 10000)
		{
			//head

			//snake_move
			int x = snake_head.first;
			int y = snake_head.second;
			int tx = snake_tail.first;
			int ty = snake_tail.second;
			bool flag = false;
			int xx = x + dx[head_direction];
			int txx = tx + dx[tail_direction];
			int yy = y + dy[head_direction];
			int tyy = ty + dy[tail_direction];
			if (xx >= 0 && xx < size && yy >= 0 && yy < size && txx >= 0 && txx < size && tyy >= 0 && tyy < size)
			{
				snake_head = make_pair(xx, yy);
				if (map[xx][yy] == 'A')
				{
					map[xx][yy] = 'S';
					snake_length++;
					flag = true;
				}
				else if (map[xx][yy] == 'S')
				{
					cout << time << endl;
					return 0;
				}
				else
				{
					snake_tail = make_pair(txx, tyy);
					map[xx][yy] = 'S';
					map[tx][ty] = '0';
				}
			}
			else
			{
				cout << time << endl;
				return 0;
			}
			//cout << "=============================" << endl;
			/*for (int a = 0; a < size; a++)
			{
				for (int b = 0; b < size; b++)
				{
					cout << map[a][b] << " ";
				}
				cout << endl;
			}*/

			//방향전환
			if (time_step[time] == 'L')
				head_direction = (head_direction + 1) % 4;
			else if (time_step[time] == 'D')
			{

				if (head_direction == 0)
					head_direction = 3;
				else
					head_direction = (head_direction - 1);
			}

			if (time_step[time - snake_length + 1] == 'L' && !flag)
				tail_direction = (tail_direction + 1) % 4;
			else if (time_step[time - snake_length + 1] == 'D' && !flag)
			{
				if (tail_direction == 0)
					tail_direction = 3;
				else
					tail_direction = (tail_direction - 1);
			}
		}

	}
}