#include <iostream>
using namespace std;
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newnode(int data){
  struct node *nnewnode = new node;
  nnewnode->data = data;
  nnewnode->left = NULL;
  nnewnode->right = NULL;
  return nnewnode;
}
struct node *insert(struct node *root,int data){
    if(root==NULL){
      root = newnode(data);
      return root;
    }
    else if(data<=root->data){
      root->left = insert(root->left,data);
    }
    else{
        root->right = insert(root->right,data);
    }
    return root;
}


void printpostorder(struct node *root){
    if(root==NULL){
       return ; 
    }
    
    printpostorder(root->right);
    cout<<root->data;
    printpostorder(root->left);
}
int main()
{struct node *root = NULL;
  int  n,k,data1;
  cin>>n;
   while(n--){
       cin>>k;
      root = insert(root,k);
   }
   printpostorder(root);
   
    return 0;
}