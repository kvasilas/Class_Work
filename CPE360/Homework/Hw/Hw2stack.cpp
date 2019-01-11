//Kirk Vasilas
#include <iostream>
#include <string>
using namespace std;


class Node{
  public:
    int value;
    Node *next;

    Node(){
      value = 0;
      next = NULL;
    }
};

class stack{
  public:
    Node *top;

    stack(){
      top = NULL;
    }

    void push(int x) {
      Node *temp = new Node;
      temp->value = x;
      if(top == NULL)
        top = temp;
      else
        temp->next = top;
        top = temp;
    }

    void pop() {
      if (top == NULL)
          cout << "Stack is empty\n";
      else{
          Node *temp;
          temp = top;
          top = top->next;
          delete temp;
      }
      return;
    }

    void displayContents() {
      if (top == NULL) {
        cout << "stack is empty" << endl;
      }
      else{
        Node *temp;
        temp = top;
        cout << "stack: " << endl;
        while(temp!= NULL){
          cout << temp->value<< endl;
          temp = temp->next;
        }
      }
    }
};

int main() {
  stack myStack;
  while (1){
      int choose, value;
      cout << "What do you want to do? \n 1. Push \n 2. Pop \n 3. Print \n anything else your heart desires to exit" << endl;
      cin >> choose;
      cout << "\n";
      switch (choose){
          case 1:
              cout << "Enter a Value\n";
              cin >> value;
              myStack.push(value);
              break;
          case 2:
              myStack.pop();
              break;
          case 3:
              myStack.displayContents();
              break;
          default: cout << "Live long and prosper" << endl;
              return 1;
      }
  }
  return 0;
}
