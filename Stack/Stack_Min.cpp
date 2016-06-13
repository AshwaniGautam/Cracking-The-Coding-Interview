//Time Complexity : O(1) for all three operation
//Space Complexity : O(N)


#include<stdio.h>
#include<iostream>
#include<stack>

using namespace std ;

class Stack{
    private:
        stack <int> stack1, stack2  ;
    public:

        void push (int element){

            stack1.push(element)    ;

            if (stack2.empty())
                stack2.push(element)    ;

            else{
                if (element < stack2.top())
                    stack2.push(element)    ;

                else
                    stack2.push(stack2.top())   ;
            }
        }

        void pop(){
                if (!stack1.empty()){
                    stack1.pop()    ;
                    stack2.pop()    ;
                    }
                else cout << "Stack is Empty :P"  << endl ;
        }

        int Min(){
            if (!stack2.empty())
                return stack2.top() ;
            else cout << "Stack is Empty :P" <<endl ;
        }

}   ;

int main(){
    int n, input   ;
    Stack mystack   ;
    cout << "Enter The No. of Elements" << endl ;
    cin  >> n   ;
    cout << "Now Enter Elements :" << endl  ;

    for(int i = 0; i < n; i++){
        cin >> input    ;
        mystack.push(input) ;
    }
    cout << "<-----------------------OUTPUT-------------------------->" << endl   ;
    for (int i = 0; i < n ; i++){
        cout << mystack.Min() << endl ;
        mystack.pop()   ;
    }

    return 0    ;
}
