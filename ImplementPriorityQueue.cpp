/* 
    class priQueue{

        int *arr;
        int size;

        priQueue(){
            arr = new int[1000];
            size = -1;
        }

        void push(int x);
        void pop();
        int getMaxElement();
        bool isempty();
    };
*/


/*
    Time Complexity of push operation: O(log(N))
    Space Complexity: O(1)

    where 'N' is the size of the Heap.
*/

// Function to return the parent of 'idx'
int parent(int idx) 
{

    return ( idx - 1 ) / 2;
}

// Function to return the left child of 'idx'
int leftChild(int idx) 
{

    return ( 2 * idx + 1 );
}

//Function to return right child of 'idx'
int rightChild(int idx) 
{

    return ( 2 * idx + 2) ;
}

// Moveup utility function used in push operation
void moveUp(int idx, int *arr)
{

    // Get the parent of 'idx'
    int prt = parent(idx);
    
    // Keep swapping the child with its parent until Heap property is satisfied
    while(idx > 0 && arr[idx] > arr[prt]){
        
        // Swaping parent with child
        swap(arr[idx], arr[prt]);
        
        // Recursively call moveUp operation on parent
        moveUp(prt, arr);
    }
}

// Function to perform push operation
void priQueue :: push(int data)
{

    // Increment the size of heap by one
    size += 1;

    // Store the data to the end of the Heap
    arr[size] = data;
    
    // To maintain the Heap property ( root element is greater than child element ) perform moveUp operation on size index
    moveUp(size, arr);
} 

/*
Time Complexity of pop operation: O(log(N))
Space Complexity: O(1)

where 'N' is the size of the Heap.
*/

// Utility function used in pop operation
void moveDown(int idx, int *arr, int size)
{
    
    // let 'greateridx' be 'idx'
    int greateridx = idx;

    // Get the left child of 'idx'
    int leftIdx = leftChild(idx);

    // Get the right child of 'idx'
    int rightIdx = rightChild(idx);

    // Compare curret greteridx with left child 
    if(leftIdx <= size && arr[leftIdx] > arr[greateridx]){
        greateridx = leftIdx;
    }

    //Compare current greteridx with right child
    if(rightIdx <= size && arr[rightIdx] > arr[greateridx]){
        greateridx = rightIdx;
    }

    // Swap the parent index 'idx' with greteridx 
    swap(arr[idx], arr[greateridx]);

    // If parent index 'idx' was not greater than it's child ,perform moveDown operation on its greatest child
    if(idx != greateridx)
    {
        moveDown(greateridx, arr, size);
    }
}

// Function to pop operation
void priQueue :: pop()
{

    // If size is negative i.e no data in heap, then do nothing
    if(size == -1)
    {
        return;
    }

    // Otherwise swap first element with last element
    swap(arr[0], arr[size]);

    // Decrease the size of Heap by One
    size -= 1;

    // To maintain the property of Heap  perform movedown opration on '0' index
    moveDown(0, arr, size);
}

/*
Time Complexity of getMaxElement operation: O(1)
Space Complexity: O(1)
*/

// Function that returns the maximum element from the Heap
int priQueue :: getMaxElement()
{
    
    // If Heap is empty 
    if(size == -1)
    {
        return -1;
    }

    // Otherwise return first Heap element
    return arr[0];
}

/*
Time Complexity of isEmpty operation: O(1)
Space Complexity: O(1)
*/

// Function to check whether Heap is empty(1) or not(0)
bool priQueue :: isempty()
{

    // If size of Heap is '-1', then Heap is empty
    if(size == -1)
    {
        return 1;
    }

    // Otherwise not empty
    return 0;
}