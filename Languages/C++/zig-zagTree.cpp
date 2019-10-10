//this code is used to print a tree in zig-zag order
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
void zigZagOrder(BinaryTreeNode<int> *root) {

   stack <BinaryTreeNode<int>* > s1,s2;
  s1.push(root);
  while(s1.size()!=0||s2.size()!=0)
  
  {
    while(!s1.empty())
    {   BinaryTreeNode<int>*curr=s1.top();
      s1.pop();
    if(curr!=NULL)
     cout<<curr->data<<" ";
      if(curr->left!=NULL)
        s2.push(curr->left);
     if(curr->right!=NULL)
         s2.push(curr->right);

    }
cout<<"\n";
  
  while(!s2.empty())
  {
     BinaryTreeNode<int>* curr1=s2.top();
      s2.pop();
         if(curr1!=NULL)
    cout<<curr1->data<<" ";
     if(curr1->right!=NULL)
        s1.push(curr1->right);
     if(curr1->left!=NULL)
         s1.push(curr1->left);
    
    
  }
  cout<<"\n"; 
  } 
      
  }

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    zigZagOrder(root);
}
