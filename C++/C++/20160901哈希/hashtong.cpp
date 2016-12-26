int insert_new_element(int new_element)
{
 int index = Hash(new_element);
 HashNode *p ;
 p = HashTable[index];
 while (p -> next != NULL)
 {
  p = p -> next;
 }
 for (int i = 0;i < 3 ; )
 {
  if (p -> a[i] != 0)
      i++;
  else
    break;
 }
 if (i < 3)
 p -> a[i] = new_element;
 else 
  {
   HashNode *p1 = new HashNode;
   p1 -> a[0] = new_element;
   p -> next = p1;
  }
  return 1;
}
