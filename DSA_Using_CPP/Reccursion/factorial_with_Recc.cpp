#include<iostream>
using namespace std;

int Factorial(int n){
    if(n<=1) return 1;
    return n*Factorial(n-1);
}

int main(){
    int n;
    cout<<"Enter value of n: ";
    cin>>n;
    cout<<"factorial of n is: "<<Factorial(n);
}