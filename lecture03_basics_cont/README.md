# 📝 Notes

C++ Basics Continued

## Memory

- two different types of memory
  - stack
  - heap
- when a program is launched, os gives it access to a number of areas of memory
- the main two that we can manipulate are the stack memory and heap memory
- both stack and heap stored in RAM, difference is determined by the OS when program runs

## Stack/Heap

- at a basic level both just store data
- we request an amount of memory from either stack or heap then it provides that memory to us
- the main differences are
  - the size of available memory
  - the way memory is found/allocated
  - the speed of memory allocation
  - the way we request memory in our code
  - stack memory deallocated when leaves scope

#### Example Syntax

Primitive

```c++
int main()
{
  int val = 5; // stack
  int* hval = new int; // heap
  *hval = 5;
}
```

List

```c++
int main()
{
  int a[5]; // stack
  int* ha = new int[5]; // heap
  ha[3] = 10;
}
```

Class

```c++
int main()
{
  MyClass c(args); // stack
  // heap allocation with new
  MyClass * hc = new MyClass(args);
}
```

### Stack

- has predefined size
- very easy to run out of stack memory
- local variables without `new` are allocated on the stack by default
- program function calls / return addresses are also allocated on the stack
- aka "static memory"
- stack memory allocation sizes need to be known at _compile_ time
- memory allocation which depends on **runtime** variables must be **heap allocated**

### Heap

- much more space available than stack
- allocation via the `new` keyword
  `Type * varName = new Type;`
- calls C function _malloc_ under the hood
- os finds a contiguous chunk of memory and returns a pointer to it
  - this is very complicated and expensive
  - **use this only when you have to**
- you then access the memory via pointer

### Stack/Heap example

This example shows some code + how it is stored in memory

```c++
int main()
{
  int i = 6; // stack
  int j = 10; // stack
  Point* p = new Point(5,4); // heap
  int arr[2] = {3, 4}; // stack
}
```

#### Heap

starts from top and goes down

| addr | value |
| ---- | ----- |
| 0x1  | 5     |
| 0x2  | 4     |

#### Stack

starts at the bottom and goes up

| value |
| ----- |
| 4     |
| 3     |
| 0x1   |
| 10    |
| 6     |

> 🚨 Heaps are not garbage colleted you need to remove it with `delete`

```c++
int main()
{
  int i = 6;
  int j = 10;
  Point* p = new Point(5,4);
  int arr[2] = {3, 4};
  delete p; // line that removes the heap
}
```

> 📝
> Stack = Fast, Limited
> Heap = Slow, Larger

## Pointers

- Same as pointers in C
- A pointer stores a memory address with an associated type
- Modifying the pointer variable modifies the address it **points** to
- To modify the value of the data in the memory that it points to, we **dereference**
- "Raw" pointers can be very unsafe

```c++
int main()
{
  int i = 6; // local int var
  int * p; // pointer to int
  p = &i; // & = address of
  *p = 7; // * = dereference
}
```

### Why use pointers?

- Must use pointer for inheritance
  - `Base * ptr = new Derived();`
- Pass by value vs by reference
  - Modifying variable passed into function
- Pointing to large data
  - Large data cant live on the stack

## References

- References are essentially `safe pointers`
- instead of \*, use &
- MUST point to existing data, and can never point to nothing/nullptr
  - this makes them almost always safe
- Prefer using reference to pointers whenever possible

## Pass by value / reference

- by default c++ pass variables by value
- PBV has a cost for copying large data
- also may want to modify the value passed
- we can use pointers to accomplish PBR but ideally we want to use references

### Pass by value

> This will not update the variable i as it passes a copy and not the memory location

```c++
void tennify(int a) { a = 10; }

int main()
{
  int i = 12;
  tennify(i);
  std::cout << i << "\n";
}
```

### Pass by Pointer

> This will pass in a copy of the address and change what is at the address

```c++
void tennify(int * a) { *a = 10; }
// careful the pointer may be null
// type casting may also fail
int main()
{
  int i = 12;
  tennify(&i);
  std::cout << i << "\n";
}
```

### Pass by Reference

```c++
void tennify(int & a) { a = 10; }
// reference will always* be valid
int main()
{
  int i = 12;
  // c++ understands it is getting a reference so you only need to pass it
  tennify(i);
  std::cout << i << "\n";
}
```

### Passing Large Data

```c++
// imagine this as a machine learning program
// (const type & d) is passing the reference so it does not copy. This also prevents it from being changed
void machineLearn(const BigData & d);

int main()
{
  BigData data(args);
  machineLearn(data);
}
```

#### Pass by const reference

- Whenever we pass a variable to a function that we don't want to be modified, use a `const reference`
- `const` declares that the variable cannot be modified inside the called function
- We only have to pass the 8-byte reference, which may be far less data than the data we are passing into the function

#### Pass by reference `exceptions`

- Pass primitive data types by **value**
  - `int add(const int a, const int b);`
- Referencing has an extra **dereference** step which is slower when using primitives
- Pass `std::shared_ptr<T>` by value
  - Copy constructor does counter inc/dec

## C++ / RAII

- Resource Acquisition is Initilization
- Binds the life cycle of a resource that must be acuired before the use to the lifetime of an object
- Makes life easier by iumplementing things in a wat the automatically manages memory/resources within an object

### RAII Implementation

- Encapsulate each resource into a class
- The class constructor acquires the resource and initilized it accordingly
- The destructor releases the resource
- The class itself should be instantiated such that it has either automatic storage duration, or in another RAII object.

#### Example

Setting up the RAII class

```c++
class IntArray
{
  // private pointer
  int * array;

  public:
    // constructor aquires the resource
    IntArray(size_t size) { array = new int[size]; }
    // deconstructor releases the resource
    ~IntArray() { delete [] array; }
    // get access to data with overloader
    int & operator [] (size_t i) { return array[i]; }
}
```

Using the above class

```c++
#include "IntArray.h"

int main()
{
  IntArray arr(10); // memory is allocated
  arr[5] = 21;
} // arr destructs, mem deallocated
```

> This works because every variables that is in the stack is removed when the scope is left.
> This is in practice setting up a garabe collector and is often faster than java's garbage collector

## C++ Smart Pointer

- Can be cumbersome to create our own RAII classes for every data type we want to store a pointer to
- C++ contains different smart pointers
- In this class: `std::shared_ptr<T>`
  - This does what we did above with RAII
- Handles RAII for a given pointer / type

### Shared Pointer

- `Reference Counted Pointer`
- Internal counter set to 1 in constructor
- Every time the shared_ptr is copied, the counter increases by 1
- Every time the shared_ptr destructs, the counter is decreased by 1
- When count reaches 0, resource deallocated

## How to allocate / pass data?

1. If possible, use the stack
   - Small, local variables
   - Pass variables by const reference if size > 8 bytes
2. If you need heap memory, use smart ptr
   - `std::shared_ptr<T> myBigData;`
   - `std::shared_ptr<Base> = std::make_shared<Derived>();`
3. Only when absolutely necesary use raw pointers / new

## C++ Templates

- Extremely powerful, easy to use
- can be VERY complicated
- can be used to implement generics
  > See cpp files for example
