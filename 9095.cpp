#include <iostream>

using namespace std;

int d[12];

int main() {
	int num;
	scanf("%d", &num);
	d[1] = 1;
	d[2] = 2;
	d[3] = 4;
	while (num--)
	{
		int number;
		scanf("%d", &number);
		for (int i = 4; i <=number; i++)
		{
			d[i] = d[i - 1] + d[i - 2] + d[i - 3];
		}
		printf("%d\n", d[number]);
	}
	return 0;
}