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

class LL{
  public:
    Node * head;
    int length;

    LL(){
      head = NULL;
      length = 0;
    }

    void insertAtHead(int x){
      Node *temp = new Node;
      temp-> value = x;
      if(head == NULL){
        head = temp;
      }
      else{
        temp -> next = head;
        head = temp;
      }
      length++;
      return;
    }

    void insertAtPosition(int x, int p){
      if (p <= length + 1){
        if (p == 1)
          insertAtHead(x);
        else{
          Node *temp = new Node;
          temp ->value = x;
          Node *trans;
          trans = head;
          for(int i = 1; i < p - 1; i++){
            trans = trans->next;
          }
          temp->next = trans -> next;
          trans ->next = temp;
          length++;
        }
      }
      else
        cout << "Not possible to insert here. sorry"<< endl;
        return;
    }

    void removeFromPosition(int p){
      if(head == NULL){
        cout << "List is empty." << endl;
        return;
      }
      if(p <= length){
        if(p == 1){
          Node *temp;
          temp = head;
          temp = head->next;
          delete temp;
          length--;
        }
        else{
          Node *temp;
          Node *trans;
          temp = trans = head;
          for (int i = 1; i<=p-1; i++){
            temp = trans;
            trans = trans->next;
          }
          temp ->next = trans ->next;
          delete trans;
          length--;
        }
      }
      else{
        cout<< "not possible" << endl;
      }
      return;
    }

    void SearchAndDestroy(int x){
      Node *a;
      Node *b;
      a = b = head;
      if(head->value == x){
        removeFromPosition(1);
        return;
      }
      else{
        while (a != NULL){
          b = a;
          a = a->next;
          if(head->value == x){
            b ->next = a->next;
            delete a;
            length--;
            return;

          }
        }
      }
      cout << "can not find value" << x << endl;
    }

    void displayContents(){
      if (head == NULL) {
        cout << "List is empty!" << endl;
      }
      else {
        Node *temp;
        temp = head;
        cout << "Linked List:"<< endl;
        while (temp != NULL) {
          cout << temp->value << endl;
          temp = temp->next;
        }
      }
      return;
    }
    int getLength(){
      return length;
    }
    void detectAndRemoveLoops(){
      Node *temp;
      temp = head;
      for(int i=0; i<getLength(); i++){
        temp = temp->next;
      }
      if(temp->next !=NULL){
        temp->next = NULL;
      }
    }

};

void mergeLinkedList(Node *firstList, Node *secondList){
  Node *merged;
  Node *curr1 = firstList;
  Node *curr2 = secondList;
  Node *follow1, *follow2;

  while (curr1 != nullptr && curr2 != nullptr) {
    follow1 = curr1->next;
    follow2 = curr2->next;

    curr2->next = follow1;
    curr1->next = follow2;

    curr1 = follow1;
    curr2 = follow2;
  }
  secondList = curr2;
  return;
}


int main() {
  LL list;
  LL mlist; //1-2-4-5
  mlist.insertAtHead(5);
  mlist.insertAtHead(4);
  mlist.insertAtHead(2);
  mlist.insertAtHead(1);
  while (1){
      int choose, value, Position;
      cout << "\nPick a function to run:\n1: Insert At Head\n2: Insert at Postion\n3: Remove at Postion\n4: Search and Delete\n5: Display\n 6: Detect Loops\n 7:merge \n Anything else to exit\n";
      cin >> choose;
      cout << "\n";
      switch (choose){
          case 1:
              cout << "Please Enter a Value" << endl;
              cin >> value;
              list.insertAtHead(value);
              break;
          case 2:
              cout << "Please Enter a Value" << endl;
              cin >> value;
              cout << "Please Enter a Position" << endl;
              cin >> Position;
              list.insertAtPosition(value, Position);
              break;
          case 3:
              cout << "Enter a Position" << endl;
              cin >> Position;
              list.removeFromPosition(Position);
              break;
          case 4:
              cout << "Enter a Value" << endl;
              cin >> value;
              list.SearchAndDestroy(value);
              break;
          case 5:
              list.displayContents();
              break;
          case 6:
              list.detectAndRemoveLoops();
              cout << "loops are gone" << endl;
              break;
          case 7:
            cout << "merging your lsit with 1-2-4-5" << '\n';
              mergeLinkedList(mlist.head, list.head);
              break;
          default: cout << "Have a good day" << '\n';
              return 1;
      }
  }

  return 0;
}
