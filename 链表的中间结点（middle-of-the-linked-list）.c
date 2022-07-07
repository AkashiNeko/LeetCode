/*
����һ��ͷ���Ϊ head �ķǿյ���������������м��㡣

����������м��㣬�򷵻صڶ����м��㡣 

ʾ�� 1��

���룺[1,2,3,4,5]
��������б��еĽ�� 3 (���л���ʽ��[3,4,5])
���صĽ��ֵΪ 3 �� (����ϵͳ�Ըý�����л������� [3,4,5])��
ע�⣬���Ƿ�����һ�� ListNode ���͵Ķ��� ans��������
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, �Լ� ans.next.next.next = NULL.
ʾ�� 2��

���룺[1,2,3,4,5,6]
��������б��еĽ�� 4 (���л���ʽ��[4,5,6])
���ڸ��б��������м��㣬ֵ�ֱ�Ϊ 3 �� 4�����Ƿ��صڶ�����㡣

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode.cn/problems/middle-of-the-linked-list
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

struct ListNode* middleNode(struct ListNode* head){
    if(head == NULL)
    {
        //������
        return head;
    }
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    //fastָ��ǲ�
    int step = 0;
    while(fast)
    {
        fast = fast->next;
        ++step;
        if(step % 2 == 0)
        {
            //fastÿ��2����slow��1��
            slow = slow->next;
        }
    }
    return slow;
}