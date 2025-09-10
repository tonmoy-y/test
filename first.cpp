#include <iostream>
#include <limits>
using namespace std;

bool isPrime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main(int argc, char** argv) {
    long long num;
    if (argc >= 2) {
        try {
            num = stoll(argv[1]);
        } catch (...) {
            cout << "Invalid number.\n";
            return 1;
        }
    } else {
        cout << "Enter a number: ";
        while (!(cin >> num)) {
            cout << "Please enter a valid integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    if (isPrime(num))
        cout << num << " is a prime number.\n";
    else
        cout << num << " is not a prime number.\n";

    return 0;
}