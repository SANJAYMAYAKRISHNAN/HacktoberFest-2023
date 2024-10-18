#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// Function to convert a number to the desired base
string convertToBase(int num, int base) {
    string result = "";
    while (num > 0) {
        result = to_string(num % base) + result;
        num /= base;
    }
    return result.empty() ? "0" : result;
}

// Function to check if a number is a Kaprekar number in the given base
bool isKaprekar(int num, int base) {
    if (num == 0) return false; // 0 is not considered a Kaprekar number

    // Calculate the square of the number
    int square = num * num;
    
    // Convert the square to the desired base
    string squareStr = convertToBase(square, base);
    
    // Split the square into two parts
    int len = squareStr.length();
    for (int i = 1; i < len; ++i) {
        // First part (left) and second part (right)
        int left = stoi(squareStr.substr(0, i), nullptr, base);
        int right = stoi(squareStr.substr(i), nullptr, base);

        // Check if the sum equals the original number
        if (left + right == num) {
            return true;
        }
    }
    
    return false;
}

int main() {
    int number, base;

    // Input the number and base
    cout << "Enter a number: ";
    cin >> number;
    cout << "Enter the base: ";
    cin >> base;

    // Check if the number is a Kaprekar number
    if (isKaprekar(number, base)) {
        cout << number << " is a Kaprekar number in base " << base << endl;
    } else {
        cout << number << " is NOT a Kaprekar number in base " << base << endl;
    }

    return 0;
}
