/*
����һ�������ͷ�ڵ� head ��һ������ val ������ɾ���������������� Node.val == val �Ľڵ㣬������ �µ�ͷ�ڵ� �� 

ʾ�� 1��

���룺head = [1,2,6,3,4,5,6], val = 6
�����[1,2,3,4,5]

ʾ�� 2��

���룺head = [], val = 1
�����[]

ʾ�� 3��

���룺head = [7,7,7,7], val = 7
�����[]

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode.cn/problems/remove-linked-list-elements
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

struct ListNode* removeElements(struct ListNode* head, int val){
    if(head == NULL) return NULL;
    //�����ڱ�λ
    struct ListNode HeadNode = {0, head};
    struct ListNode* prev = &HeadNode;
    struct ListNode* cur = head;
    while(cur)
    {
        if(cur->val == val)
        {
            //�ҵ�����Ҫ��Ľڵ㣬ɾ��
            prev->next = cur->next;
            free(cur);
            cur = prev->next;
        }
        else
        {
            //������
            prev = cur;
            cur = cur->next;
        }
    }
    return HeadNode.next;
}