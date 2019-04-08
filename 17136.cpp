#include <iostream>

using namespace std;

int min_block = 1000000;

bool check(int board[10][10], pair<int, int> node, int blocksize)
{
	int x = node.first;
	int y = node.second;
	for (int i = x; i < x+blocksize; i++)
	{
		for (int j = y; j < y+blocksize; j++)
		{
			if (board[i][j] != 1)
				return false;
		}
	}
	return true;
}

void search(int board[10][10], pair<int, int> node, int used_blcoks, int avail_blocks[5], int tet)
{
	int x = node.first;
	int y = node.second;
	for (int k = 5; k > 0; k--)
	{
		if (avail_blocks[k-1] > 0)
		{
			if (check(board, node, k))
			{
				//cout << k << endl;
				tet = tet - (k*k);
				if (tet == 0)
				{
					if (used_blcoks + 1 < min_block)
						min_block = used_blcoks + 1;
				}
				for (int i = x; i < x+k; i++)
				{
					for (int j = y; j < y+k; j++)
					{
						board[i][j] = k + 1;
					}
				}
				/*cout << "======================================" << endl;
				for (int i = 0; i < 10; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						cout << board[i][j] << " ";
					}
					cout << endl;
				}*/
				avail_blocks[k-1] = avail_blocks[k-1] - 1;
				bool flag = false;
				for (int i = x; i < 10; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						if (board[i][j] == 1)
						{
							flag = true;
							//cout << "new block :  " << i << " " << j << endl;
							search(board, make_pair(i,j), used_blcoks + 1, avail_blocks, tet);
							break;
						}
					}
					if (flag)
						break;
				}
				for (int i = x; i < x + k; i++)
				{
					for (int j = y; j < y + k; j++)
					{
						board[i][j] = 1;
					}
				}
				avail_blocks[k-1] = avail_blocks[k-1] + 1;
				tet = tet + (k*k);
			}
		}

	}
	return;
}

int main()
{
	int min_x = 11;
	int min_y = 11;
	int map[10][10];
	int total_tet = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1)
			{
				total_tet++;
				if (i <= min_x)
				{
					if (j < min_y)
						min_y = j;
					min_x = i;
				}
			}
		}
	}
	int blocks[5] = { 5,5,5,5,5 };
	if (total_tet == 0)
		printf("0\n");
	else
	{
		search(map, make_pair(min_x, min_y), 0, blocks, total_tet);

		if (min_block > 25)
			printf("-1\n");
		else
			printf("%d\n", min_block);
	}
	return 0;
}