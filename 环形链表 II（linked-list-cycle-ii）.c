/*
����һ�������ͷ�ڵ�  head ����������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��

�����������ĳ���ڵ㣬����ͨ���������� next ָ���ٴε���������д��ڻ��� Ϊ�˱�ʾ���������еĻ�������ϵͳ�ڲ�ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ������� pos �� -1�����ڸ�������û�л���ע�⣺pos ����Ϊ�������д��ݣ�������Ϊ�˱�ʶ�����ʵ�������

�������޸� ���� 

ʾ�� 1��

���룺head = [3,2,0,-4], pos = 1
�������������Ϊ 1 ������ڵ�
���ͣ���������һ��������β�����ӵ��ڶ����ڵ㡣

ʾ�� 2��

���룺head = [1,2], pos = 0
�������������Ϊ 0 ������ڵ�
���ͣ���������һ��������β�����ӵ���һ���ڵ㡣

ʾ�� 3��

���룺head = [1], pos = -1
��������� null
���ͣ�������û�л���

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode.cn/problems/linked-list-cycle-ii
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

struct ListNode *detectCycle(struct ListNode *head) {
    if(head == NULL) return NULL;
    //����ָ��
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while(fast && fast->next)
    {
        //��ָ��ÿ�ƶ�2������ָ���ƶ�1��
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
        {
            //��ָ������ָ������
            while(fast != head)
            {
				//fast��fast��slow�������������head��ͷ����
				//����λ�ü��뻷�ڵ�
                fast = fast->next;
                head = head->next;
            }
            return head;
        }
    }
    //��ָ�����������ĩβ
    return NULL;
}