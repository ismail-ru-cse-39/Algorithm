//Rat in maze using backtracking


#include <bits/stdc++.h>

using namespace std;
#define sc(a) scanf("%d")
#define N 4 //maze size

bool Maze_path_check(int maze[N][N], int x, int y, int sol[N][N]);

//Function to print the final solution(maze)
void printFinalSolution(int sol[N][N]){

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            printf("%d ",sol[i][j]);
        }
        printf("\n");
    }


}

//A function to check the validity of x,y
bool Check_boundary(int maze[N][N], int x, int y){
    if(x >= 0 && x < N && y>=0 && y < N && maze[x][y] == 1){
        return true;
    }

    return false;

}


bool Solve(int maze[N][N]){
    int sol[N][N] = {{0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
    };


    if( Maze_path_check(maze, 0, 0, sol) == false){

        cout<<"Solution is not possible"<<endl;

        return false;
    }
    printFinalSolution(sol);

    return true;

}

bool  Maze_path_check(int maze[N][N], int x, int y, int sol[N][N]){

    if(x == N-1 && y == N-1){
        sol[x][y] = 1;
        return true;
    }

    if(Check_boundary(maze,x, y) == true){
        sol[x][y] = 1;


        //checking forward for valid path
        if(Maze_path_check(maze, x+1, y, sol) == true){
            return true;
        }

        //if checking forward does not give path then,
        //we should check downward;

        if(Maze_path_check(maze, x, y+1, sol) == true){
            return true;
        }

        //putting 0 in sol as there is no such valid path from x,y;
        sol[x][y] = 0;

        return false;
    }

    return false;
}


int main()
{
     //creating maze;
     int maze[N][N]  =  { {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    Solve(maze);

    return 0;
}

