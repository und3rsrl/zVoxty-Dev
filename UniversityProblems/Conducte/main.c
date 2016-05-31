#include <stdio.h>
#include <stdlib.h>

int nrNoduriVizitate;

void createAdiacentMatrix(FILE *data, int *matrix, int nrGauri, int nrConducte){
    int i, j, firstConduct, secondConduct, offset;
    while(nrConducte--){
        fscanf(data,"%d %d", &firstConduct, &secondConduct);
        offset = firstConduct * nrGauri + secondConduct;
        matrix[offset] = 1;
    }
}

void dfs(int *visitedVector,int *adiacentMatrix, int nrGauriDeAcces, int root){
    int i, offset;
    visitedVector[root] = 1;
    nrNoduriVizitate = nrNoduriVizitate+1;

    for(i = 0; i < nrGauriDeAcces; i++){
        offset = root * nrGauriDeAcces + i;
        if(adiacentMatrix[offset] == 1 && visitedVector[i] == 0){
            dfs(visitedVector, adiacentMatrix, nrGauriDeAcces, i);
        }
    }
}

int main()
{
    FILE *data = fopen("data.in","r");
    int i;
    if(data == NULL){
        printf("ERROR\n");
        exit(0);
    }

    int nrTeste;
    fscanf(data,"%d", &nrTeste);

    while(nrTeste--){
        int solutii = 0;
        int nrGauriDeAcces, nrConducte;
        fscanf(data, "%d %d", &nrGauriDeAcces, &nrConducte);
        int *matrix = (int*)calloc((size_t)(nrGauriDeAcces * nrGauriDeAcces), sizeof(int));

        createAdiacentMatrix(data, matrix, nrGauriDeAcces, nrConducte);

        for(i = 0; i < nrGauriDeAcces; i++){
            int *visitedVector = (int*) calloc((size_t) nrGauriDeAcces, sizeof(int));
            nrNoduriVizitate = 0;
            dfs(visitedVector, matrix, nrGauriDeAcces, i);
            if(nrNoduriVizitate == nrGauriDeAcces){
                solutii++;
            }
            free(visitedVector);
        }

        free(matrix);
        if(solutii == 0){
            printf("Nu !\n");
            exit(0);
        }
        printf("%d", solutii);
        printf("\n");
    }
    fclose(data);

    return 0;
}
