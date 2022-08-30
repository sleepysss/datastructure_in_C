#include <stdio.h>

int main()
{
    int temp,flag=1,size=10;
    int store[10]={5,7,6,3,8,9,1,2,5,4};
    
    for(int i=0;flag&&i<size-1;++i)  //i代表第幾次搜尋
    {
        flag=0; //flag==0代表已完成排序
        for(int j=0;j<size-1-i;++j) //j代表比較第j對  (5,7) (7,6) (6,3) ...
        {
            if(store[j]>store[j+1]) //因為是從小到大,所以若前面的比後面的大就要交換
            {
                temp=store[j];
                store[j]=store[j+1];
                store[j+1]=temp;
                flag=1;
            }
        }
    }

    for(int i=0;i<size;++i)
        printf("%d ",store[i]);
    printf("\n");
    
    
    return 0;
}
