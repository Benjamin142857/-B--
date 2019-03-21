// test123.cpp : Defines the entry point for the console application.
//

#include "stdio.h"
#include "malloc.h"
#include "math.h"



typedef int DataType;


struct SeqList{
    int   MAXNUM;       /*˳����п��Դ��Ԫ�صĸ���*/
    int        n;        /* ʵ�ʴ�����Ա���Ԫ�صĸ�����n��MAXNUM  */ 
    DataType *element;   /* element[0],element[1]������element[n- 1]������Ա��е�Ԫ�� */
};
typedef  struct SeqList * PSeqList; 


PSeqList createNullList_seq(int m ) {
	/* �����µ�˳��� */
    PSeqList palist = (PSeqList)malloc(sizeof(struct SeqList));
    if (palist!=NULL)
	{
		palist->element = (DataType*)malloc(sizeof(DataType)*m);
		if (palist->element)
		{
			palist->MAXNUM=m;
			palist ->n = 0;			/* �ձ���Ϊ0 */
			return  palist ;
		}
		else free(palist);
    }
    printf("Out of space!!\n");    	/* �洢����ʧ�� */
    return NULL;
}




int insertPre_seq( PSeqList palist, int p, DataType x ) {
	/* ��palist��ָ˳������±�Ϊp��Ԫ��֮ǰ����Ԫ��x */
	int q;
	if ( palist->n >= palist-> MAXNUM ) {			/* ��� */
		printf("Overflow!\n");
		return   0  ;
	}
	if (p<0  ||  p>palist->n  ) {  	/* �������±�Ϊp��Ԫ�� */
		printf("Not exist! \n");  
		return  0  ;
	}
	for(q=palist->n - 1; q>=p; q--)  /* ����λ�ü�֮���Ԫ�ؾ�����һ��λ�� */
		palist->element[q+1] = palist->element[q];
	palist->element[p] = x;			/* ����Ԫ��x */
	palist->n = palist->n + 1;			/* Ԫ�ظ�����1 */
	return   1  ;
}





// �Զ��庯�� �� ��element���������ҵ���С����ֵ 
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
    xianxingbiao = createNullList_seq(30);  //�½�һ��˳���
    
	
	
    for(i=0;i<14;i++)
    {        
        insertPre_seq(xianxingbiao,i, randomArray[i]);  //��˳���Ԫ�ظ�ֵ 
    }


	// ���δ�ӡ˳����Ԫ����ֵ
    printf("n=  %d \n ",xianxingbiao->n);
    for(i=0;i<23;i++)
        printf(" element[%d] = %d ,\n ", i ,xianxingbiao->element[i]);

    int leastValue;
    leastValue = findLeastEle(xianxingbiao);   //�����Զ��庯�����ҵ���С��ֵ����ֵ��leastValue
    printf("\n the least value = %d  \n", leastValue); 
    printf("Hello World!\n");

    return 0;
}
