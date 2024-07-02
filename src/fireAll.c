#include "../include/headerA3.h"

void fireAll(a3Emp **headLL)
{

    // null case for empty linked list
    if (*headLL == NULL)
    {
        printf("The linked list is empty!\n");
    }
    else
    {
        // make a temp
        a3Emp *temp = NULL;

        // traverse linked list and fire each as it goes along

        while (*headLL != NULL)
        {
            temp = *headLL;

            for (int i = 0; i < temp->numDependents; i++)
            {
                free(temp->dependents[i]);
            }
            free(temp->dependents);

            *headLL = temp->nextEmployee;
            free(temp);
        }
        free(*headLL);
    }
}
