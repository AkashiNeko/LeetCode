/*
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。  

示例 1：

输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]
示例 2：

输入：l1 = [], l2 = []
输出：[]
示例 3：

输入：l1 = [], l2 = [0]
输出：[0]

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/merge-two-sorted-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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