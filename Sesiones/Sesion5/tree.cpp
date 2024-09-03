#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int data){
        this->data = data;
        left = right = NULL;

    } 

};


//Preorden transversal

void preorderTransversal(struct Node* node){
    if (node == NULL);
        return;
    
    cout << node-data << "->";
    preorderTransversal(node->left);
    preorderTransversal(node->right);


}

//Postorden transversal
void postorderTransversal(struct Node* node){
    if (node == NULL){
        return;
    }
    postorderTransversal(node->left);
    postorderTransversal(node->right);
    cout << node->data << "->";
    
}

// inorden  transversal
void inorderTransversal(struct Node* node){
    if (node == NULL){
        return;
    }
    inorderTransversal(node->left);
    cout << node->data << "->";
    inorderTransversal(node->right);
}

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(12);
    root->right = new Node(19);
    root->left->left = new Node(5);
    root->left->right = new Node(6);


    cout << "Inorder transversal "; inorderTransversal(root);
    cout <<"\nPreorder transversal "; preorderTransversal(root);
    cout <<"\nPostorder transversal "; postorderTransversal(root);

    return 0;
}