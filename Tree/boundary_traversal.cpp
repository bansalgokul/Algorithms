#include<iostream>
#include<queue>
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

void left_boundary_traversal(Node* root){
    if(root == nullptr || (root->left == nullptr && root->right == nullptr)) {
        return;
    }

    if(root->left) {
        cout << root->data << " -> ";
        left_boundary_traversal(root->left);
    }else {
        cout << root->data << " -> ";
        left_boundary_traversal(root->right);
    }

    return;
}

void right_boundary_traversal(Node* root) {
     if(root == nullptr || (root->left == nullptr && root->right == nullptr)) {
        return;
    }

    if(root->right) {
        cout << root->data << " -> ";
        right_boundary_traversal(root->right);
    }else {
        right_boundary_traversal(root->left);
        cout << root->data << " -> ";
    }

    return;
}

void leaves_traversal(Node* root) {
    if(root == nullptr) {
        return;
    }

    if(root->left == nullptr && root->right == nullptr){
        cout << root->data << " -> ";
        return;
    }

    leaves_traversal(root->left);
    leaves_traversal(root->right);

    return;
}

void boundary_traversal(Node* root){
    if(root == nullptr) {
        return ;
    }

    cout << root->data << " -> ";

    left_boundary_traversal(root->left);
    leaves_traversal(root);
    right_boundary_traversal(root->right);

    return;
}   


int main () {
    cout << "Enter tree nodes values : (-1 for null node, creating in dfs order)" << endl;
    Node* root = createTree();

    boundary_traversal(root);
    cout << endl;
} 