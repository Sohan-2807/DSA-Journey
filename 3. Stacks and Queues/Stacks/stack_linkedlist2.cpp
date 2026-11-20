#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

class StackLinkedList{
    Node* top;
    public:
    StackLinkedList(){
        top = nullptr;
    }

    void push(int x){
        Node*newNode = new Node(x);
        newNode->next = top;
        top = newNode;
    }

    int pop(){
        if(top==nullptr){
            cout<<"Empty or underflow";
        }
        else{
        Node*temp = top;
        int popped = temp->data;
        top = top->next;
        delete temp;
        return popped;
        }
    }

    int peek(){
        if(top==nullptr){
            cout<<"Empty or underflow";
        }
        else{
            
            return top->data;
        }
    }
    void display(){
        if(top==nullptr){
            cout<<"Empty";
        }
        else{
            Node*temp = top;
            while(temp!= NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
        }
    }


};
int main() {
    StackLinkedList s;
    s.push(5);
    s.push(15);
    s.push(25);

    cout << "Stack (linked list representation): ";
    s.display();

    cout << "Peek top: " << s.peek() << endl;

    cout << "Popped: " << s.pop() << endl;
    cout << "Stack after pop: ";
    s.display();

    return 0;
}
