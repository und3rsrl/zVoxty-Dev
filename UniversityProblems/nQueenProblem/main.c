#include "solution.h"
// show result
int main()
{
    FILE *data = fopen("solutions.out","w");
    int option = 1;

    printf("\n\t\tInsert size of table : ");
    scanf("%d", &sizeOfPuzzle);
    int puzzle[sizeOfPuzzle][sizeOfPuzzle];
    int i, j;

    for(i = 0; i < sizeOfPuzzle; i++){
        for(j = 0; j < sizeOfPuzzle; j++){
            puzzle[i][j] = 0;
        }
    }

    while(option){

        system("CLS");
        display();
        scanf("%d", &choice);
        switch(choice){
            case 1:
                solveTheProblemInFile(data, puzzle,0);
                fclose(data);
                printf("\n\t\t File printed, close program  and  \n \t\t check solutions.out in your folder !\n");
                Sleep(3000);
                break;
            case 2:
                solveTheProblem(puzzle,0);
                Sleep(5000);
                break;
            case 3:
                main();
            case 4:
                exit(0);
                break;
        }
    }
    return 0;
}
