#include "stdio.h"
#include "stdlib.h"
#define  MAXSIZE  32

typedef  struct {
  int   data[MAXSIZE];  /*队列的存储空间*/
  int front, rear;  /*队头队尾指针*/
}SeqQueue,*PSeqQueue;

PSeqQueue  Init_SeqQueue( )
{   /*初始化队列。返回值：新顺序队列指针，null表示失败*/
           PSeqQueue  Q;
           Q=(PSeqQueue)malloc(sizeof(SeqQueue));
           if (Q) {
                  Q->front=0;
                 Q->rear=0;
           }
           return Q;
}

int  Empty_SeqQueue(PSeqQueue Q)
/*判空队列。返回值：1表示为空，0表示非空*/
 {   if (Q && Q->front==Q->rear)
        return (1);
     else
        return (0);   
 }

 int   In_SeqQueue (PSeqQueue Q , int  x)
     {    /*入队。返回值：1表示成功，－1表示队满溢出*/
          if ((Q->rear+1)%MAXSIZE==Q->front)
         {    printf("队满");
               return -1;   /*队满不能入队*/
         }
         else 
        {     Q->rear=(Q->rear+1) % MAXSIZE;
               Q->data[Q->rear]=x;
               return 1;    /*入队完成*/
        }
     }
int  Out_SeqQueue (PSeqQueue Q,int *x)
           {   /*出队。返回值：1表示成功，－1表示队空,出队的元素保存到*x  */
                 if (Empty_SeqQueue(Q)) {      
                     printf("队空");
                     return -1;   /*队空不能出队*/
                }
                else
                {  Q->front=(Q->front+1) % MAXSIZE;
                    *x=Q->data[Q->front];
                     return 1;    /*出队完成*/
                }
           }
int encoding(int r,int w,int boatflag){//编码返回s为id
    int s;
    s=8*r+w*2+boatflag;
    return s;
}
/*int decoding(int s,int *dataf){//解码返回一个数组地址之中是一个兔、狼、船标
    int r,w,boatflag;
    int data[3];
    r=s/8;
    w=(s%8)/2;
    boatflag=s%2;
    data[0]=r;
    data[1]=w;
    data[2]=boatflag;
    dataf=data;
    return 0;
}*/
int isSafe(int s)
{
    int r,w,boltflag;
    r=s/8;
    w=(s%8)/2;
    boltflag=s%2;
	if((r!=0&&w>r)||((3-r)!=0&&(3-w)>(3-r)))
    {
         return 0;
    }
    else 
    return 1;
}
int r_and_w_cro(int status)
{
    int s,r,w,boatflag;
    r=status/8;
    w=(status%8)/2;
    boatflag=status%2;
    if(boatflag==1)
    {
    if((r-1)>=0&&(w-1)>=0)
    {
        r=r-1;
        w=w-1;
        boatflag=!boatflag;
    }
    s=encoding(r,w,boatflag);
    return s;   
    }
    else
    {
    if((3-r-1)>=0&&(3-w-1)>=0)
    {
        r=r+1;
        w=w+1;
        boatflag=!boatflag;
    }
    s=encoding(r,w,boatflag);
    return s;   
    }  
}
int two_r_cro(int status)
{
    int s,r,w,boatflag;
    r=status/8;
    w=(status%8)/2;
    boatflag=status%2;
    if(boatflag==1)
    {
    if((r-2)>=0)
    {
        r=r-2;
        boatflag=!boatflag;
    }
    s=encoding(r,w,boatflag);
    return s;   
    }
    else
    {
    if((3-r-2)>=0)
    {
        r=r+2;
        boatflag=!boatflag;
    }
    s=encoding(r,w,boatflag);
    return s;   
    }  
}
int two_w_cro(int status)
{
    int s,r,w,boatflag;
    r=status/8;
    w=(status%8)/2;
    boatflag=status%2;
    if (boatflag==1)
    { 
    if((w-2)>=0)
    {
        w=w-2;
        boatflag=!boatflag;
    }
    s=encoding(r,w,boatflag);
    return s; 
    }
    else
    {
    if((3-w-2)>=0)
    {
        w=w+2;
        boatflag=!boatflag;
    }
    s=encoding(r,w,boatflag);
    return s; 
    }  
}
int one_w_cro(int status){
    int s,r,w,boatflag;
    r=status/8;
    w=(status%8)/2;
    boatflag=status%2;
    if (boatflag==1)
    {
        if((w-1)>=0)
    {
        w=w-1;
        boatflag=!boatflag;
    }
    s=encoding(r,w,boatflag);
    return s; 
    }
    else
    {
    if((3-w-1)>=0)
    {
        w=w+1;
        boatflag=!boatflag;
    }
    s=encoding(r,w,boatflag);
    return s;
    }  
}
int one_r_cro(int status){
    int s,r,w,boatflag;
    r=status/8;
    w=(status%8)/2;
    boatflag=status%2;
    if (boatflag==1)
    {
        if((r-1)>=0)
    {
        r=r-1;
        boatflag=!boatflag;
    }
    s=encoding(r,w,boatflag);
    return s; 
    }
    else
    {
        if((3-r-1)>=0)
    {
        r=r+1;
        boatflag=!boatflag;
    }
    s=encoding(r,w,boatflag);
    return s; 
    }
}

void farmerCrossing()
{
PSeqQueue Q;
int visited[32],i,status,nextStatus,r,w,boatflag;

Q = Init_SeqQueue( ); 
for(i = 0;i < 32;i++)
	visited[i] = -1;

	status = 31;
	In_SeqQueue (Q , status);
visited[31] = 0; 
while(!Empty_SeqQueue(Q) && (visited[0]== -1))/* BFS */
{
Out_SeqQueue (Q,&status);
printf("\n");
printf("out%d  ",status);
nextStatus = two_r_cro(status);
if(isSafe(nextStatus) && (visited[nextStatus]== -1))
    {
        In_SeqQueue (Q , nextStatus);
        visited[nextStatus] = status;
        printf("in%d ",nextStatus);
    } 
nextStatus = two_w_cro(status);
if(isSafe(nextStatus) && (visited[nextStatus]== -1))
    {
        In_SeqQueue (Q , nextStatus);
        visited[nextStatus] = status;
        printf("in%d ",nextStatus);
    } 
nextStatus = one_r_cro(status);
if(isSafe(nextStatus) && (visited[nextStatus]== -1))
    {
        In_SeqQueue (Q , nextStatus);
        visited[nextStatus] = status;
        printf("in%d ",nextStatus);
    }
nextStatus = one_w_cro(status);
if(isSafe(nextStatus) && (visited[nextStatus]== -1))
    {
        In_SeqQueue (Q , nextStatus);
        visited[nextStatus] = status;
        printf("in%d ",nextStatus);
    } 
nextStatus = r_and_w_cro(status);
if(isSafe(nextStatus) && (visited[nextStatus]== -1))
    {
        In_SeqQueue (Q , nextStatus);
        visited[nextStatus] = status;
        printf("in%d ",nextStatus);
    } 
/*for(who = 1; who <= 8; who <<= 1)
{
    if(((status&0x08) != 0) == ((status&who) != 0))
    {
        nextStatus = status ^ (0x08 | who);
         
        if(isSafe(nextStatus) && (visited[nextStatus]== -1))
        {
            In_SeqQueue (Q , nextStatus);
            visited[nextStatus] = status;
            printf("in%d ",nextStatus);
        } 
    }
  
}*/
}
nextStatus = 0;
printf("\nthe reverse rout:");  
while(visited[nextStatus]!= -1)
   {
      printf("%d  ",visited[nextStatus]);
   	  nextStatus = visited[nextStatus];
        
   	  if(nextStatus == 0) exit(0);
   	  	  
   }
   
} 

int main(void)
{
 farmerCrossing();
  return 0;
}