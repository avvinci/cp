struct Node {
  int data;
  struct Node *right, *left;
}; 

Node* new_node(int data) {
    Node *temp = new node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

///////////////////// INSERTION //////////////////////////////
void insert_rec(Node* node, int data) {
    if(data > node->data) {
        if(node->right == NULL) {
            node->right = new_node(data);
            return; 
        } 
        insert(node->right, data);
    } else if(data < node->data) {
        if(node->left == NULL) {
            node->left = new_node(data);
            return; 
        }
        insert(node->left, data);
    }
}

/* This function should insert a new node with given data and
   return root of the modified tree  */
Node* insert(Node* node, int data) {
    if(node == NULL) return new_node(data);
    insert_rec(node, data);
    return node;
}
//////////////////////////////////////////////////////////////