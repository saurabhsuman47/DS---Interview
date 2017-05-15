//Construct Tree from given Inorder and Preorder traversals//

/* INPUT (just paste this in stdin console) - (1st line test case, for each test case number of nodes, inorder traversal and preorder traversal)
1
6
4 2 5 1 3 6
1 2 4 5 3 6
*/

#include <bits/stdc++.h>
using namespace std;

//struct node - A binary tree node has data, pointer to left child and a pointer to right child//
struct Node{
    int data;
    Node *left;
    Node *right;
};

//finds the index of an element from an array, also given the start and end indexes to search between//
int find(int x, int arr[], int start, int end){
    for(int i = start; i <= end; i++){
        if(arr[i] == x)return i;
    }
    return 0;
}

//buildTree - builds the tree O(n^2) time complexity//
Node* buildTree(int in[], int pre[], int n, int &idx, int inStart, int inEnd){
    if(idx >=n || inStart > inEnd)return NULL;
    Node *root = new Node();
    root -> data = pre[idx];
    idx++;
    int i = find(root->data, in, inStart, inEnd);
    root -> left = buildTree(in, pre, n, idx, inStart, i - 1);
    root -> right = buildTree(in, pre, n, idx, i + 1, inEnd);
    return root;
}

//calls buildTree and passes parameters//
Node* callBuildTree(int in[], int pre[], int n){
    int idx = 0;
    Node *root = buildTree(in, pre, n, idx, 0 , n-1);
    return root;
}

//prints post order traversal//
void printPostOrder(Node *root){
    if(!root)return;
    printPostOrder(root -> left);
    printPostOrder(root -> right);
    cout<<root -> data<<" ";
}

//takes input, calls function for constructing the tree then printing post order traversal//
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int in[n];    
        int pre[n];
        for(int i = 0; i < n; i++){
            cin>>in[i];
        }
        for(int i = 0; i < n; i++){
            cin>>pre[i];
        }
        Node *root = callBuildTree(in, pre, n);
        printPostOrder(root);
        cout<<endl;
    }
}


