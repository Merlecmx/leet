/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next = NULL;
    struct ListNode* s = head;
    int min = INT_MAX;
    int i;
    int count = 0;               //计数连接完的链表
    while (count != listsSize)
    {
        int k = -1;
        count = 0;
        int min = INT_MAX;
        for (i = 0;i < listsSize;i++)     //找到每一次最小元素的节点
        {
            if (lists[i] == NULL)
            {
                count++;
                continue;
            }
            if (lists[i]->val < min)
            {
                min = lists[i]->val;
                k = i;
            }
        }
        if (k != -1)
        {
            head->next = lists[k];
            head = head->next;
            lists[k] = lists[k]->next;
        }  
    }
    head = s->next;
    free(s);
    return head;
}
