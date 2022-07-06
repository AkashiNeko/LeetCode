/*
给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。

请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。

注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。

示例 1：

输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
输出：[1,2,2,3,5,6]
解释：需要合并 [1,2,3] 和 [2,5,6] 。
合并结果是 [1,2,2,3,5,6] ，其中斜体加粗标注的为 nums1 中的元素。
示例 2：

输入：nums1 = [1], m = 1, nums2 = [], n = 0
输出：[1]
解释：需要合并 [1] 和 [] 。
合并结果是 [1] 。
示例 3：

输入：nums1 = [0], m = 0, nums2 = [1], n = 1
输出：[1]
解释：需要合并的数组是 [] 和 [1] 。
合并结果是 [1] 。
注意，因为 m = 0 ，所以 nums1 中没有元素。nums1 中仅存的 0 仅仅是为了确保合并结果可以顺利存放到 nums1 中。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/merge-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    //创建新的数组arr
    int* arr = NULL;
    if (m)
    {
        arr = (int*)malloc(m * sizeof(int));
        assert(arr);
        //将nums1中元素复制到arr中
        memcpy(arr, nums1, m * sizeof(int));
    }
    int i = 0;  //遍历arr
    int n1 = 0; //遍历nums1
    int n2 = 0; //遍历nums2
    //通过n1和n2把arr和nums2中的元素插入到num1中
    while (n1 < nums1Size)
    {
        if (i >= m)
        {
            //arr已遍历完成，将剩下的nums2中的元素存进nums1
            nums1[n1++] = nums2[n2++];
        }
        else if (n2 >= n)
        {
            //nums2已遍历完成，将剩下的arr中的元素存进nums1
            nums1[n1++] = arr[i++];
        }
        else
        {
            //将arr和nums2中较小的数放入nums1中
            nums1[n1++] = arr[i] < nums2[n2] ? arr[i++] : nums2[n2++];
        }
    }
    if (arr)
    {
        free(arr);
    }
}