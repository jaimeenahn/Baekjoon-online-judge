#include <iostream>

using namespace std;

int d[31][2];
/*
0 : maintained one
1 : newly generated one
*/

int main()
{
	int number;
	scanf("%d", &number);

	d[2][1] = 3;

	for (int i = 3; i <= number; i++)
	{
		if (i % 2 == 1)
		{
			d[i][0] = 0;
			d[i][1] = 0;
		}
		else
		{	
			cout << i << endl;
			for (int k = 2; k <= i; k+=2)
			{
				d[i][0] += (d[i - k][0] + d[i - k][1]) * d[k][1];
				cout <<k << " " <<(d[i - k][0] + d[i - k][1]) * d[k][1] << endl;
			}
			d[i][1] = 2;
		}
	}

	printf("%d\n", d[number][0]+d[number][1]);

	return 0;

}