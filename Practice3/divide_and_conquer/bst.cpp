#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node*left,*right;

    Node(int val){//constructor
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root,int data){
    if(root == NULL){
        return new Node(data);
    }
    if(data < root -> data){
        root -> left  = insert(root -> left,data);//root -> left assignment
    }
    else{
        root -> right = insert(root -> right,data);
    }
    return root;
}

void inorder(Node* root){
    if(root == NULL)
        return;

    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

void preorder(Node* root){
    if(root == NULL)
        return;

    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}

void postorder(Node* root){
    if(root == NULL){
        return;
    }
    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << " ";
}

int main(){
    int N;
    cout << "Enter number of entries into tree :- ";
    cin >> N;

    Node* root = NULL;//assign to NULL
    cout << "Enter entries into tree :- ";
    for(int i = 0;i < N;i++){
        int value;
        cin >> value;
        root = insert(root,value);
    }
    cout << "\nInorder Traversal :- \n";
    inorder(root);
    cout << "\nPreorder traversal :- \n";
    preorder(root);
    cout << "\nPostorder traversal :- \n";
    postorder(root);

    return 0;
}