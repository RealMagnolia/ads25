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

    int getHeight(Node *node) {
        if (node == NULL)
            return 0;
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }

    void calcsum(Node *node, int lvl, int sum[]){
        if(node == NULL){
            return;
        }
        sum[lvl] += node->data;
        calcsum(node->left, lvl+1, sum);
        calcsum(node->right, lvl+1, sum);
    }

    void printArr(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
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

    int height = bst->getHeight(bst->root);
    cout << height << endl;
    int sum[height] = { 0 };
    bst->calcsum(bst->root, 0, sum);
    bst->printArr(sum, height);

    return 0;
}