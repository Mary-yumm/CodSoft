//Task 3
#include<iostream>
#include<iomanip>
using namespace std;
const int N = 5;
const int M = 11;

class TicTacToe {
	char* map[N]; // map which is to be printed
	int* grid[3]; 

public:
	TicTacToe();
	void CreationOfmap();
	void printmap();
	void Game();
	void Player1Turn();
	void Player2Turn();
	bool winner();
	bool checkp1(int i, int j);
	bool checkp2(int i, int j);
	bool CheckIfP1Wins();
	bool CheckIfP2Wins();
	void winner(int p);
	bool CheckIfTie();
};
TicTacToe::TicTacToe() {
	for (int i = 0; i < N; i++)
		map[i] = new char[M];
	for (int i = 0; i < 3; i++) {
		grid[i] = new int[3];
		for (int j = 0; j < 3; j++) {
			grid[i][j] = -1;
		}
	}
}
void TicTacToe::CreationOfmap() {
	for (int i = 0; i < N; i++) {
		int j = 0;
		while (j < M) {
			if (i % 2 != 0) {
				map[i][j] = '-';
				j++;
			}
			else {
				map[i][j] = ' ';
				map[i][j + 1] = ' ';
				map[i][j + 2] = ' ';
				map[i][j + 3] = '|';
				j += 4;
			}
		}

	}
}
void TicTacToe:: printmap() {
	for (int i = 0; i < N; i++) {
		cout << setw(100) << endl;
		for (int j = 0; j < M; j++) {
			cout << map[i][j];
		}
	}
}
void TicTacToe::Player1Turn() {
	while (true) {
		int p1Row, p1Col;
		while (true) {
			cout << "\nPlayer 1's Turn(X): " << endl;
			cout << "Row: ";
			cin >> p1Row;
			cout << "Column: ";
			cin >> p1Col;
			if (!(p1Row > 3 || p1Row < 1 || p1Col < 1 || p1Row>3))
				break;
		}

		if (grid[p1Row - 1][p1Col - 1]==-1) {
			grid[p1Row - 1][p1Col - 1] = 1;
			map[(p1Row - 1) * 2][(p1Col - 1) * 4 + 1] = 'X';
			break;
		}
		else {
			cout << "Invalid Input " << endl;
		}
	}
}
void TicTacToe::Player2Turn() {
	while (true) {
		int p2Row, p2Col;
		while (true) {
			cout << "\nPlayer 2's Turn(O): " << endl;
			cout << "Row: ";
			cin >> p2Row;
			cout << "Column: ";
			cin >> p2Col;
			if (!(p2Row > 3 || p2Row < 1 || p2Col < 1 || p2Row>3))
				break;
		}
		if (grid[p2Row - 1][p2Col - 1]==-1) {
			grid[p2Row - 1][p2Col - 1] = 0;
			map[(p2Row - 1) * 2][(p2Col - 1) * 4 + 1] = 'O';
			break;
		}
		else {
			cout << "Invalid Input " << endl;
		}
	}
}
bool TicTacToe::checkp1(int i, int j) {
	return grid[i][j] == 1;
}
bool TicTacToe:: checkp2(int i, int j) {
	return grid[i][j] == 0;
}
bool TicTacToe::CheckIfP1Wins() {
	//Check if Player 1 wins
	for (int i = 0; i < 3; i++) {
		if (checkp1(i, 0) && checkp1(i, 1) && checkp1(i, 2))
			return true;
	}
	for (int i = 0; i < 3; i++) {
		if (checkp1(0, i) && checkp1(1, i) && checkp1(2, i))
			return true;
	}
	if (checkp1(0, 0) && checkp1(1, 1) && checkp1(2, 2))
		return true;
	if (checkp1(0, 2) && checkp1(1, 1) && checkp1(2, 0))
		return true;
	return false;
}
bool TicTacToe::CheckIfP2Wins() {

	//Check if Player 2 Wins
	for (int i = 0; i < 3; i++) {
		if (checkp2(i, 0) && checkp2(i, 1) && checkp2(i, 2))
			return true;
	}
	for (int i = 0; i < 3; i++) {
		if (checkp2(0, i) && checkp2(1, i) && checkp2(2, i))
			return true;
	}
	if (checkp2(0, 0) && checkp2(1, 1) && checkp2(2, 2))
		return true;
	if (checkp2(0, 2) && checkp2(1, 1) && checkp2(2, 0))
		return true;
	return false;
}
void TicTacToe:: winner(int p) {
	if (p == 1)
		cout << "\nPlayer 1 Wins!" << endl;
	else if (p == 2)
		cout << "\nPlayer 2 Wins!" << endl;
}
bool TicTacToe::CheckIfTie() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (grid[i][j] == -1)
				return false;
		}
	}
	return true;
}
void TicTacToe::Game() {

	cout << "Instructions: " << endl;
	cout << "Choice for Player 1 is X" << endl;
	cout << "Choice for Player 2 is O" << endl << endl;
	cout << "It's a 3 cross 3 grid." << endl;
	cout << "Rows (1 to 3) , Columns (1 to 3)" << endl;

	CreationOfmap();
	printmap();

	while(true){
		while (true) {
			Player1Turn();
			printmap();
			if (CheckIfP1Wins()) {
				winner(1);
				break;
			}
			if (CheckIfTie()) { 
				cout << "\nGame has been tied!" << endl;
				break;
			}
			Player2Turn();
			printmap();
			if (CheckIfP2Wins()) {
				winner(2);
				break;
			}
		}
		char choice;
		cout << "Do you want to play again? n for no , any other key for yes: ";
		cin >> choice;
		if (choice == 'n')
			break;
		else {
			cout << endl;
			CreationOfmap();
			printmap();
		}
	}

}
int main() {
	TicTacToe game;
	game.Game();
	return 0;
}