#include <iostream>

using namespace std;

int P[10001];
int d[1001];

int main()
{
	int cards;
	scanf("%d", &cards);
	for (int i = 0; i < cards; i++)
	{
		int card;
		scanf("%d", &card);
		P[i + 1] = card;
	}
	P[0] = 0;
	for (int i = 0; i <= cards; i++)
	{
		d[i] = P[i];
		for (int j = 0; j <= i/2; j++)
		{
			int tmp = d[j] + d[i - j];
			if (tmp > d[i])
				d[i] = tmp;
		}
	}
	printf("%d\n", d[cards]);

	return 0;
}