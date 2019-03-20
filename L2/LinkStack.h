//
// Created by Benjamin142857 on 3/17/2019.
//

#ifndef L2_LINKSTACK_H
#define L2_LINKSTACK_H

#include "malloc.h"

/** Def ----------------------------------------------------   **/
// 数据类型-名定义
typedef char DataType;
// 节点结构-定义
struct  Node;
// 节点结构-名定义
typedef  struct  Node  *PNode;
// 节点结构-内部定义
struct  Node { 			/* 结点结构 */
    DataType      info;
    PNode         link;
};
// 链表栈-定义
struct LinkStack
{
    PNode  top; /* 指向栈顶结点 */
};
// 链表栈-名定义
typedef  struct LinkStack  *PLinkStack;



/** Fun ----------------------------------------------------   **/
// 创建结点
PNode create_node(PNode next_p, DataType x) {
    // 1.定义指针
    PNode p;
    // 2.分配内存
    p = (PNode)malloc(sizeof(struct Node));
    // 3.判断节点是否创建成功
    if(p != NULL) {
        p->info = x;
        p->link = next_p;
    }
    else {
        printf("结点创建失败\n");
    }

}


// 创建空LinkStack
PLinkStack create_LinkStack(void) {
    // 1.定义指针
    PLinkStack pls;
    // 2.分配内存
    pls = (PLinkStack)malloc(sizeof(struct LinkStack));
    // 3.判断链表栈是否创建成功
    if(pls != NULL) {
        pls->top = NULL;
    }
    else {
        printf("链表栈创建失败\n");
    }
    // 4.返回LinkStack指针
    return pls;
}


// 判断是否空栈 (0-非空，1-空)
int is_empty(PLinkStack pls) {
    return (pls->top == NULL);
}


// 进栈
int push(PLinkStack pls, DataType x) {
    // 1.创建一个结点
    PNode p = create_node(pls->top, x);
    // 2.判断结点是否创建成功
    if(p != NULL) {
        pls->top = p;
    }
    else {
        printf("进栈失败");
    }
}


// 出栈
void pop(PLinkStack pls) {
    // 1.定义空结点指向栈顶元素作为临时容器，然后free
    PNode p = pls->top;
    // 2.判断是否空栈
    if (is_empty(pls)) {
        printf("该链表栈为空\n");
    }
    else {
        pls->top = pls->top->link;
        free(p);
    }
}


// 取栈顶
DataType get_top(PLinkStack pls) {
    // 1.判断是否空栈
    if (is_empty(pls)) {
        printf("该链表栈为空\n");
    }
    else {
        return pls->top->info;
    }
}

#endif //L2_LINKSTACK_H
