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





#include <stdio.h>

int asscending(int a,int b)
{
    return a<b;
}

int descending(int a,int b)
{
    return a>b;
}

void sorting(int store2[],int start,int end,int (*cmp)(int,int))
{
   for(int i=start;i<end-1;++i)
   {
       for(int j=start;j<end-1-i;++j)
       {
           if(!cmp(store2[j],store2[j+1]))
           {
               int temp=store2[j];
               store2[j]=store2[j+1];
               store2[j+1]=temp;
           }
       }
   }
}

int main()
{
    int store[10]={1,2,3,4,5,6,7,8,9,10},count_even=10,count_odd=-1; //count_even:第一個偶數,count_odd:最後一個奇數
    
    int store2[10];
    
    //分成奇數在前,偶數在後
    for(int i=0;i<10;++i)
    {
        if(store[i]%2) //odd
            store2[++count_odd]=store[i];
        else
            store2[--count_even]=store[i];
    }
    
    //對0~count_odd做小到大排序,對count_even~9做大到小排序
    sorting(store2,0,count_odd,asscending);
    sorting(store2,count_even,9,descending);
    
    for(int i=0;i<10;++i)
        printf("%d ",store2[i]);
    printf("\n");
    
    return 0;
}
