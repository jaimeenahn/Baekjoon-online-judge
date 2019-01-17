#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	stack<char> fr;
	stack<char> re;

	string input;
	cin >> input;
	for (int i = 0; i < input.size(); i++)
	{
		fr.push(input[i]);
	}
	int num = 0;
	scanf("%d", &num);
	while (num--) {
		char cmd;		
		scanf(" %c", &cmd);
		cout << num << endl;
		if (cmd == 'L')
		{
			if (!fr.empty())
			{
				re.push(fr.top());
				fr.pop();
			}
		}
		else if (cmd == 'D')
		{
			if (!re.empty())
			{
				fr.push(re.top());
				re.pop();
			}
		}
		else if (cmd == 'B')
		{
			if (!fr.empty())
			{
				fr.pop();
			}
		}
		else if (cmd == 'P')
		{
			char alphabet;
			scanf(" %c", &alphabet);
			fr.push(alphabet);
		}
	}
	while (!fr.empty())
	{
		re.push(fr.top());
		fr.pop();
	}
	while (!re.empty()) {
		printf("%c", re.top());
		re.pop();
	}

	return 0;
}
