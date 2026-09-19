/*
	Project Title: Simple Calculator
	Name: Haiden Griffith
	Inputs: (Based on a menu showing 4 options) a choice linked to an operator, first number, second number
	Outputs: Mathematical expression along with result
*/

#include <iostream>
using namespace std;

// Declaration for Function 1: Display menu
void display_menu();

// Declaration for Function 2: Get operator input and validate it
void validate_choice(int &choice);

// Declaration for Function 3: Get number inputs and validate them
void validate_numbers(float &num1, float &num2);

// Declaration for Function 4: Calculate result
void calculate_result(int choice, float num1, float num2);

int main()
{
	cout << "--- Simple Calculator ---";
	char loop_choice = 'y';

	// Step 1: Loop start
	while (loop_choice == 'y' || loop_choice == 'Y')
	{
		int menu_choice;
		float first_number, second_number;

		// Step 2: Display menu function
		display_menu();

		// Step 3: Get operator input from user for choice based on menu options and validate it
		validate_choice(menu_choice);

		// Step 4: Get input from user for first and second number
		validate_numbers(first_number, second_number);

		// Step 5: Calculate and display result
		calculate_result(menu_choice, first_number, second_number);
		// Step 6: Ask user if they would wish to calculate another expression
		cout << "\n\nInput 'Y' to calculate another expression, or any other key to exit: ";
		cin >> loop_choice;
	}
}

// Defintion for Function 1:
void display_menu()
{
	cout << "\n\nOptions:\n\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n";
}

// Definition for Function 2:
void validate_choice(int &choice)
{
	bool valid = false;
	// Starts a loop
	while (valid == false)
	{
		// Asks for user input
		cout << "\nInput choice: ";
		cin >> choice;

		// Validates if input is a valid number
		if (choice == 1 || choice == 2 || choice == 3 || choice == 4)
		{
			valid = true;
		}
		// Makes sure the program doesn't break if the user inputs a non-integer character or a string
		else
		{
			cout << "\nInvalid operator. Please enter a valid input.\n";
			cin.clear();
			cin.ignore(1000,'\n');
		}
	}
}

// Declaration for Function 3:
void validate_numbers(float& num1, float& num2)
{
	bool valid = false;
	// Starts a loop
	while (valid == false)
	{
		// Asks for user input for the first number
		cout << "\nInput first number: ";
		cin >> num1;

		// Validates if the input is a number
		if (cin)
		{
			valid = true;
		}
		// Makes sure the program doesn't break if the user inputs a non-integer character or a string
		else
		{
			cout << "\nInvalid input. Please enter a number.\n";
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}

		// Asks for user input for the second number
		cout << "\nInput second number: ";
		cin >> num2;

		if (cin)
		{
			valid = true;
		}
		// Makes sure the program doesn't break if the user inputs a non-integer character or a string
		else
		{
			cout << "\nInvalid input. Please enter a number.\n";
			cin.clear();
			cin.ignore(1000, '\n');
			valid = false;
		}
	}
}

// Definition for Function 4:
void calculate_result(int choice, float num1, float num2)
{
	float result = 0;
	char num_operator = ' ';
	
	// Checks what the operator is, and uses it within an expression between the first and the second number
	switch (choice)
	{
	case 1:
		result = num1 + num2;
		num_operator = '+';
		break;
	case 2:
		result = num1 - num2;
		num_operator = '-';
		break;
	case 3:
		result = num1 * num2;
		num_operator = '*';
		break;
	case 4:
		result = num1 / num2;
		num_operator = '/';
		break;
	}
	
	// Outputs the expression along with the result
	cout << "\nResult: " << num1 << " " << num_operator << " " << num2 << " = " << result;
}