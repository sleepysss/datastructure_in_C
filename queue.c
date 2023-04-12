//init rear=-1(include),front=-1(include)

void insert()
{
    int item;
    if(rear == MAX - 1)
        printf("Queue Overflow n");
    else
    {
        if(front== - 1)
            front = 0;
        printf("Inset the element in queue : ");
        scanf("%d", &item);
        rear = rear + 1;
        queue_array[rear] = item;
    }
}

void delete()
{
    if(front == - 1 || front > rear)
    {
        printf("Queue Underflow n");
        return;
    }
    else
    {
        printf("Element deleted from queue is : %dn", queue_array[front]);
        front = front + 1;
    }
}
