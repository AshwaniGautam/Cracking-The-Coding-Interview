//Time Complexity = O(N)
//Space Complexity= O(N), used stack
//Assumption: Only Head pointer is Given, Data to be stored is character.
#include<stdio.h>
#include<iostream>
#include<stack>
using namespace std;

struct Node{
    char data     ;
    Node *next;
} ;

int main(){
    int n ,  part   ;
    char input      ;
    Node *ptr, *head, *tail   ;
    stack <Node *> mystack     ;
//Taking input to fill Linked List
    cout << "How many Nodes ? "  ;
    cin  >> n   ;

    head  = new Node ;
    head -> next = NULL;
    ptr  = head  ;
    for (int i = 0; i < n; i++){
        cin  >>  input   ;
        Node * current = new Node   ;
        current -> data = input ;
        current -> next = NULL  ;
        ptr -> next = current   ;
        ptr = current           ;
    }

    ptr = head;
    int length = 0;
    while(ptr){
        mystack.push(ptr)     ;
        ptr = ptr -> next     ;
        length ++           ;
    }

    ptr = head -> next  ;
    for(int i = 0; i < length / 2; i++){
            if (ptr -> data != mystack.top() -> data){
                cout << "Not A Palindrome " ;
                return 0    ;
            }
            mystack.pop()   ;
            ptr = ptr -> next   ;
    }
    cout << "Palindrome Found"  ;
    return 0    ;
}
