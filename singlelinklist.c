#include <stdio.h>
#include <malloc.h>

struct student
{
    int roll;
    char name[10];
    struct student *next;
} *start;

struct student *createnode()
{
    struct student *newnode;
    newnode = (struct student *)malloc(sizeof(struct student));
    printf("enter roll and Name : ");
    scanf("%d %s", &newnode->roll, &newnode->name);
    newnode->next = NULL;
    return (newnode);
}

void createlinklist()
{
    struct student *newnode, *pmt;
    newnode = createnode();
    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        pmt = start;
        while (pmt->next != NULL)
        {
            pmt = pmt->next;
        }

        pmt->next = newnode;
    }
}

void display()
{
    struct student *pmt;
    pmt = start;
    if (start == NULL)
    {
        printf("linklist is not exist : ");
    }
    else
    {
        while (pmt != NULL)
        {
            printf("roll no is %d    %s \n", pmt->roll, pmt->name);
            pmt = pmt->next;
        }
    }
}

void insetInFirst()
{
    struct student *newnode;
    newnode = createnode();
    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        newnode->next = start;
        start = newnode;
    }
}

void insertAtDesireNodeAfter()
{
    int n, i = 1;
    printf("enter node no to which after insert nod : ");
    scanf("%d", &n);
    struct student *newnode, *pmt;
    newnode = createnode();
    pmt = start;
    while (i != n && pmt->next != NULL)
    {
        i++;
        pmt = pmt->next;
    }

    if (i != n)
    {
        printf("your no is over on linklist size ");
    }
    else if (pmt->next != NULL)
    {
        newnode->next = pmt->next;
        pmt->next = newnode;
    }
    else
    {
        createlinklist();
    }
}

void insertAtDesireNodeBefore()
{
    int n, i = 1;
    printf("enter node no to which after insert nod : ");
    scanf("%d", &n);
    n = n - 1;
    struct student *newnode, *pmt;
    newnode = createnode();
    pmt = start;

    if (n == 0)
    {
        insetInFirst();
    }
    else
    {
        while (i != n && pmt->next != NULL)
        {
            i++;
            pmt = pmt->next;
        }
        if (i == n)
        {
            newnode->next = pmt->next;
            pmt->next = newnode;
        }
        else
        {
            printf("your no is over on link list size ");
        }
    }
}

void deleteAtFirst()
{
    struct student *pmt;
    if (start == NULL)
    {
        printf("linklist is not exist ");
    }
    else
    {
        pmt = start;
        printf("successfull delete roll no is %d and name is %s  ", pmt->roll, pmt->name);
        start = start->next;
        free(pmt);
    }
}

void deleteAtLast()
{
    //                              one last element delete then exit code why?
    struct student *pmt, *prev;
    pmt = start;
    if (start == NULL)
    {
        printf("linklist is not exist \n");
    }
    else if (pmt->next == NULL)
    {
        free(pmt);
    }
    else
    {

        while (pmt->next != NULL)
        {
            prev = pmt;
            pmt = pmt->next;
        }
        prev->next = NULL;
        free(pmt);
    }
}

void deleteAtDesirePosition()
{
    int n, i = 1;
    printf("enter desire node no to delete : ");
    scanf("%d", &n);
    struct student *pmt, *prev;
    if (n == 1)
    {
        deleteAtFirst();
    }
    else
    {
        pmt = start;
        while (i != n && pmt->next != NULL)
        {
            i++;
            prev = pmt;
            pmt = pmt->next;
        }
        if (i != n)
        {
            printf("your node no  is over on link list size ");
        }
        else
        {
            prev->next = pmt->next;
            free(pmt);
        }
    }
}

void findLinkListSize()
{
    struct student *ptr;
    ptr = start;
    int i = 1;
    if (start == NULL)
    {
        printf("link list is not exist ");
    }
    else
    {

        while (ptr->next != NULL)
        {
            i++;
            ptr = ptr->next;
        }
    }

    printf("Link list size is %d : ", i);
}

void linearSearch()
{
    int n;
    struct student *pmt;
    printf("enter roll no which is search you : ");
    scanf("%d", &n);

    if (start == NULL)
    {
        printf("linklist is not exist ");
    }
    else
    {
        pmt = start;
        while (pmt->roll != n && pmt->next!=NULL)
        {
            pmt = pmt->next;
        }

        if (pmt->roll == n)
        {
            printf("\n\n This roll no is match \nroll no is %d   %s \n\n", pmt->roll, pmt->name);
        }
        else
        {
            printf("\n\nroll no is not match plz enter right roll no OK \n\n");
        }
    }
}

int main()
{
    int k;
    do
    {
        printf("\npress 1 to create linklist \n");
        printf("press 2 to display \n");
        printf("Press 3 to isert in first \n");
        printf("Press 4 to insert at desire node after data : \n");
        printf("press 5 to insert data at desire node before \n");
        printf("press 6 to delete first node \n");
        printf("press 7 to delete last node \n");
        printf("press 8 to desire node delete \n");
        printf("press 9 to find link list size \n");
        printf("press 10 to search roll no \n");
        scanf("%d", &k);
        switch (k)
        {
        case 1:
            createlinklist();
            break;

        case 2:
            display();
            break;

        case 3:
            insetInFirst();
            break;

        case 4:
            insertAtDesireNodeAfter();
            break;

        case 5:
            insertAtDesireNodeBefore();
            break;

        case 6:
            deleteAtFirst();
            break;

        case 7:
            deleteAtLast();
            break;

        case 8:
            deleteAtDesirePosition();
            break;

        case 9:
            findLinkListSize();
            break;

        case 10: linearSearch();;
                break;
        }
    } while (k != 11);
}