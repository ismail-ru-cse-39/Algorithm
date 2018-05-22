/*If all squares are visited
    print the solution
Else
   a) Add one of the next moves to solution vector and recursively
   check if this move leads to a solution. (A Knight can make maximum
   eight moves. We choose one of the 8 moves in this step).
   b) If the move chosen in the above step doesn't lead to a solution
   then remove this move from the solution vector and try other
   alternative moves.
   c) If none of the alternatives work then return false (Returning false
   will remove the previously added item in recursion and if false is
   returned by the initial call of recursion then "no solution exists" )
   */



#include <bits/stdc++.h>

using namespace std;
#define N 8

int knightTourBacktracking(int x, int y,int mov_cnt, int mov[N][N], int mov_in_x[N], int mov_in_y[N]);

//A function to check the bound

bool checkBound(int x, int y, int mov[N][N])
{
    return (x >= 0 && x < N && y >= 0 && y < N && mov[x][y] == -1);

}

//Function to print solution matrix

void printSolution(int mov[N][N])
{
    for(int i = 0 ; i < N ; i++){
        for(int j = 0; j < N ; j++){
            printf("%2d ",mov[i][j]);
        }
        printf("\n");
    }
}

bool solveKnightTour()
{
    int mov[N][N];

    //Initializing solution matrix

    for(int i = 0; i < N; i++){
        for(int j = 0 ; j < N ; j++){
            mov[i][j] = -1;
        }
    }

    //mov_in_x[] and mov_in_y[] define next move of knight in x axis and y axis

    int mov_in_x[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int mov_in_y[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    mov[0][0] = 0;
    //start from 0,0 and explore all tours using knightTourBacktracking()

    if(knightTourBacktracking(0, 0, 1, mov,mov_in_x, mov_in_y)== false){
        printf("Solution does not exist\n");
        return false;
    }
    else{
        printSolution(mov);
    }

    return true;
}

int knightTourBacktracking(int x, int y,int mov_cnt, int mov[N][N], int mov_in_x[N], int mov_in_y[N])
{
    int k,next_x,next_y;

    if(mov_cnt == N*N){
        return true;
    }
    //Try all next move from current position

    for(k = 0; k < 8 ; k++){
        next_x = x + mov_in_x[k];
        next_y = y + mov_in_y[k];

        if(checkBound(next_x, next_y, mov)){
            mov[next_x][next_y] = mov_cnt;

            if(knightTourBacktracking(next_x,next_y,mov_cnt+1,mov,mov_in_x,mov_in_y)== true){
                return true;
            }
            else{
                mov[next_x][next_y] = -1;//backtracking
            }
        }
    }

    return false;
}

int main()
{
    solveKnightTour();
    return 0;
}
