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
