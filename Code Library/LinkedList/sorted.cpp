void intersection(Node **head1, Node **head2, Node **head3) {
    Node *p1 = *head1, *p2 = *head2;
    while(p1 != NULL && p2 != NULL) {
        while(p1 != NULL &&  p2 != NULL && p1->val < p2->val) {
            p1 = p1->next;
        }
        while(p2 != NULL &&  p1 != NULL && p2->val < p1->val) {
            p2 = p2->next;
        }
        while(p2 != NULL &&  p1 != NULL && p2->val == p1->val) {
            push(head3, p1->val);
            p1 = p1->next;
            p2 = p2->next;                
        }
    }
}

Node* SortedMerge(Node* head1, Node* head2) {
    Node *head = NULL, *tail = NULL;
    Node *p1 = head1, *p2 = head2;
    while(p1 != NULL || p2 != NULL) {
        while(p1 != NULL &&  (p2 == NULL || p1->data <= p2->data)) {
            append(&head, &tail, p1->data);
            p1 = p1->next;
        }
        while(p2 != NULL &&  (p1 == NULL || p2->data <= p1->data)) {
            append(&head, &tail, p2->data);
            p2 = p2->next;
        }
    }
    return head;
}

Node *removeDuplicates(Node *root) {
    Node *temp = root;
    while(temp && temp->next) {
        while(temp && temp->next && temp->data != temp->next->data) {
            temp = temp->next;
        }
        if(temp) { 
            Node* del = temp->next;
            temp->next = NULL;
            if(temp && del){
                temp->next = del->next;
                delete del;
            }
        }
    }
    return root;
}