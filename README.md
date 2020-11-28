# CS163-Heap

Create a program that creates a heap.  (A binary tree where every node is larger than its child, which is called a max heap.) You should be able to enter a series of numbers (up to 100 numbers will be stored) OR enter a filename, which contains a space-separated list of numbers (with a range between 1 and 1000 for each number, and yes, this means your program should be able to handle both input methods). When finished, the heap should then be able to remove each element in order from the heap, adding them to the output. Continue until you have removed all of the numbers from the heap. The output will be from largest to smallest, since this is a max heap.

Finally, you have a visual way to display your tree when it is full. There should be an obvious way to see the parent-child relationship for each node, as well as each value. (This will help you greatly in debugging your code.)

A last word: no vectors, but you are allowed to implement this ADT as either a series of links OR as an array. I HIGHLY RECOMMEND YOU MAKE THE HEAP USING AN ARRAY. Assuming you start at index 1 (instead of 0), you can find your left child at (index * 2) and your right child at (index * 2 + 1), while your parent is (floor(index / 2)).

 

Numbers are entered into the heap correctly:  10 points

Numbers are removed from the heap correctly:  10 points

You have a way to visually represent the tree. 5 points

Comments. Really? I have to keep putting this on here? 5 points

 

Total: 30 points
