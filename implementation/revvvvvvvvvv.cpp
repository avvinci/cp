/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
void printSpiral(Node *root)
{
     //Your code here
     if(root == NULL )return ;
     vector< vector < int > > v(104);
     queue< Node * > q ;
     int cnt =0 ;
     struct Node * p = (struct Node *)malloc(sizeof(struct Node));
     p->data = -1;
     q.push(root);
     q.push(p);
     int i,j ;
     while(!q.empty()){
         struct Node * t = q.front();
         q.pop();
         if(t->data == -1){
             q.push(p);
             if(cnt % 2 == 1) reverse(v[cnt].begin() , v[cnt].end()) ;
             cnt++;
             continue;
         }
         v[cnt].push_back(t->data);
         if(t->left != NULL)
         q.push(t->left);
         if(t->right != NULL)
         q.push(t->right);
     }
     for(i =0 ;i < cnt;i++){
         for(j =0 ; j< v[i].size(); j++){
             cout<<v[i][j]<<" ";
         }
     }
}