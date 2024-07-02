#include "../include/headerA3.h"

int lookOnFullName(struct employee *headLL, char whichName[100])
{

    // declare variables
    a3Emp *temp = NULL;
    int count = 1;
    int i;
    char fName[MAX_LENGTH];
    char lName[MAX_LENGTH];

    temp = headLL;

    // split words into dummy variables
    sscanf(whichName, "%s %s", fName, lName);

    // traverse linked list
    while (temp != NULL)
    {

        // compare both first and last names, print once found
        if (strcmp(fName, temp->fname) == 0 && strcmp(lName, temp->lname) == 0)
        {
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
