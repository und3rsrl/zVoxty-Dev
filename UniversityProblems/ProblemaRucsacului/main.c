#include <stdio.h>

typedef struct Items{
    char *idItem;
    int weight;
    float value;
    float density;
}Item;

void insertData(Item *itemz, char *idItem, int weight, float value, float density){
    itemz->idItem = idItem;
    itemz->weight = weight;
    itemz->value = value;
    itemz->density = density;
}

void insertion(int *a,int n){
    int i,j;
    float aux;
    for(i=0; i<n ; i++){
        j=i;                                //
        while(j > 0 && a[j-1] > a[j]){
            aux = a[j];
            a[j] = a[j-1];
            a[j-1] = aux;
            j--;
        }
    }
}

void solveKnapsack(Item *itemz, int numberOfItems, int KnapsackWeight){
    float totalWeight = 0, totalBenefit = 0;
    int tempWeight, value;
    int i;

    for(i = 0; i < numberOfItems; i++){
        if(itemz[i].weight + totalWeight <= KnapsackWeight){
            totalWeight += itemz[i].weight;
            totalBenefit += itemz[i].value;
            printf("Selected Item: %s, Weight: %d, Value: %0.2f, Total Weight: %0.2f, Total Benefit: %0.2f\n", itemz[i].idItem, itemz[i].weight, itemz[i].value, totalWeight, totalBenefit);
        }
        else{
            /* Enable if you want fractional knapsack
            tempWeight = (KnapsackWeight - totalWeight);
            value = tempWeight * (itemz[i].value / itemz[i].weight);

            totalWeight += tempWeight;
            totalBenefit += value;
            printf("Selected Item: %s, Weight: %d, Value: %0.2f, Total Weight: %0.2f, Total Benefit: %0.2f\n", itemz[i].idItem, itemz[i].weight, itemz[i].value, totalWeight, totalBenefit);
            */
            break;
        }
    }

    printf("Total Weight: %0.2f\n", totalWeight);
	printf("Total Benefit: %0.2f\n", totalBenefit);
}

int main(){
    int i, j;
    int numberOfElements;
    int knapsackWeight;
    char idItem[20];
    int weight;
    float value;
    float density;

    printf("Number of elements : ");
    scanf("%d", &numberOfElements);

    printf("Insert knapsack weight : ");
    scanf("%d", &knapsackWeight);

    Item items[numberOfElements+1];

    for(i = 0; i < numberOfElements; i++){
        printf("Insert (itemId) (weightItem) (valueId) : ");
        scanf("%s %d %f", &idItem, &weight, &value);
        printf("\n");
        density = value / weight;
        insertData(&items[i], idItem, weight, value, density);
       // printf("Item %d : %s, weightItem: %d, valueItem: %0.2f, densityItem: %0.2f \n", i+1, items[i].idItem, items[i].weight, items[i].value, items[i].density);
    }

    for(i = 1; i < numberOfElements; i++) {
		for(j = 0; j < numberOfElements - i; j++) {
			if(items[j+1].density > items[j].density) {
				Item temp = items[j+1];
				items[j+1] = items[j];
				items[j] = temp;
			}
		}
	}

	solveKnapsack(items, numberOfElements, knapsackWeight);

    return 0;
}
