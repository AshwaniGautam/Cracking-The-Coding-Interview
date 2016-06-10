//Time Complexity : O(N)
//Space Complexity: O(1)
// irand contains a randomly choosen Node in the LL to be the starting of the Loop, you can manually type values(1-based).
// Since we are given a Circular Linked List, we are guarnteed of a Loop.

#include<stdio.h>
#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std ;

struct Node{
    int data    ;
    Node * next ;
}   ;


int main(){
//--------------------------------------------------INPUT SECTION------------------------------------------------------------
    int n, input, irand;
    Node *head, *ptr, *temp  ;
    srand (time(NULL));
    cout << "Enter the length of the LL: "  ;
    cin  >> n   ;

    irand = rand() % n + 1    ;
    head = new Node;
    head -> next = NULL ;
    ptr = head  ;
    for (int i = 0; i < n; i++){
        Node * current = new Node   ;
        cin >> input    ;
        current -> data = input ;
        current -> next = NULL  ;
        ptr -> next = current   ;
        ptr = current           ;

        if (i == irand - 1)
            temp = current;
    }
        ptr -> next = temp  ;

/*-------------------------------------Floyd's Loop Detection Theorem--------------------------------------------------------

            head = Reference to the head of the given Circular Linked List

---------------------------------------------------------------------------------------------------------------------------*/

        Node *Hare, *Tortoise    ;
        int perimeter = 0        ;

        Hare = head -> next -> next -> next ;    // Third Node
        Tortoise = head -> next -> next ;       // First Node


        while(Hare != Tortoise){
            Hare = Hare -> next -> next ;
            Tortoise = Tortoise -> next ;
        }

        Tortoise = Tortoise -> next ;
        perimeter ++    ;


        while(Hare != Tortoise){
            Tortoise = Tortoise -> next ;
            perimeter++ ;
        }
        Hare = head -> next ;

        while(Hare != Tortoise){
            Hare = Hare -> next ;
            Tortoise = Tortoise -> next ;
        }

        cout << Hare -> data << " starts the Loop " << endl ;
        // Hare/Tortoise is the Node which starts the Loop.

    ptr = head -> next  ;
    while(ptr != Hare){
        cout << ptr -> data << " --> "    ;
        ptr = ptr -> next   ;
    }

    cout << Hare -> data    ;

    return 0    ;
}
