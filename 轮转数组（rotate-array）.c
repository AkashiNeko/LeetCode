/*
给你一个数组，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。

示例 1:

输入: nums = [1,2,3,4,5,6,7], k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右轮转 1 步: [7,1,2,3,4,5,6]
向右轮转 2 步: [6,7,1,2,3,4,5]
向右轮转 3 步: [5,6,7,1,2,3,4]
示例?2:

输入：nums = [-1,-100,3,99], k = 2
输出：[3,99,-1,-100]
解释: 
向右轮转 1 步: [99,-1,-100,3]
向右轮转 2 步: [3,99,-1,-100]

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/rotate-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

void reverse(int* nums, int left, int right)
{
    while(left < right)
    {
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        --right;
        ++left;
    }
}
void rotate(int* nums, int numsSize, int k){
    k %= numsSize;
    reverse(nums, 0, numsSize - k - 1);
    reverse(nums, numsSize - k, numsSize - 1);
    reverse(nums, 0, numsSize - 1);
}