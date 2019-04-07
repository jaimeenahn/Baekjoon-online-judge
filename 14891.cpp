//12시방향부터 시계방향 순서대로 주어진다. N극은 0, S극은 1로 나타나있다.
//방향이 1인 경우는 시계 방향이고, -1인 경우는 반시계 방향이다.
//오른쪽 +6 왼쪽 +2
#include <iostream>
#include <memory.h>
#include <vector>
#include <queue>
using namespace std;

bool chk[4];
int gears[4][8];
int gear_top[4] = { 0, };
int dx[] = { -1, 1 };
queue<pair<int, int>> q;
void rotate(int gear, int direction)
{
	if (direction == -1)
		gear_top[gear] = (gear_top[gear] + 1) % 8;
	else
	{
		if (gear_top[gear] == 0)
			gear_top[gear] = 7;
		else
			gear_top[gear]--;
	}
}
void rotate_all()
{
	while (!q.empty())
	{
		int gear = q.front().first;
		int dir = q.front().second;
		q.pop();
		for (int i = 0; i < 2; i++)
		{
			int new_gear = gear + dx[i];
			if (new_gear >= 0 && new_gear < 4)
			{
				if (chk[new_gear] == false)
				{
					chk[new_gear] = true;
					if (i == 0)
					{
						if (gears[new_gear][(gear_top[new_gear] + 2) % 8] != gears[gear][(gear_top[gear] + 6) % 8])
							q.push(make_pair(new_gear, -1 * dir));
					}
					else if (i == 1)
					{
						if (gears[new_gear][(gear_top[new_gear] + 6) % 8] != gears[gear][(gear_top[gear] + 2) % 8])
							q.push(make_pair(new_gear, -1 * dir));
					}
				}
			}
		}
		rotate(gear, dir);
	}
}
int main()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			scanf("%1d", &gears[i][j]);
		}
	}
	int num_cmd; 
	scanf("%d", &num_cmd);
	vector<pair<int, int>> cmd;
	for (int i = 0; i < num_cmd; i++)
	{
		int tmp1, tmp2;
		scanf("%d %d", &tmp1, &tmp2);
		cmd.push_back(make_pair(tmp1-1, tmp2));
	}
	for (int i = 0; i < cmd.size(); i++)
	{
		memset(chk, false, sizeof(bool) * 4);
		chk[cmd[i].first] = true;
		q.push(make_pair(cmd[i].first, cmd[i].second));
		rotate_all();
	}
	int score = 0;
	int x = 1;
	for (int i = 0; i < 4; i++)
	{
		score += (gears[i][gear_top[i]]*x);
		x *= 2;
	}
	
	cout << score << endl;
}