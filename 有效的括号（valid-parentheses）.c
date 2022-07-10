/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。 

示例 1：

输入：s = "()"
输出：true

示例 2：

输入：s = "()[]{}"
输出：true

示例 3：

输入：s = "(]"
输出：false

示例 4：

输入：s = "([)]"
输出：false

示例 5：

输入：s = "{[]}"
输出：true

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

bool isValid(char * s){
    int capacity = 8;
    int top = 0;
    //创建一个栈
    char* stack = (char*)malloc(capacity * sizeof(char));
    assert(stack);
    while (*s)
    {
        if (*s == '(' || *s == '[' || *s == '{')
        {
            //将左括号放入栈中
            stack[top++] = *s;
            if (top + 1 == capacity)
            {
                //栈空间不够时扩容
                capacity *= 2;
                char* temp = (char*)realloc(stack, capacity * sizeof(char));
                assert(temp);
                stack = temp;
            }
        }
        else if (*s == ')' || *s == ']' || *s == '}')
        {
            if (top-- == 0)
            {
                free(stack);
                return false;
            }
            //找到右括号时，判断栈中是否有对应的左括号
            if ((*s == ')' && stack[top] != '(')
            ||  (*s == ']' && stack[top] != '[')
            ||  (*s == '}' && stack[top] != '{'))
            {
                free(stack);
                return false;
            }
        }
        //向后遍历
        ++s;
    }
    free(stack);
    //栈为空则括号全部闭合
    if (top != 0)
        return false;
    return true;
}