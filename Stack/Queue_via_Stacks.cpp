//Time Complexity : enqueue --> O(1), dequeue --> O(1) amortized.
//Space Complexity: O(N)

#include<stdio.h>
#include<iostream>
#include<stack>
#include<climits>
using namespace std ;

class Myqueue{
    private:
        stack<int> s1, s2   ;

    public:
        void queue(int element){
            s2.push(element)    ;
            }

        int dequeue(){
            if (s1.empty()){
                while(s2.size()){
                    s1.push(s2.top())   ;
                    s2.pop()    ;
                    }
                }
            if (!s1.empty()){
                int result = s1.top() ;
                s1.pop()    ;
                return result;
            }
            else
                    return INT_MIN  ;
        }

}   ;
int main(){
    int c, input; ;
    Myqueue myque;
    cout << "For queue enter 1 and element, e.g, 1 66 \nFor dequeu press 2. press any other key to exit." << endl  ;

    while(true){
        cin >> c    ;
        if(c == 1){
            cin >> input    ;
            myque.queue(input)  ;
        }

        else
            if(c == 2)
                cout << myque.dequeue() << endl;
        else
            return 0    ;
    }
}
