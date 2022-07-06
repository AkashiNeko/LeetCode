/*
���������� �ǵݼ�˳�� ���е��������� nums1 �� nums2�������������� m �� n ���ֱ��ʾ nums1 �� nums2 �е�Ԫ����Ŀ��

���� �ϲ� nums2 �� nums1 �У�ʹ�ϲ��������ͬ���� �ǵݼ�˳�� ���С�

ע�⣺���գ��ϲ������鲻Ӧ�ɺ������أ����Ǵ洢������ nums1 �С�Ϊ��Ӧ�����������nums1 �ĳ�ʼ����Ϊ m + n������ǰ m ��Ԫ�ر�ʾӦ�ϲ���Ԫ�أ��� n ��Ԫ��Ϊ 0 ��Ӧ���ԡ�nums2 �ĳ���Ϊ n ��

ʾ�� 1��

���룺nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
�����[1,2,2,3,5,6]
���ͣ���Ҫ�ϲ� [1,2,3] �� [2,5,6] ��
�ϲ������ [1,2,2,3,5,6] ������б��Ӵֱ�ע��Ϊ nums1 �е�Ԫ�ء�
ʾ�� 2��

���룺nums1 = [1], m = 1, nums2 = [], n = 0
�����[1]
���ͣ���Ҫ�ϲ� [1] �� [] ��
�ϲ������ [1] ��
ʾ�� 3��

���룺nums1 = [0], m = 0, nums2 = [1], n = 1
�����[1]
���ͣ���Ҫ�ϲ��������� [] �� [1] ��
�ϲ������ [1] ��
ע�⣬��Ϊ m = 0 ������ nums1 ��û��Ԫ�ء�nums1 �н���� 0 ������Ϊ��ȷ���ϲ��������˳����ŵ� nums1 �С�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode.cn/problems/merge-sorted-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    //�����µ�����arr
    int* arr = NULL;
    if (m)
    {
        arr = (int*)malloc(m * sizeof(int));
        assert(arr);
        //��nums1��Ԫ�ظ��Ƶ�arr��
        memcpy(arr, nums1, m * sizeof(int));
    }
    int i = 0;  //����arr
    int n1 = 0; //����nums1
    int n2 = 0; //����nums2
    //ͨ��n1��n2��arr��nums2�е�Ԫ�ز��뵽num1��
    while (n1 < nums1Size)
    {
        if (i >= m)
        {
            //arr�ѱ�����ɣ���ʣ�µ�nums2�е�Ԫ�ش��nums1
            nums1[n1++] = nums2[n2++];
        }
        else if (n2 >= n)
        {
            //nums2�ѱ�����ɣ���ʣ�µ�arr�е�Ԫ�ش��nums1
            nums1[n1++] = arr[i++];
        }
        else
        {
            //��arr��nums2�н�С��������nums1��
            nums1[n1++] = arr[i] < nums2[n2] ? arr[i++] : nums2[n2++];
        }
    }
    if (arr)
    {
        free(arr);
    }
}