#include <iostream>
#include <vector>
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
        if(val <= node->data) node->right = insert(node->right, val);
        else node->left= insert(node->left, val);
        return node;
    }

    void inOrder(Node *node, int &sum){
        if(node == NULL) return;
        inOrder(node->left, sum);
        sum+=node->data;
        cout << sum << " ";
        inOrder(node->right, sum);
    }
};

int main(){
    Bst *bst = new Bst;
    int n; cin >> n;
    vector <int> count(n);

    for(int i = 0 ; i < n ; i++){
        int a; cin >> a;
        if(bst->root == NULL) bst->root = bst->insert(bst->root, a);
        else bst->insert(bst->root, a); 
    }   

    int sum = 0;
    bst->inOrder(bst->root, sum);
    return 0;
}