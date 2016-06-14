#include<stdio.h>
#include<iostream>
#include<climits>
#include<string>
using namespace std ;

class Node{
    public:
            int data        ;
            string Animal   ;
            Node *next      ;
            Node(int ArrivalTime, string pet){
                data = ArrivalTime  ;
                next = NULL         ;
                Animal = pet        ;
    }
}   ;

class AnimalShelter{
    private:
        void deleteN (){
            if (head -> next -> next == NULL){
                head -> next = NULL;
                tail = head;
                }
            else
                head -> next = head -> next -> next;
        }
    public:
        Node *head, *tail, *current, *ptr    ;

        AnimalShelter(){
            head = new Node(INT_MAX,"No Animal")    ;
            tail = head                             ;
        }

        void enqueue(int ArrivalTime, string petname){
            current  = new Node(ArrivalTime, petname)    ;
            tail -> next = current                      ;
            tail = current                              ;
        }

        Node * dequeueany(){
            if (head -> next != NULL){
                ptr = head -> next  ;
                deleteN()    ;
                return ptr ;
            }
            else{
                cout << "Shelter Empty" << endl ;
                return nullptr;
            }
    }

        Node * dequeueDog(){
            if (head -> next){
                current = head -> next  ;
                while(current -> Animal != "Dog" && current -> next != NULL){
                    current = head -> next   ;
                    dequeueany()                ;
                }
                if (current -> Animal == "Dog"){
                    dequeueany()    ;
                    return current  ;
                }
            }
            cout << "No Dog Found in the Shelter" << endl;
            return nullptr  ;
        }

        Node * dequeueCat(){
            if(head -> next){
                current = head -> next  ;
                while(current -> Animal != "Cat" && current -> next != NULL){
                    current = current -> next   ;
                    dequeueany()                ;
                }
                if (current -> Animal == "Cat"){
                    dequeueany()    ;
                    return current  ;
                    }
            }
            cout << "No Cat Found in the Shelter" << endl;
            return nullptr  ;
        }
}   ;

int main(){
    int n, input, count = 0;
    Node  *ans ;
    AnimalShelter myshelter ;
    cout << "1 --> Enqueue --> Dog(1)/Cat(2)\n2 --> DequeuAny\n3 --> DequeuDog\n4 --> DequeuCat\nAny other key to exit" << endl ;
    while(true){
        cin >> n    ;
        if (n == 1){
            cin >> input    ;
            count ++    ;
            if (input == 1)
                myshelter.enqueue(count, "Dog") ;
            else
                myshelter.enqueue(count, "Cat") ;
        }
        else
            if(n == 2){
                ans = myshelter.dequeueany()    ;
                if (ans != nullptr)
                    cout << ans -> data << " " << ans -> Animal << endl ;
            }
        else
            if(n == 3){
                ans = myshelter.dequeueDog()    ;
                if (ans != nullptr)
                    cout << ans -> data << " " << ans -> Animal << endl ;
            }
        else
            if(n == 4){
                ans = myshelter.dequeueCat()    ;
                if (ans != nullptr)
                    cout << ans -> data << " " << ans -> Animal << endl ;
        }
        else
            return 0;
    }
}
