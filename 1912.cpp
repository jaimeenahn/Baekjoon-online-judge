#include <iostream>

using namespace std;

long long int c[100001];
long long int d[100001];

int main() {
	int number; 
	scanf("%d", &number);
	long long int max_sum = -1000;
	for (int i = 0; i < number; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		c[i + 1] = tmp;
	}
	for (int i = 1; i <= number; i++)
	{
		for (int j = i; j <= number; j++)
		{
			d[i] = d[i] + c[j];
			if (max_sum < d[i])
				max_sum = d[i];
			if (d[i] <= 0)
				break;
		}
	}
	printf("%lld\n", max_sum);
	return 0;
}