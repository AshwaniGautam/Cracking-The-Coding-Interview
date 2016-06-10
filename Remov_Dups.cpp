// Assumption: Only the Head pointer to the Linked List and K is Given

#include<stdio.h>
#include<iostream>
#include<unordered_map>
using namespace std;

struct Node{
    int data     ;
    Node *next;
} ;

int main(){
    int n, input   ;
    Node *ptr, *head, *tail   ;
    unordered_map <int, int> dict ; // for amortized O(1) lookup, map have an lookup of O(LogN).

    /*Taking input to fill Linked List*/
    cout << "How many Nodes ? "  ;
    cin  >> n   ;

    head  = new Node ;
    head -> next = NULL;
    ptr  = head  ;
    for (int i = 0; i < n; i++){
        cin >>  input   ;
        Node * current = new Node   ;
        current ->data = input ;
        current -> next = NULL  ;
        ptr -> next = current   ;
        ptr = current           ;
    }

    /*The Algo*/
    ptr = head -> next          ;
    dict.insert(make_pair(ptr -> data, 1))    ;
    while(ptr -> next != NULL){
            if (dict.count(ptr  -> next -> data))
                ptr -> next = ptr -> next -> next   ;
            else{
                dict.insert(make_pair(ptr -> next -> data, 1)) ;
                ptr = ptr -> next   ;
                }

    }


/*Output of the Final Linked List*/
    ptr = head -> next  ;
    while(ptr){
        cout << ptr -> data ;
        ptr = ptr -> next   ;
    }


        return 0    ;

}

