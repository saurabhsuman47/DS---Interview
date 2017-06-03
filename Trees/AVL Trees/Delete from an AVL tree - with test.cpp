//Delete in an AVL tree - with test(insert elements and then delete)//

/* INPUT (just paste this in stdin console) - (1st line test case, for each test case n = number of nodes to insert, after that n values to be inserted, then node to delete)
1  
5
3 2 4 5 6
2
*/
/* OUTPUT - print inorder and preorder with balancing factors for each node
2(BF=0) 3(BF=-1) 4(BF=0) 5(BF=0) 6(BF=0) 
3(BF=-1) 2(BF=0) 5(BF=0) 4(BF=0) 6(BF=0) 
*/

#include<iostream>
using namespace std;

//avl node, height parameter is added to BST node for balancing reasons//
struct Node{
	int data;
	Node *left;
	Node *right;
	int height;
};

//create a new node with data//
Node* createNewNode(int data){
	Node *ptr = new Node();
	ptr -> data = data;
	ptr -> left = NULL;
	ptr -> right = NULL;
	ptr -> height = 0;
	return ptr;
}

//returns node with minimum value//
Node* findMinValueNode(Node *root){
    if(!root)return NULL;
    if(!root -> left)return root;
    return findMinValueNode(root -> left);
}

//get height of a node//
int height(Node *root){
	if(root == NULL)return -1;
	else return root -> height;
}

//update height of any node by checking its children height//
void updateHeight(Node *root){
    if(!root)return;
	root -> height = max(height(root -> left) , height(root -> right)) + 1;
}

//balance factor - diff between subtree heights//
int balanceFactor(Node *root){
	if(!root)return 0;
	return height(root -> left) - height(root -> right);
}

//left rotate//
Node* leftRotate(Node *z){
	Node *y = z -> right;
	z -> right = y -> left;
	y -> left = z;
	updateHeight(z);
	updateHeight(y);
	return y;
}

//right rotate//
Node* rightRotate(Node *z){
	Node *y = z -> left;
	z -> left = y -> right;
	y -> right = z;
	updateHeight(z);
	updateHeight(y);
	return y;	
}

//insert a node with data to AVL//
Node* insertToAVL(Node *root, int data){
	if(root == NULL){
		root = createNewNode(data);
		return root;
	}
	if(data < root -> data)root -> left = insertToAVL(root -> left, data);
	else if(data > root -> data) root -> right = insertToAVL(root -> right, data);
	else return root; // if duplicates return
	
	updateHeight(root);
	//left heavy unbalanced
	if(balanceFactor(root) > 1){
		//left left case
		if(data < root -> left -> data){
			root = rightRotate(root);
		}
		//left right case
		else{
			root -> left = leftRotate(root -> left);
			root = rightRotate(root);
		}
	}
	//right heavy unbalanced
	else if(balanceFactor(root) < -1){
		//right right case
		if(data > root -> right -> data){
			root = leftRotate(root);	
		}
		//right left case
		else{
			root -> right = rightRotate(root -> right);
			root = leftRotate(root);
		}
	}
	return root;
}

//Delete a node with data to AVL//
Node* deleteFromAVL(Node *root, int data){
	if(!root){
		return root;
	}
	if(data < root -> data)root -> left = deleteFromAVL(root -> left, data);
	else if(data > root -> data) root -> right = deleteFromAVL(root -> right, data);
	else{
		if(!root -> left && !root -> right){
			delete root;
			return NULL;
		}
		else if(!root -> left){
			Node *temp = root -> right;
			delete root;
			root = temp;
		}
		else if(!root -> right){
			Node *temp = root -> left;
			delete root;
			root = temp;
		}
		else{
			Node *temp = findMinValueNode(root -> right);
			root -> data = temp -> data;
			root -> right = deleteFromAVL(root -> right, temp -> data);
		}
		
	}
	if(!root)return NULL;
	updateHeight(root);
	//left heavy unbalanced
	if(balanceFactor(root) > 1){
		//left left case
		if(balanceFactor(root -> left) >= 0){
			root = rightRotate(root);
		}
		//left right case
		else{
			root -> left = leftRotate(root -> left);
			root = rightRotate(root);
		}
	}
	else if(balanceFactor(root) < -1){
		//right right case
		if(balanceFactor(root -> right) <= 0){
			root = leftRotate(root);
		}
		//right left case
		else{
			root -> right = rightRotate(root -> right);
			root = leftRotate(root);
		}
	}
	return root;
}

//print inorder along with balance factors of each node//
void printInorderBF(Node *root){
	if(!root)return;
	printInorderBF(root -> left);
	cout<<root -> data<<"(BF="<<balanceFactor(root)<<") ";
	printInorderBF(root -> right);
}

//print preorder along with balance factors of each node//
void printPreorderBF(Node *root){
	if(!root)return;	
	cout<<root -> data<<"(BF="<<balanceFactor(root)<<") ";
	printPreorderBF(root -> left);
	printPreorderBF(root -> right);
}

//driver program to test//
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		Node *root = NULL;
		for(int i = 0; i < n; i++){
			int val;
			cin>>val;
			root = insertToAVL(root, val);
		}
		printInorderBF(root);
		cout<<endl;
		printPreorderBF(root);
		cout<<endl;
		int del_val;
		cin>>del_val;
		root = deleteFromAVL(root, del_val);
		printInorderBF(root);
		cout<<endl;
		printPreorderBF(root);
		cout<<endl;
		
	}
}