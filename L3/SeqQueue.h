//
// Created by Benjamin142857 on 3/21/2019.
//

#ifndef QUEUE_SEQQUEUE_SEQQUEUE_H
#define QUEUE_SEQQUEUE_SEQQUEUE_H

#include "malloc.h"

/** Def ----------------------------------------------------**/
// 类型定义 - 数据
typedef int DataType;
// 结构体定义 - SeqQueue
struct SeqQueue {
    int MaxNum;     // SeqQueue最大数
    int first,last;        // f:首位元素位置, t:末尾元素位置+1；空队列:f=t=0
    DataType *members;    // 顺序表连续存储空间指针
};
// 类型定义 = SeqQueue指针
typedef struct SeqQueue *PSeqQueue;



/** Fun ----------------------------------------------------**/
// 创建空SeqQueue
PSeqQueue SeqQueue_create(int max) {
    // 1.定义SeqQueue指针,分配内存
    PSeqQueue psq = (PSeqQueue)malloc(sizeof(struct SeqQueue));

    // 2.判断是否分配成功
    if(psq != NULL) {
        // 2.1 定义members指针，分配内存
        psq->members = (DataType*)malloc(sizeof(DataType)*max);
        // 2.2 判断是否分配成功
        if(psq->members != NULL) {
            psq->MaxNum = max;          // 队列可容纳最大数，最大本质上环形队列可容纳最大数为 MaxNum-1，否则会first-last重合，出现空满同态
            psq->first = 0;             // 队列头元素位置
            psq->last = 0;              // 队列尾元素位置 + 1
            return psq;
        }
        else {
            free(psq);
            printf("SeqQueue create fail !!!\n");
            return NULL;
        }
    }
    else {
        printf("SeqQueue create fail !!!\n");
        return NULL;
    }

}

// SeqQueue是否为空队
int SeqQueue_IsEmpty(PSeqQueue psq) {
    return (psq->last == psq->first);
}

// SeqQueue是否满队
int SeqQueue_IsFull(PSeqQueue psq) {
    return ((psq->last + 1) % psq->MaxNum == psq->first);
}

// SeqQueue入队
void SeqQueue_enq(PSeqQueue psq, DataType x) {
    // 1.判断队列是否满
    if(SeqQueue_IsFull(psq)) {
        printf("SeqQueue is Full, enqueue fail !!!\n");
    }
    else {
        // 2 元素入队
        psq->members[psq->last] = x;
        // 3 last环形进位
        psq->last = (psq->last + 1) % psq->MaxNum;
    }
}

// SeqQueue出队
void SeqQueue_deq(PSeqQueue psq) {
    // 1.判断队列是否为空
    if(SeqQueue_IsEmpty(psq)) {
        printf("SeqQueue is empty, dequeue fail !!!\n");
    }
    else {
        // 2. first 环形进位
        psq->first = (psq->first + 1) % psq->MaxNum;
    }
}


// SeqQueue判断队列元素个数
int SeqQueue_MemberNum(PSeqQueue psq) {
    // 1.末尾元素-首位元素
    int err = psq->last - psq->first;
    // 2.判断末尾是否在首位前，若不是，则总数为 MaxNum + err
    if(err >= 0) {
        return err;
    }
    else {
        return (psq->MaxNum + err);
    }
}

// SeqQueue取队首元素值
DataType SeqQueue_GetFirst(PSeqQueue psq) {
    // 1.判断是否空栈
    if(SeqQueue_IsEmpty(psq)) {
        printf("SeqQueue is empty, get first fail !!!\n");
    }
    else {
        return psq->members[psq->first];
    }
}


#endif //QUEUE_SEQQUEUE_SEQQUEUE_H
