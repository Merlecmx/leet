/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct list{
    int val;
    int id;
};
void swim(struct list* heap,int p)        //元素向上调整
{
     int q = p/2;
     struct list temp = heap[p];
     while (q && temp.val < heap[q].val)
     {
         heap[p] = heap[q];
         p = q;
         q = q/2;
     }
     heap[p] = temp;
}
void sink(struct list* heap,int p,int n)         //元素向下调整
{
     int q = 2*p;
     struct list temp = heap[p];
     while (q <= n)
     {
         if (q < n && heap[q].val > heap[q+1].val)
             q++;
         if (temp.val <= heap[q].val)
             break;
         heap[p] = heap[q];
         p = q;
         q *= 2;
     }
     heap[p] = temp;
}
void build(struct list* heap,int n)          //建堆
{
     int i;
     for (i = n/2;i > 0;i--)
         sink(heap,i,n);
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    if (listsSize == 0)
        return NULL;
    struct list* heap = (struct list*)malloc(sizeof(struct list)* (listsSize+1));
    int i;
    for (i = 0;i < listsSize;i++)               // 52line-67line 堆排序（小堆）
    {
        if (lists[i] != NULL){
            heap[i+1].val = lists[i]->val;
            heap[i+1].id = i;
        }
        else{
            heap[i+1].val = INT_MAX;
            heap[i+1].id = i;
        }
    }
    build(heap,listsSize);
    for (i = listsSize/2+1;i <= listsSize;i++)
    {
        swim(heap,i);
    }
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* p = head;
    while (heap[1].val != INT_MAX)
    {
        int t = heap[1].id;                 //获取最小元素所在链表的位置
        p->next = lists[t];
        p = p->next;
        lists[t] = lists[t]->next;
        if (lists[t] != NULL)               //添加此链表next元素到堆根
            heap[1].val = lists[t]->val;
        else
            heap[1].val = INT_MAX;
        sink(heap,1,listsSize);                   //维护堆
        
    }
    p->next = NULL;
    p = head->next;
    free(head);
    return p; 
}
