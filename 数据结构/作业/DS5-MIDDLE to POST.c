#include <stdio.h>
#include <string.h>

int Compare(char str1) {
    if (str1 == '#') {
        return 0;
    } else if (str1 == '+' || str1 == '-') {
        return 1;
    } else if (str1 == '*' || str1 == '/') {
        return 2;
    } else if (str1 == '(' || str1 == ')') {
        return 0;
    }
    else {
        return -1; //字母或者数字 
    }
}

int main (void) {
	//结果栈 
    char endStack[100];
    int endTop = -1;
    
    //操作符栈 
    char symbolStack[100];
    int symbolTop = -1;
    
    char str[100];
    scanf("%s", str);
    int length = (int)strlen(str);
    
    for (int i = 0; i < length; ) {
        if (Compare(str[i]) == -1) {    //是字母或者数字就把它压入结果栈中 
            endStack[++endTop] = str[i++];
        } else if (str[i] == '(') {     //遇到（直接压入操作符栈中 
            symbolStack[++symbolTop] = str[i++];
        } else if (str[i] == ')') {     //遇到）将操作符栈中的符号全部弹出压入结果栈中 
            while (Compare(symbolStack[symbolTop]) != 0) {
                endStack[++endTop] = symbolStack[symbolTop--];
            }
            symbolTop--;
            i++;
        } else {     //遇到操作符 
            if (symbolTop == -1 || Compare(symbolStack[symbolTop]) < Compare(str[i])) { //操作符栈为空或者字符串中的操作符优先级大于操作符栈顶操作符的优先级就将该操作符压入操作符栈中 
                symbolStack[++symbolTop] = str[i++];
            } else {     //若字符串中的操作符优先级小于或等于操作符栈顶操作符的优先级，就将操作符栈的栈顶元素弹出压入结果栈中，并且字符串中的位置不变，直到操作符栈为空或遇到高优先级的操作符 
                endStack[++endTop] = symbolStack[symbolTop--];
            }
            if (str[i] == '#') {
                break;
            }
        }
    }
    for (int i = 0; i < endTop + 1; i++) {
        printf("%c ", endStack[i]);
    }
    return 0;
}    
