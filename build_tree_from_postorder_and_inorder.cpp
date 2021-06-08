#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int search(int inorder[], int start, int end, int current) {
    for(int i=start; i<=end; i++) {
        if(inorder[i] == current) {
            return i;
        }
    }
    return -1;
}

Node* buildTree(int postorder[], int inorder[], int start,  int end) {
    static int idx = end;

    if(start > end) {
        return NULL;
    }

    int current = postorder[idx];
    idx--;
    Node* node = new Node(current);

    if(start == end) {
        return node;
    }

    int pos = search(inorder, start, end, current);
    node->right = buildTree(postorder, inorder, pos+1, end);
    node->left = buildTree(postorder, inorder, start, pos-1);

    return node;
}
void inorderPrint(Node* root) {

    if(root == NULL) {
        return;
    }
    
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

int main() {

    int postorder[] = {4, 2, 5, 3, 1};
    int inorder[] = {4, 2, 1, 5, 3};

    Node* root =  buildTree(postorder, inorder, 0, 4);
    inorderPrint(root);

    return 0;
}