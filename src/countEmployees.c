#include "../Employee-Linked-List-Manager/include/headerA3.h"

int countEmployees(a3Emp *headLL)
{

    // declare variables
    a3Emp *temp = NULL;
    int count = 0;
    temp = headLL;

    // move temp forward and increment counter
    while (temp != NULL)
    {
        count++;
        temp = temp->nextEmployee;
    }

    return count;
}
