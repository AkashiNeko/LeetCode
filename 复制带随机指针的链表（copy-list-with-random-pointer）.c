/*
����һ������Ϊ n ������ÿ���ڵ����һ���������ӵ����ָ�� random ����ָ�����ָ�������е��κνڵ��սڵ㡣

������������ ����� ���Ӧ�������� n �� ȫ�� �ڵ���ɣ�����ÿ���½ڵ��ֵ����Ϊ���Ӧ��ԭ�ڵ��ֵ���½ڵ�� next ָ��� random ָ��Ҳ��Ӧָ���������е��½ڵ㣬��ʹԭ����͸��������е���Щָ���ܹ���ʾ��ͬ������״̬�����������е�ָ�붼��Ӧָ��ԭ�����еĽڵ� ��

���磬���ԭ�������� X �� Y �����ڵ㣬���� X.random --> Y ����ô�ڸ��������ж�Ӧ�������ڵ� x �� y ��ͬ���� x.random --> y ��

���ظ��������ͷ�ڵ㡣

��һ���� n ���ڵ���ɵ���������ʾ����/����е�����ÿ���ڵ���һ�� [val, random_index] ��ʾ��

val��һ����ʾ Node.val ��������
random_index�����ָ��ָ��Ľڵ���������Χ�� 0 �� n-1���������ָ���κνڵ㣬��Ϊ  null ��
��Ĵ��� ֻ ����ԭ�����ͷ�ڵ� head ��Ϊ��������� 

ʾ�� 1��


���룺head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
�����[[7,null],[13,0],[11,4],[10,2],[1,0]]

ʾ�� 2��

���룺head = [[1,1],[2,1]]
�����[[1,1],[2,1]]

ʾ�� 3��

���룺head = [[3,null],[3,0],[3,null]]
�����[[3,null],[3,0],[3,null]]

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode.cn/problems/copy-list-with-random-pointer
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

struct Node* copyRandomList(struct Node* head) {
    if (head == NULL) return NULL;
    struct Node* cur = head;
    struct Node* nex = cur->next;
    do
    {
        //��ԭ����ÿ���ڵ�֮�����ýڵ�Ŀ���
        cur->next = (struct Node*)malloc(sizeof(struct Node));
        assert(cur->next);
        cur->next->val = cur->val;
        cur->next->next = nex;
        if (nex == NULL)
            break;
        cur = nex;
        nex = nex->next;
    } while (1);
    //���ÿ����ڵ��randomָ��
    cur = head;
    do
    {
        if (cur->random != NULL)
            cur->next->random = cur->random->next;
        else
            cur->next->random = NULL;
        cur = cur->next->next;
    } while (cur);
    //���뿽���ڵ�Ϊ������
    struct Node* newList = head->next;
    cur = head;
    nex = newList->next;
    while(nex)
    {
        cur->next->next = nex->next;
        cur->next = nex;
        cur = nex;
        nex = nex->next->next;
    }
    //������β�ڵ�next�ÿ�ָ��
    cur->next = NULL;
    return newList;
}