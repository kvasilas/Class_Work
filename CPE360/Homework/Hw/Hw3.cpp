#include <iostream>
#include <string>
using namespace std;

class  asses{
  void deleteBst(int value){
    treenode *chase = *follow;
    if (root == nullptr){
      cout <<"tree is empty" << '\n';
    }
    else{
      while (chase->value != value || chase!=nullptr) {
        if(chase-> value < value){
          follow=chase;
          chase = chase->right;
        }
        else{
          follow = chase;
          chase = chase->left;
        }
      }
    }


  }
};
