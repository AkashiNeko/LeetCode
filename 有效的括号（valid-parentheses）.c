/*
����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ��� s ���ж��ַ����Ƿ���Ч��

��Ч�ַ��������㣺

�����ű�������ͬ���͵������űպϡ�
�����ű�������ȷ��˳��պϡ� 

ʾ�� 1��

���룺s = "()"
�����true

ʾ�� 2��

���룺s = "()[]{}"
�����true

ʾ�� 3��

���룺s = "(]"
�����false

ʾ�� 4��

���룺s = "([)]"
�����false

ʾ�� 5��

���룺s = "{[]}"
�����true

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode.cn/problems/valid-parentheses
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

bool isValid(char * s){
    int capacity = 8;
    int top = 0;
    //����һ��ջ
    char* stack = (char*)malloc(capacity * sizeof(char));
    assert(stack);
    while (*s)
    {
        if (*s == '(' || *s == '[' || *s == '{')
        {
            //�������ŷ���ջ��
            stack[top++] = *s;
            if (top + 1 == capacity)
            {
                //ջ�ռ䲻��ʱ����
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
            //�ҵ�������ʱ���ж�ջ���Ƿ��ж�Ӧ��������
            if ((*s == ')' && stack[top] != '(')
            ||  (*s == ']' && stack[top] != '[')
            ||  (*s == '}' && stack[top] != '{'))
            {
                free(stack);
                return false;
            }
        }
        //������
        ++s;
    }
    free(stack);
    //ջΪ��������ȫ���պ�
    if (top != 0)
        return false;
    return true;
}