#include<iostream>
using namespace std;

class Node {
    public: 
    int data; 
    Node* left;
    Node* right;

    Node() {
        this->data = -1;
        this->left = nullptr;
        this->right = nullptr;
    }
    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
    Node(int data, Node* left, Node* right) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

Node* createTree () {
    int data;
    cin >> data;

    if(data == -1) {
        return nullptr;
    }

    Node* root = new Node(data);
    root->left = createTree();
    root->right = createTree();

    return root;
}

void pre_order_traversal(Node* root) {
    if(root == nullptr) {
        cout  << "-1 -> ";
        return;
    }

    cout << root->data << " -> ";
    pre_order_traversal(root->left);
    pre_order_traversal(root->right);

    return ;
}

void in_order_traversal(Node* root) {
    if(root == nullptr) {
        cout  << "-1 -> ";
        return;
    }

    in_order_traversal(root->left);
    cout << root->data << " -> ";
    in_order_traversal(root->right);

    return ;
}

void post_order_traversal(Node* root) {
    if(root == nullptr) {
        cout  << "-1 -> ";
        return;
    }

    post_order_traversal(root->left);
    post_order_traversal(root->right);
    cout << root->data << " -> ";

    return ;
}

int main () {
    cout << "Enter tree nodes values : (-1 for null node, creating in dfs order)" << endl;
    Node* root = createTree();

    pre_order_traversal(root);
    cout << endl;
} 