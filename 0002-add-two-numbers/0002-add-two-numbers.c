/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry;
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode)), *end = NULL;
    int sum = (l1->val + l2->val);

    head->val = (sum >= 10) ? sum % 10 : sum;
    carry = (sum >= 10) ? sum / 10 : 0;
    
    head->next = NULL;
    end = head;
    l1 = l1->next;
    l2 = l2->next;

    while (l1 != NULL || l2 != NULL) {
        struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        sum = 0;
        
        if (l1 == NULL) {
            sum += (l2->val + carry);
        } else if (l2 == NULL) {
            sum += (l1->val + carry);
        } else {
            sum += (l1->val + l2->val + carry);
        }
        
        if (sum >= 10) {
            newNode->val = sum % 10;
            carry = sum / 10;
        } else {
            newNode->val = sum;
            carry = 0;
        }
        
        newNode->next = NULL;
        end->next = newNode;
        end = newNode;
        l1 = (l1 == NULL) ? NULL : l1->next;
        l2 = (l2 == NULL) ? NULL : l2->next;
    }

    if (carry != 0) {
        struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = carry;
        newNode->next = NULL;
        end->next = newNode;
    }

    return head;
}