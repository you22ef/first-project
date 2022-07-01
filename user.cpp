#include<iostream>
#include<string>
#include<regex>
#include<conio.h>
#include<sstream> 
#include<cctype> 
#include<cstring> 
#include<fstream>
#include<vector>
#include"user.h"
using namespace std;
char password3[50];
char password2[50];
char password4[50];
char password5[50];
int n1 = 0;
int n2 = 0;
string word;
string word2;
int shifts, len;
int line_num = 0;
int choice;

bool user::isvalidemail(string e) {

	if (regex_match(e, regex(("^(([^<>()[\\]\\.,;:\\s@\"]+(\\.[^<>()[\\]\\.,;:\\s@\"]+)*)|(\".+\"))@((\\[[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\])|(([a-zA-Z\\-0-9]+\\.)+[a-zA-Z]{2,}))$")))) {
		return true;
		
	}
	else {
		return false;
	}
}
bool user::isvalidphonenum(string e) {

	if (regex_match(e, regex("^(010|011|012|015)+[0-9]{8}$"))) {
		return true;
	}
	else {
		return false;
	}
}
bool user::isvalidusername(string e) {

	if (regex_match(e, regex("^[a-zA-Z-_ ]{0,20}$"))) {
		return true;
	}
	else {
		return false;
	}
}
bool user::isvalidpassword(string e) {

	if (regex_match(e, regex("^[A-Z]+[a-z]+[\@|\#|\%|\&|\$|\!|\+|\-]*[0-9]+$"))) {

		return true;

	}
	else {
		return false;

	}
}

void user::setemail() {
	string e;
	cout << "please enter your email : ";
	cin >> e;
	if (isvalidemail(e)) {
		email = e;
		previousemail(email);
	}
	else {
		cout << "please enter a valid email!!" << endl;
		setemail();
	}

}
void user::setphone() {
	string e;
	cout << "please enter your phone num : ";
	cin >> e;
	if (isvalidphonenum(e)) {
		phone = e;
		previousphone(phone);
	}
	else {
		cout << "please enter a valid phone num!!" << endl;
		setphone();
	}

}
void user::setusername() {
	string e;
	cout << "please enter the username : ";
	cin.ignore();
	getline(cin, e);
	if (isvalidusername(e)) {
		username = e;
		previoususername(username);
	}
	else {
		cout << "please enter a valid username!!" << endl;
		setusername();
	}

}

void user::setpassword() {
	word = "";
	int i;
	char ch;
	cout << "please enter a password (0-9) : ";
	for (i = 0; (ch = _getch()) != '\r';) {
		if (ch != '\b') {
			password2[i] = ch;
			cout << "*";
			i++;
		}

		else {
			i--;
			if (i < 0) {
				i++;
			}
			else {
				cout << "\b \b";
			}
		}
	}
	for (int y = 0; y < i; y++) {
		word = word + password2[y];
	}

	if (isvalidpassword(password2)) {
		cout << endl;
		encryptpassword(password2);
	}
	else {
		cout << endl;
		cout << "please enter a valid password!!" << endl;
		setpassword();
	}

}

void user::setpassword_to_login() {
	word = "";
	int i;
	char ch;
	cout << "please enter your password (0-9) : ";
	for (i = 0; (ch = _getch()) != '\r';) {
		if (ch != '\b') {
			password2[i] = ch;
			cout << "*";
			i++;
		}

		else {
			i--;
			if (i < 0) {
				i++;
			}
			else {
				cout << "\b \b";
			}
		}
	}
	for (int y = 0; y < i; y++) {
		word = word + password2[y];
	}
	len = word.length();
	for (int i = 0; i < len; i++) {

		word[i] = int(word[i]) + 6;
	}

	loginpassword(word);


}

void user::confirmpassword() {
	int i;
	char ch;
	cout << "please confirm your password : ";
	for (i = 0; (ch = _getch()) != '\r';) {
		if (ch != '\b') {
			password3[i] = ch;
			cout << "*";
			i++;
		}

		else {
			i--;
			if (i < 0) {
				i++;
			}
			else {
				cout << "\b \b";
			}
		}
	}
	for (int y = 0; y < i; y++) {
		word2 = word2 + password2[y];
	}
	if (word == word2) {
		if (choice == 1) {
			cout << endl << endl;
			n1++;
			cout << "Congratulation!!, you registerd successfully :) " << endl;
			cout << endl;
			password = password2;
		}
	}
	else {
		word2 = "";
		cout << endl;
		cout << "Please enter the same password!! " << endl;
		confirmpassword();

	}
}
void user::save_data(string e) {
	ofstream myfile2;
	myfile2.open("data.txt", ios::out | ios::app);
	myfile2 << e << endl;
	myfile2.close();

}

void user::encryptpassword(string e) {
	len = e.length();
	for (int i = 0; i < len; i++) {

		e[i] = int(e[i]) + 6;
	}
	epassword = e;
	previouspassword(epassword);
}

void user::previousemail(string e) {
	ifstream file;
	char text;
	string line = "";
	file.open("data.txt");
	while (!file.eof()) {
		file.get(text);
		line = line + text;
		if (text == '\n') {
			line.pop_back();
			if (email.compare(line) == 0) {
				cout << "this email is already exist !!" << endl;
				cout << "please enter another email" << endl;
				setemail();
			}
			line = "";
		}
	}
}

void user::previouspassword(string e) {
	n1 = n2;
	ifstream file;
	char text;
	string line = "";
	file.open("data.txt");
	while (!file.eof()) {
		file.get(text);
		line = line + text;
		if (text == '\n') {
			line.pop_back();
			if (e.compare(line) == 0) {
				if (choice == 1) {
					cout << "this password is already exist !!" << endl;
					cout << "please enter another password" << endl;
					setpassword();
				}
				else if (choice == 3) {
					change_password(e);
				}
			}
			line = "";
		}
	}
	if (n1 == n2 && (choice == 1 || choice == 2)) {
		confirmpassword();
	}
	if (n1 == n2 && choice == 3) {
		cout << "not exist!!" << endl;
		isvalid_new_password();
	}
}

void user::previoususername(string e) {
	ifstream file;
	char text;
	string line = "";
	file.open("data.txt");
	while (!file.eof()) {
		file.get(text);
		line = line + text;
		if (text == '\n') {
			line.pop_back();
			if (e.compare(line) == 0) {
				cout << "this username is already exist !!" << endl;
				cout << "please enter another username" << endl;
				setusername();
			}
			line = "";
		}
	}
}

void user::previousphone(string e) {
	ifstream file;
	char text;
	string line = "";
	file.open("data.txt");
	while (!file.eof()) {
		file.get(text);
		line = line + text;
		if (text == '\n') {
			line.pop_back();
			if (e.compare(line) == 0) {
				cout << "this phone num is already exist !!" << endl;
				cout << "please enter another phone num" << endl;
				setphone();
			}
			line = "";
		}
	}
}

void user::loginusername() {
	string username1;
	static int counter = 0;
	bool check = false;
	cout << "please enter your username : ";
	cin.ignore();
	getline(cin, username1);
	ifstream file;
	char text;
	string line = "";
	file.open("data.txt");
	while (!file.eof()) {
		file.get(text);
		line = line + text;
		if (text == '\n') {
			line_num++;
			line.pop_back();
			if (username1.compare(line) == 0) {
				username = username1;
				check = true;
				break;
			}
			line = "";
		}

	}
	if (check) {
		setpassword_to_login();
	}
	else {
		cout << "login faild..pls try agine" << endl;
		counter++;
		if (counter == 3) {
			cout << "you are denied access to the system : " << endl;
			counter = 0;
			menue();
		}
		else {
			loginusername();
		}
	}

}

void user::loginpassword(string e) {
	int line_num2 = 0;
	bool check = false;
	static int counter = 0;
	ifstream file;
	char text;
	string line = "";
	file.open("data.txt");
	while (!file.eof()) {
		file.get(text);
		line = line + text;
		if (text == '\n') {
			line_num2++;
			if (line_num2 == line_num + 1) {
				line.pop_back();
				if (e.compare(line) == 0) {
					check = true;
					break;
				}
			}
			line = "";
		}
	}
	if (check) {
		cout << endl << endl;
		cout << "Successful login, welcome " << username << endl << endl;
		line_num = 0;
		menue();
	}
	else {
		cout << endl;
		cout << "login faild..pls try agine" << endl;
		counter++;
		if (counter == 3) {
			cout << "you are denied access to the system : " << endl;
			counter = 0;
			menue();
		}
		else {
			setpassword_to_login();
		}
	}

}


void user::menue() {

	while (true) {

		cout << "what do you want to do today (1-2) " << endl;
		cout << "1- registration\n2- login\n3- change password\n--> ";
		if (!cin) {
			// unset failbit
			cin.clear();
			// clear the buffer
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cin >> choice;
		if (choice == 1) {
			registration();
		}
		if (choice == 2) {
			login();
		}
		if (choice == 3) {
			isvalid_new_password();
		}

	}
}

void user::isvalid_new_password() {
	word = "";
	int i;
	char ch;
	cout << "please enter your old password (0-9) : ";
	for (i = 0; (ch = _getch()) != '\r';) {
		if (ch != '\b') {
			password4[i] = ch;
			cout << "*";
			i++;
		}
		else {
			i--;
			if (i < 0) {
				i++;
			}
			else {
				cout << "\b \b";
			}
		}
	}
	for (int y = 0; y < i; y++) {
		word = word + password4[y];
	}

	if (isvalidpassword(password4)) {
		cout << endl;
		len = word.length();
		for (int i = 0; i < len; i++) {

			word[i] = int(word[i]) + 6;
		}
		previouspassword(word);
	}
	else {
		cout << endl;
		cout << "please enter a valid password!!" << endl;
		isvalid_new_password();
	}

}
void user::change_password(string e) {
	vector<string>data;
	string line;
	string name;
	string new_password;
	int i = 0;
	ifstream myfile;
	ofstream myfile2;
	char ch;
	myfile.open("data.txt", ios::out | ios::app);
	while (getline(myfile, line)) {
		data.push_back(line);
		i++;
	}

	cout << "please enter a new password :";
	for (i = 0; (ch = _getch()) != '\r';) {
		if (ch != '\b') {
			password5[i] = ch;
			cout << "*";
			i++;
		}
		else {
			i--;
			if (i < 0) {
				i++;
			}
			else {
				cout << "\b \b";
			}
		}
	}
	for (int y = 0; y < i; y++) {
		new_password = new_password + password5[y];
	}
	if (isvalidpassword(new_password)) {
		confirm_new_password(new_password);
		cout << endl;
		len = new_password.length();
		for (int i = 0; i < len; i++) {
			new_password[i] = int(new_password[i]) + 6;
		}
		for (int z = 0; z < data.size(); z++) {

			if (data[z].compare(e) == 0) {
				data[z] = new_password;
			}
		}
		myfile2.open("data.txt", ios::trunc);
		for (int z = 0; z < data.size(); z++) {
			myfile2 << data[z] << endl;
		}

		cout << "you changed your password successfull :) " << endl << endl;
		menue();
	}
	else {
		cout << endl;
		cout << "please enter a valid password!!" << endl;
		change_password(e);
	}

}

void user::confirm_new_password(string e) {
	word2 = "";
	int i;
	char ch;
	cout << endl;
	cout << "please confirm your new password : ";
	for (i = 0; (ch = _getch()) != '\r';) {
		if (ch != '\b') {
			password3[i] = ch;
			cout << "*";
			i++;
		}

		else {
			i--;
			if (i < 0) {
				i++;
			}
			else {
				cout << "\b \b";
			}
		}
	}
	for (int y = 0; y < i; y++) {
		word2 = word2 + password3[y];
	}
	if (e.compare(word2) == 0) {
		cout << endl;
		cout << "Done!!" << endl;

	}
	else {
		word2 = "";
		cout << endl;
		cout << "Please enter the same password!! " << endl;
		confirm_new_password(e);

	}
}

void user::registration() {
	system("cls");
	setemail();
	system("cls");
	setphone();
	system("cls");
	setusername();
	system("cls");
	setpassword();
	save_data(email);
	save_data(phone);
	save_data(username);
	save_data(epassword);

}

void user::login() {
	system("cls");
	loginusername();


}