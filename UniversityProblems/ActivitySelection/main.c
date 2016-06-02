#include<stdio.h>

// Prints a maximum set of activities that can be done by a single
// person, one at a time.
//  n   -->  Total number of activities
//  s[] -->  An array that contains start time of all activities
//  f[] -->  An array that contains finish time of all activities
void printMaxActivities(int s[], int f[], int n)
{
    int i, j;

    printf ("Following activities are selected \n");

    // The first activity always gets selected
    i = 0;  //incepem cu prima activitate
    printf("%d ", i);

    // Consider rest of the activities
    for (j = 1; j < n; j++) // pornim de la a doua activitate si
    {
      // If this activity has start time greater than or
      // equal to the finish time of previously selected
      // activity, then select it
      if (s[j] >= f[i]) //vedem daca start time-ul este mai mare sau egal decat finish time-ul activitatii precedente
      {
          printf ("%d ", j); // afisam activitatea pe care o putem face in continuare
          i = j; // si o atribuim lui i dupa care reluam pasii precedenti pt aceasta activitate
      }
    }
}

// driver program to test above function
int main()
{
    int s[] =  {1, 3, 0, 5, 8, 5}; // start time-ul activitatilor
    int f[] =  {2, 4, 6, 7, 9, 9};  // finish time-ul activitatilor
    int n = sizeof(s)/sizeof(s[0]); // numarul de activitati
    printMaxActivities(s, f, n);
    getchar();
    return 0;
}
