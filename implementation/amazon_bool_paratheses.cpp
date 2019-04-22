/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */


/*you are required to 
complete this function */
bool hasPathSum(Node *root, int sum)
{
    if(root == NULL )return 0 ; 
    if(root->right == NULL && root->right == NULL){
        if(sum ==  root->data ) return 1;
        return  0 ; 
    }
   //Your code here
   int r1 ,r2 ; 
   r1 = hasPathSum(root->right , sum - root->data) ; 
   r2 = hasPathSum(root->left , sum  - root->data) ; 
   return (r1 | r2)  ;
}