// Practice.....

#include<iostream>
using namespace std;

#define MAX 100

class Stack{
    public:
    int top;
    int arr[MAX];
    

Stack(){
    top = -1;
}

bool push(int val){
    if(top>=MAX-1){
        cout<<"Stack overflow";
        return false;
    }
    else{
        arr[++top] = val;
        return true;
    }
}
int pop(){
    if(top<0){
        cout<<"Stack underflow";
        return -1;
    }
    else{
        return arr[top--];
    }
}

int peek(){
    if(top<0){
        cout<<"Stack empty";
        return -1;
    }
    else{
        return arr[top] ;
    }
}

void display(){
    if(top<0){
        cout<<"Stack empty";
        return ;
    }
    else{
        for(int i = top;i>=0;i--){
            cout<<arr[i]<<"-";
        }
    }
}

};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Stack elements (top to bottom): ";
    s.display();

    cout << "Top element is: " << s.peek() << endl;

    cout << "Popped element: " << s.pop() << endl;
    cout << "Stack after pop: ";
    s.display();

    return 0;
}

