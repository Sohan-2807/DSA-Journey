#include<iostream>
using namespace std;

int main(){
    int n,p;
    int fact = 1;
    cout<<"Enter value of n:";
    cin>>n;
    p = n;
    while(n>0){
        fact*=n;
        n--;
    }
    cout<<"Factorial of "<< p <<" is: "<<fact;
    return 0;
}