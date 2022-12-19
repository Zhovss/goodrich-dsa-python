#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node *next;
};

void printList(struct Node *head){
    struct Node *temp = head;
    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->next; 
    }
    cout << "NULL";
}

struct Node *creatNode(int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node *push(struct Node *head, int data){
    struct Node *newNode = creatNode(data);
    head->next = newNode;
    return newNode;
}

void deleteNode(struct Node *p, int key){
    struct Node *pre;
    while(p != NULL && p->data != key){
        pre = p;
        p = p->next;
    }
    if(p == NULL){
        return;
    }
    else if(p->data == key){
        struct Node *temp = p;
        p = temp->next;
        pre->next = temp->next;
        free(temp);
    }
}

void removeDuplicates(struct Node* head){
    if(head == NULL){
        return;
    }else{
        struct Node *check = head;
        while(check->next != NULL){
            if(check->data == check->next->data){
                struct Node *temp = check->next;
                deleteNode(head,check->data);
                check = temp;
            }else{
                check = check->next;
            }
        }
    }
}

int main(){
    int n, data;
    cin >> n;
    cin >> data;
    struct Node *head = creatNode(data);
    
    struct Node *temp = head;
    for(int i=0; i<n-1; i++){
        cin >> data;
        temp = push(temp,data);
    }
    
    removeDuplicates(head);
    
    printList(head);
    return 0;
}