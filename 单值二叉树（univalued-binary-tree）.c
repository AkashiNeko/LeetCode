/*
���������ÿ���ڵ㶼������ͬ��ֵ����ô�ö��������ǵ�ֵ��������

ֻ�и��������ǵ�ֵ������ʱ���ŷ��� true�����򷵻� false��

ʾ�� 1��

���룺[1,1,1,1,1,null,1]
�����true
ʾ�� 2��

���룺[2,2,2,5,2]
�����false
*/

bool isUnivalTree(struct TreeNode* root){
    if (root == NULL)
        return true;

    if (root->left != NULL && root->left->val != root->val)
        return false;

    if (root->right != NULL && root->right->val != root->val)
        return false;
    
    if (isUnivalTree(root->left) == false)
        return false;

    if (isUnivalTree(root->right) == false)
        return false;

    return true;
}