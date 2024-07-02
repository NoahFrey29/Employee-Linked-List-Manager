#include "../include/headerA3.h"

int lookOnId(struct employee *headLL, int whichEmpId)
{

    // declare variables
    a3Emp *temp = NULL;
    int count = 1;
    int i;

    temp = headLL;

    // traverse the linked list
    while (temp != NULL)
    {
        if (temp->empId == whichEmpId)
        { // search for the empId at the current temp
            // print once found
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
            // return once found
            return count;
        }
        count++;
        // traverse linked list
        temp = temp->nextEmployee;
    }
    // else return -1
    return -1;
}
