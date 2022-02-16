#include "linkeddeque.h"

void test(void)
{
  LinkedDeque *a = createLinkedDeque();

  DequeNode DN0 = {0, NULL, NULL};
  DequeNode DN1 = {1, NULL, NULL};
  DequeNode DN2 = {2, NULL, NULL};
  DequeNode DN3 = {3, NULL, NULL};

  insertRearLD(a, DN2);
  insertRearLD(a, DN3);
  insertFrontLD(a, DN1);
  insertFrontLD(a, DN0);
  displayLinkedDeque(a);

  ft_rrb(a);

  displayLinkedDeque(a);
  //deleteLinkedDeque(a);
}

int main()
{
  test();
  system("leaks a.out");
  return (0);
}