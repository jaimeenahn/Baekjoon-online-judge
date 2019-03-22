#include <iostream>
#include <algorithm>
using namespace std;

int max(int a, int b, int c) { int king = a; if (king<b) king = b; if (king<c) king = c; return king; }


int stair[301];
int d[301][3];
int main()
{
	int number;
	scanf("%d", &number);

	for (int i = 0; i < number; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		stair[i + 1] = tmp;
	}
	d[1][1] = stair[1];
	for (int i = 2; i <= number; i++)
	{
		d[i][1] = max(d[i - 2][1], d[i - 2][2]) + stair[i];
		d[i][2] = d[i - 1][1] + stair[i];
	}
	printf("%d", max(d[number][1], d[number][2]));

	return 0;
}