/*
给你一个二叉树的根节点 root ， 检查它是否轴对称。

示例 1：

输入：root = [1,2,2,3,4,4,3]
输出：true

示例 2：

输入：root = [1,2,2,null,3,null,3]
输出：false
 
提示：

树中节点数目在范围 [1, 1000] 内
-100 <= Node.val <= 100

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/symmetric-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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