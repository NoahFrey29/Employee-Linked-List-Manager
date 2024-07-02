#include "../include/headerA3.h"

void fireOne(a3Emp **headLL, int whichOne)
{

    // declare new nodes
    a3Emp *temp = NULL;
    a3Emp *before = NULL;
    a3Emp *target = NULL;
    a3Emp *after = NULL;
    temp = *headLL;

    if (whichOne == 1)
    {
        // do procedure when head has to be deleted
        *headLL = temp->nextEmployee;
        // free dependents
        for (int i = 0; i < temp->numDependents; i++)
        {
            free(temp->dependents[i]);
        }
        free(temp->dependents);
        // free node
        free(temp);
    }
    else
    {
        // else procedure
        for (int i = 1; i < (whichOne - 1); i++)
        {
            temp = temp->nextEmployee; // loop through to the element before the target
        }
        // assign the before, target, and after values
        before = temp;
        target = temp->nextEmployee;
        after = temp->nextEmployee->nextEmployee;
        // free target

        for (int i = 0; i < target->numDependents; i++)
        {
            free(target->dependents[i]);
        }
        free(target->dependents);

        free(target);

        // link before -> after
        before->nextEmployee = after;
    }
    // print display message
    printf("Employee #%d has been fired!\n", whichOne);
}
