/*
����һ���������ĸ��ڵ� root �� ������Ƿ���Գơ�

ʾ�� 1��

���룺root = [1,2,2,3,4,4,3]
�����true

ʾ�� 2��

���룺root = [1,2,2,null,3,null,3]
�����false
 
��ʾ��

���нڵ���Ŀ�ڷ�Χ [1, 1000] ��
-100 <= Node.val <= 100

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode.cn/problems/symmetric-tree
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

bool isMirrorTree(struct TreeNode* p, struct TreeNode* q)
{
    if (p == NULL && q == NULL)
        return true;

    if (p == NULL || q == NULL)
        return false;

    if (p->val != q->val)
        return false;

    return isMirrorTree(p->left, q->right)
        && isMirrorTree(p->right, q->left);
}

bool isSymmetric(struct TreeNode* root){
    if (root == NULL)
        return true;

    return isMirrorTree(root->left, root->right);
}