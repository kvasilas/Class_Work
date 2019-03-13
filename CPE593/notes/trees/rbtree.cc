class RBTree{
private:
    class Node{
    public:
        int val;
        Node* left;
        Node* right;
        Node* parent;
        Node(int v, Node* L, Node* R, Node* P) : val(v), left(L), right(R), parent(P){}
    };
    Node* root;
public:
    RBTree() : root(nullptr) {}

    void add(int v){
        Node* p = root;
        if(p ==  nullptr)
            p = new Node(v, nullptr, nullptr, nullptr);
        else{
            do {
                /* code */
            } while(/* condition */);
        }
    }

    void insert_fixupTree(Node* n){
        if(parent(n) == nullptr){
            n -> color = BLACK;
        }
        else if(parent(n)-> color == BLACK){
            return;
        }
        else if(uncle(n) != nullptr && uncle(n)->color == RED){
            
        }
        else{

        }
    }

};
