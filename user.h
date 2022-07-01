#pragma once
#include<iostream>
#include<string>
#include<conio.h>
using namespace std;
class user
{
private:
	string email;
	string phone;
	string username;
	string password;
	string epassword;
public:
	bool isvalidemail(string e);
	bool isvalidphonenum(string e);
	bool isvalidusername(string e);
	bool isvalidpassword(string e);
	void setemail();
	void setphone();
	void setusername(); 
	void setpassword();
	void registration();
	void confirmpassword();
	void previousemail(string e);
	void previouspassword(string e);
	void save_data(string e);
	void encryptpassword(string e);
	void previoususername(string e);
	void previousphone(string e);
	void loginusername();
	void loginpassword(string e);
	void isvalid_new_password();
	void change_password(string e);
	void setpassword_to_login();
	void confirm_new_password(string e);
	void login();
	void menue();
};

