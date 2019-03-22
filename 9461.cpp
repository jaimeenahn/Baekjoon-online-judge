#include <iostream>

using namespace std;

long long int d[101];

int main() {
	int T;
	scanf("%d", &T);

	d[1] = 1;
	d[2] = 1;
	d[3] = 1;
	d[4] = 2;
	d[5] = 2;

	while (T--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 6; i <= n; i++)
		{
			d[i] = d[i - 1] + d[i - 5];
		}
		printf("%lld\n", d[n]);
	}

	return 0;
}