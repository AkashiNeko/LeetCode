/*
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 
示例 1：

输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]
示例 2：

输入：head = [1,2]
输出：[2,1]
示例 3：

输入：head = []
输出：[]

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/reverse-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

struct ListNode* reverseList(struct ListNode* head){
	if (head == NULL || head->next == NULL) return head;
	//链表中存在两个及以上节点时
	struct ListNode* prv = head;
	struct ListNode* cur = prv->next;
	struct ListNode* nex = cur->next;
	//原链表头的next置空
	prv->next = NULL;
	//原链表第二个节点指向第一个节点
	cur->next = prv;
	while (nex)
	{
		//nex带着prv和cur向后遍历
		prv = cur;
		cur = nex;
		nex = nex->next;
		//prv和cur修改节点之间的指针方向
		cur->next = prv;
	}
	//新的链表头
	return cur;
}