/*
����һ������ nums ��һ��ֵ val������Ҫ ԭ�� �Ƴ�������ֵ���� val ��Ԫ�أ��������Ƴ���������³��ȡ�

��Ҫʹ�ö��������ռ䣬������ʹ�� O(1) ����ռ䲢 ԭ�� �޸��������顣

Ԫ�ص�˳����Ըı䡣�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�

ʾ�� 1��

���룺nums = [3,2,2,3], val = 3
�����2, nums = [2,2]
���ͣ�����Ӧ�÷����µĳ��� 2, ���� nums �е�ǰ����Ԫ�ؾ�Ϊ 2���㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء����磬�������ص��³���Ϊ 2 ���� nums = [2,2,3,3] �� nums = [2,2,0,0]��Ҳ�ᱻ������ȷ�𰸡�
ʾ�� 2��

���룺nums = [0,1,2,2,3,0,4,2], val = 2
�����5, nums = [0,1,4,0,3]
���ͣ�����Ӧ�÷����µĳ��� 5, ���� nums �е�ǰ���Ԫ��Ϊ 0, 1, 3, 0, 4��ע�������Ԫ�ؿ�Ϊ����˳���㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode.cn/problems/remove-element
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/


int removeElement(int* nums, int numsSize, int val){
    if(numsSize == 0)
        return 0;
	//����ָ�루leftָ��ͷ��rightָ��β��
    int left = 0;
    int right = numsSize - 1;
    while(nums[right] == val)
    {
		//��ָ���ƶ�����valԪ����
        right--;
        numsSize--;
        if(numsSize == 0)
            return 0;
    }
    while(left < right)
    {
        if(nums[left] == val)
        {
			//��ָ���ҵ���val���򽫸�ֵ��β����ָ�뽻��
            nums[left] = nums[right];
            nums[right] = val;
            while(nums[right] == val)
            {
				//val��������β��������rightָ��ǰ��
                right--;
                numsSize--;
            }
        }
		//��ָ�����
        left++;
    }
    return numsSize;
}