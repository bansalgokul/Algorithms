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

void bfs_level_traversal(Node* root) {
    if(root == nullptr) {
        return;
    }

    queue<Node* > q;
    q.push(root);

    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << curr->data << " -> ";
        if(curr->left ) {
            q.push(curr->left);
        }
        if(curr->right) {
            q.push(curr->right);
        }
    }
    return;
}

int main () {
    cout << "Enter tree nodes values : (-1 for null node, creating in dfs order)" << endl;
    Node* root = createTree();

    bfs_level_traversal(root);
    cout << endl;
} 