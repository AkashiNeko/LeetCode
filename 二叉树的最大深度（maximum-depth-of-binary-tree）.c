/*
����һ�����������ҳ��������ȡ�

�����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����

˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣

ʾ����
���������� [3,9,20,null,null,15,7]��

    3
   / \
  9  20
    /  \
   15   7
�������������� 3 ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode.cn/problems/maximum-depth-of-binary-tree
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

int maxDepth(struct TreeNode* root){
    if(root == NULL)
        return 0;
    
    int LeftDepth = maxDepth(root->left) + 1;
    int RightDepth = maxDepth(root->right) + 1;

    return LeftDepth > RightDepth ? LeftDepth : RightDepth;
}