//Construct a special tree from given preorder traversal//
/*http://www.geeksforgeeks.org/construct-a-special-tree-from-given-preorder-traversal/
Given an array ‘pre[]’ that represents Preorder traversal of a spacial binary tree where every node has either 0 or 2 children. One more array ‘preLN[]’ is given which has only two possible values ‘L’ and ‘N’. The value ‘L’ in ‘preLN[]’ indicates that the corresponding node in Binary Tree is a leaf node and value ‘N’ indicates that the corresponding node is non-leaf node. Write a function to construct the tree from the given two arrays.*/

/* INPUT (just paste this in stdin console) - (1st line test case, for each test case number of nodes, preorder traversal and preorder leaf or non leaf details)
1
5
10 30 20 5 15
N N L L L
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};

//constructTree - builds the tree O(n) time complexity//
Node* constructTree(int pre[], char preLN[], int &idx){
    idx++;
    Node *ptr = new Node();
    ptr -> data = pre[idx];
    if(preLN[idx] == 'L'){
        ptr -> left = NULL;
        ptr -> right = NULL;
    }
    else{
        ptr -> left = constructTree(pre, preLN, idx);
        ptr -> right = constructTree(pre, preLN, idx);
    }
    return ptr;
}

//calls constructTree and passes parameters//
Node* constructTreeWrapper(int pre[], char preLN[]){
    int idx = -1;
    return constructTree(pre, preLN, idx);
}

//prints in order traversal//
void printInorder(Node *root){
    if(root == NULL)return;
    printInorder(root -> left);
    cout<<root -> data<<" ";
    printInorder(root -> right); 
}

//takes input, calls function for constructing the tree then printing in order traversal//
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int pre[n];
        char preLN[n];
        for(int i = 0; i < n; i++){
            cin>>pre[i];
        }
        for(int i = 0; i < n; i++){
            cin>>preLN[i];
        }
        Node *root = constructTreeWrapper(pre, preLN);
        printInorder(root);
        cout<<endl;
        
    }
}

