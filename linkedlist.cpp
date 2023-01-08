#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void delnode(Node**head,int key){
   Node*temp = *head;
   Node* prev = NULL;
   if(temp->data == key){
     *head = temp->next;
     delete temp;
     return ;
   }
   else
   {
     while (temp!=NULL && temp->data != key)
     {
        prev = temp;
        temp = temp->next;
     }
     if(temp == NULL){
        return ;
     }
     prev->next = temp->next;
     delete temp;
   }
}

void concatenate(Node*a,Node *b){
        if(a->next == NULL){
            a->next = b;
        }else{
            concatenate(a->next,b);
        }
}

void removeodds(Node*head){
    while(head!=NULL){
        if(head->data%2!=0){
            delnode(&head,head->data);
        }
        head=head->next;
    }
}

void swap(Node*head,int x,int y){
        Node*h = head;
        while(head->next->data!=x){
            head=head->next;
        }
        Node*t1 = head;
        while(h->next->data!=y){
            h=h->next;
        }
        Node*t2=h;
        

}

void joinlink(Node*a,Node*b){
     int fir = b->data;
     Node*c = a->next;

     while ((a!=NULL)&&(a->data <= fir)){
        if(a->data <= fir){
            a->next = b;
     }
        a=a->next;
}
     while (b!=NULL)
     {
        if(b->next == NULL){
            b->next = c;
        }
     }
}

void showlist(Node *head){
    while (head!=NULL){
        cout << head->data << " ";
        head =head->next;
    }
    cout << endl;
}
void headpush(Node*head,int val){
        head->data=val;
        head->next=NULL;
    
}
void push(Node*head , int val){
     Node*newnode = new Node();
     newnode->data=val;
     while(head!=NULL){
        if(head->next==NULL){
            head->next=newnode;
            newnode->next=NULL;

        }
        head=head->next;
     }
}

int main(){
    Node*head1 = new Node();
    Node*head2 = new Node();
    headpush(head1,0);
    push(head1,1);
    push(head1,2);
    push(head1,9);
    push(head1,10);


    headpush(head2,3);
    push(head2,4);
    push(head2,5);
    push(head2,6);
    push(head2,7);


    joinlink(head1,head2);
    removeodds(head1);
    showlist(head1);
    
    return 0;

}