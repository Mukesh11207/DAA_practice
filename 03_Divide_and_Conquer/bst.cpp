#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;

    Node(int value){
        data = value;
        left = right = NULL;
    }
};

Node* insert(Node* root,int value){
    if(root == NULL){
        return new Node(value);
    }
    if(value < root -> data){
        root -> left = insert(root -> left,value);
    }
    else{
        root -> right = insert(root -> right,value);
    }
    return root;
}

void inorder(Node* root){
    if(root == NULL) return;

    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

void preorder(Node* root){
    if(root == NULL) return;

    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}

void postorder(Node* root){
    if(root == NULL) return;

    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << " ";
}

int main(){
    Node* root = NULL;
    int n,value;

    cout << "Enter number of elements :- ";
    cin >> n;

    cout << "Enter elements:\n";

    for(int i = 0;i < n;i++){
        cin >> value;
        root = insert(root,value);
    }
    cout << "\nInorder traversal :- ";
    inorder(root);

    cout << "\nPreorder traversal :- ";
    preorder(root);

    cout << "\nPostorder traversal :- ";
    postorder(root);

    return 0;
}