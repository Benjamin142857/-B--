// 实验2 - 分别基于递归函数与链表栈实现数字字符串转数字整型
// 第2组 - [古富源，方智威，杜祖铧，邓泽淳]
// 2019-03-17


#include <stdio.h>
#include <string.h>
#include <math.h>
#include "LinkStack.h"


// 字符串-名定义
typedef char String[128];


// 题二 - 基于递归函数的数字字符串转数字整型
long NumStr2NumInt_1(String NumStr, int NumStrLen) {
    long res;
    if(NumStrLen==0){
        return 0;
    }
    else {
        int temp = NumStr[NumStrLen-1] - 48;
        res = temp + 10*NumStr2NumInt_1(NumStr, NumStrLen-1);
        return res;
    }


}


// 题二 - 基于链表栈的数字字符串转数字整型
long NumStr2NumInt_2(String NumStr) {
    // 1.数字字符串从左到右依次入栈
    PLinkStack pls = create_LinkStack();
    for(int i=0; i<strlen(NumStr); i++) {
        push(pls, NumStr[i]);
    }

    // 2.再依次取栈顶，出栈，字符转Int
    long res = 0;
    for(int i=0; i<strlen(NumStr); i++) {
        int temp = get_top(pls) - 48;
        res += temp*pow(10, i);
        pop(pls);
    }

    // 3.返回
    return res;

}


int main() {
    String NumStr = "421353242";
    long res1 = NumStr2NumInt_1(NumStr, strlen(NumStr));
    long res2 = NumStr2NumInt_2(NumStr);
    printf("[1] Output result:\n%ld\n\n", res1);
    printf("[2] Output result:\n%ld\n", res2);
    return 0;
}

