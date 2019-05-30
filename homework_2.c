#include "stdio.h"
#include "stdlib.h"
#define  MAXSIZE  32

typedef  struct {
  int   data[MAXSIZE];  
  int front, rear;  
}SeqQueue,*PSeqQueue;

PSeqQueue  Init_SeqQueue( )
{   //初期化queue
           PSeqQueue  Q;
           Q=(PSeqQueue)malloc(sizeof(SeqQueue));
           if (Q) {
                  Q->front=0;
                 Q->rear=0;
           }
           return Q;
}

int  Empty_SeqQueue(PSeqQueue Q)
 {   if (Q && Q->front==Q->rear)
        return (1);
     else
        return (0);   
 }

 int   In_SeqQueue (PSeqQueue Q , int  x)
     {
          if ((Q->rear+1)%MAXSIZE==Q->front)
         {    printf("full");
               return -1;   
         }
         else 
        {     Q->rear=(Q->rear+1) % MAXSIZE;
               Q->data[Q->rear]=x;
               return 1;   
        }
     }
int  Out_SeqQueue (PSeqQueue Q,int *x)
           {   
                 if (Empty_SeqQueue(Q)) {      
                     printf("empty");
                     return -1;   
                }
                else
                {  Q->front=(Q->front+1) % MAXSIZE;
                    *x=Q->data[Q->front];
                     return 1;    
                }
           }
int encoding(int r,int w,int boatflag){//状態をidに
    int s;
    s=8*r+w*2+boatflag;
    return s;
}
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

void Crossing()
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
}
nextStatus = 0;
printf("\nthe reverse rout:\n");
printf("0 0 0\n");  
while(visited[nextStatus]!= -1)
   {
        if(visited[nextStatus]==0){
            printf("start\n");
            exit(0);
        }
        int temp_r,temp_w,temp_boatflag;
        temp_r=visited[nextStatus]/8;
        temp_w=(visited[nextStatus]%8)/2;
        temp_boatflag=visited[nextStatus]%2;
        printf("%d %d %d\n",temp_r,temp_w,temp_boatflag);
        nextStatus = visited[nextStatus];
        //if(nextStatus == 0) exit(0);
   	  	  
   }
   
} 

int main(void)
{
  Crossing();
  return 0;
}