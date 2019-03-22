#include <iostream>
#include <algorithm>
using namespace std;

int sticker[2][100000];
int d[100001][3];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int max(int a, int b, int c) { int king = a; if (king<b) king = b; if (king<c) king = c; return king; }

int main() {
	int num;
	scanf("%d", &num);

	while (num--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int score;
				scanf("%d", &score);
				sticker[i][j] = score;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			d[i][0] = max(d[i - 1][0], d[i - 1][1], d[i - 1][2]);
			d[i][1] = max(d[i - 1][0], d[i - 1][2]) + sticker[0][i-1];
			d[i][2] = max(d[i - 1][0], d[i - 1][1]) + sticker[1][i - 1];
		}
		printf("%d\n", max(d[n][0], d[n][1], d[n][2]));
	}
	return 0;
}