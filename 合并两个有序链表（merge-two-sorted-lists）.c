/*
��������������ϲ�Ϊһ���µ� ���� �������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�  

ʾ�� 1��

���룺l1 = [1,2,4], l2 = [1,3,4]
�����[1,1,2,3,4,4]
ʾ�� 2��

���룺l1 = [], l2 = []
�����[]
ʾ�� 3��

���룺l1 = [], l2 = [0]
�����[0]

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode.cn/problems/merge-two-sorted-lists
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode Head = {0, NULL};
    struct ListNode* New = &Head;
    while(list1 || list2)
    {
        if(list1 == NULL)
        {
            New->next = list2;
            break;
        }
        else if(list2 == NULL)
        {
            New->next = list1;
            break;
        }
        else
        {
            if(list1->val < list2->val)
            {
                New->next = list1;
                New = list1;
                list1 = list1->next;
                New->next = NULL;
            }
            else
            {
                New->next = list2;
                New = list2;
                list2 = list2->next;
                New->next = NULL;
            }
        }
    }
    return Head.next;
}