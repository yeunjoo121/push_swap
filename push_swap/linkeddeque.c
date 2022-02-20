#include "linkeddeque.h"

LinkedDeque* createLinkedDeque()
{
  LinkedDeque *pReturn;
  pReturn = (LinkedDeque *)calloc(1, sizeof(LinkedDeque));
  if (pReturn == NULL)
  {
    printf("malloc failure\n");
    return (NULL);
  }
  return (pReturn);
}

int insertFrontLD(LinkedDeque* pDeque, DequeNode element)
{
  DequeNode *pNode;
  
  if (pDeque == NULL)
  {
    printf("pDeque is NULL\n");
    return (FALSE);
  }
  pNode = (DequeNode*)calloc(1, sizeof(DequeNode));
  if (pNode == NULL)
  {
    printf("pNode malloc failure\n");
    return (FALSE);
  }
  pNode->data = element.data;
  if (isLinkedDequeEmpty(pDeque) == TRUE)
  {
    pNode->pRLink = pNode;
    pNode->pLLink = pNode;
    pDeque->pFrontNode = pNode;
    pDeque->pRearNode = pNode;
  }
  else
  {
    pNode->pLLink = pDeque->pRearNode;
    pNode->pRLink = pDeque->pFrontNode;
    pDeque->pFrontNode->pLLink = pNode;
    pDeque->pRearNode->pRLink = pNode;
    pDeque->pFrontNode = pNode;
  }
  (pDeque->currentElementCount)++;
  return (TRUE);
}

int insertRearLD(LinkedDeque* pDeque, DequeNode element)
{
  DequeNode *pNode;
  
  if (pDeque == NULL)
  {
    printf("pDeque is NULL\n");
    return (FALSE);
  }
  pNode = (DequeNode*)calloc(1, sizeof(DequeNode));
  if (pNode == NULL)
  {
    printf("pNode malloc failure\n");
    return (FALSE);
  }
  pNode->data = element.data;
  if (isLinkedDequeEmpty(pDeque) == TRUE)
  {
    pNode->pRLink = pNode;
    pNode->pLLink = pNode;
    pDeque->pFrontNode = pNode;
    pDeque->pRearNode = pNode;
  }
  else
  {
    pNode->pRLink = pDeque->pFrontNode;
    pDeque->pRearNode->pRLink = pNode;
    pNode->pLLink = pDeque->pRearNode;
    pDeque->pFrontNode->pLLink = pNode;
    pDeque->pRearNode = pNode;
  }
  (pDeque->currentElementCount)++;
  return (TRUE);
}

DequeNode* deleteFrontLD(LinkedDeque* pDeque)
{
  DequeNode *pReturn;
  
  if (pDeque == NULL)
  {
    printf("pDeque is NULL\n");
    return (NULL);
  }
  if (isLinkedDequeEmpty(pDeque) == TRUE)
  {
    printf("pDeque is Empty\n");
    return (NULL);
  }
  else
  {
    pReturn = pDeque->pFrontNode;
    if (pDeque->currentElementCount == 1)
    {
		  //pDeque->pFrontNode = pDeque->pFrontNode->pRLink;
      pDeque->pFrontNode = NULL;
      pDeque->pRearNode = NULL;
      pReturn->pRLink = NULL;
      pReturn->pLLink = NULL;
    }
    else
    {
      pDeque->pFrontNode = pDeque->pFrontNode->pRLink;
      pDeque->pFrontNode->pLLink = pDeque->pRearNode;
      pDeque->pRearNode->pRLink = pDeque->pFrontNode;
      pReturn->pRLink = NULL;
      pReturn->pLLink = NULL;
    }
  }
  (pDeque->currentElementCount)--;
  return (pReturn);
}

DequeNode* deleteRearLD(LinkedDeque* pDeque)
{
  DequeNode *pReturn;
  
  if (pDeque == NULL)
  {
    printf("pDeque is NULL\n");
    return (NULL);
  }
  if (isLinkedDequeEmpty(pDeque) == TRUE)
  {
    printf("pDeque is Empty\n");
    return (NULL);
  }
  else
  {
    pReturn = pDeque->pRearNode;
    if (pDeque->currentElementCount == 1)
    {
      pDeque->pFrontNode = NULL;
      pDeque->pRearNode = NULL;
      pReturn->pRLink = NULL;
      pReturn->pLLink = NULL;
    }
    else
    {
      pDeque->pRearNode = pDeque->pRearNode->pLLink;
      pDeque->pRearNode->pRLink = pDeque->pFrontNode;
      pDeque->pFrontNode->pLLink = pDeque->pRearNode;
      pReturn->pRLink = NULL;
      pReturn->pLLink = NULL;
    }
  }
  (pDeque->currentElementCount)--;
  return (pReturn);
}

DequeNode* peekFrontLD(LinkedDeque* pDeque)
{
  if (pDeque == NULL)
  {
    printf("pDeque is NULL\n");
    return (NULL);
  }
  if (isLinkedDequeEmpty(pDeque) == TRUE)
  {
    printf("pDeque is Empty\n");
    return (NULL);
  }
  return (pDeque->pFrontNode);
}

DequeNode* peekRearLD(LinkedDeque* pDeque)
{
  if (pDeque == NULL)
  {
    printf("pDeque is NULL\n");
    return (NULL);
  }
  if (isLinkedDequeEmpty(pDeque) == TRUE)
  {
    printf("pDeque is Empty\n");
    return (NULL);
  }
  return (pDeque->pRearNode);
}

void deleteLinkedDeque(LinkedDeque* pDeque)
{
  if (pDeque == NULL)
  {
    printf("pDeque is NULL\n");
    return ;
  }
  while (isLinkedDequeEmpty(pDeque) == FALSE)
  {
    DequeNode *pNode = deleteFrontLD(pDeque);
    free(pNode);
    pNode = NULL;
  }
  free(pDeque);
  pDeque = NULL;
}

int isLinkedDequeFull(LinkedDeque* pDeque)
{
  if (pDeque == NULL)
  {
    printf("pDeque is NULL\n");
  }
  return (FALSE);
}

int isLinkedDequeEmpty(LinkedDeque* pDeque)
{
  if (pDeque == NULL)
  {
    printf("pDeque is NULL\n");
  }
  if (pDeque->currentElementCount == 0)
  {
    return (TRUE);
  }
  return (FALSE);
}

void displayLinkedDeque(LinkedDeque* pDeque)
{
  DequeNode *pNode;
  if (pDeque == NULL)
  {
    printf("pDeque is NULL\n");
    return ;
  }
  if (isLinkedDequeEmpty(pDeque) == TRUE)
  {
    printf("pDeque is Empty\n");
    return ;
  }
  pNode = pDeque->pFrontNode;
  printf("%d ", pNode->data);
  pNode = pNode->pRLink;
  while (pNode != pDeque->pFrontNode)
  {
    printf("%d ", pNode->data);
    pNode = pNode->pRLink;
  }
  printf("\n");
}