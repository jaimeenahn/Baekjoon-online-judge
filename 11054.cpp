#include <iostream>
#include <algorithm>


using namespace std;

int max(int a, int b, int c) { int king = a; if (king<b) king = b; if (king<c) king = c; return king; }

int c[1001];
int d[1001][2];
int main() {
	int num;
	scanf("%d", &num);
	int max_s = 0;
	for (int i = 0; i < num; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		c[i + 1] = tmp;
	}
	/*
	0 : increasing phase
	1 : decreasing phase
	*/
	for (int i = 1; i <= num; i++)
	{
		int x = c[i];
		for (int j = i; j >= 1; j--)
		{
			if (c[i] > c[j])
			{
				d[c[i]][0] = max(d[c[i]][0], d[c[j]][0] + 1);
				if (max_s < d[c[i]][0])
					max_s = d[c[i]][0];
			}
			else if(c[i] < c[j])
			{
				d[c[i]][1] = max(d[c[i]][1], d[c[j]][0] + 1, d[c[j]][1]+1);
				if (max_s < d[c[i]][1])
					max_s = d[c[i]][1];
			}
		}
	}
	printf("%d", max_s + 1);

	return 0;
}