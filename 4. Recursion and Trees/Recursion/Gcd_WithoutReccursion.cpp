
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a,b;
    cout<<"a & b values: ";
    cin>>a>>b;
    cout<<"Gcd of "<<a<<" & "<<b<<" is: "<<gcd(a,b);

    return 0;
}

