#include <iostream>
#include <queue>
#include <string>
#include <tuple>
using namespace std;
int n, m;
int dx[] = { -1 ,1 ,0, 0 };
int dy[] = { 0, 0, -1, 1 };
int board[11][11];
bool chk[11][11][11][11];
queue<tuple<pair<int, int>, pair<int, int>, int, int>> q;
//queue (위치, 방향, 카운트)
// 위, 아래, 왼, 오
bool checkMove(pair<int, int> ball, int direction)
{
	int x = ball.first;
	int y = ball.second;
	//cout << x << " " << y << endl;
	if (x + dx[direction] >= 0 && x + dx[direction] < n && y + dy[direction] >= 0 && y + dy[direction] < m)
	{
		if ((board[x + dx[direction]][y + dy[direction]] != '.' && board[x + dx[direction]][y + dy[direction]] != 'O'))
			return false;
		return true;
	}
	return false;
}

bool bfs()
{
	while (!q.empty())
	{
		int red_x = get<0>(q.front()).first;
		int red_y = get<0>(q.front()).second;
		int blue_x = get<1>(q.front()).first;
		int blue_y = get<1>(q.front()).second;
		//cout << "===============================" << endl;
		//cout << "red : " << red_x << " " << red_y << endl;
		//cout << "blue : " << blue_x << " " << blue_y << endl;
		int direction = get<2>(q.front());
		//cout << "direction : " << direction << endl;
		int cnt = get<3>(q.front());
		if (cnt > 10)
		{
			return false;
		}
		q.pop();
		bool red_move = checkMove(make_pair(red_x, red_y), direction);
		bool blue_move = checkMove(make_pair(blue_x, blue_y), direction);
		bool flag = true;
		bool return_flag = false;
		while (red_move || blue_move)
		{
			//cout << 'a' << endl;
			if (board[red_x + dx[direction]][red_y + dy[direction]] == 'O')
			{
				red_x = n, red_y = m;
				//cout << blue_x << " " << blue_y << endl;
				//cout << "score" << endl;
				return_flag = true;
			}
			if (board[blue_x + dx[direction]][blue_y + dy[direction]] == 'O')
			{
				flag = false;
				return_flag = false;
				break;
			}
			if (red_move && blue_move)
			{
				red_x += dx[direction];
				red_y += dy[direction];
				blue_x += dx[direction];
				blue_y += dy[direction];
			}
			else if (red_move)
			{
				if (red_x + dx[direction] == blue_x && red_y + dy[direction] == blue_y)
					break;
				red_x += dx[direction];
				red_y += dy[direction];
			}
			else
			{
				if (blue_x + dx[direction] == red_x && blue_y + dy[direction] == red_y)
					break;
				blue_x += dx[direction];
				blue_y += dy[direction];
			}
			red_move = checkMove(make_pair(red_x, red_y), direction);
			blue_move = checkMove(make_pair(blue_x, blue_y), direction);
		}

		if (return_flag)
		{
			cout << cnt << endl;
			return true;
		}
		if (chk[red_x][red_y][blue_x][blue_y] == false)
		{
			chk[red_x][red_y][blue_x][blue_y] = true;
		}
		else
			flag = false;
		if (flag) {
			//cout << "red : " << red_x << " " << red_y << endl;
			//cout << "blue : " << blue_x << " " << blue_y << endl;
			for (int i = 0; i < 4; i++)
			{
				if (i == direction) continue;
				int xx = red_x + dx[i], yy = red_y + dy[i];
				int bx = blue_x + dx[i], by = blue_y + dy[i];
				if ((xx >= 0 && xx < n && yy >= 0 && yy < m) && (bx >= 0 && bx < n && by >= 0 && by < m))
				{
					q.push(make_tuple(make_pair(red_x, red_y), make_pair(blue_x, blue_y), i, cnt + 1));
				}
				else if ((xx >= 0 && xx < n && yy >= 0 && yy < m))
					q.push(make_tuple(make_pair(red_x, red_y), make_pair(blue_x, blue_y), i, cnt + 1));
				else if (bx >= 0 && bx < n && by >= 0 && by < m)
					q.push(make_tuple(make_pair(red_x, red_y), make_pair(blue_x, blue_y), i, cnt + 1));
			}

		}
	}
	return false;
}
int main()
{
	pair<int, int> red;
	pair<int, int> blue;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < m; j++)
		{
			board[i][j] = tmp[j];
			if (board[i][j] == 'R')
			{
				red = make_pair(i, j);
				board[i][j] = '.';
			}
			else if (board[i][j] == 'B')
			{
				blue = make_pair(i, j);
				board[i][j] = '.';
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{

		if (board[red.first + dx[i]][red.second + dy[i]] == '.' || board[red.first + dx[i]][red.second + dy[i]] == 'O' ||
			board[blue.first + dx[i]][blue.second + dy[i]] == '.' || board[blue.first + dx[i]][blue.second + dy[i]] == 'O')
		{
			chk[red.first][red.second][blue.first][blue.second] = true;
			q.push(make_tuple(red, blue, i, 1));
		}
	}
	if (!bfs())
		cout << -1 << endl;

}