#ifndef _CHAPTER4_
#define _CHAPTER4_


typedef int DataType;

struct  SeqQueue{ /* ˳��������Ͷ��� */
int  MAXNUM;      /* ���������Ԫ�ظ��� */
int  f,r;    
DataType  *q;
};
/*Ϊ���㷨����ϵķ��㣺
  f ָ��ʵ�ʶ�ͷԪ�����ڵ�λ�ã�
  r ָ��ʵ�ʶ�βԪ������λ�õ���һ��λ�á�*/
typedef  struct SeqQueue  *PSeqQueue;	/* ˳��������͵�ָ������ */


struct  Node;
typedef  struct  Node  *PNode;
struct  Node { 			/* ���ṹ */
	DataType      info;
	PNode         link;
};
struct  LinkQueue { 		/* ���Ӷ������Ͷ��� */	
	PNode  f;  		/* ͷָ�� */
	PNode  r;  		/* βָ�� */
};			
typedef  struct LinkQueue  *PLinkQueue;  /*���Ӷ������͵�ָ������*/



struct SeqStack{
	int MAXNUM;
	int t;
	DataType * s;
};
typedef struct SeqStack * PSeqStack;


struct LinkStack /* ����ջ���Ͷ��� */
{
	PNode  top; /* ָ��ջ����� */
};
typedef  struct LinkStack  *PLinkStack;	 





PSeqStack createEmpty_seq(int m );
void  push_seq( PSeqStack pastack, DataType x );
void  pop_seq( PSeqStack pastack );
DataType  top_seq( PSeqStack pastack );
PLinkStack createEmptyStack_link(void) ;
int  isEmptyStack_link( PLinkStack plstack ) ;
void push_link( PLinkStack plstack, DataType x );
void  pop_link( PLinkStack plstack ) ;
DataType  top_link( PLinkStack plstack ) ;



PSeqQueue createEmptyQueue_seq(int m);			
void  enQueue_seq( PSeqQueue paqu, DataType x ) ;
int isEmptyQueue_seq(PSeqQueue paqu);
void  deQueue_seq( PSeqQueue paqu ) ;
DataType  frontQueue_seq( PSeqQueue paqu );

PLinkQueue  createEmptyQueue_link( void ) ;
int  isEmptyQueue_link( PLinkQueue plqu );
void  enQueue_link( PLinkQueue plqu, DataType x );
void  deQueue_link( PLinkQueue plqu ) ;
DataType  frontQueue_link( PLinkQueue plqu ) ;


/* -----���º�����Ե������㷨���8�� ----*/
PLinkQueue  createEmptyQueue_links8( void ) ;
int  isEmptyQueue_links8( PLinkQueue plqu );
void  enQueue_links8( PLinkQueue plqu, DataType x );
void  deQueue_links8( PLinkQueue plqu ) ;
DataType  frontQueue_links8( PLinkQueue plqu ) ;
/* -----���Ϻ�����Ե������㷨���8�� ----*/



#endif
