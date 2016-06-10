#include<stdio.h>
#include<iostream>
using namespace std;

struct Node{
    int data     ;
    Node *next;
} ;

void swap(Node *a, Node *b){
    int mid ;
    mid = a -> data ;
    a -> data = b -> data   ;
    b -> data = mid ;
}

int main(){
    int n , input,  part   ;
    Node *ptr, *head, *p, *j   ;
//Taking input to fill Linked List
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

    cout << "Enter the Number for Partitioninig: "  ;
    cin  >> part    ;

    // This is Exactly a one pass of PARTITION routine of QUICKSORT algortihm, it produces STABLE List.

    p = head                ;
    j = head -> next        ;
    while(j){
        if (j -> data < part){
            p = p -> next   ;
            swap(p, j)      ;
        }
        j = j -> next       ;
    }

//Output of the Final Linked List
    ptr = head -> next  ;
    while(ptr){
        cout << ptr -> data << endl;
        ptr = ptr -> next          ;
    }

    return 0    ;
}
