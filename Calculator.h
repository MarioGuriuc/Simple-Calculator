#pragma once
#include <iostream>
#include <string>
#include <array>
#include "Operation.h"
using namespace std;

class Calculator {
public:
	static void start() {
		Calculator().readNumber1();
	}

private:
	//0->Addition, 1->Subtraction, 2->Multiplication, 3->Division, 4->Power, 5->Mod
	array<Operation*, 6> operations;
	string numbersToBeComputed;
	string answer;
	char op;
	double number1;
	double number2;

private:
	Calculator() {
		operations = { new Addition(), new Subtraction(), new Multiplication(),
			new Division(), new Power(), new Mod() };
		numbersToBeComputed = "";
		number1 = 0, 
		number2 = 0, 
		op = ' ';
	}

	void readOperator() {
		cout << '\n' << numbersToBeComputed << '\n';
		cout << "Select one of the following operators [+,-,/,*,^,%] for calculations,\n";
		cout << "[=] for showing the result, or [C] to restart calculations : ";
		cin >> op;
		switch (op) {
		case '=':
			printf("Result: ");
			cout << number1 << "\n";
			printf("Do you want to restart the calculations? [Y/N]: ");
			cin >> answer;
			if (answer == "N" || answer == "n") {
				system("cls");
				exit(0);
			}
			else if (answer == "Y" || answer == "y") {
				system("cls");
				numbersToBeComputed.clear();
				this->readNumber1();
			}
			break;
		case 'C' || 'c':
			this->readNumber1();
			break;
		default:
			if(checkOp())
				this->readNumber2();
			printf("----------------------------------------------------------------------------\n");
			printf("\nInvalid operator, please try again!\n");
			readOperator();
			break;
		}
	}

	bool checkOp() {
		return (op == '+' || op == '-' || op == '*'
			 || op == '/' || op == '^' || op == '%');
	}

	void readNumber1() {
		printf("----------------------------------------------------------------------------\n");
		cout << '\n' << numbersToBeComputed << '\n';
		printf("Write a number: ");
		cin >> number1;
		numbersToBeComputed.push_back(number1 + '0');
		this->readOperator();
	}

	void readNumber2() {
		printf("----------------------------------------------------------------------------\n");
		numbersToBeComputed.push_back(op);
		cout << '\n' << numbersToBeComputed << '\n';
		printf("Write a number: ");
		cin >> number2;
		this->calculate();
		this->readOperator();
	}

	void calculate() {
		switch (op) {
		case '+':
			operations[0]->Compute(number1, number2);
			break;
		case '-':
			operations[1]->Compute(number1, number2);
			break;
		case '*':
			operations[2]->Compute(number1, number2);
			break;
		case '/':
			try {
				if (number2 == 0) throw "Divison by 0 is not allowed.\n";
			}
			catch (const char* exc) {
				cout << exc;
				numbersToBeComputed.clear();
				readNumber1();
			}
			operations[3]->Compute(number1, number2);
			break;
		case '^':
			operations[4]->Compute(number1, number2);
			break;
		case '%':
			operations[5]->Compute(number1, number2);
			break;
		}
		numbersToBeComputed.push_back(number2 + '0');
		printf("----------------------------------------------------------------------------\n");
	}
};