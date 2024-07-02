#include "../include/headerA3.h"

void recruitEmployee(struct employee **headLL)
{
    // declaring variables
    a3Emp *justTemp = NULL;
    a3Emp *newNode = NULL;
    char asker = 'y';
    char first[MAX_LENGTH];
    char last[MAX_LENGTH];
    int id = 0;
    int count = 0;
    char tempDep[MAX_LENGTH];
    int depLength = 0;

    // malloc a new node
    newNode = malloc(sizeof(a3Emp));

    // assigning head to the first linked list node
    if (*headLL == NULL)
    {
        *headLL = newNode;
    }
    // getting some user input
    printf("Enter the first name of the employee: ");
    scanf("%s", first);
    printf("Enter the last name of the employee: ");
    scanf("%s", last);

    // assigning values
    strcpy(newNode->fname, first);
    strcpy(newNode->lname, last);
    newNode->numDependents = 0;

    // while loop to keep asking for the dependents
    while (asker == 'Y' || asker == 'y')
    {
        if (newNode->numDependents == 0)
        {                                                               // for the first dependent
            newNode->dependents = malloc(sizeof(char *) * (count + 1)); // mallocs first char pointer
            printf("Enter name of dependent #1: ");
            scanf("%s", tempDep);
            printf("|%s|\n", tempDep);
            depLength = strlen(tempDep);
            // malloc to the length of the name after taking in input
            newNode->dependents[count] = malloc(sizeof(char) * (depLength + 1));
            strcpy(newNode->dependents[count], tempDep); // populate where its supposed to go
            newNode->numDependents++;
            count++; // increment numbers
        }
        else
        {                                                                                     // for the after ones
            newNode->dependents = realloc(newNode->dependents, sizeof(char *) * (count + 1)); // malloc plus 1 space
            printf("Enter name of dependent #%d: ", count + 1);
            scanf("%s", tempDep);
            depLength = strlen(tempDep);
            // malloc to the length of the name after taking in input
            newNode->dependents[count] = malloc(sizeof(char) * (depLength + 1));
            strcpy(newNode->dependents[count], tempDep);
            newNode->numDependents++;
            count++; // incrememnt numbers
        }
        // strcpy(newNode->dependents[count-1],tempDep);
        getchar();
        printf("Do you have any more dependents? Enter y or n: ");
        scanf("%c", &asker); // keep getting input
    }

    printf("You have %d dependants\n", newNode->numDependents);

    for (int i = 0; i < strlen(newNode->fname); i++)
    {
        id += (int)(newNode->fname[i]);
    }
    id += strlen(newNode->lname);
    newNode->empId = id;

    // bring the head back to the temp
    justTemp = *headLL;
    while (justTemp != *headLL && justTemp != NULL)
    { // skip the head
        if ((newNode->empId == justTemp->empId) && newNode != *headLL)
        {
            newNode->empId += rand() % 999 + 1; // add random number
        }
        justTemp = justTemp->nextEmployee;
    }
    // print the generated ID
    printf("Your computer generated ID is %d\n", newNode->empId);

    // bring the head back to the temp
    justTemp = *headLL;
    while ((newNode != *headLL) && justTemp->nextEmployee != NULL)
    {
        justTemp = justTemp->nextEmployee;
    }
    // traverse to the end of the linked list and link the node to the end
    justTemp->nextEmployee = newNode;
    newNode->nextEmployee = NULL;
}
