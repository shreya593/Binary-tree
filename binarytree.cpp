#include <iostream>
using namespace std;
struct node{
    struct node *left;
    int data;
    struct node *right;
};

struct node *newnode(int data){
    struct node *newnode = new node;
    newnode->data = data;
    newnode->right = NULL;
    newnode->left = NULL;
  return newnode;
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
        root->right  = insert(root->right,data);
    }
    return root;
}

int main()
{ struct node *root = NULL;
    int n,k;
    cin>>n;
    while(n--){
        cin>>k;
    
      root =  insert(root,k);
     
    }
   cout<<root->left->data;
    
}
