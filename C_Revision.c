#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#define addGlobalFuncs 98

#ifdef addGlobalFuncs

//some arithmetic functions, later used in array of fucntion pointers
int add(int x, int y)
{
    return x+y;
}

int sub(int x, int y)
{
    return x-y;
}

int mul(int x, int y)
{
    return x*y;
}

int divv(int x, int y)
{
    return x/y;
}

void calculator(int (*func)(int, int), int x , int y)
{
    int ans=(*func)(x, y);
    printf("answer is %d\n", ans);
}

//array of function pointers
int arithmetic(char comm, int x, int y)
{
    int (*options[4])(int, int) = {add, sub, mul, divv};
    switch (comm)
    {
    case 'a':
        return options[0](x, y);
        break;
    case 's':
        return options[1](x, y);
        break;
    case 'm':
        return options[2](x, y);
        break;
    case 'd':
        return options[3](x, y);
        break;
    default:
        printf("wrong command entered");
        return 0;
        break;
    }
}

//Bit manipulation functions
void bitEnable(int *number, int bitno)
{
    if(bitno!=0)
    {
        int bit=bitno-1;
        *number= (*number)|(1<<bit);
    }
}

void bitDisable(int *number, int bitno)
{
    if(bitno!=0)
    {
        int bit=bitno-1;
        *number=*number&~(1<<bit);
    }
}

void toggleAbit(int *number, int bitno)
{
    if(bitno!=0)
    {
        int bit=bitno-1;
        *number=*number^(1<<bit);
    }
}

void checkAbit(int *number, int bitno)
{
    if(bitno!=0)
    {
        int bit=bitno-1;
        int result=*number&(1<<bit);
        if(result)
            printf("bit %d is set\n", bitno);
        else
            printf("bit %d is clear\n", bitno);
    }
}

//String Functions and their utility
void strfuncs2()
{
    char str1[100], str2[100]="Super Nova";
    strcpy(str1, str2);
    printf("str1 is filled with the phrase '%s'\n", str1);
    //strncpy is same as strcpy except its allows the first n
    //characters to be copied
    str1[0]='Y';
    printf("str1 is filled with the phrase '%s'\n", str1);
    strncpy(str1, str2, 5);
    printf("str1 is filled with the phrase '%s'\n", str1);
    //strcat: string concatenation
    strcpy(str1, "Umair ");
    strcpy(str2, "Akram");
    strcat(str1, str2);
    printf("My name is %s\n", str1);
    //strncat: string concatenation of n characters to destination string
    strcpy(str1, "Batting");
    strcpy(str2, "Batting");
    strncat(str1, str2, 3);
    printf("%s\n", str1);
    //compare the two strings lexicographically
    int compval=strcmp(str1, str2);// note: theres garbage at the end of each str var, so they might look equal but strcmp wont tell
    if(compval==0)
        printf("overall, both strings equal\n");
    else if (compval>0)
    {
        printf("overall, str1 is greater than str2\n");
    }
    else
    {
        printf("overall, str2 is greater than str1\n");
    }
    //strncmp: compare the first n characters of both strings
    compval=strncmp(str1, str2, 7);
    if(compval==0)
        printf("for first 7 chars, both strings equal\n");
    else if (compval>0)
    {
        printf("for first 7 chars, str1 is greater than str2\n");
    }
    else
    {
        printf("for first 7 chars, str2 is greater than str1\n");
    }
    //strchr: to find first occurence of a character
    char *ptrr=strchr(str1, 't');
    printf("the first t is at index %d of str1\n", ptrr-str1);
    ptrr=strrchr(str1, 't');
    printf("the last t is at index %d of str1\n", ptrr-str1);
    //strstr:
    char* ptt= strstr(str1, "Bat");
    printf("the word 'bat' starts at index %d of str1\n", ptt-str1);
    //sprint:
    int accno=9457; char named[50]="umair"; int balance=50000;
    char info[200];
    sprintf(info, "Name is %s, account number: %d, Balance: %d\n", named, accno, balance);
    printf("%s", info);
}


//linked list implementation
typedef struct node
{
    int val;
    struct node *next;
}node;

node* createALinkedList(int val)
{
    node* newNode=(node*)malloc(sizeof(node));
    newNode->val=val;
    newNode->next=NULL;
    return newNode;
}

void addToLinkedList(node** pointerToHeadAddress, int val)
{
    node* temp=*pointerToHeadAddress;

    if(temp==NULL)
    {
        printf("no linked list found, first use createALinkedList func\n");
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        node* newNode=(node*)malloc(sizeof(node));
        newNode->val=val;
        newNode->next=NULL;
        temp->next=newNode;
    }
}

void deleteAnode(node** pointerToHeadAddress, int nodeNo)
{
    node* temp=*pointerToHeadAddress;
    if(temp==NULL)
    {
        printf("no linked list found, first use createALinkedList func\n");
    }
    else if(nodeNo<1)
    {
        printf("node doesnt exist, please enter a correct node number\n");
        return;
    }
    else if(nodeNo==1)
    {
        node* toBeDel=*pointerToHeadAddress;
        *pointerToHeadAddress=temp->next;
        free(toBeDel);
    }
    else
    {
        int currentNodeNo=1;
        while(currentNodeNo!=nodeNo-1)
        {
            temp=temp->next;
            if (temp->next==NULL)
            {
                printf("node doesnt exist, please enter a correct node number\n");
                return;
            }
            currentNodeNo++;
        }
        node* nodeToBeDel=temp->next;
        temp->next=temp->next->next;
        free(nodeToBeDel);
        return;
    }
}

void printAlist(node** pointerToHeadAddress)
{
    node* temp=*pointerToHeadAddress;
    if(temp==NULL)
    {
        printf("no linked list found, first use createALinkedList func\n");
        return;
    }
    else
    {
        printf("Linked List as follows:\n");
        while(temp!=NULL)
        {
            printf("%d\n", temp->val);
            temp=temp->next;
        }
        return;
    }
}

#endif
void main()
{
    int x=2;
    switch(x)
    {
        case 1:
            printf("x is 1\n");
            break;
        case 2:
            printf("x is 2\n");
            break;
        default:
            printf("x is neither 1 or 2");
            break;
    }

    //loops, while, do-while
    int inc=0;
    for(int i=0; i<5; i++)
    {
        inc++;
    }

    while(inc!=0)
    {
        inc--;
    }

    do
    {
        inc++;
    }
    while(inc!=1);

    int *temp=(int*)malloc(sizeof(int));
    *temp=5;
    int **doublePtr=&temp;

    free(doublePtr);
    free(temp);

    int bit8no=8;
    checkAbit(&bit8no, 3);
    //printf("%d", bit8no);

    char word[100];
    sprintf(word, "%s is %d", "My age", 22);
    //printf("%s", word);

    void *ptrr= &bit8no;
    //printf("bit8no's address: %d\n", ptrr);

    char phrase[100], phrase2[100], phrase3[100];
    int digits;
    
    sscanf(word, "%s %s %s %d", &phrase, &phrase2, &phrase3, &digits);
    //printf("%s %s %s %d\n", phrase, phrase2, phrase3, digits);

    node* firstNode=createALinkedList(5);
    addToLinkedList(&firstNode, 3);
    addToLinkedList(&firstNode, 1);
    addToLinkedList(&firstNode, 1);

    node *yoyo=NULL;

    printAlist(&firstNode);
    deleteAnode(&firstNode,2);
    printAlist(&firstNode);

    calculator(divv, 2,3);
}
