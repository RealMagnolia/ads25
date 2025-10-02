#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

int diametr = 0;
class Bst{
    public:
    Node *root;

    Bst(){
        root = NULL;
    }

    Node *insert(Node *node, int val){
        if(node == NULL){
            node = new Node(val);
            return node;
        }
        if(val <= node->data) node->left = insert(node->left, val);
        else node->right = insert(node->right, val);
        return node;
    }

    int depth(Node *node){
        if(node == NULL) return 0;
        int l = depth(node->left);
        int r = depth(node->right);
        diametr = max(diametr, l+r);
        return 1 + max(l, r);
    }
};

int main(){
    Bst *bst = new Bst;
    int n; cin >> n;
    
    for(int i = 0 ; i < n ; i++){
        int a; cin >> a;
        if(bst->root == NULL) bst->root = bst->insert(bst->root, a);
        else bst->insert(bst->root, a);
    }
    bst->depth(bst->root);
    cout << diametr+1;
    return 0;
}