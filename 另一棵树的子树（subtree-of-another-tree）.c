/*
�������ö����� root �� subRoot ������ root ���Ƿ������ subRoot ������ͬ�ṹ�ͽڵ�ֵ��������������ڣ����� true �����򣬷��� false ��

������ tree ��һ���������� tree ��ĳ���ڵ������ڵ�����к���ڵ㡣tree Ҳ���Կ����������һ�������� 

ʾ�� 1��

���룺root = [3,4,5,1,2], subRoot = [4,1,2]
�����true

ʾ�� 2��

���룺root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
�����false

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode.cn/problems/subtree-of-another-tree
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if (p == NULL && q == NULL)
        return true;
    
    if (p == NULL || q == NULL)
        return false;

    if (p->val != q->val)
        return false;

    return isSameTree(p->left, q->left)
        && isSameTree(p->right, q->right);
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot){
    if (root == NULL)
        return false;

    if (root->val == subRoot->val && isSameTree(root, subRoot))
        return true;

    return isSubtree(root->left, subRoot)
        || isSubtree(root->right, subRoot);
}