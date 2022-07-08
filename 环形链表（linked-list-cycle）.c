/*
����һ�������ͷ�ڵ� head ���ж��������Ƿ��л���

�����������ĳ���ڵ㣬����ͨ���������� next ָ���ٴε���������д��ڻ��� Ϊ�˱�ʾ���������еĻ�������ϵͳ�ڲ�ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ����ע�⣺pos ����Ϊ�������д��� ��������Ϊ�˱�ʶ�����ʵ�������

��������д��ڻ� ���򷵻� true �� ���򣬷��� false ��
 
ʾ�� 1��

���룺head = [3,2,0,-4], pos = 1
�����true
���ͣ���������һ��������β�����ӵ��ڶ����ڵ㡣

ʾ�� 2��

���룺head = [1,2], pos = 0
�����true
���ͣ���������һ��������β�����ӵ���һ���ڵ㡣

ʾ�� 3��

���룺head = [1], pos = -1
�����false
���ͣ�������û�л���

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode.cn/problems/linked-list-cycle
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

bool hasCycle(struct ListNode *head) {
    if(head == NULL) return false;
    //����ָ��
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    int step = 0;
    while(fast->next)
    {
        fast = fast->next;
        ++step;
        if(step % 2 == 0)
        {
            //��ָ��ÿ�ƶ�2������ָ���ƶ�1��
            slow = slow->next;
        }
        if(fast == slow)
            //��ָ��׷����ָ��
            return true;
    }
    //��ָ�����������ĩβ
    return false;
}