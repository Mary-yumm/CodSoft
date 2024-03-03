//Task 1
#include<iostream>
using namespace std;
int main() {
	int guess, number;
	char choice=' ';
	bool flag = 0;
	srand(time(0));
	cout << "------------------------------Number Guessing Game------------------------------" << endl;
	while (true) {
		number = rand();
		cout << "Guess the number(Press -1 to to reveal the number): ";
		cin >> guess;
		if (guess == -1) {
			cout << "Number was " << number << endl;
			flag = 1;
		}
		else if (guess < number) {
			cout << "Guess is too low" << endl;
		}
		else if (guess > number) {
			cout << "Guess is too high" << endl;
		}
		else {
			cout << "Guessed number is correct!" << endl;
			flag = 1;
		}
		if (flag == 1) {
			cout << "Do you want to guess another number? y/n : ";
			cin >> choice;
			if (choice == 'n')
				break;
		}
	}
	
	return 0;
}