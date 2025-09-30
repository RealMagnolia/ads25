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

    Node *find(Node *node, int val){
        if(node == NULL) return NULL;
        if(node->data == val) return node;
        if(node->data > val) return find(node->left, val);
        else return find(node->right, val);
    }

    void preorder(Node* node){
        if(node == NULL) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
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
    int t; cin >> t;
    Node *tar = bst->find(bst->root, t);
    if(tar != NULL) bst->preorder(tar);
    return 0;
}