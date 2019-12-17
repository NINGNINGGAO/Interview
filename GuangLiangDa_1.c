#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *Next;
};
typedef struct ListNode* Node;

struct ListNode* retmid(struct ListNode *head) {
    int num = 0;
    Node temp = head;
    while (temp->Next != NULL) {
        temp = temp->Next;
        num++;
    }
    if (num % 2 == 1) {
        num++;
    }
    int mid = num / 2 - 1;
    Node pFast = head, pSlow = head;
    for (int i = 0; i < mid; i++) {
        pFast = pFast->Next;
    }
    while (pFast->Next != NULL) {
        pFast = pFast->Next;
        pSlow = pSlow->Next;
    }
    return pSlow;
}

int main() {
    Node head = malloc(sizeof(struct ListNode));
    Node temp = head, mid;
    char tmp;
    do {
        mid = malloc(sizeof(struct ListNode));
        mid->Next = NULL;
        scanf("%d%c", &(mid->val), &tmp);
        temp->Next = mid;
        temp = temp->Next;
    } while (tmp != '\n');
    struct ListNode* ret = retmid(head);
    printf("%d\n", ret->val);
    return 0;
    }