#include <stdio.h>
#include <stdlib.h>
#include "singly-linked-list.h"

int main(int argc, char const *argv[])
{
  list list1 = lst_create();
  list list2 = lst_create();
  list list3 = lst_create();
  list copy;

  list1 = lst_insertion(list1, 1);
  lst_add(&list1, 2);
  lst_add_ord(&list1, 0);

  lst_print(list1);
  lst_print_rec(list1);

  printf("%d\n", is_empty(list2));
  printf("%d\n", is_equal(list1, list2));

  
  return 0;
}
