/*

FCAI – Programming 1 – 2022 - Assignment 2
Program Name: Rational Number Calculator

Program Description: 
    this is Rational Number Calculator takes 2 Rational number and (_, +, /, *) between them
    and count the result of them and print the result as a Rational number.

Last Modification Date: 3 / 25 / 2022

Author1 and ID and Group: Abdelrhman Mostafa Hessain _ 20210210 _ S10
Author2 and ID and Group: Youssef mohamed atya _ 20210484 _ S10
Author3 and ID and Group: Marwan Tarik Madbouly _ 20210379 _ S9

Teaching Assistant: Eng.TA. Afaf

Purpose:
Enter the firstnum and the operator and the secondnum in the same input separated with space.
Check for validation for each one of them if valid next else return to the main function to start over.
Take the firstnum to his function to separate the first numerator and the first denominator and return them.
Take the secondnum to his function to separate the second numerator and the second denominator and return them.
switch on the operator and make the equation of each operator and get the greatest common divisor.
To print the simplification of the result.

*/




#include <iostream>
#include <string>
#include <regex>

int num1, num2, deno1, deno2;
int first(std::string firstNum);
int sec(std::string secNum);
int gcd(int x, int y);
bool valid(std::string text);

int main() {

    std::string  firstNum, secNum;
    char op;
    long double equation;
    long long num_op, den_op, simple;

    std::cout << "Please enter a rational number operations: ";
    std::cin >> firstNum >> op >> secNum;

    first(firstNum);
    sec(secNum);

    // Switches from possible operations
    if (valid(firstNum) && valid(secNum)) {

        switch (op)
        {
            // Plural formula operation
        case '+':
            num_op = ((num1 * deno2) + (num2 * deno1));
            den_op = (deno1 * deno2);
            simple = gcd(num_op, den_op);
            std::cout << num_op / simple << "/" << den_op / simple;
            break;

            // Proposal formula operation
        case '-':
            num_op = (num1 * deno2) - (num2 * deno1);
            den_op = (deno1 * deno2);
            simple = gcd(num_op, den_op);
            std::cout << num_op / simple << "/" << den_op / simple;
            break;

            // Multiply formula operation
        case '*':
            num_op = (num1 * num2);
            den_op = (deno1 * deno2);
            simple = gcd(num_op, den_op);
            std::cout << num_op / simple << "/" << den_op / simple;
            break;

            // Divide formula operation
        case '/':
            num_op = (num1 * deno2);
            den_op = (num2 * deno1);
            simple = gcd(num_op, den_op);
            std::cout << num_op / simple << "/" << den_op / simple;
            break;

        default:
            break;
        }
        std::cout << "\nThank you for using rational number calculator.";
    }
}


// Convert denominator and numerator of the first term from string to integer
int first(std::string firstNum) {

    std::string numrator, den;
    long int first;

    if (valid(firstNum)) {

        if (firstNum.find('/') < firstNum.size() && firstNum.find('/') > 0) {
            numrator = firstNum.substr(0, firstNum.find('/'));
            den = firstNum.substr(firstNum.find('/') + 1, firstNum.size() - 1);
            num1 = stoi(numrator);
            deno1 = stoi(den);
        }

        else {
            num1 = stoi(firstNum);
            deno1 = 1;
        }

        first = stoi(firstNum);
        return first;
    }

    else {
        std::cout << "invalid input please enter a rational number.\n";
        return main();
    }
}


// Convert denominator and numerator of the second term from string to integer
int sec(std::string secNum) {
    std::string numrator, den;
    long int sec;
    if (valid(secNum)) {

        if (secNum.find('/') < secNum.size() && secNum.find('/') > 0) {
            numrator = secNum.substr(0, secNum.find('/'));
            den = secNum.substr(secNum.find('/') + 1, secNum.size() - 1);
            num2 = stoi(numrator);
            deno2 = stoi(den);

        }

        else {
            num2 = stoi(secNum);
            deno2 = 1;
        }
        sec = stoi(secNum);
        return sec;
    }

    else {
        std::cout << "invalid input please enter a rational number.\n";
        return main();
    }
}

// Simplification denominator and numerator with gcd function
int gcd(int num1, int num2) {

    if (num2 == 0) {
        return num1;
    }
    return gcd(num2, num1 % num2);
}

// Validation Function
bool valid(std::string text) {

    std::regex rationalValid("[-+]?[0-9]+(/[1-9][0-9]*)?");
    return regex_match(text, rationalValid);

}