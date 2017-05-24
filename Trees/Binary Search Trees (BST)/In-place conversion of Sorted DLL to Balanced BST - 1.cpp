//http://www.geeksforgeeks.org/in-place-conversion-of-sorted-dll-to-balanced-bst/ - method 2 O(n)//
#include<iostream>
#include<cmath>
using namespace std;

struct Node{
	int data;
	Node *next;
	Node *prev;
};

void push(Node **head_dll,int d){
	Node *n = new Node();
	n -> data = d;
	n -> prev = NULL;
	n -> next = *head_dll;
	if(*head_dll)
	(*head_dll)-> prev = n;	
	*head_dll = n;
}

Node* convertDLLtoBSTUtil(Node **head_ref, int count){
    if(count == 0)return NULL;
    int idx = ceil((float)(count + 1)/(2.0));
    Node *left = convertDLLtoBSTUtil(head_ref, idx -1);
    Node *root = *head_ref;
    *head_ref = (*head_ref) -> next;
    Node *right = convertDLLtoBSTUtil(head_ref, count - idx);
    root -> prev = left;
    root -> next = right;
    return root;
}

Node* convertDLLtoBST(Node *head){
    Node *temp = head;
    int count = 0;
    while(temp){
        count++;
        temp = temp -> next;
    }
    return convertDLLtoBSTUtil(&head, count);
}

void printPreorder(Node *root){
    if(!root)return;
    cout<<root -> data<<" ";
    printPreorder(root -> prev);
    printPreorder(root -> next);
}

void printInorder(Node *root){
	if(root==NULL)return;	
	printInorder(root -> prev);
	cout<<root -> data<<" ";
	printInorder(root -> next);	
}


int main(){
	Node *head_dll = NULL;
	push(&head_dll, 5);
	push(&head_dll, 4);
	push(&head_dll, 3);
	push(&head_dll, 2);
	push(&head_dll, 1);
	Node *head = convertDLLtoBST(head_dll); 
	printInorder(head);
	cout<<endl;
	printPreorder(head);
	return 0;
}
