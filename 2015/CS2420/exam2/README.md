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

- This function has no other purpose

~~~cpp
unsigned int  hash(string key)

__Properties of a good hash function:__  

## Collisions <a name="collisions"></a>

>When two values hash to the same array location, this is called a collision

### Linear Probing

> Use a vacant spot in table following HASH(key) – “open” addressing means that we find an unused address and use it. 
- One problem with the “linear probing” is the tendency to form “clusters”

### Clustering
> A cluster is a group of items not containing any open slots

- Primary Clustering
> is the tendency for certain open-addressing hash tables collision resolution schemes to create long sequences of filled slots.

- Secondary Clustering
> when different keys that hash to same locations compete for successive hash locations.

### Quadratic Probing

- Quadratic probing eliminates primary clustering, but not secondary clustering. 
- - Each of the probe sequences visits all the table locations if the size of the table and the size of the increment are relatively prime with respect to each other. 
>Another way to handle collisions is to have each entry in the hash table hold more than one (B) item. 
>Each location in the hash table is a pointer to a linked list of things that hashed to that location. 
- Saves space if records are long  
__Disadvantages:__  
- Links require space   

>Works well, but we have the overhead of pointers. 
>Rehash – create a larger  (or smaller) array.  Rehash all old elements into new array.
> Hash tables are actually surprisingly efficient
 > __solution:__ Use lazy deletions  
 
## Cuckoo Hashing
>Cuckoo hashing  worst-case constant lookup time. 
|---|---|---|
|Non-Mergable Heaps	|[Binary Heap](#queue-binary-heap)|
|						|[D-Heap](#queue-d-heap)|
|Mergable Heaps	|[Leftist Heap](#queue-leftist-heap)|
|					|[Binomial Queue](#queue-binomial-queue)|
- ordering CPU jobs  

You don't need to be as sorted as other data structures (BST trees, Splay trees, AVL trees)

## Binary Heap <a name="queue-binary-heap"></a>

```c++
// Delete Code
Comparable deleteMin(){
percolateDown(int hole) {

// Insert Code
void insert(Comparable newVal) {

Floyd's method  

```c++  
buildHeap(){

// O(n log n) worst case, but O(n) average case.

### Performance

||Binary Heap Worst Case|Binary Heap Average Case|AVL Worst|BST Average|
|---|:---:|:---:|:---:|:---:|
|Insert|(log n)		|O(1) *2.6 compares*|O(log n)|O(log n)|
|Delete Min|O(log n)|O(log n)				|O(log n)|O(log n)|





### Definition:

- Each node has d children

Complexity of O(n) with Floyd's method

## Leftist Heap <a name="queue-leftist-heap"></a>
> Binary heap-ordered trees with left subtrees always “longer” than right subtrees
> A heap structure that enables fast merges

- Main idea: Recursively work on right path for Merge/Insert/DeleteMin

> the null path length (npl) of a node is the smallest number of nodes between it and a null in the tree

- Basically, the shortest path must be to the right.  So, if you always take the shortest path, it can’t be longer than log n.

- If both the left and right sub-trees are leftist heaps but the root does not form a leftist heap, We only need to swap the two sub-trees
Node * merge (Node * t1, Node * t2)   // t1 and t2 are merged, new tree is created

### Problems with leftist heaps
## Skew Heap <a name="queue-skew-heap"></a>
> Self-adjusting version of leftist heaps (a la splay trees)

> Motivation? Remember that we “often” get heavy right sides when we merge.

> We can make a simple modification to the leftist heap and get similar results without storing (or computing) the null path length.

- Do not actually keep track of path lengths

Skew Notes

- blind adjusting version of leftist heaps
```c++
Node * SkewHeapMerge (Node * t1, Node * t2)   // t1 and t2 are merged, a new tree

## Binomial Queue <a name="queue-binomial-queue"></a>



  
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
- __Null Path Length:__ the null path length (npl) of a node is the smallest number of nodes between it and a null in the tree