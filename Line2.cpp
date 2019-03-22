//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//int main(void) {
//	string str;
//	cin >> str;
//
//	vector<string> element;
//	vector<string> num_elem;
//	int cnt = 0;
//
//	for (int i = 0; i < str.length(); i++)
//	{
//		if (str[i] <= 90 && str[i] >= 65)
//		{
//			if (str[i + 1] >= 97 && str[i + 1] <= 122)
//			{
//				element.push_back(str.substr(i, 2));
//			}
//			else
//			{
//				element.push_back(str.substr(i, 1));
//			}
//		}
//		else if (str[i] >= 49 && str[i] <= '57')
//		{
//			if (i != str.length() - 1)
//			{
//				if (str[i + 1] == 48)
//					num_elem.push_back(str.substr(i, 2));
//				else
//					num_elem.push_back(str.substr(i, 1));
//			}
//			else
//				num_elem.push_back(str.substr(i, 1));
//		}
//	}
//	if (element.size() != num_elem.size())
//	{
//		printf("error\n");
//		return 0;
//	}
//	for (int i = 0; i < element.size(); i++)
//	{
//		cout << element[i];
//		if (num_elem[i] == "1")
//			continue;
//		else
//			cout << num_elem[i];
//	}
//	printf("\n");
//}