/******************************************************************************
LinkList1.c
 * :
This file contains the 'main' function. Program execution begins ends
 * there.

*******************************************************************************/
#include "LinkListUtility.h"

Node *createLinkList(Node *list, insType tpye, int userData, int *arr,
                     int size)
{
  if (userData)
  {
    char ch = 'y';
    while (ch == 'y' || ch == 'Y')
    {
      int value;
      printf("Please Enter element in LinkList\n");
      scanf_s("%d", &value);

      if (list == NULL)
      {
        list = createNode(value);
      }
      else
      {
        list = insertNode(list, -1, value, tpye);
      }

      printf("Please press 'y' or 'Y' to continue\n");
      scanf_s(" %c", &ch, 1);
    }

    return list;
  }
  else
  {
    if (size <= 0)
    {
      printf("WARNINIG THE ARRAY IS EMPTY\tEXITING!!!\n");
      return list;
    }
    else
    {
      size--;
      while (size >= 0)
      {
        if (list == NULL)
        {
          list = createNode(arr[size]);
        }
        else
        {
          list = insertNode(list, -1, arr[size], !tpye);
        }
        size--;
      }
      return list;
    }
  }
}

int main()
{
  //This is the begining 
  //Hello to the QAIOR QA QIPL Team
  Node *start          = NULL;
  int arrValue[]       = { 11, 12, 13, 14, 15, 16 };
  unsigned int arrSize = sizeof(arrValue) / sizeof(arrValue[0]);
  start                = createLinkList(start, INS_ENDING, 0, arrValue, arrSize);
  //printLinkList(start,-1);

  start = NULL;
  start = insertNode(start, -1, 49, INS_BEGINING); //INS_BEGINING INS_ENDING INS_POSITION
  start = insertNode(start, -1, 164, INS_ENDING);
  start = insertNode(start, 2, 67, INS_POSITION);
  start = insertNode(start, 3, 99, INS_POSITION);
  printLinkList(start, 1);

  start = deleteNode(start, 1, -1, DEL_ENDING); //DEL_BEGINING DEL_ENDING DEL_POSITION
  printLinkList(start, -1);

  start = deleteNode(start, 1, -1, DEL_ENDING);
  printLinkList(start, -1);

  start = deleteNode(start, 0, -1, DEL_POSITION);
  printLinkList(start, -1);

  //start = deleteNode(start, -1, -1, DEL_BEGINING);
  //printLinkList(start, -1);

  //start = deleteNode(start, -1, -1, DEL_ENDING);
  //printLinkList(start, -1);

  //W8 Console
  char buf[15];
  gets(buf);
  return 0;
}
