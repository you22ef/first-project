#include <fstream>
#include<iostream>
#include <string>
#include<conio.h>
using namespace std;
ifstream myfile;
string file_name;

void creat_file() {


    cout << "please enter the name of the file : ";
    cin >> file_name;

    myfile.open(file_name + ".txt");
    if (myfile) {
        cout << endl;
        cout << "This File Already Exists" << endl;
        cout << endl;
    }
    else {
        cout << "This is a new file. I created it for you " << endl;
        myfile.open(file_name + ".txt", ios::out | ios::app);

    }

}

void Add_new_text() {
    char text[1000];
    int i;
    char ch;
    ofstream myfile;
    myfile.open(file_name + ".txt", ios::out | ios::app);
    system("cls");
    cout << "please enter the text that you want to add : ";
    cin.ignore();
    for (i = 0; (ch = _getche()) != '\r';) {

        if (ch != '\b') {
            text[i] = ch;
            i++;
        }

        else {
            i--;

            if (i < 0) {
                i++;
            }
            else {
                cout << " \b";
            }
        }
        if (ch == 26) {
            system("cls");
            return;
        }
    }
    text[i] = '\0';
    myfile << text;
    cout << endl;
    cout << "Done!!";
    cout << endl << endl;
    myfile.close();

}
void display() {
    char text_file;
    ifstream myfile;
    myfile.open(file_name + ".txt", ios::out | ios::app);
    system("cls");
    while (!myfile.eof()) {
        myfile.get(text_file);
        cout << text_file;
    }
    cout << endl << endl;

}
void delete_text() {
    char text_file;
    fstream myfile;
    myfile.open(file_name + ".txt", ios::trunc);
    system("cls");

}

void cipher() {
    char text_file;
    string text_file2;
    text_file2 = "";
    ifstream myfile;
    ofstream myfile2;
    myfile.open(file_name + ".txt", ios::out | ios::app);
    system("cls");
    while (!myfile.eof()) {
        myfile.get(text_file);
        text_file2 = text_file2 + char(text_file + 6);
    }
    myfile2.open(file_name + ".txt", ios::trunc);
    myfile2 << text_file2;
    cout << "Done!!" << endl;
    cout << endl << endl;



}
void decipher() {
    char text_file;
    string text_file2;
    text_file2 = "";
    ifstream myfile;
    ofstream myfile2;
    myfile.open(file_name + ".txt", ios::out | ios::app);
    system("cls");
    while (!myfile.eof()) {
        myfile.get(text_file);
        text_file2 = text_file2 + char(text_file - 6);
    }
    myfile2.open(file_name + ".txt", ios::trunc);
    myfile2 << text_file2;
    cout << "Done!!" << endl;
    cout << endl << endl;



}

void merge() {
    char text_file;
    char text_file3;
    string text_file2;
    string file_name2;
    string file_name3;
    text_file2 = "";
    ifstream myfile;
    ifstream myfile2;
    ofstream myfile3;
    system("cls");
    cout << "please enter the name of other file : ";
    cin >> file_name2;
    myfile.open(file_name + ".txt", ios::out | ios::app);
    myfile2.open(file_name2 + ".txt", ios::out | ios::app);
    while (!myfile.eof()) {
        myfile.get(text_file);
        text_file2 = text_file2 + char(text_file);
    }
    text_file2.pop_back();
    while (!myfile2.eof()) {
        myfile2.get(text_file3);
        text_file2 = text_file2 + char(text_file3);
    }
    text_file2.pop_back();
    cout << "please enter the name of the new file : ";
    cin.ignore();
    getline(cin, file_name3);
    myfile3.open(file_name3 + ".txt", ios::out | ios::app);
    myfile3 << text_file2;
    cout << endl << endl;



}

void count_words() {
    char text_file;
    int counter;
    counter = 0;
    ifstream myfile;
    myfile.open(file_name + ".txt", ios::out | ios::app);
    system("cls");
    while (!myfile.eof()) {
        myfile.get(text_file);
        if (text_file == 32) {
            counter++;
        }
    }
    cout << "the number of words is : " << counter + 1;
    cout << endl << endl;

}

void count_char() {
    char text_file;
    int counter;
    counter = 0;
    ifstream myfile;
    myfile.open(file_name + ".txt", ios::out | ios::app);
    system("cls");
    while (!myfile.eof()) {
        myfile.get(text_file);
        if (text_file != 32) {
            counter++;
        }
    }
    cout << "the number of characters is : " << counter - 1;
    cout << endl << endl;

}

void count_lines() {
    char text_file;
    int counter;
    counter = 0;
    ifstream myfile;
    myfile.open(file_name + ".txt", ios::out | ios::app);
    system("cls");
    while (!myfile.eof()) {
        myfile.get(text_file);
        if (text_file == '\n') {
            counter++;
        }
    }
    cout << "the number of lines is : " << counter + 1;
    cout << endl << endl;

}

void find_word() {
    char text_file;
    char text_file3;
    string text_file2;
    string word;
    int counter = 0;
    int counter2 = 0;
    ifstream myfile;
    ifstream myfile2;
    myfile.open(file_name + ".txt", ios::out | ios::app);
    system("cls");
    cout << "please enter the word : ";
    cin >> word;
    while (!myfile.eof()) {
        myfile.get(text_file3);
        counter++;
    }
    myfile2.open(file_name + ".txt", ios::out | ios::app);
    while (!myfile2.eof()) {
        myfile2.get(text_file);
        if (text_file != 32) {
            text_file2 = text_file2 + char(text_file);
        }
        if (text_file == 32) {
            text_file2 = "";
        }
        if (text_file2 == word) {
            cout << "Word was found in the file" << endl << endl;
            break;
        }

        if (counter2 == counter - 1) {
            cout << "Word was not found in the file" << endl << endl;
            break;
        }

        counter2++;
    }


}
void word_times() {
    char text_file;
    char text_file3;
    string text_file2;
    string word;
    int counter = 0;
    int counter2 = 0;
    ifstream myfile;
    ifstream myfile2;
    myfile.open(file_name + ".txt", ios::out | ios::app);
    system("cls");
    cout << "please enter the word : ";
    cin >> word;
    while (!myfile.eof()) {
        myfile.get(text_file3);
        counter++;
    }
    myfile2.open(file_name + ".txt", ios::out | ios::app);
    while (!myfile2.eof()) {
        myfile2.get(text_file);
        if (text_file != 32) {
            text_file2 = text_file2 + char(text_file);
        }
        if (text_file == 32) {
            text_file2 = "";
        }
        if (text_file2 == word) {
            counter2++;
        }
    }

    cout << "the number of times a word is : " << counter2 << endl << endl;
}

void upper_case() {
    char text_file;
    string text_file2;
    text_file2 = "";
    ifstream myfile;
    ofstream myfile2;
    myfile.open(file_name + ".txt", ios::out | ios::app);
    system("cls");
    while (!myfile.eof()) {
        myfile.get(text_file);
        text_file2 = text_file2 + char(toupper(text_file));
    }
    myfile2.open(file_name + ".txt", ios::trunc);
    myfile2 << text_file2;
    cout << "Done!!" << endl;
    cout << endl << endl;

}
void lower_case() {
    char text_file;
    string text_file2;
    text_file2 = "";
    ifstream myfile;
    ofstream myfile2;
    myfile.open(file_name + ".txt", ios::out | ios::app);
    system("cls");
    while (!myfile.eof()) {
        myfile.get(text_file);
        text_file2 = text_file2 + char(tolower(text_file));
    }
    myfile2.open(file_name + ".txt", ios::trunc);
    myfile2 << text_file2;
    cout << "Done!!" << endl;
    cout << endl << endl;

}

void first_char_capital() {
    char text_file;
    string text_file2;
    int counter;
    int counter2;
    counter = 0;
    counter2 = 0;
    text_file2 = "";
    ifstream myfile;
    ofstream myfile2;
    myfile.open(file_name + ".txt", ios::out | ios::app);
    system("cls");
    while (!myfile.eof()) {
        myfile.get(text_file);
        if (counter == 0 || counter2 == counter) {
            text_file2 = text_file2 + char(toupper(text_file));
            counter++;
            continue;
        }

        if (text_file == 32) {
            text_file2 = text_file2 + char(text_file);
            counter2 = counter;
            continue;
        }
        text_file2 = text_file2 + char(text_file);
    }
    myfile2.open(file_name + ".txt", ios::trunc);
    myfile2 << text_file2;
    cout << "Done!!" << endl;
    cout << endl << endl;

}
void save() {
    string new_name;
    char content;
    string content2;
    ifstream myfile;
    ofstream myfile2;
    myfile.open(file_name + ".txt", ios::out | ios::app);
    system("cls");
    cout << "please enter the new name of the file : ";
    cin.ignore();
    getline(cin, new_name);
    while (!myfile.eof()) {
        myfile.get(content);
        content2 = content2 + char(content);
    }
    myfile2.open(new_name + ".txt", ios::out | ios::app);
    myfile2 << content2;
    cout << "Done!!" << endl;
    cout << endl << endl;


}

int main() {
    creat_file();
    while (true) {

        int choice;

        cout << "1- Add new text to the end of the file \n2- Display the content of the file\n3- Empty the file\n4- Encrypt the file content\n5- Decrypt the file content\n6- Merge another file\n7- Count the number of words in the file\n8- Count the number of characters in the file\n9- Count the number of lines in the file\n10- Search for a word in the file\n11- Count the number of times a word exists in the file\n12- Turn the file content to upper case\n13- Turn the file content to lower case\n14- Turn file content to 1st caps (1st char of each word is capital)\n15- Save\n16- Exit " << endl;
        cout << endl;
        cout << "what do you want to do today (1-16) : ";
        if (!cin) {
            // unset failbit
            cin.clear();
            // clear the buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin >> choice;
        if (choice == 1) {
            Add_new_text();
        }
        if (choice == 2) {
            display();
        }
        if (choice == 3) {
            delete_text();
        }
        if (choice == 4) {
            cipher();
        }
        if (choice == 5) {
            decipher();
        }
        if (choice == 6) {
            merge();
        }
        if (choice == 7) {
            count_words();
        }
        if (choice == 8) {
            count_char();
        }
        if (choice == 9) {
            count_lines();
        }
        if (choice == 10) {
            find_word();
        }
        if (choice == 11) {
            word_times();
        }
        if (choice == 12) {
            upper_case();
        }
        if (choice == 13) {
            lower_case();
        }
        if (choice == 14) {
            first_char_capital();
        }
        if (choice == 15) {
            save();
        }
        if (choice == 16) {
            exit(0);
        }
        else {
            continue;
        }



    }
}