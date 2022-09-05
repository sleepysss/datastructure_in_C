#include <stdio.h>

//return Returns the pivot's position in the original array
int partition(int store[], int first, int last)
{
    int pivot = store[last], temp;
    int count = first - 1;
    for (int i = first; i < last; ++i)
    {
        if (store[i] < pivot)
        {
            count++;
            temp = store[count];
            store[count] = store[i];
            store[i] = temp;
        }
    }
    count++;
    temp = store[count];
    store[count] = store[last];
    store[last] = temp;

    return count;
}

int quickselect(int store[], int k, int first, int last) //k:k-th smallest element of list
{
    int pivot = partition(store, first, last);
    if (pivot + 1 == k)
        return store[pivot];
    else if (pivot + 1 < k) //If pivot's position is less, recur for right subarray
        return quickselect(store, k, pivot + 1, last);
    else
        return quickselect(store, k, first, pivot - 1);
}

int main()
{
    int store[10] = {100,99,88,55,200,500,60,8,1,30};
    int num = quickselect(store, 10, 0, 9);
    printf("%d\n", num);

    return 0;
}
