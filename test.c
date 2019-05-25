#include <stdio.h>

/*int dosomething(int x[],int n){
    int y[n];

    for (int i = 0; i < 2; i++)
    {   
        
        y[i]=x[i]+5;
    }
    return y;
    
}*/
int encoding(int r,int w,int boatflag){//编码返回s为id
    int s;
    s=8*r+w*2+boatflag;
    return s;
}
int two_r_cro(int r,int w,int boatflag){
    int s;
    if((r-2)>=0)
    {
        /* code */
        r=r-2;
        boatflag=!boatflag;
    }
    s=encoding(r,w,boatflag);
    return s; 
}
int main(){
    int r,w,boatflag,s;
    r=0;
    w=3;
    boatflag=1;
    s=two_r_cro(r,w,boatflag);
    //dosomething(b,2);
    printf("%d",s);
    return 0;
}