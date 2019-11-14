#include <stdlib.h>
#include "List.h"

void deleteList(ListNode* head) {
	while (head != NULL) {
		free(head->data);
		ListNode* next = head->next;
		free(head);
		head = next;
	}
}
