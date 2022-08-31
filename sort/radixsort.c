#include <stdio.h>

int getbiggest(int data[],int size)
{
    int biggest=data[0];
    for(int i=0;i<size;++i)
    {
        if(data[i]>biggest)
            biggest=data[i];
    }
    return biggest;
}

void sort(int data[],int size,int n)
{
    int store[10][10]={0};
    int count_store[10]={0}; //看各個bucket現在裡面有幾個數字
    
    //分配到bucket
    for(int i=0;i<size;++i)
    {
        int num=(data[i]/n)%10;  //看這個數字(對應的位數)要分配到哪個桶
        store[num][count_store[num]]=data[i];
        count_store[num]++;
    }
    
    //重新排成新的數列(collect)
    int data_count=0;
    for(int i=0;i<10;++i)
    {
        for(int j=0;j<count_store[i];++j)
        {
            data[data_count]=store[i][j];
            data_count++;
        }
    }
}

void print_array(int data[],int size)
{
    for(int i=0;i<size;++i)
        printf("%d ",data[i]);
    printf("\n");
}

void radixsort(int data[],int size)
{
    int biggest_data=getbiggest(data,size);
    
    for(int n=1;(biggest_data/n)>0;n*=10) //using LSD n的用途為取個位數,十位數...的值
    {
        sort(data,size,n);
        print_array(data,size); //each round
    }
}


int main()
{
    int data[10] = {73, 22, 93, 43, 55, 14, 28, 65, 39, 1000};
    
    radixsort(data,10);

    return 0;
}
