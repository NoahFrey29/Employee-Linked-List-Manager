#include "../include/headerA3.h"

void printAll(struct employee *headLL)
{

    // if head is null
    if (headLL == NULL)
    {
        printf("Your linked list is empty!\n\n");
    }
    else
    {
        // create variables
        int count = 0;
        int i;
        a3Emp *temp = NULL;

        temp = headLL;

        printf("Printing the full linked list:\n");

        // traversing linked list and printing everything
        while (temp != NULL)
        {
            printf("Employee #%d:\n", count + 1);
            printf("\tEmployee id: %d\n", temp->empId);
            printf("\tFirst name: %s\n", temp->fname);
            printf("\tLast name: %s\n", temp->lname);
            printf("\tDependents[%d]: ", temp->numDependents);

            // loop through up to the last dependent
            for (i = 0; i < (temp->numDependents) - 1; i++)
            {
                printf("%s, ", temp->dependents[i]);
            }

            // print last dependent, move temp forward
            printf("%s\n", temp->dependents[i]);
            count++;
            temp = temp->nextEmployee;
        }
    }
}
