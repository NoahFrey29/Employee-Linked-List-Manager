#include "../include/headerA3.h"

void printOne(struct employee *headLL, int whichOne)
{

    // if the list is empty skip everything else
    if (headLL == NULL)
    {
        printf("Your linked list is empty!\n\n");
    }
    else
    {
        // declare variables
        int count = 1;
        int i;
        a3Emp *temp = NULL;

        temp = headLL;
        // traverse linked list and search for the correct position
        while (temp != NULL)
        {
            if (whichOne == count)
            { // print once found, same logic as printAll
                printf("Employee #%d:\n", count);
                printf("\tEmployee id: %d\n", temp->empId);
                printf("\tFirst name: %s\n", temp->fname);
                printf("\tLast name: %s\n", temp->lname);
                printf("\tDependents[%d]: ", temp->numDependents);

                for (i = 0; i < (temp->numDependents) - 1; i++)
                {
                    printf("%s, ", temp->dependents[i]);
                }

                printf("%s\n", temp->dependents[i]);
            }
            count++;
            temp = temp->nextEmployee;
        }
    }
}
