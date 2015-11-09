# Exam II

|Topics|
|---|
|[Hashing](#hashing)|
|[Priority Queue](#priority-queue)
|[Sorting](#sorting)|

# Hashing <a name="hashing"></a> [Instructor Notes](https://usu.instructure.com/courses/388377/files/58790856/download?wrap=1)

|Hashing|Concepts|
|---|---|
|[Hash Function](#hash-function)|Hash Function|
|[Collisions](#collisions)|Linear Probing|
||Clustering|
||Quadratic Probing|



## Hash Function <a name="hash-function"></a>


> This function is called a hash function because it “makes hash” of its inputs

A hash function is a function that:  
- When applied to an Object, returns a number- When applied to equal Objects, returns the same number for each- When applied to unequal Objects, is very unlikely to return the same number for each
- This function has no other purposeHash function with sliding bits and exclusive or

~~~cpp
unsigned int  hash(string key){unsigned int hashVal=0;   for (i=0; i < key.length(); i++)      hashVal =  (hashVal << 5) ^ key[i]  ^ hashVal;   return hashVal %TABLESIZE;}~~~

__Properties of a good hash function:__  - Minimize collisions  - Fast to compute  - Scatter data evenly through hash table. Data may have patterns to them.  - Uses all bits of the key – generally helps in scattering non-random data  - If mod is used, base should be prime  

## Collisions <a name="collisions"></a>

>When two values hash to the same array location, this is called a collision- Solution #1: Search from desired spot for an empty location  (with wrap)- Solution #2: Try again with a second hash function...and a third, and a fourth, and a fifth, ... to find a better location.- Solution #3: Create a linked list of values that hash to this location

### Linear Probing

> Use a vacant spot in table following HASH(key) – “open” addressing means that we find an unused address and use it. Evaluation - Longer search times - Clustering gets worse and worse (snowballs).  Primary clustering is when two keys that hash onto different values compete for same locations in successive hashes. - Better if successive probe locations are picked in “scrambled” order to lessen clustering.
- One problem with the “linear probing” is the tendency to form “clusters”

### Clustering
> A cluster is a group of items not containing any open slots- The bigger a cluster gets, the more likely it is that new values will hash into the cluster, and make it ever bigger- Clusters cause efficiency to degrade

- Primary Clustering
> is the tendency for certain open-addressing hash tables collision resolution schemes to create long sequences of filled slots.

- Secondary Clustering
> when different keys that hash to same locations compete for successive hash locations.

### Quadratic Probing

- Quadratic probing eliminates primary clustering, but not secondary clustering. __Note:__ For both linear and quadratic probing, the sequences checked are key independent.Two different keys which hash to same location, keep competing.### Double Hashing> Have two functions, Step gives the increment for Hash. - Define: Step(key) = 1 + key % (TABLESIZE - 2) – gives personalized increment. - Notice, the location of Step is never used directly as the hash value. It is only an auxiliary function. - If TABLESIZE and TABLESIZE–2 are primes, it works better. - Hash(key) = key % TABLESIZE - If Hash(key) is full, successively add increment as specified by Step(key). - __example:__ for key = 38 and TABLESIZE = 13
- - Each of the probe sequences visits all the table locations if the size of the table and the size of the increment are relatively prime with respect to each other. ### Bucket <a name="collisions-bucket"></a>
>Another way to handle collisions is to have each entry in the hash table hold more than one (B) item. - Each entry is called a bucket. - This doesn’t really solve the problem. As soon as the bucket fills up, you still have to deal with collisions. - I think it would be better to just have the original table B times as large. ### Separate Chaining <a name="collisions-separate-chaining"></a>
>Each location in the hash table is a pointer to a linked list of things that hashed to that location. __Advantages:__  
- Saves space if records are long  - Collisions are no problem   - Overflow is solved as space is dynamic   - Deletion is easy  
__Disadvantages:__  
- Links require space   - Following linked list is more time consuming

>Works well, but we have the overhead of pointers. ## Rehash <a name="rehash"></a>
>Rehash – create a larger  (or smaller) array.  Rehash all old elements into new array.## Efficiency <a name="hash-efficiency"></a>
> Hash tables are actually surprisingly efficient- Until the table is about 70% full, the number of probes (places looked at in the table) is typically only 2 or 3- Sophisticated mathematical analysis is required to prove that the expected cost of inserting into a hash table, or looking something up in the hash table, is O(1)- Even if the table is nearly full (leading to occasional long searches), efficiency is usually still quite high- load factor = number-of-elements / TABLESIZE - Should not exceed 2/3. - With chaining, the concern is the average size of a chain. ## Deletions <a name="hash-deletions"></a>
 > __solution:__ Use lazy deletions  
 
## Cuckoo Hashing
>Cuckoo hashing  worst-case constant lookup time. >The name derives from the behavior of some species of cuckoo, where the cuckoo chick pushes the other eggs or young out of the nest when it hatches; analogously, inserting a new key into a cuckoo hashing table may push an older key to a different location in the table.- There are two hash functions, one for each table.- If a key can’t go in either location, it tries to move the existing key to its alternative spot in the other table.- When a new key is inserted, the new key is inserted in one of its two possible locations, "kicking out", that is, displacing, any key that might already reside in this location. - This displaced key is then inserted in its alternative location, again kicking out any key that might reside there, until a vacant position is found, or the procedure enters an __infinite loop__. In the latter case, the __hash table__ is rebuilt __in-place__ using new __hash functions__:--# Priority Queue <a name="priority-queue"></a> [Instructor Notes](https://usu.instructure.com/courses/388377/files/58841559/download?wrap=1)> Anything Greedy|Main Idea|Sub idea|Description|
|---|---|---|
|Binary Heap|
|D-Heap|Examples:  
- ordering CPU jobs  - searching for the exit in a maze (or looking for moves in the rotation puzzle game)  - emergency room admission processing  

You don't need to be as sorted as other data structures (BST trees, Splay trees, AVL trees)

## Binary Heap

```c++
// Delete Code
Comparable deleteMin(){  x = A[0];  A[0]=A[size--];  percolateDown(0);  return x;}
percolateDown(int hole) {  shiftVal=heap[hole];  while (2*hole+1 <= size) {    left = 2*hole+1;     right = left + 1;    if (right <= size &&         heap[right] < heap[left])      target = right;    else      target = left;    if (heap[target] < shiftVal) {      heap[hole] = heap[target];      hole = target;    }    else      break;  }  Heap [hole] = shiftVal;}

// Insert Code
void insert(Comparable newVal) {  // Efficiency hack: we won’t actually put newVal  // into the heap until we’ve located the position  // it goes in.  This avoids having to copy it  // repeatedly during the percolate up.  int hole = ++size;  // Percolate up  for( ; hole>0 && newVal < heap[(hole-1)/2] ;          hole = (hole-1)/2)    heap[hole] = heap[(hole-1)/2];   heap[hole] = newVal;}```

Floyd's method  

```c++  
buildHeap(){  for (i=size/2; i>0; i--)     percolateDown(i);}

// O(n log n) worst case, but O(n) average case.// Can we get a worst case O(n) bound?```

### Performance

||Binary Heap Worst Case|Binary Heap Average Case|AVL Worst|BST Average|
|---|:---:|:---:|:---:|:---:|
|Insert|(log n)		|O(1) *2.6 compares*|O(log n)|O(log n)|
|Delete Min|O(log n)|O(log n)				|O(log n)|O(log n)|
### Observations
- finding a child/parent index is a multiply/divide by two- each percolate down operation looks at only two kids- inserts are at least as common as deleteMins
### Realities
- division and multiplication by powers of two are fast- with huge data sets (that can’t be stored in main memory), memory - accesses dominate## D-Heap <a name="queue-d-heap"></a>

### Definition:

- Each node has d children- Still representable by array### Good choices for d:- optimize performance based on # of inserts/removes- power of two for efficiency- fit one set of children in a cache line  (the block of memory that - is transferred to memory cache)- fit one set of children on a memory page/disk block### Merging

--# Sorting <a name="sorting"></a> [Instructor Notes](https://usu.instructure.com/courses/388377/files/58888554/download?wrap=1)
  
|Main Idea|Sub Idea|Complexity|Adaptive|Stable|in-Place|
|---|---|---|---|---|---|
|Sort Theory	| Adaptive(Non-oblivious)	| Definition |
|				|Stable						| Definition |
|Non-Recursive Sorts|Bubble Sort|		O(n^2)|Adaptive|Stable
|						|Insertion Sort|	O(n^2)|Adaptive|Stable
|						|Selection Sort|	O(n^2)|Not Adaptive|Not Stable
|Recursive Sorts	|Quicksort|
|					|Shell|
|					|Heap|
|					|Merge|


## Adaptive / Non-Oblivious

- faster with mostly sorted data

## Stable

## In-Place

## Non-Recursive Sorts <a name="sorting-non-recursive-sorts"></a>

|Sorts|Complexities|Oblivious|Adaptive|Stable
|---|---|---|---|---|
|Bubble|O(n) - O(n^2)||Adaptive|Stable
|Selection|O(n^2)||Not Adaptive|not stable
|Insertion|O(n) - O(n^2)||Adaptive|Stable

## bubble sort

- A sorting algorithm is said to be stable if two objects with equal keys appear in the same order in sorted output as they appear in the input array to be sorted. Some sorting algorithms are stable by nature like Insertion sort, Merge Sort, Bubble Sort, etc.Oct 5, 2009

## Insertion Sort
> Although it is one of the elementary sorting algorithms with O(n2) worst-case time, insertion sort is the algorithm of choice either when the data is nearly sorted (because it is adaptive) or when the problem size is small (because it has low overhead).

>For these reasons, and because it is also stable, insertion sort is often used as the recursive base case (when the problem size is small) for higher overhead divide-and-conquer sorting algorithms, such as merge sort or quick sort. 


## Selection Sort

> From the comparions presented here, one might conclude that selection sort should never be used. It does not adapt to the data in any way (notice that the four animations above run in lock step), so its runtime is always quadratic.

> However, selection sort has the property of minimizing the number of swaps. In applications where the cost of swapping items is high, selection sort very well may be the algorithm of choice. 

## Recursive Sorts  
|Sorts|Complexities|Adaptive|Stable|in-place|
|---|---|---|---|---|
|Quicksort|
|Shell|O(n^1/2) - O(nlogn)|Adaptive|not stable
|Heap|Ologn)|Not adaptive|Not stable|in-place
|Merge|O(nlogn)|Not adaptive|Stable

## Quicksort

- partitions


## Shell Sort
> The worse-case time complexity of shell sort depends on the increment sequence. For the increments 1 4 13 40 121..., which is what is used here, the time complexity is O(n3/2). For other increments, time complexity is known to be O(n4/3) and even O(n·lg2(n)). Neither tight upper bounds on time complexity nor the best increment sequence are known.

> Because shell sort is based on insertion sort, shell sort inherits insertion sort's adaptive properties. The adapation is not as dramatic because shell sort requires one pass through the data for each increment, but it is significant. For the increment sequence shown above, there are log3(n) increments, so the time complexity for nearly sorted data is O(n·log3(n)).

> Because of its low overhead, relatively simple implementation, adaptive properties, and sub-quadratic time complexity, shell sort may be a viable alternative to the O(n·lg(n)) sorting algorithms for some applications when the data to be sorted is not very large. 

## Heap Sort
> Heap sort is simple to implement, performs an O(n·lg(n)) in-place sort, but is not stable.

> The first loop, the Θ(n) "heapify" phase, puts the array into heap order. The second loop, the O(n·lg(n)) "sortdown" phase, repeatedly extracts the maximum and restores heap order.

> The sink function is written recursively for clarity. Thus, as shown, the code requires Θ(lg(n)) space for the recursive call stack. However, the tail recursion in sink() is easily converted to iteration, which yields the O(1) space bound.

> Both phases are slightly adaptive, though not in any particularly useful manner. In the nearly sorted case, the heapify phase destroys the original order. In the reversed case, the heapify phase is as fast as possible since the array starts in heap order, but then the sortdown phase is typical. In the few unique keys case, there is some speedup but not as much as in shell sort or 3-way quicksort. 


## Mege Sort
> Merge sort is very predictable. It makes between 0.5*lg(n) and lg(n) comparisons per element, and between lg(n) and 1.5*lg(n) swaps per element. The minima are achieved for already sorted data; the maxima are achieved, on average, for random data. If using Θ(n) extra space is of no concern, then merge sort is an excellent choice: It is simple to implement, and it is the only stable O(n·lg(n)) sorting algorithm. Note that when sorting linked lists, merge sort requires only Θ(lg(n)) extra space (for recursion).

> Merge sort is the algorithm of choice for a variety of situations: when stability is required, when sorting linked lists, and when random access is much more expensive than sequential access (for example, external sorting on tape).

> There do exist linear time in-place merge algorithms for the last step of the algorithm, but they are both expensive and complex. The complexity is justified for applications such as external sorting when Θ(n) extra space is not available. 



## Appendix

- __Greedy:__ A greedy algorithm is an algorithm that follows the problem solving heuristic of making the locally optimal choice at each stage with the hope of finding a global optimum.