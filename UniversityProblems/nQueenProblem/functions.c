/* N QUEEN Problem */
#include "solution.h"

bool found_sol(int puzzle[sizeOfPuzzle][sizeOfPuzzle], int line, int col)
{
    int i, j;
    /* Check this line on left side */
    for (i = 0; i < col; i++)
        if (puzzle[line][i])
            return false;
    /* Check upper diagonal on left side */
    for (i=line, j=col; i>=0 && j>=0; i--, j--)
        if (puzzle[i][j])
            return false;
    /* Check lower diagonal on left side */
    for (i=line, j=col; j>=0 && i<sizeOfPuzzle; i++, j--)
        if (puzzle[i][j])
            return false;
    return true;
}

/* Print solution */
void showSol(int puzzle[sizeOfPuzzle][sizeOfPuzzle])
{
    int i,j ;
    for ( i = 0; i < sizeOfPuzzle; i++)
    {
        for (j = 0; j < sizeOfPuzzle; j++)
            printf(" %d ", puzzle[i][j]);
            printf("\n");
    }
}

void showSolInFile(FILE *data, int puzzle[sizeOfPuzzle][sizeOfPuzzle],int sizeOfPuzzle)
{
    int i,j ;
    for ( i = 0; i < sizeOfPuzzle; i++)
    {
        for (j = 0; j < sizeOfPuzzle; j++)
            fprintf(data, " %d ", puzzle[i][j]);
            fprintf(data, "\n");
    }
}

/* A utility function to check if a queen can
   be placed on puzzle[line][col]. Note that this
   function is called when "col" queens are
   already placed in columns from 0 to col -1.
   So we need to check only left side for
   attacking queens */

/* Recursive  function*/
bool solveTheProblem(int puzzle[sizeOfPuzzle][sizeOfPuzzle], int col)
{

    /* If all queens are placed
      then return true */
    if (col >= sizeOfPuzzle){
       // return true;
        showSol(puzzle);
        printf("\n");
    }
    /* Consider this column and try placing
       this queen in all lines one by one */
       int i;
    for (i = 0; i < sizeOfPuzzle; i++)
    {
        /* Check if queen can be placed on
          board[i][col] */
        if ( found_sol(puzzle, i, col) )
        {
            /* Place this queen in board[i][col] */
            puzzle[i][col] = 1;
            /* recur to place rest of the queens */
            if ( solveTheProblem(puzzle, col + 1) ){
                showSol(puzzle);
                printf("\n");
            }

            /* If placing queen in board[i][col]
               doesn't lead to a solution, then
               remove queen from board[i][col] */
            puzzle[i][col] = 0; // BACKTRACKING
        }
    }
     /* If queen can not be place in any line in
        this colum col  then return false */
    return false;
}

bool solveTheProblemInFile(FILE *data, int puzzle[sizeOfPuzzle][sizeOfPuzzle], int col)
{



    /* If all queens are placed
      then return true */
    if (col >= sizeOfPuzzle){
       // return true;
        showSolInFile(data, puzzle,sizeOfPuzzle);
        fprintf(data ,"\n");
    }
    /* Consider this column and try placing
       this queen in all lines one by one */
       int i;
    for (i = 0; i < sizeOfPuzzle; i++)
    {
        /* Check if queen can be placed on
          board[i][col] */
        if ( found_sol(puzzle, i, col) )
        {
            /* Place this queen in board[i][col] */
            puzzle[i][col] = 1;
            /* recur to place rest of the queens */
            if ( solveTheProblemInFile(data, puzzle, col + 1) ){
                showSolInFile(data, puzzle, sizeOfPuzzle);
                fprintf(data ,"\n");
            }

            /* If placing queen in board[i][col]
               doesn't lead to a solution, then
               remove queen from board[i][col] */
            puzzle[i][col] = 0; // BACKTRACKING
        }
    }
     /* If queen can not be place in any line in
        this colum col  then return false */
    return false;

}

/* This function returns false if queens
   cannot be placed, otherwise return true and
   prints placement of queens in the form of 1s. */

void display(){
    printf("\t\t Queen Problem \n");
    printf("\t\t 1) Print solution in file !\n");
    printf("\t\t 2) Print solution in console !\n");
    printf("\t\t 3) Restart program .\n");
    printf("\t\t 4) Exit program .\n");
    printf("\t\t Insert your choice : ");
}
