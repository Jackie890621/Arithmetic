#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int n;
	long long num1, num2;
	vector<long long> stack;
	string str;
	string temp;
	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("\n");
		getline(cin, str);
		for (int j = 0; j < str.length(); j++) {
			if (str[j] >= 48 && str[j] <= 57) {
				temp += str[j];
				continue;
			}
			if (str[j] == ' ') {
				if (temp.empty()) {
					continue;
				}
				stack.push_back(stoll(temp));
				temp.clear();
			}
			if (str[j] == '+' || str[j] == '*') {
				if (!temp.empty()) {
					stack.push_back(stoll(temp));
                                	temp.clear();
				}
				num2 = stack.back();
				stack.pop_back();
				num1 = stack.back();
				stack.pop_back();
				if (str[j] == '+') {
					num1 = num1 + num2;
					stack.push_back(num1);
				} else {
					num1 = num1 * num2;
					stack.push_back(num1);
				}
			}

		}
		for (int j = 0; j < stack.size(); j++) {
			cout << stack[j] << endl;
		}
		str.clear();
		stack.clear();
	}
	return 0;
}
