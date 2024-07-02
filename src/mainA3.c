#include "../include/headerA3.h"

int main()
{

    // declaring variables
    int userInput = 0;
    int whichPrint = 0;
    int searchId = 0;
    int func4 = 0;
    int func5 = 0;
    char func5search[MAX_LENGTH];
    int countEmp = 0;
    int func8Pos = 0;
    char fireAsk = ' ';
    a3Emp *head = NULL;

    // calling the initial loadEmp function
    loadEmpData(&head, "proFile.txt");

    do
    {
        // print menu
        printf("\n******************************************\n");
        printf("1. Add a new employee\n");
        printf("2. Print data of all employees\n");
        printf("3. Print data of the nth employee\n");
        printf("4. Search for employee based on empId\n");
        printf("5. Search for employee based on full name\n");
        printf("6. Count the total number of employees\n");
        printf("7. Sort the employees based on their empId\n");
        printf("8. Remove the nth employee in the current LL\n");
        printf("9. Remove all employees in the current LL\n");
        printf("10. Exit\n");
        printf("******************************************\n\n");

        // take in user option
        printf("Choose a menu option: ");
        scanf("%d", &userInput);

        switch (userInput)
        {
        case 1:
            recruitEmployee(&head); // no validation needed for func 1
            break;
        case 2:
            printAll(head); // no validation needed for func 2
            break;
        case 3:
            countEmp = countEmployees(head); // count employees
            if (head == NULL)
            {
                printf("The linked list is empty!\n"); // cover NULL case
            }
            else
            {
                do
                {
                    printf("Enter a position: ");
                    scanf("%d", &whichPrint); // take in input and continue to ask until a valid employee is inputted
                    if (whichPrint <= 0 || whichPrint > countEmp)
                    {
                        printf("Please enter a valid employee between 1 and %d!\n", countEmp);
                    }
                } while (whichPrint <= 0 || whichPrint > countEmp);

                // call function
                printOne(head, whichPrint);
            }
            break;
        case 4:
            printf("Enter an employee Id: ");
            scanf("%d", &searchId); // grab user input
            // call function
            func4 = lookOnId(head, searchId);
            if (func4 == -1)
            { // case where the linked list is NULL or no ID exists
                printf("No such employee ID exists in the system!\n");
            }
            else
            { // print position found
                printf("Position found in main: %d\n", func4);
            }
            break;
        case 5:
            // grab user input
            printf("Enter a name to find: ");
            getchar();
            fgets(func5search, 100, stdin);
            // call function
            func5 = lookOnFullName(head, func5search);
            if (func5 == -1)
            { // case where the linked list is NULL or no ID exists
                printf("No such employee name exists in the system!\n");
            }
            else
            { // print position found
                printf("Position found in main: %d\n", func5);
            }
            break;
        case 6:
            countEmp = countEmployees(head);
            // case where the head is NULL or there are no employees
            if (head == NULL || countEmp == 0)
            {
                printf("Your linked list is empty!\n");
            }
            else
            { // print number of emps
                printf("Number of employees = %d\n", countEmp);
            }
            break;
        case 7:
            if (head == NULL)
            { // cover NULL case
                printf("Your linked list is empty!\n");
            }
            else
            { // run sort employees
                sortEmployeesId(head);
            }
            break;
        case 8:
            countEmp = countEmployees(head);
            if (head == NULL || countEmp == 0)
            { // cover the case where the linked list is empty
                printf("The linked list is empty!\n");
            }
            else
            {
                do
                { // keep entering until a valid employee can be fired
                    printf("Enter the number of the employee to fire: ");
                    scanf("%d", &func8Pos);
                    if (func8Pos <= 0 || func8Pos > countEmp)
                    {
                        printf("Please enter a valid employee position!\n");
                    }
                } while (func8Pos <= 0 || func8Pos > countEmp);
                fireOne(&head, func8Pos); // fire said employee
            }
            break;
        case 9:
            if (head == NULL)
            { // cover NULL case
                printf("The linked list is empty!\n");
            }
            else
            { // double check user wants to fire all
                printf("Are you sure you want to fire all the employees? (Enter y if yes): ");
                getchar();
                scanf("%c", &fireAsk);
                if (fireAsk == 'y' || fireAsk == 'Y')
                {
                    fireAll(&head);
                    printf("Employees fired!\n");
                }
            }
            break;
        case 10:
            // exit program
            printf("Thank you! Exiting program...\n");
            break;
        default:
            printf("This is an invalid choice, please enter a valid one\n");
            break;
        }

    } while (userInput != 10); // while everything but exit condition is entered

    return 0;
}
