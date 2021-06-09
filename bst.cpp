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

bool search(struct node *root,int data1){
    if(root==NULL){
        return false;
    }
    else if(root->data==data1){
    return true;
    }
    else if(data1<=root->data){
        return search(root->left,data1);}
    
    else{
       return  search(root->right,data1);
        
    }
}
int main()
{struct node *root = NULL;
  int  n,k,data1;
  cin>>n;
   while(n--){
       cin>>k;
      root = insert(root,k);
   }
   cout<<root->right->data;
   cin>>data1;
   if(search(root,data1)==true){
       cout<<"Found";
   }
   else{
       cout<<"not Found";
   }
    return 0;
}