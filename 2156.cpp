#include <iostream>

using namespace std;

int max(int a, int b, int c) { int king = a; if (king<b) king = b; if (king<c) king = c; return king; }

int wine[10001];
int d[10001][3];

int main() {
	int glass;
	scanf("%d", &glass);
	for (int i = 0; i < glass; i++)
	{
		int w;
		scanf("%d", &w);
		wine[i + 1] = w;
	}
	/*
	0 : not drink
	1 : drink 
	2 : drink consecutively
	*/
	for (int i = 1; i <= glass; i++)
	{
		d[i][0] = max(d[i - 1][0], d[i - 1][1], d[i - 1][2]);
		d[i][1] = d[i - 1][0] + wine[i];
		d[i][2] = d[i - 1][1] + wine[i];
	}
	printf("%d", max(d[glass][0], d[glass][1], d[glass][2]));

	return 0;
}