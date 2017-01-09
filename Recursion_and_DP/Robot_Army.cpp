#include <stdio.h>
#include <iostream>
#define N 5
#define M 5

using namespace std;

bool is_way(int r, int c, int gris[][M]){

    int possible[r][c]  ;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)                  // 0 --> "off limits"
            possible[i][j] = 0  ;                   // 2 --> reached

    possible[0][0] = 2  ;

    for (int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            if (possible[i][j] == 2){

                if(i+1 < N and j < M and gris[i+1][j] != 0) possible[i+1][j] = 2    ;
                if(i < N and j+1 < M and gris[i][j+1] != 0) possible[i][j+1] = 2    ;

    }


    if (possible[N-1][M-1] == 2)
        return true;
    return false;


}

int main(){

    int grid[N][M] = {

    {1, 1, 1, 1, 1},                // 1 means accessible, 0 means "off limit".
    {1, 1, 1, 0, 1},                    // start and finish will alway be accessible
    {1, 1, 0, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 0, 1}

    }    ;

    if (is_way(5, 5, grid))
        cout << "yes there is a way"    ;
    else
        cout << "no there isn't any"    ;

    return 0    ;
}
