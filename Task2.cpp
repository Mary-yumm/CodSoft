// Task 2
#include<iostream>
#include<string>
#include<iomanip>
#include<sstream>
using namespace std;
bool Calculator(string& answer_string) {
	ostringstream oss;
	double num1, num2, ans = 0;
	char op = ' ';
	cout << "Enter first number: ";
	cin >> num1;
	cout << "Enter second number: ";
	cin >> num2;

		cout << "Enter the operation you want to perform (+,-,*,/): ";
		cin >> op;
		switch (op) {
		case '+':
			answer_string = " + ";
			ans = num1 + num2;
			break;
		case '-':
			answer_string = " - ";
			ans = num1 - num2;
			break;
		case '*':
			answer_string = " * ";
			ans = num1 * num2;
			break;
		case '/':
			answer_string = " / ";
			ans = num1 / num2;
			break;
		default:
			cout << "Invalid Choice!" << endl;
			return false;
		}
		if (num1 / int(num1) == 1) {
			oss << fixed << setprecision(1) << int(num1);
		}
		else
			oss << fixed << setprecision(1) << num1;
		oss << fixed << setprecision(1) << answer_string;
		if (num2 / int(num2) == 1) {
			oss << fixed << setprecision(1) << int(num2);
		}
		else
			oss << fixed << setprecision(1) << num2;
		oss << " = ";
		if (ans / int(ans) == 1) {
			oss << fixed << setprecision(1) << int(ans);
		}
		else
			oss << fixed << setprecision(1) << ans;
		answer_string = oss.str();
	
	return true;
}
int main() {
	cout << "------------------------------CALCULATOR------------------------------" << endl;
	bool flag = 0;
	while (true) {
		string answer;
		flag = Calculator(answer);
		if (flag) {
			cout << answer << endl;
			char choice;
			cout << "Do you want to perform another calculation?('n' for no and any key for yes) ";
			cin >> choice;
			if (choice == 'n')
				break;
		}

	}
	return 0;

}