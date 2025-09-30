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
    int sz;

    Bst(){
        root = NULL;
        sz = 0;
    }

    Node *insert(Node *node , int val){
        if(node == NULL){
            node = new Node(val);
            return node;
        }
        if(val <= node->data) node->left = insert(node->left, val);
        else node->right = insert(node->right, val);
        return node;
        sz++;
    }

    int triCnt(Node *cur){
        int cnt = 0;
        if(cur == NULL) return 0;
        if(cur->left != NULL && cur->right != NULL) cnt++;
        cnt += triCnt(cur->left);
        cnt += triCnt(cur->right);
        return cnt; 
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
    cout << bst->triCnt(bst->root);
    return 0;
}