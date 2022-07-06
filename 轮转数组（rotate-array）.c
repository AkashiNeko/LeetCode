/*
����һ�����飬�������е�Ԫ��������ת k ��λ�ã����� k �ǷǸ�����

ʾ�� 1:

����: nums = [1,2,3,4,5,6,7], k = 3
���: [5,6,7,1,2,3,4]
����:
������ת 1 ��: [7,1,2,3,4,5,6]
������ת 2 ��: [6,7,1,2,3,4,5]
������ת 3 ��: [5,6,7,1,2,3,4]
ʾ��?2:

���룺nums = [-1,-100,3,99], k = 2
�����[3,99,-1,-100]
����: 
������ת 1 ��: [99,-1,-100,3]
������ת 2 ��: [3,99,-1,-100]

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode.cn/problems/rotate-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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