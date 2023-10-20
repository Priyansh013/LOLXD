#include <bits/stdc++.h>
using namespace std;


struct Node{
    int key;
    Node *left;
    Node *right;
    Node(int k){
        key  =  k;
        left = right = NULL;
    }
};


void InOrder(Node *root){
    if(root!=NULL){
        InOrder(root->left);
        cout<<root->key<<" ";
        InOrder(root->right);    
    }
} 

void PreOrder(Node *root){
    if(root!=NULL){
        cout<<root->key<<" ";
        PreOrder(root->left);
        PreOrder(root->right);    
    }
} 

void PostOrder(Node *root){
    if(root!=NULL){
        PostOrder(root->left);
        PostOrder(root->right);
        cout<<root->key<<" ";
    }
} 

int Height(Node *root){
    if(root==NULL)
        {return 0;}
    else
        {int maxm =max(Height(root->left),Height(root->right)) ;
        return 1 + maxm;}
} 

void NodeAtk(Node *root,int k){
    if(root==NULL){return;}
    
    if(k==0){cout<<root->key<<" ";}
    else{
    NodeAtk(root->left,k-1);
    NodeAtk(root->right,k-1);
    }
}

void LevelOrder( Node *root){
    int height = Height(root);
    for(int i =0 ;i<height; i++){
      NodeAtk(root,i);
      cout << endl;
    }
}

int indd=0;
int countt=0;
void SpiralNodeAtk(Node *root,int k,int arr[]){
   // cout << "indd  is " << indd << endl; 
    if(root==NULL){return;}
    if(k==0){arr[indd] = root->key;
    // cout << "arr indd is " << arr[indd] << endl;
     indd++;countt++;
    
    }
    else{
    SpiralNodeAtk(root->left,k-1 , arr);
    SpiralNodeAtk(root->right,k-1 , arr);
    }
}

void SpiralLevelOrder( Node *root){
    int height = Height(root);
    int val = true;
    for(int i =0 ;i<height; i++){
    //    cout << "lol" <<i<< endl;
        indd=0;
        countt=0;
        int deg = pow(2,i);
        int arr[deg];
      SpiralNodeAtk(root,i,arr);

    //  cout << "val is " << val << endl;
      if(val ==1){
        for(int i=0; i <countt;i++){
            cout << arr[i] << " " ;
        }
        cout << endl;
        val = 0;
      }
      else{
        for(int i = countt-1; i>=0;i--){
            cout << arr[i] << " ";
        }
        cout<< endl;
        val =1;
      }
    }
}

int ChildrenSum(Node *root){
    if(root != NULL){
        int sum =root->key;
        //cout << "root key is " << root->key << endl;
        if(root->left != NULL && root->right != NULL){
            sum = root->left->key + root->right->key;       
        }
        else if(root->left == NULL && root->right != NULL){
            sum =root->right->key;
        }

         else if(root->left != NULL && root->right == NULL){
            sum =root->left->key;
        }

       // cout << "sum is " << sum << endl;
        if(sum == root->key){return 1 * ChildrenSum(root->left) * ChildrenSum(root->right);}
        else{return 0;}
    }
    else{
        return 1;
    }
}



int NumberOfNodesAtk(Node *root,int k){

    if(root==NULL){return 0;}
    if(k<0){return 0;}
    else{
    if(k==0){ return 1;}
    else{
    return NumberOfNodesAtk(root->left,k-1) + NumberOfNodesAtk(root->right,k-1);
    }}
}


void MaxmWidth(Node *root){
    int height = Height(root);
    int maxm = 0;
    for(int i=0;i<height ; i++){
        maxm = max(maxm, NumberOfNodesAtk(root,i));
        }
    cout << maxm << endl;

}

int checkHeightBalanced(Node *root){
    if(root != NULL){
        int diff = abs(Height(root->left) - Height(root->right));
        if(diff >1){return 0;}
        else{
            return 1 * checkHeightBalanced(root->left) * checkHeightBalanced(root->right);
        }
    }
    else{
        return 1;
    }
}


int preIndex = 0;
Node *cTree( int in[] , int pre[] , int is, int ie){

    if(is > ie) return NULL;

    Node *root = new Node(pre[preIndex]);
    preIndex++;

    int inIndex;
    for(int i = is ; i<=ie ; ++i){
        if(in[i] == root->key){
            inIndex = i;
            break;
        }
    }

    root->left = cTree(in,pre,is,inIndex-1);
    root->right = cTree(in,pre,inIndex+1, ie);
    return root;


 }


int main(){

Node *root = NULL;

root = new Node(10);
root->left = new Node(20);
root->right = new Node(30);
root->right->right = new Node(60);
root->left->left = new Node(40);
root->left->right = new Node(50);
root->left->right->left = new Node(70);
root->left->right->right = new Node(80);
root->left->right->right->right = new Node(90);
root->left->right->right->right->right = new Node(100);


// root = new Node(10);
// root->left = new Node(60);
// root->right = new Node(40);
// root->right->right = new Node(80);
// root->left->left = new Node(20);
// root->right->left = new Node(210);
// root->left->left->left = new Node(876);
//root->left->right = new Node(40);
// root->right->right->left = new Node(50);
// root->left->right->left = new Node(40);
// root->left->right->right = new Node(80);
// root->right->right->left->right = new Node(89);
// root->left->right->right->right = new Node(90);
// root->left->right->right->right->right = new Node(100);

// LevelOrder(root);
// cout <<endl;
SpiralLevelOrder(root);


}