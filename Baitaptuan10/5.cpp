#include <iostream>
#include <unordered_map>
using namespace std;
 

struct Node {
    int data;
    Node* link;
    Node* arbit;
    Node(int x)
    {
        this->data = x;
        this->link = NULL;
        this->arbit = NULL;
    }
};
Node* Clone(Node* head)
{
    unordered_map<Node*, Node*> mp;
    Node *temp, *nhead;
    temp = head;
    nhead = new Node(temp->data);
    mp[temp] = nhead;
    while (temp->link != NULL) {
        nhead->link
            = new Node(temp->link->data);
        temp = temp->link;
        nhead = nhead->link;
        mp[temp] = nhead;
    }
    temp = head;
    while (temp != NULL) {
        mp[temp]->arbit = mp[temp->arbit];
        temp = temp->link;
    }
    return mp[head];
}
void printList(Node* head)
{
    cout << head->data << "("
         << head->arbit->data << ")";
    head = head->link;
    while (head != NULL) {
        cout << " -> " << head->data << "("
             << head->arbit->data << ")";
        head = head->link;
    }
    cout << endl;
}
int main()
{
    Node* head = new Node(1);
    head->link = new Node(2);
    head->link->link = new Node(3);
    head->link->link->link = new Node(4);
    head->link->link->link->link
        = new Node(5);
    head->arbit = head->link->link;
    head->link->arbit = head;
    head->link->link->arbit
        = head->link->link->link->link;
    head->link->link->link->arbit
        = head->link->link;
    head->link->link->link->link->arbit
        = head->link;
    cout << "The original linked list:\n";
    printList(head);
    Node* sol = Clone(head);
    cout << "The cloned linked list:\n";
    printList(sol);
   
    return 0;
}