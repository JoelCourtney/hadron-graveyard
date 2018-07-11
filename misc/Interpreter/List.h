#ifndef LIST_H
#define LIST_H

typedef struct listnode ListNode;

struct listnode {
	void* data;
	ListNode* next;
};

void deleteList(ListNode* head);

#endif
