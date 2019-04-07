#include <iostream>
#include <vector>
using namespace std;

int map[103][103];
vector<int> curves[10];

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };
int sx[] = { 0, 0, 1, 1 };
int sy[] = { 0 ,1, 0, 1 };
int cnt = 0;

int max_x = 0;
int max_y = 0;

int change_direction(int direction)
{
	return (direction + 1)%4;
}

void isSquare()
{
	for (int i = 0; i <= max_x; i++)
	{
		for (int j = 0; j <= max_y; j++)
		{
			bool flag = true;
			for (int k = 0; k < 4; k++)
			{
				int ii = i + sx[k];
				int jj = j + sy[k];
				if (ii >= 0 && ii <= 101 && jj >= 0 && jj <= 101)
					if (map[ii][jj] != 1)
						flag = false;
			}
			if (flag)
				cnt++;
		}
	}
}

void dragon_curve(pair<int, int> node, int generation, int current)
{
	if (current < generation)
	{
		for (int i = 0; i < curves[current - 1].size(); i++)
		{
			curves[current].push_back(curves[current - 1][i]);
		}
	}
	int x = node.first;
	int y = node.second;
	for (int i = curves[current-1].size()-1; i >=0 ; i--)
	{
		int direction = change_direction(curves[current-1][i]);
		int xx = x + dx[direction];
		int yy = y + dy[direction];
		if (map[xx][yy] == 0)
			map[xx][yy] = 1;
		x = xx;
		y = yy;
		curves[current].push_back(direction);
		if (max_x < x)
			max_x = x;
		if (max_y < y)
			max_y = y;
 	}
	
	if (current < generation)
	{
		dragon_curve(make_pair(x, y), generation, current + 1);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		int x, y, d, g;
		scanf("%d %d %d %d", &y, &x, &d, &g);
		map[x][y] = 1;
		map[x + dx[d]][y + dy[d]] = 1;
		if (max_x < x)
			max_x = x;
		if (max_y < y)
			max_y = y;
		if (max_x < x + dx[d])
			max_x = x + dx[d];
		if (max_y < y + dy[d])
			max_y = y + dy[d];

		if (g > 0)
		{
			curves[0].push_back(d);
			dragon_curve(make_pair(x + dx[d], y + dy[d]), g, 1);
		}
		
		for (int i = 0; i <= g; i++)
		{
			curves[i].clear();
		}
	}
	/*cout << "======================" << endl;
	for (int a = 90; a < 103; a++)
	{
		for (int b = 90; b < 103; b++)
		{
			cout << map[a][b] << " ";
		}
		cout << endl;
	}*/
	isSquare();

	cout << cnt << endl;
	return 0;
}