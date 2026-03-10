#define MAX 100005

typedef struct {
    int maxHeap[MAX]; // lower half
    int maxSize;
    int minHeap[MAX]; // upper half
    int minSize;
} MedianFinder;

// Max Heap helpers
void maxPush(int* heap, int* size, int val) {
    heap[++(*size)] = val;
    int i = *size;
    while (i > 1 && heap[i] > heap[i/2]) {
        int tmp = heap[i]; heap[i] = heap[i/2]; heap[i/2] = tmp;
        i /= 2;
    }
}

int maxPop(int* heap, int* size) {
    int top = heap[1];
    heap[1] = heap[(*size)--];
    int i = 1;
    while (1) {
        int largest = i, l = 2*i, r = 2*i+1;
        if (l <= *size && heap[l] > heap[largest]) largest = l;
        if (r <= *size && heap[r] > heap[largest]) largest = r;
        if (largest == i) break;
        int tmp = heap[i]; heap[i] = heap[largest]; heap[largest] = tmp;
        i = largest;
    }
    return top;
}

// Min Heap helpers
void minPush(int* heap, int* size, int val) {
    heap[++(*size)] = val;
    int i = *size;
    while (i > 1 && heap[i] < heap[i/2]) {
        int tmp = heap[i]; heap[i] = heap[i/2]; heap[i/2] = tmp;
        i /= 2;
    }
}

int minPop(int* heap, int* size) {
    int top = heap[1];
    heap[1] = heap[(*size)--];
    int i = 1;
    while (1) {
        int smallest = i, l = 2*i, r = 2*i+1;
        if (l <= *size && heap[l] < heap[smallest]) smallest = l;
        if (r <= *size && heap[r] < heap[smallest]) smallest = r;
        if (smallest == i) break;
        int tmp = heap[i]; heap[i] = heap[smallest]; heap[smallest] = tmp;
        i = smallest;
    }
    return top;
}

MedianFinder* medianFinderCreate() {
    MedianFinder* obj = (MedianFinder*)calloc(1, sizeof(MedianFinder));
    return obj;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    // Push to max heap (lower half)
    maxPush(obj->maxHeap, &obj->maxSize, num);

    // Balance: max of lower <= min of upper
    minPush(obj->minHeap, &obj->minSize, maxPop(obj->maxHeap, &obj->maxSize));

    // Keep maxHeap size >= minHeap size
    if (obj->minSize > obj->maxSize)
        maxPush(obj->maxHeap, &obj->maxSize, minPop(obj->minHeap, &obj->minSize));
}

double medianFinderFindMedian(MedianFinder* obj) {
    if (obj->maxSize > obj->minSize)
        return (double)obj->maxHeap[1];
    return (obj->maxHeap[1] + obj->minHeap[1]) / 2.0;
}

void medianFinderFree(MedianFinder* obj) {
    free(obj);
}
