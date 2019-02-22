#include <iostream>
using namespace std;

template<typename T>
class LinkedList{
private:
    class Node {
    public:
        int val;
        Node* next;
        Node(int v, Node n) : val(v), next(n){}
    };

    Node* head;
};
