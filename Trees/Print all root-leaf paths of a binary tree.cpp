//Given a binary tree print out all its root-leaf paths.//
//GFG template apart from printPaths() function which is at the bottom.//

/* INPUT (just paste this in stdin console) - (1st line test case, for each test case number of edges is given and description of those edges[parent, child, left/right])
2
2
3 2 L 3 4 R
4
10 20 L 10 30 R 20 40 L 20 60 R
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


void printPaths( Node* node);

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

/* Driver program to test size function*/
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

     printPaths(root);
     cout<< endl;
  }
  return 0;
}


int arr[100];
int idx = 0;
void printPaths(Node *root)
{
    //Your code here
    if(root == NULL)return;
    if(!root -> left && !root -> right){
        for(int i = 0; i < idx; i++)cout<<arr[i]<<" ";
        cout<<root->data<<endl;
    }
    else{
        arr[idx] = root -> data;
        idx++;
        if(root -> left)printPaths(root -> left);
        if(root -> right)printPaths(root -> right);
        idx --;
    }
}
