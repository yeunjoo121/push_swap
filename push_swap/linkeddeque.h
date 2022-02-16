#ifndef _LINKED_DEQUE_
#define _LINKED_DEQUE_

typedef struct DequeNodeType
{
	int data;
	struct DequeNodeType* pRLink;
	struct DequeNodeType* pLLink;
} DequeNode;

typedef struct LinkedDequeType
{
	int currentElementCount;
	DequeNode* pFrontNode;
	DequeNode* pRearNode;
} LinkedDeque;

#include <stdio.h>
#include <stdlib.h>

LinkedDeque* createLinkedDeque();
int insertFrontLD(LinkedDeque* pDeque, DequeNode element);
int insertRearLD(LinkedDeque* pDeque, DequeNode element);
DequeNode* deleteFrontLD(LinkedDeque* pDeque);
DequeNode* deleteRearLD(LinkedDeque* pDeque);
DequeNode* peekFrontLD(LinkedDeque* pDeque);
DequeNode* peekRearLD(LinkedDeque* pDeque);
void deleteLinkedDeque(LinkedDeque* pDeque);
int isLinkedDequeFull(LinkedDeque* pDeque);
int isLinkedDequeEmpty(LinkedDeque* pDeque);
void displayLinkedDeque(LinkedDeque* pDeque);

void    ft_sa(LinkedDeque *a);
void	ft_sb(LinkedDeque *b);
void	ft_ss(LinkedDeque *a, LinkedDeque *b);
void ft_pa(LinkedDeque *a, LinkedDeque *b);
void ft_pb(LinkedDeque *a, LinkedDeque *b);
void ft_ra(LinkedDeque *a);
void ft_rb(LinkedDeque *b);
void ft_rr(LinkedDeque *a, LinkedDeque *b);
void ft_rra(LinkedDeque *a);
void ft_rrb(LinkedDeque *b);
void ft_rrr(LinkedDeque *a, LinkedDeque *b);

#endif

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE		1
#define FALSE		0

#endif