// copyright Maximiliano Fairman Dec 12th, 2025
// all rights reserved
// this asks for 3 parameters : an operation sign
// and two decimal numbers.
// It performs the operation on the two numbers.

#include <iostream>
#include <stdexcept>  // needed for std::runtime_error

float calculate(char sign, float firstNumber, float secondNumber) {
    switch (sign) {
        case '+':
            return firstNumber + secondNumber;
        case '-':
            return firstNumber - secondNumber;
        case '*':
            return firstNumber * secondNumber;
        case '/':
            if (secondNumber == 0) {
                throw std::runtime_error("Cannot divide by zero.");
            }
            return firstNumber / secondNumber;
        default:
            throw std::runtime_error("Invalid operation sign.");
    }
}

int main() {
    char sign;
    float firstNumber, secondNumber;

    std::cout << "=== Calculator ===" << std::endl;

    // Validate sign
    while (true) {
        std::cout << "Enter operation (+, -, *, /): ";
        std::cin >> sign;

        if (sign == '+' || sign == '-' || sign == '*' || sign == '/')
            break;

        std::cout << "Invalid operation. Try again.\n";
    }

    // Validate first number
    while (true) {
        std::cout << "Enter first number: ";
        std::cin >> firstNumber;

        if (!std::cin.fail()) break;

        std::cout << "Invalid input. Enter a decimal.\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    // Validate second number
    while (true) {
        std::cout << "Enter second number: ";
        std::cin >> secondNumber;

        if (!std::cin.fail()) break;

        std::cout << "Invalid input. Enter a decimal.\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    try {
        float result = calculate(sign, firstNumber, secondNumber);
        std::cout << "Result: " << result << std::endl;
    } catch (std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
