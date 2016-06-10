#include<stdio.h>
#include<iostream>
using namespace std;

struct Node{
    int data     ;
    Node *next;
} ;

int main(){
    int n , input,  M   ;
    Node *ptr, *head, *tail   ;
    /*Taking input to fill Linked List*/
    cout << "How many Nodes ? "  ;
    cin  >> n   ;

    head  = new Node ;
    head -> next = NULL;
    ptr  = head  ;
    for (int i = 0; i < n; i++){
        cin  >>  input   ;
        Node * current = new Node   ;
        current ->data = input ;
        current -> next = NULL  ;
        ptr -> next = current   ;
        ptr = current           ;
    }
    cout << "Enter the index(Except first and last) of the node to be get its reference: " ;
    cin  >> M   ;
    Node * mid  ;
    mid = head -> next;
    for (int i = 0; i < M - 1; i++)
        mid = mid -> next   ;

// Pointer mid is the reference to the given index(1-based), this is what would be given.

    mid -> data = mid -> next -> data   ;
    mid -> next = mid -> next -> next   ;

//Output of the Final Linked List
    ptr = head -> next  ;
    while(ptr){
        cout << ptr -> data << endl;
        ptr = ptr -> next   ;
    }

    return 0    ;
}
