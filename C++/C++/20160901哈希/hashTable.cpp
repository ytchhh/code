#include<iostream>
#include"HashTable.h"


bool insert_1(HashNode *pht[],ElemType x)//back
{
  int index = Hash(x);

  HashNode *p = pht[index];
  HashNode *p1 = (HashNode*)malloc(sizeof(HashNode));
  p1 -> data = x;
  p -> next = p1;
  p1 -> next = NULL;
  pht[index] = p1;
  return true;
 /*
 HashNode *p,*p1,*p2;
 int index = hash(x);
 p1 = HashTable[index];
 p2 = p1 ->next;
 p = new HashNode;
 p -> data = x;
 p1 -> next = p;
 p -> next = p2;
 return true;
 */
}

int Hash(int data)
{
 int index = data % P;
 return index;
}
void ShowHashTable(HashTable pht)
{
  for (int i = 0; i < P; ++i)
      {
        cout<<""
      }
}
