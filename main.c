//Program takes an unsolved sudoku grid and uses backtracking algorithm to solve it, then prints results

#include <stdio.h>
#include <math.h>

//Definition of our grid size
#define GRIDSIZE 9

//Declare unsolved sudoku grid
int sudokuGrid[GRIDSIZE][GRIDSIZE] = {
        {6,0,9,0,0,0,0,1,0},
        {0,0,0,9,0,0,6,0,0},
        {2,7,0,0,4,0,0,3,0},
        {3,0,0,0,0,0,0,0,0},
        {8,0,6,2,0,0,0,0,9},
        {0,0,0,0,7,0,1,0,0},
        {0,0,0,0,0,1,7,0,5},
        {0,0,0,0,0,3,0,0,6},
        {0,9,0,0,0,2,0,0,0},
};

//Function to print the grid in a 9x9 array
void printGrid(){

    //Loop through grid and print
    for(int i = 0; i < GRIDSIZE; i++) {
        for(int j = 0; j < GRIDSIZE; j++) {
            if (j == 8) {
                printf("%d, \n", sudokuGrid[i][j]);
            } else {
                printf("%d, ", sudokuGrid[i][j]);
            }
        }
    }
}

//Function checks whether value can be added to sudoku grid at location
int checkValueValidAtLocation(int y, int x, int n){

    //Loop through grid in x axis
    for(int i = 0; i < 9; i++){
        if(sudokuGrid[y][i] == n) {
            return 0;
        }
    }

    //Loop through grid in y axis
    for(int i = 0; i < 9; i++){
        if(sudokuGrid[i][x] == n) {
            return 0;
        }
    }

    double dx0 = floor(x/3) * 3;
    double dy0 = floor(y/3) * 3;
    int x0 = floor(dx0);
    int y0 = floor(dy0);

    //Check that grid values are not repeated
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(sudokuGrid[y0 + 1][x0 + j] == n) {
                return 0;
            }
        }
    }

    //If none of the above return false then return true as value for grid location is valid
    return 1;

}

//Function to solve sudoku puzzle
void runAutoSolver(){

    //Nested for loops, loop through grid in y axis and x axis
    for(int y = 0; y < 9; y++) {
        for(int x = 0; x < 9; x++) {

            //Check whether grid location is empty
            if(sudokuGrid[y][x] == 0) {

                //Loop through all values 1-9 and check if they can be entered at grid location
                for(int n = 1; n < 10; n++) {

                    //Check whether it is checkValueValidAtLocation to enter character at grid location
                    if(checkValueValidAtLocation(y, x, n) == 1) {

                        //Set grid location to value n
                        sudokuGrid[y][x] = n;

                        //Call solve function recursively
                        runAutoSolver();
                        sudokuGrid[y][x] = 0;
                    }
                }
                //Break out of for loop
                return;
            }
        }
    }

    //Print out solved sudoku grid
    printf("\nSolved Sudoku Grid:\n");
    printGrid();

    //User input prompt to continue
    printf("\nMore solutions?\nPress ENTER to continue: ");

    //Wait for user to enter char
    getchar();

}

//Main function used to call all other functions
void main() {

    //Print out sudoku grid 9x9
    printf("Unsolved Sudoku Grid:\n");
    printGrid(sudokuGrid);

    //Solve our sudoku grid and print results
    runAutoSolver();

}