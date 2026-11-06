#include<iostream>
using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int main(){
    int a,b;
    cout<<"a & b values: ";
    cin>>a>>b;
    cout<<"Gcd of "<<a<<" & "<<b<<" is: "<<gcd(a,b);
    return 0;
}