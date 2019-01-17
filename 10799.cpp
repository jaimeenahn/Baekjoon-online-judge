#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	string input;
	stack<char> s;
	char prev = ')';
	int pipe = 0;
	cin >> input;
	for (int i = 0; i < input.size(); i++)
	{
		if(i!=0)
			prev = input[i - 1];
		if (input[i] == '(')
		{
			s.push('(');
		}
		else if(input[i]==')')
		{
			if (prev == '(')
			{
				s.pop();
				pipe += s.size();
			}
			else
			{
				s.pop();
				pipe += 1;
			}
		}
	}
	printf("%d", pipe);

	return 0;
}