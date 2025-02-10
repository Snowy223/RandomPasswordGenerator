#include <iostream>
#include <string>
#include <limits>
#include <cctype>
#include <cstdio>
#include <ctime>

namespace characters {
	std::string uppercase = "ABCDEFGHIHJKLMNOPQRSTUVWXYZ";
	std::string lowercase = "abcdefghihkjlmnopqrstuvwxyz";
	std::string numbers   = "0123456789";
	std::string special   = "!£$%^&*()-_=+<>/[]{}|~";
}

std::string PasswordGenerator(int pwLength, std::string params) {
	using namespace std;
	
	string randomchars;
	string result;
	for(int i = 0; i < params.length(); i++) {
		if(params[i] == 'N') continue;

		switch(i) {
		case 0:
			randomchars = randomchars + characters::uppercase;
			break;
		case 1:
			randomchars = randomchars + characters::lowercase;
			break;
		case 2:
			randomchars = randomchars + characters::numbers;
			break;
		default:
			randomchars = randomchars + characters::special;
			break;
		}
	}

	srand(time(0));
	for(int i = 0; i < pwLength; i++) {
		int randomNum = rand() % randomchars.length();

		result = result + randomchars[randomNum];
	}

	return result;
}

bool Menu() {
	using namespace std;
	string input;
	int pwLength;

	while(true) {
		cout << "Would you like to generate a password? (Y/N): ";
		cin >> input;

		input = toupper(input[0]);
		if(input == "Y") {
			break;
		}
		else if(input == "N") {
			return false;
		}
		else {
			cout << "\nWrong input. Please try again...\n";
			continue;
		}
		break;
	}

	while(true) {
		cout << "\nChoose the length of your password: ";
		cin >> pwLength;

		if(cin.fail()) {
			cout << "\nInvalid input. Please use an integer...\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			break;
		}
	}

	string params;
	bool failed;
	while(true) {
		cout << "\nNow choose which parameters you want: uppercase, lowercase, numbers, and special characters (yyyy/nnnn): ";
		cin >> params;

		if(params.length() != 4) {
			cout << "\nInvalid input. Please use the yyyy/nnnn format...";
			continue;
		}
		
		failed = false;
		for(int i = 0; i < params.length(); i++) {
			params[i] = toupper(params[i]);
			if(params[i] == 'Y') {
				continue;
			}
			else if(params[i] == 'N') {
				continue;
			}
			else {
				cout << "\nInvalid input. Please use the yyyy/nnnn format...";
				failed = true;
				break;
			}
		}
		if(failed) {
			continue;
		}
		if(params == "NNNN") {
			cout << "\nInput can't be all no's...";
			continue;
		}

		break;
	}


	string result;
	result = PasswordGenerator(pwLength, params);

	cout << result << "\n";
	return false;
}

int main() {
	while(true) {
		bool loop = Menu();
		if(!loop) {
			break;
		}	
	}
	return 0;	
}
