#include "../include/headerA3.h"

void sortEmployeesId(struct employee *headLL)
{

    // declaring variables
    a3Emp *temp = NULL;
    temp = headLL;
    a3Emp *newList = NULL;
    a3Emp *lowestTemp = NULL;
    a3Emp *before = NULL;
    a3Emp *after = NULL;
    int changed = 0;

    // make a copy of the linked list using the built in function
    newList = cpyLL(headLL);

    // finding the lowest item and making it the head
    lowestTemp = newList;
    a3Emp *currentTemp = newList;

    // set temp to the new list
    temp = newList;
    while (temp != NULL)
    {
        //	printf("Next employee id: %d\n", temp->nextEmployee->empId);
        // check that the node beyond isnt empty and then find if lowestTemp is bigger than it
        if ((temp->nextEmployee != NULL) && (lowestTemp->empId > temp->nextEmployee->empId))
        {
            // if yes, assign a before, lowest, and after
            before = temp;
            lowestTemp = temp->nextEmployee;
            after = temp->nextEmployee->nextEmployee;
            //            printf("After: %d\n", after->empId);
            changed = 1; // boolean variable gets changed
        }
        temp = temp->nextEmployee; // traverse linked list
    }
    if (changed != 0)
    { // if a change was made, relink everything
        newList = lowestTemp;
        newList->nextEmployee = currentTemp;
        before->nextEmployee = after;
    }

    // swap everything around
    a3Emp *swapList = newList;
    a3Emp *swapping = NULL;

    while (swapList->nextEmployee != NULL)
    {
        // if 2 nodes ahead is not empty and if the node ahead is bigger than 2 nodes ahead
        if ((swapList->nextEmployee->nextEmployee != NULL) && (swapList->nextEmployee->empId > swapList->nextEmployee->nextEmployee->empId))
        {
            // assign a before, current, and after
            before = swapList;
            swapping = swapList->nextEmployee;
            after = swapList->nextEmployee->nextEmployee;
            // relink all of them
            swapping->nextEmployee = after->nextEmployee;
            after->nextEmployee = swapping;
            before->nextEmployee = after;
            swapList = newList; // reset back to the beginning
        }
        else
        { // if not, move onto next node
            swapList = swapList->nextEmployee;
        }
    }

    // print the new swapped list
    printf("New swapped list:\n");
    printAll(newList);

    // fire said list
    fireAll(&newList);
}

/*Function that takes in a linked list head and copies it into a new head*/
a3Emp *cpyLL(struct employee *headLL)
{

    // if the head is empty, return NULL
    if (headLL == NULL)
    {
        return NULL;
    }
    else
    {
        a3Emp *node = NULL;

        // malloc space for a new node
        node = malloc(sizeof(a3Emp));
        node->dependents = malloc(sizeof(char *) * (headLL->numDependents));
        for (int i = 0; i < headLL->numDependents; i++)
        {
            node->dependents[i] = malloc(sizeof(char) * strlen(headLL->dependents[i]) + 1);
        }

        // populate the stuff you need to populate
        strcpy(node->fname, headLL->fname);
        strcpy(node->lname, headLL->lname);
        node->empId = headLL->empId;
        node->numDependents = headLL->numDependents;

        for (int i = 0; i < node->numDependents; i++)
        {
            strcpy(node->dependents[i], headLL->dependents[i]);
        }

        // call the function at the next->employee recursively
        node->nextEmployee = cpyLL(headLL->nextEmployee);
        return node;
    }
}
