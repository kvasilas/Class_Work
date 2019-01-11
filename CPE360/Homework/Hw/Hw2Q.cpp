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

class Queue{
  public:
    Node *head;
    Node *tail;

    queue(){
      head = tail = NULL;
    }

    void enqueue(int x){
      if (head == NULL && tail == NULL){
        tail = head = new Node;
        head->value = x;
      }
      else{
        Node *temp = new Node;
        temp->value = x;
        temp->next = tail;
        tail = temp;
      }
      return;
    }

    void dequeue(){
      if(head == NULL && tail == NULL){
        cout << "Empty Queue" << endl;
      }
      else{
        Node *follow;
        Node *behind;
        while(behind->next != NULL){
          follow = behind;
          behind = behind->next;
        }
        follow->next = NULL;
        delete behind;
      }
      return;
    }

    void printContents(){
      Node *temp;
      temp = tail;
      cout << "Queue: " << endl;
      while(temp!= NULL){
        cout << temp->value << endl;
        temp = temp->next;
      }

    }
};

int main() {
  Queue myQueue;
  while (1){
    int choose, value;
    cout << "What do you want to do? \n 1. Enqueue \n 2. Dequeue \n 3. Print \n anything else your heart desires to exit" << endl;
    cin >> choose;
    cout << '\n';
    switch(choose){
      case 1:
        cout << "Please Enter a Value\n";
        cin >> value;
        myQueue.enqueue(value);
        break;
      case 2:
        myQueue.dequeue();
        break;
      case 3:
        myQueue.printContents();
        break;
      default: cout << "Adios Amigo\n";
        return 1;
    }
  }

  return 0;
}
