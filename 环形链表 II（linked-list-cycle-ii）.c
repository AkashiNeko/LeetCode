/*
给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

不允许修改 链表。 

示例 1：

输入：head = [3,2,0,-4], pos = 1
输出：返回索引为 1 的链表节点
解释：链表中有一个环，其尾部连接到第二个节点。

示例 2：

输入：head = [1,2], pos = 0
输出：返回索引为 0 的链表节点
解释：链表中有一个环，其尾部连接到第一个节点。

示例 3：

输入：head = [1], pos = -1
输出：返回 null
解释：链表中没有环。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/linked-list-cycle-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

struct ListNode *detectCycle(struct ListNode *head) {
    if(head == NULL) return NULL;
    //快慢指针
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while(fast && fast->next)
    {
        //快指针每移动2步，慢指针移动1步
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
        {
            //快指针与慢指针相遇
            while(fast != head)
            {
				//fast从fast与slow的相遇点出发，head从头出发
				//相遇位置即入环节点
                fast = fast->next;
                head = head->next;
            }
            return head;
        }
    }
    //快指针遍历到链表末尾
    return NULL;
}