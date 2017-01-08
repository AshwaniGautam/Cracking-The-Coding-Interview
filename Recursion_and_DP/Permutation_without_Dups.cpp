#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#define N 100000
using namespace std;

// Code taken/plagiarised from geeksforgeeks.com

void swap(char * f, char * t){

    char temp   ;
    temp = *f   ;
    *f = *t     ;
    *t = temp   ;

}

void print_permutation(char str[], int low, int high){

    if(low == high){
        cout << str << endl;
        return ;
    }

    for(int i = low; i <= high; i++){

        swap(str+low, str+i)    ;
        print_permutation(str, low+1, high) ;
        swap(str+low, str+i) ;

    }
}

int main(){

    char str[] = "string"  ;// Replace with string of your choice

    print_permutation(str, 0, strlen(str)-1)  ;

    return 0    ;
}
