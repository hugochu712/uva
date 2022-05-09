#include <stdio.h>

#define SWAP(a, b, t) ((t) = (a), (a) = (b), (b) = (t))

#define MAX_HEAP_SIZE 5000

long int maxHeap[MAX_HEAP_SIZE];
long int minHeap[MAX_HEAP_SIZE];
long int medianValue, value, temp;
int minHeapSize, maxHeapSize;

int main()
{
    maxHeapSize = 0;
    minHeapSize = 0;
    scanf("%ld", &medianValue);
    printf("%ld\n", medianValue);
    while (scanf("%ld", &value) != EOF)
    {
        if (value >= medianValue)
        {
            // push value to min heap
            minHeap[++minHeapSize] = value;
            for (int i = minHeapSize; i > 1; i >>= 1)
                if (minHeap[i] < minHeap[i>>1])
                    SWAP(minHeap[i], minHeap[i>>1], temp);
                else break;
        }
        else
        {
            // push value to max heap
            maxHeap[++maxHeapSize] = value;
            for (int i = maxHeapSize; i > 1; i >>= 1)
                if (maxHeap[i] > maxHeap[i>>1])
                    SWAP(maxHeap[i], maxHeap[i>>1], temp);
                else break;
        }

        if (minHeapSize == maxHeapSize + 2)
        {
            // push medianValue to max heap
            maxHeap[++maxHeapSize] = medianValue;
            for (int i = maxHeapSize; i > 1; i >>= 1)
                if (maxHeap[i] > maxHeap[i>>1])
                    SWAP(maxHeap[i], maxHeap[i>>1], temp);
                else break;

            // pop min heap to medianValue
            medianValue = minHeap[1];
            minHeap[1] = minHeap[minHeapSize--];
            for (int i = 2; i <= minHeapSize; )
            {
                if (minHeap[i] > minHeap[i+1])
                    i++;
                if (minHeap[i] < minHeap[i>>1])
                {
                    SWAP(minHeap[i], minHeap[i>>1], temp);
                    i <<= 1;
                }
                else break;
            }

            printf("%ld\n", medianValue);
        }
        else if (maxHeapSize == minHeapSize + 2)
        {
            // push medianValue to min heap
            minHeap[++minHeapSize] = medianValue;
            for (int i = minHeapSize; i > 1; i >>= 1)
                if (minHeap[i] < minHeap[i>>1])
                    SWAP(minHeap[i], minHeap[i>>1], temp);
                else break;

            // pop max heap to medianValue
            medianValue = maxHeap[1];
            maxHeap[1] = maxHeap[maxHeapSize--];
            for (int i = 2; i <= maxHeapSize; )
            {
                if (maxHeap[i] < maxHeap[i+1])
                    i++;
                if (maxHeap[i] > maxHeap[i>>1])
                {
                    SWAP(maxHeap[i], maxHeap[i>>1], temp);
                    i <<= 1;
                }
                else break;
            }

            printf("%ld\n", medianValue);
        }
        else if (maxHeapSize == minHeapSize + 1)
            printf("%ld\n", (medianValue + maxHeap[1])>>1);
        else if (minHeapSize == maxHeapSize + 1)
            printf("%ld\n", (medianValue + minHeap[1])>>1);
        else 
            printf("%ld\n", medianValue);
    }

    return 0;
}