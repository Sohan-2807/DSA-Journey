#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    if (n < 0) {
        cout << "Please enter a non-negative number.\n";
        return 1;
    }

    cout << "Fibonacci number at position " << n
         << " is: " << fibonacci(n) << '\n';
}