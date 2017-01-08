#include <stdio.h>
#include <iostream>
#define N 3 // number of rings on fist peg
using namespace std;

int N_O_S = 0   ; // number of steps

int third_peg(int first, int second){

    int mid = (first + second) / 2  ;
    if((first + second) % 2 == 0)
        return 2    ;
    if(mid == 1)
        return 3    ;
    return 1    ;

}

void solve(int n, int start, int end){

    if (n == 1){

        cout << "Move from " << start << " to " << end  << endl;
        N_O_S ++    ;
        return ;
    }

    solve(n-1, start, third_peg(start, end))    ;
    cout << "Move from " << start << " to " << end  << endl;
    N_O_S ++    ;
    solve(n-1, third_peg(start, end), end)  ;

}

int main(){

    solve(N, 1, 3)    ;  // pegs are numbered as 1, 2, 3. we shift pegs from 1 to 3, change accordingly.
    cout << N_O_S << endl;
    return 0    ;
}
