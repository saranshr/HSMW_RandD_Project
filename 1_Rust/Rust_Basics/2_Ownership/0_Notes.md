## **Understanding Ownership**  
&rarr; enables Rust to make memory safety guarantees without needing a garbage collector  

### **What is Ownership**  
* All programs have to manage the way the use a computer's memory while running  
* Some languages have garbage collection that constantly looks for unused memory as the program runs; in other languages the programmer must explicitly allocate and free the memory **(e.g. in C)**
* Rust uses a third approach: memory is managed through a system of ownership with a set of rules that the compiler checks at compile time &rarr; this does not slow down the program while its running

#### **The Stack and the Heap** 
* Both the stack and the heap are parts of memory that are available to your code to use at runtime, but are structured in different ways
* Stack &rarr; LIFO Structure  
    * Adding data is called _pushing onto the stack_ and removing data is called _popping off the stack_
    * All data must have a **known, fixed size**
    * Data with an _unknown size at compile time or a size that might change (dynamic)_ must be stored on the **heap**
* Heap &rarr; less organized
    * To put data on the heap, a certain amount of memory space is requested
    * The OS finds an empty, large enough, spot on the heap, marks it as being in use, and return a _pointer_, which is the address of that location
        * This is called _allocating (on the heap)_
* The pointer is a known, fixed size and can be stored on the stack; but when the actual data needs to be accessed, the pointer needs to be 'followed'

&rarr; When a function is called, the values passed into the function (including pointers to data on the heap) as well as the functions local variables get pushed onto the stack  
&rarr; Once the function is over, the values get popped off the stack  
&rarr; **Task of ownership:**  
1. Keeping track of data being used on the heap  
2. Minimizing amount of duplicate data on the heap  
3. Cleaning up unused data on the heap

#### **Ownership Rules**  
1. Each value in Rust has a variable that's called a _owner_
2. There can only be one owner at a time
3. WHen the owner goes out of scope, the value will be dropped