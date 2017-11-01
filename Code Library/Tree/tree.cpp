/////////////////// DIAMETER OF BINARY TREE /////////////////////
struct Node {
 int data;
 Node* left, *right;
}; 

int height(Node* node) {
  if(node == NULL) 
    return 0;
  return max(height(node->left), height(node->right)) + 1; 
}

/* Computes the diameter of binary tree with given root.  */
int diameter(Node* node) {
  if(node == NULL) return 0;
  int ld = diameter(node->left);
  int rd = diameter(node->right);
  int cur_d = height(node->left) + height(node->right) + 1;
  return max(cur_d, max(ld, rd));
}
//////////////////////      MIRROR     //////////////////////////
// check if n-ary tree T1 is mirror of tree T2. T1 is kept on left. 
bool are_mirror(vvi &t1, vvi &t2) { // 1-indexed
  if(t2.size() != t1.size()) return false;
  int n = t1.size();

  for(int i = 1; i <= n; i++) {
    for(int l = 0; l < t1[i].size(); l++) {
      int r = t1[i].size() - l - 1;

            // no. of children is different in both trees for the ith node
      if(r < 0 || r >= t2[i].size()) return false; 

            // leftmost child = rightmost child for each child of ith node
      if(t1[i][l] != t2[i][r]) return false;
    }
  }
  return true;
}
/* Given two binary trees, should return true if they are
   mirror of each other. */
int areMirror(Node* a, Node* b) {
 if(a == NULL) {
   if(b == NULL) return 1;
   else return 0;
 }
 if(a->data != b->data) return 0;
 return areMirror(a->left, b->right) && areMirror(b->left, a->right);
}

// has some path from root to path = sum
bool hasPathSum(Node *node, int sum) {
  bool ans = 0;  
  int subSum = sum - node->data;

    /* If we reach a leaf node and sum becomes 0 then return true*/
  if (subSum == 0 && node->left == NULL && node->right == NULL)
  return 1;

  if(node->left)
   ans = ans || hasPathSum(node->left, subSum);
  if(node->right)
   ans = ans || hasPathSum(node->right, subSum);

  return ans;
}
//////////////////////////////////////////////////////////////////
void printLeaves(Node* node) {
    if(!node)return;
    if(node->left == NULL && node->right == NULL) {
        cout << node->data << " "; 
        return;
    }
    printLeaves(node->left);
    printLeaves(node->right);
}

void printLeft(Node* node) {
    if(node == NULL) return;
    if(node->left == NULL && node->right == NULL) return;
    
    cout << node->data << " ";
    if(node->left == NULL) printLeft(node->right);
    else printLeft(node->left);
}

void printRight(Node* node) {
    if(node == NULL) return;
    if(node->left == NULL && node->right == NULL) return;
        
    if(node->right == NULL) printRight(node->left);
    else printRight(node->right);
    cout << node->data << " ";
}

void printBoundary(Node *root) {
    if(root) cout << root->data << " ";
    printLeft(root->left);
    printLeaves(root->left);
    printLeaves(root->right);
    printRight(root->right);
}
///////////////////////////////////////////////////////////////////