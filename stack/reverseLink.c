#include <iostream>

using namespace std;

typedef struct Node{
	int nValue;
	struct Node *pNext;
}ListNode;

/* create null Link */
ListNode * createList()
{
	ListNode *pHead;
	pHead = new ListNode;
	pHead->nValue = 0;
	pHead->pNext = NULL;
}

/* insert node at the end of Link */
ListNode * insertNode(ListNode *pHead, int elem)
{
	if (NULL == pHead)
	{
		cout << " head is null " << endl;
		return pHead;
	}

	ListNode *temp, *current;
	current = pHead;
	while (NULL != current->pNext)
	{
		current = current->pNext;
	}

	temp = new ListNode;
	temp->nValue = elem;
	temp->pNext = NULL;
	current->pNext = temp;

	pHead->nValue += 1;
	
	return pHead;
}

/* display link */
void showList(ListNode *pHead)
{
	if (NULL == pHead)
	{
		cout << " Null link " << endl;
		return;
	}

	ListNode *temp;
	temp = pHead->pNext;
	cout << " list are ";
	while (NULL != temp)
	{
		cout << temp->nValue << " ";
		temp = temp->pNext;
	}
	cout << endl;
}


/* reverse list */
ListNode * reverseList(ListNode *pHead)
{
	if (NULL == pHead || NULL == pHead->pNext)
	{
		return pHead;
	}

	ListNode *temp, *current;
	current = pHead->pNext;
	pHead->pNext = NULL;

	while (NULL != current)
	{
		temp = current->pNext;
		current->pNext = pHead->pNext;
		pHead->pNext = current;
		current = temp;
	}

	return pHead;
}

int main()
{
	int len_of_list = 6;
	int i = 1;
	ListNode *pHead;
	pHead  = createList();
	while(len_of_list > 0)
	{
		insertNode(pHead, i++);
		len_of_list --;
	}
	showList(pHead);

	reverseList(pHead);

	showList(pHead);

	return 0;
}
