/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* MergeSort(struct ListNode* left,struct ListNode* right)
{
    struct ListNode* p = NULL;
    if (left->val <= right->val){
        p = left;
        left = left->next;
    }
    else{
        p = right;
        right = right->next;
    }
    struct ListNode* s = p;
    while (left != NULL && right != NULL)
    {
        if (left->val <= right->val)
        {
            p->next = left;
            left = left->next;
        }
        else
        {
            p->next = right;
            right = right->next;
        }
        p = p->next;
    }
    p->next = left ? left : right;
    return s;  
}

struct ListNode* sortList(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
        return head;
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    struct ListNode* mid = slow->next;
    slow->next = NULL;
    struct ListNode* left = sortList(head);
    struct ListNode* right = sortList(mid);
    
    return MergeSort(left,right);
}
