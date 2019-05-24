#include <stdio.h>
#include <string.h>

struct node{
    int a[2];
    int b[2];
    int boatflag;
    struct node *nextnode[3]={0,0,0};
    char id[5];
};
static struct node nodeindex[30];
int ifok(struct node tempnode){
    //if rubbits are safe
    if ((tempnode.a[0]<0)||(tempnode.a[1]<0)||(tempnode.b[0]<0)||(tempnode.b[1]<0))
    {
        return 0;
    }
    else{
        if(((tempnode.a[0] < tempnode.a[1])&&(tempnode.a[0]!=0))||((tempnode.b[0]!=0)&&(tempnode.b[0] < tempnode.b[1])))
        return 0;
        else
        {
            return 1;
        }
    } 
}
struct node two_r_to_b(struct node tempnode){
    tempnode.a[0] = tempnode.a[0]-2;
    tempnode.b[0] = tempnode.b[0]+2;
    return tempnode;
}
struct node r_w_to_b(struct node tempnode){
 
    tempnode.a[0] = tempnode.a[0]-1;
    tempnode.a[1] = tempnode.a[1]-1;
    tempnode.b[0] = tempnode.b[0]+1;
    tempnode.b[1] = tempnode.b[1]+1;
    return tempnode;
}
struct node two_w_to_b(struct node tempnode){
    tempnode.a[1] = tempnode.a[1]-2;
    tempnode.b[1] = tempnode.b[1]+2;
    return tempnode;
}
struct node one_w_to_a(struct node tempnode){
    tempnode.a[1] = tempnode.a[1]+1;
    tempnode.b[1] = tempnode.b[1]-1;
    return tempnode;
}
struct node one_r_to_a(struct node tempnode){
    tempnode.a[0] = tempnode.a[0]+1;
    tempnode.b[0] = tempnode.b[0]-1;
    return tempnode;
}

int main()
{
    struct node start;
    start.a[0]=3;
    start.a[1]=3;
    start.b[0]=0;
    start.b[1]=0;
    start.boatflag=0;
    strcpy(start.id, "33000");
    printf("%d\n",ifok(two_r_to_b(start)));
    printf("%d\n%d\n%s\n",start.a[0],start.b[0],start.id);
    printf("%d\n%d\n",start.a[0],start.b[0]);
    int *test[2];
    memset(test,0,sizeof(test));
    //test[0]='a';
    printf("%d",test[0]);
    printf("%d",test[1]);
    
    return 0;
}