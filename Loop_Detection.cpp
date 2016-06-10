#include<stdio.h>
#include<iostream>
using namespace std ;

struct Node{
    int data    ;
    Node * next ;
}   ;

int main(){

    int n, input;
    Node *head, *ptr  ;
    cout << "Enter the length of the LL: "  ;
    cin  >> n   ;
    head = new Node;
    head -> next = NULL ;
    ptr = head -> next  ;
    for (int i = 0; i < n; i++){
        Node * current = new Node   ;
        cin >> input    ;
        current -> data = input ;
        current -> next = NULL  ;
        ptr -> next = current   ;
        ptr = current           ;
    }
    return 0    ;
}
