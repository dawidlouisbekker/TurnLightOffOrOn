#include <iostream>
#include <string>
#include <utility>
//#include <initializer_list>

using namespace std;

std::string line = "";
bool on = false;

template <typename... Words>    //std:c++ 17 or higher
bool IsInputStringThis(std::string line, Words... words) {
	return ((words == line) || ...);
};



template <typename... Words> //std:c++ 17 or higher for the "...", it is an args list
bool IsInputStreamThis(iostream& in_cin, Words... words) { //Program will freeze if you use this because '&' is in iostream& so it locks memory I think (refrence variable) and does not make copy.
	string line;
	getline(in_cin, line);
	return ((words == line) || ...);
};

template <typename... Words>
bool IsInputThis(Words... words) {
	string line;
	getline(std::cin, line);
	return ((words == line) || ...);
};

static void PromptUser() {
	cout << "Turn on light bulb (yes, Yes , y, no, No, n): ";
}
///////////////////////////////////////////////////////////Example


bool prompt_user_with_and_use_IsInputStringThis() {
	PromptUser();
	getline(std::cin, line);
	if (IsInputStringThis(line, "Yes", "yes", "y")) {
		on = true;
		cout << "Turned Light Bulb on" << endl;
		//could also do this // return false;
	}
	if (IsInputStringThis(line, "No, no, n")) {
		on = false;
		cout << "Turned Light Bulb off";
		//could also do this // return false;
	}
	if (on != true && on != false) {
		cout << "You did not input a valid option please try again" << endl;
		false;
	}
	else {

		return true; }
};

int main() {
	//example
	bool isfinished = false;

		 //accesses you cmd and puts in cls basically
	prompt_user_with_and_use_IsInputStringThis();
	system("cls");
	cout << "type 'exit' to quite" << endl;
	string choice;
	while (isfinished == false) {
		cout << "Would you like to turn on the light? (type 'yes', 'Yes', 'YES', 'yEs' or 'no','No','N','n','nO')" << endl;
		getline(cin, choice);
		if (IsInputStringThis(choice, "yes", "Yes", "YES", "yEs")) //Bag of words
		{
			if (on = true) {
				cout << "Light is already on" << endl;
			}
			if(on = false) {
				cout << "Turned on light" << endl;
			}
			
		}; 

		if (IsInputStringThis(choice, "no", "No", "N", "n", "nO")) //Bag of words
		{
			if (on = true) {
				cout << "Light is already on" << endl;
			}
			if (on = false) {
				cout << "Turned on light" << endl;
			}
		};

		if (IsInputStringThis(choice, "exit")) //Bag of words
		{
			system("cls");
			cout << "Exiting";
			isfinished = true;
		};
		
		//almost like bag of words
	};

	//Mine


	return 1;
}

/*bool isValid(iostream cin) {
	std::string line;
	getline(cin, line);
	int asciiVal;
	for (char ch : line) {
		asciiVal = static_cast<int>(ch);
	}
}
*/
