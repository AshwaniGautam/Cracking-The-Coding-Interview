#include <stdio.h>
#include <iostream>
#include <vector>
#define N 10000
using namespace std;

int Array[N]    ;

vector <vector<int> > subset    ;
vector<int> phi    ;

void collect_subset(int n){

    if(n == 1){

        vector <int> base   ;
        base.push_back(Array[0])    ;
        subset.push_back(base)  ;

        return ;
    }

    collect_subset(n-1) ;

    int sz = subset.size()  ;
    for(int i = 0; i < sz; i++){

        vector<int> cpy(subset[i])  ;
        cpy.push_back(Array[n-1]) ;
        subset.push_back(cpy) ;

    }
}

void print_subset(){

    for(int i = 0; i < subset.size(); i++){
        cout << "(" ;
        for(int j = 0; j < subset[i].size(); j++)
            cout << subset[i][j] << ',' ;
        cout << ")" ;
    }

}

int main(){

    subset.push_back(phi)   ; // empty subset

    for (int i = 0; i < 6; i++)             // Input array of integers, change accordingly
        Array[i] = i+1    ;

    collect_subset(6) ; // change 6 to size of your array, collects all the subset in a vectors of vectors, each vector of "subset" vector is a subset

    print_subset()  ;

    return 0    ;
}
