//Time Complexity:   O(N1+N2)
//Space Complexity:  O(1)

#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

struct Node{
    int data     ;
    Node *next;
} ;

int main(){
//--------------------------------------------------INPUT SECTION------------------------------------------------------------
    int inter, n1, input, n2, len1 = 0, len2 = 0, irand;
    Node *head1, *head2, *ptr1, *ptr2, *interm  ;
    srand (time(NULL));

    head1 = new Node;
    head2 = new Node;
    head1 -> next = NULL;
    head2 -> next = NULL;

    cout << "Enter The length of the First Linked List: "   ;
    cin  >> n1   ;

    inter = rand() % n1  ;  // inter holds the index of the Intersecting node in the First Linked List.

    ptr1 = head1 ;
    for(int i = 0; i < n1; i++){
        cin >> input              ;
        Node *current = new Node  ;
        current -> data = input   ;
        current -> next = NULL    ;
        ptr1 -> next = current    ;
        ptr1 = current            ;

        if (i == inter)
            interm = ptr1         ;

    }

    cout << "Enter Number of nodes for 2nd LL, before the intersection(if any)" << endl   ;
    cin >> n2   ;

    ptr2 = head2 ;
    for(int i = 0; i < n2; i++){
        cin >> input    ;
        Node *current  = new Node ;
        current -> data =  input    ;
        current -> next = NULL      ;
        ptr2 -> next = current      ;
        ptr2 = current              ;
    }

        ptr2 -> next = interm   ;   // this node is the  intersection(if any)

/*---------------------------------------------Algorithm Section-------------------------------------------------------------

            head1 = Reference to the Head of the First  Linked List
            head2 = Reference to the Head of the Second Linked List

---------------------------------------------------------------------------------------------------------------------------*/
    ptr1 = head1 -> next    ;
    ptr2 = head2 -> next    ;

    while(ptr1){
        len1++  ;
        ptr1 = ptr1 -> next ;
    }
    while(ptr2){
        len2++  ;
        ptr2 = ptr2 -> next ;
    }

    int larger, smaller ;
    if (len1 > len2){
        larger = len1   ;
        ptr1 = head1    ;
        ptr2 = head2    ;
        }
    else {
        larger = len2   ;
        ptr1 = head2    ;
        ptr2 = head1    ;
        }

    smaller= len1 + len2 - larger   ;

    int jump = larger - smaller ;
    ptr1 = ptr1 -> next ;
    ptr2 = ptr2 -> next ;
    for(int i = 0; i < jump; i++)
        ptr1 = ptr1 -> next    ;

    while(ptr1){
        if (ptr1 == ptr2){
            cout << "Intersection Found" ;
            //ptr1 or equvialently ptr2 is the Intersecting Node   .
            return 0    ;
        }
        ptr1 = ptr1 -> next ;
        ptr2 = ptr2 -> next ;
    }
    cout << "No Intersection"   ;
    return 0    ;
}
