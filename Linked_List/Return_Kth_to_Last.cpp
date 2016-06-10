/* Assumption: Only the Head pointer to the Linked List and K is Given.
                K <= length of the Linked list.
*/

#include<stdio.h>
#include<iostream>
#include<stack>

using namespace std ;

struct Node{
    int data    ;
    Node * next ;
}   ;

int main(){
    int n, input, K   ;
    Node *head, *ptr, *temp    ;
    stack <Node*> mystack;

    /*Taking input to fill Linked List*/
    cout << "How many Nodes ? " ;
    cin >> n    ;
    head  = new Node ;
    head -> next = NULL ;
    ptr = head ;
    for (int i = 0; i < n; i++){
        cin >> input    ;
        Node * current = new Node;
        current -> data = input ;
        current -> next =  NULL ;
        ptr -> next = current   ;
        ptr = current  ;
    }



    cout << "enter Kth element to be removed "  ;
    cin >> K    ;

    /*The Algo*/

    ptr = head -> next  ;
    while(ptr){
        mystack.push(ptr)     ;     // creating a stack of pointers pointing to nodes of Linked List
        ptr = ptr -> next   ;
    }

    temp -> next = NULL;
    for (int i = 0; i < K; i++){
        if(i == K - 2)
            temp = mystack.top()    ;    // Saving the (K-1)th pointer for Linking it to the (K - 2)th pointer later
        mystack.pop()           ;       //Popping the pointers till Kth from the top is removed
    }


    if (!mystack.empty())
        mystack.top() -> next = temp    ;
    else                                       //First Node is being removed, so incrementing the head to the second node
        head -> next = head -> next -> next ;


    /*Output of the Final Linked List*/
    ptr = head -> next  ;
    while(ptr){
        cout << ptr -> data << endl;
        ptr = ptr -> next   ;
    }

}
