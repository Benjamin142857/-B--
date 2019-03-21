#ifndef _CHAPTER4_
#define _CHAPTER4_


typedef int DataType;

struct  SeqQueue{ /* 顺序队列类型定义 */
int  MAXNUM;      /* 队列中最大元素个数 */
int  f,r;    
DataType  *q;
};
/*为了算法设计上的方便：
  f 指出实际队头元素所在的位置，
  r 指出实际队尾元素所在位置的下一个位置。*/
typedef  struct SeqQueue  *PSeqQueue;	/* 顺序队列类型的指针类型 */


struct  Node;
typedef  struct  Node  *PNode;
struct  Node { 			/* 结点结构 */
	DataType      info;
	PNode         link;
};
struct  LinkQueue { 		/* 链接队列类型定义 */	
	PNode  f;  		/* 头指针 */
	PNode  r;  		/* 尾指针 */
};			
typedef  struct LinkQueue  *PLinkQueue;  /*链接队列类型的指针类型*/



struct SeqStack{
	int MAXNUM;
	int t;
	DataType * s;
};
typedef struct SeqStack * PSeqStack;


struct LinkStack /* 链接栈类型定义 */
{
	PNode  top; /* 指向栈顶结点 */
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


/* -----以下函数针对第四章算法题第8题 ----*/
PLinkQueue  createEmptyQueue_links8( void ) ;
int  isEmptyQueue_links8( PLinkQueue plqu );
void  enQueue_links8( PLinkQueue plqu, DataType x );
void  deQueue_links8( PLinkQueue plqu ) ;
DataType  frontQueue_links8( PLinkQueue plqu ) ;
/* -----以上函数针对第四章算法题第8题 ----*/



#endif
