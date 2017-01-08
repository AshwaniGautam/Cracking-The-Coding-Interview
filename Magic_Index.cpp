#include <stdio.h>
#include <iostream>
#define N 100000

using namespace std;

bool magic_index(int Array[], int low, int high){

	int mid = (low + high) / 2	;

	if(Array[mid] == mid)
		return true;

	if (low == high)
		return false;

	if(Array[mid] > mid)
		magic_index(Array, low, mid-1);

	else
		magic_index(Array, mid+1, high)	;
}

int main(){

	int Array[N];

    Array = {/*Enter elements in sorted(ascending) order*/}  ;

	printf("%d\n", magic_index(Array, 0, 8))	; // change 8 to your Array size - 1 (0-based indexing)

	return 0	;
}
