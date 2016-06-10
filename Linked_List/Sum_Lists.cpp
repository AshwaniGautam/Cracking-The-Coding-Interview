#include<stdio.h>
#include<iostream>
#include<unordered_map>
using namespace std;

struct Node{
    int data     ;
    Node *next;
} ;


void input_number(int n, Node *head1){
    Node *ptr1   ;
    ptr1  = head1  ;
    while(n){
         Node * current = new Node   ;
        current -> data = n % 10    ;
        current -> next = NULL      ;
            ptr1 -> next = current   ;
                    ptr1 = current   ;
                     n /= 10        ;
        }
    return ;
}

int main(){
    char ch ;
    int n , input,  M, carry = 0   ;
    Node  *head1, *head3, *head2, *ptr1, *ptr2, *ptr3    ;

    cout << "FOLLOW UP ?(y/n) " ;
    cin  >> ch  ;

    head1 = new Node    ;
    head1 -> next = NULL;

    head2 = new Node    ;
    head2 -> next = NULL;

    head3 = new Node    ;
    head3 -> next = NULL;

/*Taking input to fill Linked List*/
    if (ch == 'n'){

// Note that, if you give the input normally(not reverse) the Linked List created will be reverse of number and vice-versa.

        cout << "Enter the First Number(not reverse)  ? "  ;
        cin  >> n   ;
        input_number(n, head1)    ;
        cout << "Enter the Second Number(not reverse) ? "  ;
        cin  >>  n  ;
        input_number(n, head2)  ;

        ptr1 = head1 -> next;
        ptr2 = head2 -> next;
        ptr3 = head3;

        while(ptr1 || ptr2){
            Node * current = new Node   ;
            if (ptr1 && ptr2){
                carry = carry + (ptr1 -> data) + (ptr2 -> data)  ;
                current -> data = carry % 10  ;
                carry /= 10 ;
                current -> next =  NULL ;
                ptr3 -> next = current  ;
                ptr3 = current     ;

                ptr1 = ptr1 -> next ;
                ptr2 = ptr2 -> next ;
            }

            else{
                if (ptr1){
                    carry = carry + (ptr1 -> data)  ;
                    current -> data = carry % 10  ;
                    carry /= 10 ;
                    current -> next = NULL ;
                    ptr3 -> next = current  ;
                    ptr3 = current     ;

                    ptr1 = ptr1 -> next ;
                }
                else{
                    carry = carry + (ptr2 -> data)  ;
                    current -> data = carry % 10  ;
                    carry /= 10 ;
                    current -> next = NULL ;
                    ptr3 -> next = current  ;
                    ptr3 = current     ;
                    ptr2 = ptr2 -> next ;
                }


            }


        }
        if (carry){
         Node *current  ;
         current -> data = carry;
         current -> next =  NULL    ;
         ptr3 -> next = current;
        }


    }
//Output of the Final Linked List
    ptr3 = head3 -> next  ;
    while(ptr3){
        cout << ptr3 -> data ;
        ptr3 = ptr3 -> next          ;
    }

    return 0    ;
}
