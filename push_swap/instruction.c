#include "linkeddeque.h"

void    ft_sa(LinkedDeque *a)
{
    int temp;

    temp = 0;
    if (a->currentElementCount <= 1)
    {
        return ;
    }
    temp = a->pRearNode->data;//top에서 2번째의 데이터 swap
    a->pRearNode->data = a->pRearNode->pLLink->data;
    a->pRearNode->pLLink->data = temp;//top노드의 데이터
}

void ft_sb(LinkedDeque *b)
{
    int temp;

    temp = 0;
    if (b->currentElementCount <= 1)
    {
        return ;
    }
    temp = b->pRearNode->data;//top에서 2번째의 데이터 swap
    b->pRearNode->data = b->pRearNode->pLLink->data;
    b->pRearNode->pLLink->data = temp;//top노드의 데이터
}

void ft_ss(LinkedDeque *a, LinkedDeque *b)
{
    ft_sa(a);
    ft_sb(b);
}

void ft_pa(LinkedDeque *a, LinkedDeque *b)
{
    DequeNode *temp;
    DequeNode insert;

    temp = deleteRearLD(b);
    if (temp != NULL)
    {
        insert.data = temp->data;
        insert.pLLink = NULL;
        insert.pRLink = NULL;
        insertRearLD(a, insert);
        free(temp);
    }
}

void ft_pb(LinkedDeque *a, LinkedDeque *b)
{
    DequeNode *temp;
    DequeNode insert;

    temp = deleteRearLD(a);
    if (temp != NULL)
    {
        insert.data = temp->data;
        insert.pLLink = NULL;
        insert.pRLink = NULL;
        insertRearLD(b, insert);
        free(temp);
    }
}

void ft_ra(LinkedDeque *a)
{
    a->pFrontNode = a->pFrontNode->pLLink;
    a->pRearNode = a->pRearNode->pLLink;
}

void ft_rb(LinkedDeque *b)
{
    b->pFrontNode = b->pFrontNode->pLLink;
    b->pRearNode = b->pRearNode->pLLink;
}

void ft_rr(LinkedDeque *a, LinkedDeque *b)
{
    ft_ra(a);
    ft_rb(b);
}

void ft_rra(LinkedDeque *a)
{
    a->pFrontNode = a->pFrontNode->pRLink;
    a->pRearNode = a->pRearNode->pRLink;
}

void ft_rrb(LinkedDeque *b)
{
    b->pFrontNode = b->pFrontNode->pRLink;
    b->pRearNode = b->pRearNode->pRLink;
}

void ft_rrr(LinkedDeque *a, LinkedDeque *b)
{
    ft_rra(a);
    ft_rrb(b);
}