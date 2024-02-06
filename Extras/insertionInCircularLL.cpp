//insertion in circular sorted linked list
class Solution
{
    public:
    Node* sortedInsert(Node* head, int data) {
    Node* temp = new Node(data);

    if (head == NULL) {
        temp->next = temp;
        return temp;
    }

    Node* curr = head;
    Node* prev = NULL;

    do {
        prev = curr;
        curr = curr->next;
        if (data >= prev->data && data < curr->data) {
            break;
        }
    } while (curr != head);

    prev->next = temp;
    temp->next = curr;

    if (data < head->data) {
        return temp;
    }

    return head;
}

};