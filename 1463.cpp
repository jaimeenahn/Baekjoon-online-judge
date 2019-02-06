#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;
int step[1000000];

int makeone(int x)
{
	for (int i = x; i >1; i--)
	{
		int tmp;
		if (i % 3 == 0)
		{
			tmp = i / 3;
			if (step[tmp] == 0)
			{
				step[tmp] = step[i] + 1;
			}
			else
			{
				step[tmp] = min(step[tmp], step[i] + 1);
			}
		}
		if (i % 2 == 0) {
			tmp = i / 2;
			if (step[tmp] == 0)
			{
				step[tmp] = step[i] + 1;
			}
			else
			{
				step[tmp] = min(step[tmp], step[i] + 1);
			}
		}
		tmp = i - 1;
		if (step[tmp] == 0)
		{
			step[tmp] = step[i] + 1;
		}
		else
		{
			step[tmp] = min(step[tmp], step[i] + 1);
		}
	}

	return step[1];
}


int main(){
	int number;

	scanf("%d", &number);
	memset(step, 0, sizeof(int)*(number + 1));

	step[number] = 0;

	int result = makeone(number);

	printf("%d\n", result);

	return 0;
}