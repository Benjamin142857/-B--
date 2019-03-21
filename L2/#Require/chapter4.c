#include "stdio.h"
#include "malloc.h"
#include "chapter4.h"


PSeqStack createEmpty_seq(int m )
 {
    /* �����µ�*/
    PSeqStack pastack = (PSeqStack)malloc(sizeof(struct SeqStack));    //PSeqStack��ջ��ָ������
    if (pastack!=NULL)
    {
        pastack->s = (int*)malloc(sizeof(int)*m);
        if (pastack->s)
        {
            pastack->MAXNUM=m;
            pastack->t = -1;     
            return  pastack ;
        }
        else
        {
            free(pastack);
        }
    }
    printf("Out of space!!\n");       /* �洢����ʧ�� */
    return NULL;
}


void  push_seq( PSeqStack pastack, DataType x ) {
	/* ��ջ��ѹ��һԪ��x */
	if( pastack->t >= pastack->MAXNUM - 1  ) 
		printf( "Overflow! \n" );
	else{
		pastack->t = pastack->t + 1;
		pastack->s[pastack->t] = x;
	}
}

void  pop_seq( PSeqStack pastack ) {
	/* ɾ��ջ��Ԫ�� */
	if (pastack->t == -1 )
		printf( "Underflow!\n" );
	else 
		pastack->t = pastack->t - 1;
}

DataType  top_seq( PSeqStack pastack ) {
	/* ��pastack��ָ��ջ��Ϊ��ջʱ����ջ��Ԫ�ص�ֵ */
	if (pastack->t == -1 ) 
		printf( "It is empty!\n" );
	else 
		return (pastack->s[pastack->t]);
}


/*******************************************************************************/

PLinkStack createEmptyStack_link(void) {
	PLinkStack plstack;
	plstack = (PLinkStack )malloc( sizeof(struct LinkStack));
	if (plstack != NULL)
		plstack->top = NULL;
	else
		printf("Out of space! \n");  /*����ʧ��*/  
	return  plstack ;
}

int  isEmptyStack_link( PLinkStack plstack ) {
	return (plstack->top == NULL);
}

void push_link( PLinkStack plstack, DataType x ) {
	PNode  p;
	p = (PNode)malloc( sizeof( struct Node ) );
	if ( p == NULL  ) 
		printf("Out of space!\n");
	else {
		p->info = x;
		p->link = plstack->top;
		plstack->top = p;
	}
}

void  pop_link( PLinkStack plstack ) {
	PNode   p;
	if( isEmptyStack_link(plstack ))
		printf( "Empty stack pop.\n" );
	else{
		p = plstack->top;
		plstack->top = plstack->top->link;
		free(p);
	}
}

DataType  top_link( PLinkStack plstack ) {
	if (plstack->top == NULL )  
		printf( "Stack is empty!\n" );
	else  
		return (plstack->top->info);
}



/*********************************************************************************/


PSeqQueue createEmptyQueue_seq(int m){
	/* �����µ�˳��� */
    PSeqQueue paqu = (PSeqQueue)malloc(sizeof(struct SeqQueue));
    if (paqu!=NULL)
	{
		paqu->q = (DataType*)malloc(sizeof(DataType)*m);
		if (paqu->q)
		{
			paqu->MAXNUM=m;
			paqu ->f = 0;			
			paqu ->r = 0;
			return  paqu ;
		}
		else free(paqu);
    }
    printf("Out of space!!\n");    	/* �洢����ʧ�� */
    return NULL;
}

			
void  enQueue_seq( PSeqQueue paqu, DataType x ) {
	/* �ڶ�β����Ԫ��x */
	if( (paqu->r + 1)%paqu->MAXNUM == paqu->f  )
		printf( "Full queue.\n" );
	else { 
		paqu->q[paqu->r] = x;
		paqu->r = (paqu->r + 1) % paqu->MAXNUM;
	}
}

int isEmptyQueue_seq(PSeqQueue paqu)
{
	return(paqu->f == paqu->r);
}

void  deQueue_seq( PSeqQueue paqu ) {
	/* ɾ������ͷ��Ԫ�� */
	if( paqu->f == paqu->r )	
		printf( "Empty Queue.\n" );
	else  
		paqu->f = (paqu->f + 1) % paqu->MAXNUM;
}

DataType  frontQueue_seq( PSeqQueue paqu ) {
	if( paqu->f == paqu->r )	
		printf( "Empty Queue.\n" );
	else  
		return (paqu->q[paqu->f]);
}


