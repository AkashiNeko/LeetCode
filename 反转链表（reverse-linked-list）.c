/*
���㵥�����ͷ�ڵ� head �����㷴ת���������ط�ת�������
 
ʾ�� 1��

���룺head = [1,2,3,4,5]
�����[5,4,3,2,1]
ʾ�� 2��

���룺head = [1,2]
�����[2,1]
ʾ�� 3��

���룺head = []
�����[]

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode.cn/problems/reverse-linked-list
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

struct ListNode* reverseList(struct ListNode* head){
	if (head == NULL || head->next == NULL) return head;
	//�����д������������Ͻڵ�ʱ
	struct ListNode* prv = head;
	struct ListNode* cur = prv->next;
	struct ListNode* nex = cur->next;
	//ԭ����ͷ��next�ÿ�
	prv->next = NULL;
	//ԭ����ڶ����ڵ�ָ���һ���ڵ�
	cur->next = prv;
	while (nex)
	{
		//nex����prv��cur������
		prv = cur;
		cur = nex;
		nex = nex->next;
		//prv��cur�޸Ľڵ�֮���ָ�뷽��
		cur->next = prv;
	}
	//�µ�����ͷ
	return cur;
}