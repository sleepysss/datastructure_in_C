//method 1

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

void AddQ(int store[], int *front, int *end, int num)
{
	if (((*end) + 1) % 5 == (*front))  //隊伍的最後一個的下一個為隊伍開頭的前一個(代表有一個空位)(因為要留一個空位)    留空位的原因為如果不留,front==back可能會全滿或沒半個,留的話全滿的條件會變左邊那個
		return;
	else
	{
		*end = ((*end) + 1) % 5;
		store[*end] = num;
	}
}

void DeleteQ(int store[], int *front, int *end, int num)
{
	if ((*front) == (*end)) //隊伍中沒任何東西
		return;
	else
		(*front) = ((*front) + 1) % 5;
}

int main()
{
	//circular queue 畫圖較好理解
	int store[5];
	//front:隊伍開頭的前一個的index back:隊伍的最後一個的index  index initial to 0,0 if -1,-1 then continue add the condition in line 7 wont hold

	system("pause");
	return 0;
}


//method 2

typedef struct Q {
    int front;
    int back;
    int *store;
    int size;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {

    MyCircularQueue *ptr=(MyCircularQueue *)malloc(sizeof(MyCircularQueue));
    ptr->front=-1; //含
    ptr->back=-1; //含
    ptr->store=(int *)malloc(sizeof(int)*k);
    ptr->size=k;
    return ptr;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {

    if((obj->back+1)%obj->size==obj->front) //full
    {
        return false;
    }
    else if(obj->front==-1) //empty
    {
        obj->front++;
    }
    obj->back=(obj->back+1)%obj->size;
    obj->store[obj->back]=value;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {

    if(obj->front==-1) //empty
        return false;
    if(obj->front==obj->back) //剩一個(一定要做這個,不然不會work)
        obj->front=obj->back=-1; //丟回index-1
    else
        obj->front=(obj->front+1)%obj->size;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {

    return obj->front==-1?-1:obj->store[obj->front];

}

int myCircularQueueRear(MyCircularQueue* obj) {

    return obj->back==-1?-1:obj->store[obj->back];
    
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {

    //  empty時,back和front一定會是-1(因為init和dequeue的關係)

    return obj->front==-1; //或obj->back==-1
    
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {

    return (obj->back+1)%obj->size==obj->front;
    
}

void myCircularQueueFree(MyCircularQueue* obj) {

    free(obj->store);
    free(obj);
}
