/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* s = p;
    while (l1 && l2)
    {
        if (l1->val <= l2->val)
        {
            p->next = l1;
            p = l1;
            l1 = l1->next;
        }
        else
        {
            p->next = l2;
            p = l2;
            l2 = l2->next;
        }
    }
    p->next = l1? l1 : l2;
    p = s->next;
    free(s);
    return p;
}
struct ListNode* merge(struct ListNode** lists, int left,int right)
{
    if (left == right)
        return lists[left];
    
     int mid = (left+right)/2;
     struct ListNode* l = merge(lists,left,mid);
     struct ListNode* r = merge(lists,mid+1,right);
     return mergeTwoLists(l,r);
    
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    if (listsSize == 0)
        return NULL;

    return merge(lists,0,listsSize-1);

}
