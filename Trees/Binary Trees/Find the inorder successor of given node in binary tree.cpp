//Given a binary tree print out inorder Successor of a given node//
//GFG template apart from inorderSuccessor() function which is at the bottom.//

/* INPUT (just paste this in stdin console) - (1st line test case, for each test case number of edges is given and description of those edges[parent, child, left/right], after that the node for which inorder successor is to be found).
2
2
3 2 L 3 4 R
3
4
10 20 L 10 30 R 20 40 L 20 60 R
10
*/

#include <bits/stdc++.h>
using namespace std;


/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};


int inorderSuccessor( Node* node, int n);

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
  struct Node* node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}

/* Computes the number of nodes in a tree. */
int height(struct Node* node)
{
  if (node==NULL)
    return 0;
  else
    return 1 + max(height(node->left), height(node->right));
}

void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

/* Driver program to test*/
int main()
{
  int t;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);

        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];

        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
	 int nn;
	 cin>>nn;
     cout<<inorderSuccessor(root, nn);
     cout<< endl;
  }
  return 0;
}


void inorderSuccessorHelper(Node *root, int n, int &flag, int &result){
	if(root == NULL)return;
	inorderSuccessorHelper(root -> left, n, flag, result);
	if(flag == 1){
		result = root -> data;
		flag = 0;
	}
	if(root -> data == n){
		flag = 1;
	}	
	inorderSuccessorHelper(root -> right, n, flag, result);
}
int inorderSuccessor(Node *root, int n)
{
    //Your code here
	int flag = 0;
	int result = NULL;
	inorderSuccessorHelper(root, n, flag, result);
	return result;
    
}
