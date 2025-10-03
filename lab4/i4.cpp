#include <iostream>
using namespace std;

struct Node {
    int data;
    int cnt;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
        this->cnt = 1;
    } 
};

Node* getMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return new Node(data);
    }
    if (root->data == data) {
        root->cnt++;
        return root;
    }
    if (root->data > data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

Node* deleteNode(Node* root, int data) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data > data) {
        root->left = deleteNode(root->left, data);
        return root;
    }
    if (root->data < data) {
        root->right = deleteNode(root->right, data);
        return root;
    }
    if (root->cnt > 1) {
        root->cnt--;
        return root;
    }
    if (root->left == NULL && root->right == NULL) {
        delete root;
        return NULL;
    }
    if (root->right == NULL) {
        Node* temp = root->left;
        delete root;
        return temp;
    }
    if (root->left == NULL) {
        Node* temp = root->right;
        delete root;
        return temp;
    }
    Node* temp = getMin(root->right);
    root->data = temp->data;
    root->cnt = temp->cnt;
    root->right = deleteNode(root->right, temp->data);
    return root;
}

int cnt(Node* root, int x) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == x) {
        return root->cnt;
    }
    if (root->data > x) {
        return cnt(root->left, x);
    }
    return cnt(root->right, x);
}

int main() {
    int n;
    cin >> n;
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        string query;
        int data;
        cin >> query >> data;
        if (query == "insert") {
            root = insert(root, data);
        } else if (query == "cnt") {
            cout << cnt(root, data) << endl;
        } else if (query == "delete") {
            root = deleteNode(root, data);
        }
    }
    return 0;
}
