// test123.cpp : Defines the entry point for the console application.
//

#include "stdio.h"
#include "malloc.h"
#include "math.h"



typedef int DataType;


struct SeqList{
    int   MAXNUM;       /*顺序表中可以存放元素的个数*/
    int        n;        /* 实际存放线性表中元素的个数，n≤MAXNUM  */ 
    DataType *element;   /* element[0],element[1]，…，element[n- 1]存放线性表中的元素 */
};
typedef  struct SeqList * PSeqList; 


PSeqList createNullList_seq(int m ) {
	/* 创建新的顺序表 */
    PSeqList palist = (PSeqList)malloc(sizeof(struct SeqList));
    if (palist!=NULL)
	{
		palist->element = (DataType*)malloc(sizeof(DataType)*m);
		if (palist->element)
		{
			palist->MAXNUM=m;
			palist ->n = 0;			/* 空表长度为0 */
			return  palist ;
		}
		else free(palist);
    }
    printf("Out of space!!\n");    	/* 存储分配失败 */
    return NULL;
}




int insertPre_seq( PSeqList palist, int p, DataType x ) {
	/* 在palist所指顺序表中下标为p的元素之前插入元素x */
	int q;
	if ( palist->n >= palist-> MAXNUM ) {			/* 溢出 */
		printf("Overflow!\n");
		return   0  ;
	}
	if (p<0  ||  p>palist->n  ) {  	/* 不存在下标为p的元素 */
		printf("Not exist! \n");  
		return  0  ;
	}
	for(q=palist->n - 1; q>=p; q--)  /* 插入位置及之后的元素均后移一个位置 */
		palist->element[q+1] = palist->element[q];
	palist->element[p] = x;			/* 插入元素x */
	palist->n = palist->n + 1;			/* 元素个数加1 */
	return   1  ;
}





// 自定义函数 ： 在element数组里面找到最小的数值 
int findLeastEle(PSeqList palist)
{
    int value=palist->element[0];
    int  i;
    for(i=1;i<palist->n;i++)
        if(value > palist->element[i]) 
            value = palist->element[i];
	return  value;
}

int main(int argc, char* argv[])
{

    int i, tem=2 ,sig = -1;
    int randomArray[]={1,2,3,6,-2,9,10,45,23,15,67,22,18,13,73,82,11,-4,-67,-17,-87,-23};
	
	PSeqList xianxingbiao;
    xianxingbiao = createNullList_seq(30);  //新建一个顺序表
    
	
	
    for(i=0;i<14;i++)
    {        
        insertPre_seq(xianxingbiao,i, randomArray[i]);  //给顺序表元素赋值 
    }


	// 依次打印顺序表的元素数值
    printf("n=  %d \n ",xianxingbiao->n);
    for(i=0;i<23;i++)
        printf(" element[%d] = %d ,\n ", i ,xianxingbiao->element[i]);

    int leastValue;
    leastValue = findLeastEle(xianxingbiao);   //调用自定义函数，找到最小数值并赋值给leastValue
    printf("\n the least value = %d  \n", leastValue); 
    printf("Hello World!\n");

    return 0;
}
