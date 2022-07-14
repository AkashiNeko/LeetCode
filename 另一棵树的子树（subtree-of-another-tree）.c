/*
给你两棵二叉树 root 和 subRoot 。检验 root 中是否包含和 subRoot 具有相同结构和节点值的子树。如果存在，返回 true ；否则，返回 false 。

二叉树 tree 的一棵子树包括 tree 的某个节点和这个节点的所有后代节点。tree 也可以看做它自身的一棵子树。 

示例 1：

输入：root = [3,4,5,1,2], subRoot = [4,1,2]
输出：true

示例 2：

输入：root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
输出：false

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/subtree-of-another-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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