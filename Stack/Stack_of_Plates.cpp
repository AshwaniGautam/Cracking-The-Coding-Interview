//Time Complexity : O(1) for all operations.
//Space Complexity: O(N)
#include<stdio.h>
#include<iostream>
#include<stack>
#include<vector>
#include<climits>
 using namespace std    ;

 class SetofStacks{
    private:
        int stack_limit ;
        int stacks      ;
        vector <stack<int>> arr;
    public:

        SetofStacks(int data){
            stack_limit = data  ;
            stacks = 1  ;
            stack <int> s ;
            arr.push_back(s)    ;
        }

        void push(int element){
            if ( arr[stacks - 1].size() >= stack_limit){
                stack <int> s ;
                arr.push_back(s)    ;
                stacks ++   ;
            }
            arr[stacks - 1].push(element)   ;
        }

        void pop(){
            if (stacks != 0){
                if(!arr[stacks-1].empty())
                    arr[stacks-1].pop() ;
            }
        }

        int top(){
            if ( stacks != 0){
                while(stacks >= 1 && arr[stacks-1].empty())
                    stacks--    ;
                if( stacks != 0)
                    return arr[stacks-1].top()  ;
            }
            return INT_MIN  ;
        }

        void PopAt(int index){
            if (!arr[index - 1].empty())
                arr[index-1].pop()  ;
        }
 }  ;

 int main(){
    int siz, input, elem ;
    cout << "Enter limit size of a stack " << endl  ;
    cin  >> siz ;
    cout << "Enter Total No.of elements : " << endl ;
    cin  >> elem;
    SetofStacks mystack(siz) ;

    cout << "Enter elements"  << endl   ;
    for (int i = 0; i < elem; i++){
        cin >> input    ;
        mystack.push(input)  ;
    }

    cout << "<-------------------------------Output------------------------------------->"<< endl;

    mystack.PopAt(3);
    mystack.PopAt(3);
    mystack.PopAt(3);
    for(int i = 0; i < elem; i++){
        cout << mystack.top() << " "<<endl   ;
        mystack.pop();
    }

 }
