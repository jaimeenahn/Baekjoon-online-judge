#include <iostream>

using namespace std;

int result[1001];

int main() {
	int number;

	scanf("%d", &number);

	result[1] = 1;
	result[2] = 2;
	for (int i = 3; i <= number; i++)
	{
		result[i] = (2 * result[i - 2] + (result[i - 1] - result[i - 2]));
	}

	printf("%d", result[number]);

	return 0;

}
