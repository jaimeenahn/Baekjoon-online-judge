#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
n개의 수가 있을 때 n-1개의 연산자가 필요하고 각 번호가 있음
각 연산자들이 어디에 들어갈 지 구하면 최대 최소값을 구할 수 있을 것
0 : + 1 : - 2 : * 3 : /
*/
int main()
{
	int n;
	scanf("%d", &n);
	vector<int> numbers;
	vector<int> operators;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		numbers.push_back(tmp);
	}
	int op[4];
	long long int max_result = -1000000000;
	long long int min_result = 1000000000;
	for (int i = 0; i < 4; i++)
	{
		scanf("%d", &op[i]);
		if (i == 0)
		{
			for (int j = 0; j < op[0]; j++)
			{
				operators.push_back(0);
			}
		}
		else if (i == 1)
		{
			for (int j = 0; j < op[1]; j++)
			{
				operators.push_back(1);
			}
		}
		else if (i == 2)
		{
			for (int j = 0; j < op[2]; j++)
			{
				operators.push_back(2);
			}
		}
		else
		{
			for (int j = 0; j < op[3]; j++)
			{
				operators.push_back(3);
			}
		}
	}
	do
	{
		long long int result = numbers[0];
		for (int i = 0; i < n-1; i++)
		{
			if (operators[i] == 0)
			{
				result += numbers[i + 1];
			}
			else if (operators[i] == 1)
			{
				result -= numbers[i + 1];
			}
			else if (operators[i] == 2)
			{
				result *= numbers[i + 1];
			}
			else
			{
				result /= numbers[i + 1];
			}
		}
		if (result > max_result)
			max_result = result;
		if (result < min_result)
			min_result = result;
	} while (next_permutation(operators.begin(), operators.end()));

	cout << max_result << endl;
	cout << min_result << endl;

	return 0;

}