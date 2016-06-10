//Time Complexity:   O(N1+N2)
//Space Complexity:  O(1)

#include<stdio.h>
#include<iostream>
using namespace std;

struct Node{
    int data     ;
    Node *next;
} ;

int main(){
    int inter, n1, input, n2, len1 = 0, len2 = 0;
    Node *head1, *head2, *ptr1, *ptr2, *interm  ;

    cout << "Enter which node of the 1st LL to be the Intersection point(1-based) press 0 for no intersection" << endl  ;
    cin  >> inter   ;
    head1 = new Node;
    head2 = new Node;
    head1 -> next = NULL;
    head2 -> next = NULL;

    if (inter)
        cout << "Enter No. of Nodes for First LL (>= " << inter << endl;
    else
        cout << "Enter No. of Nodes for First LL" << endl   ;
    cin  >> n1   ;

    ptr1 = head1 ;
    for(int i = 0; i < n1; i++){
        cin >> input    ;
        Node *current = new Node  ;
        current -> data = input ;
        current -> next = NULL ;
        ptr1 -> next = current   ;
        ptr1 = current  ;

        if (inter)
            if (i == inter - 1)
                interm = ptr1   ;

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

    if (inter)
        ptr2 -> next = interm   ;   // this node is the  intersection(if any)

    /*The Algo*/

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
