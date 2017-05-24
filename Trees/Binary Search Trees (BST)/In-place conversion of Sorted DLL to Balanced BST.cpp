//http://www.geeksforgeeks.org/in-place-conversion-of-sorted-dll-to-balanced-bst/ - method 1 O(nlogn)//
#include<iostream>
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

Node* findMiddleElement(Node *head){
    Node *t1 = head;
    Node *t2 = head;
    while(t1 -> next && t2 -> next && t2 -> next -> next){
        t1 = t1 -> next;
        t2 = t2 -> next -> next;
    }
    return t1;
}

Node* convertDLLtoBST(Node *head){
    if(!head )return head;
	Node *temp = findMiddleElement(head);
    if(temp -> prev){temp -> prev -> next = NULL;}
    if(temp -> next)temp -> next -> prev = NULL;
    if(head != temp)temp -> prev = convertDLLtoBST(head);
    temp -> next = convertDLLtoBST(temp -> next);
    return temp;
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
