# 📝 Notes

## C++ Basics

### 📖 Background

#### What is it?

- it is a programing language that focuses on run speed and functionality
- is a compiled language
- is a mid-level programming language
  - High Level = Python
  - Low Level = Assembly
- created by Bjarne Stroustrup, Bell Labs
- Originally coined "C with Classes", c++ 1983
- supports object-oriented and generics
- maintains the efficiency of C
- Very popular in video game development
- influenced development of c# and java

#### 👍 Advantages

- Very widely used/supported
- many libraries available
- resulting code is very fast
- syntax is similar to Java / other languages
- large market for hiring
- code is highly customizable
- will be around for a long time (most likely)

#### 👎 Disadvantages

- Easy to write unsafe code / crashes
- must manage your own memory
- syntax can be a little confusing
- can be hard to read others' code due to custom definitons / op overloading
- compiler/linker errors hard to interpret

#### Versions

- First appeared in 1985
- C++98 - First Standardized Version
- C++11 - many new features / QOL improvments
- C++14, C++17, C++20
- C++17 is current standard

> You can set the version with the compiler flag `-std=C++17`

## Code Details

### Typed

- C++ is statically typed
  - Variables defined/typed **before** use `int year = 2018;`
  - Java, C also statically typed
  - variable types defined at compile time

#### Primitive Types

| Name        | Description                                            |
| ----------- | ------------------------------------------------------ |
| char        | Character or eight bit integer                         |
| short       | sixteen bit integer                                    |
| long        | thirty-two bit integer                                 |
| int         | system dependent, likely four bytes or thirty-two bits |
| float       | floating point number                                  |
| double      | double precision floating point                        |
| long double | long double precision floating point                   |
| bool        | boolean value: false -> 0, true -> 1                   |

### Arithmetic Operators

| Name           | Syntax  |
| -------------- | ------- |
| additon        | `a + b` |
| subtraction    | `a - b` |
| unary plus     | `+a`    |
| unary minus    | `-a`    |
| multiplication | `a * b` |
| division       | `a / b` |
| modulo         | `a % b` |
| pre-increment  | `++a`   |
| post-increment | `a++`   |
| pre-decrement  | `--a`   |
| post-decrement | `a--`   |

### Bitwise Operators

| Name                   | Syntax   |
| ---------------------- | -------- | 
| NOT                    | `~a`     |
| AND                    | `a & b`  |
| OR                     | `a | b`  |
| XOR                    | `a ^ b`  |
| arithmetic left shift  | `a << b` |
| arithmetic right shift | `a >> b` |

### Functions
- very similar to Java
- can have same function name with different input arguments
- can not have functions with the same name and args that differ only in return type


```c++
returnType funcName(args) {
   // logic goes here 
}
```

### Classes
- anything you do not provid scope for is default private

#### Class Declaration
```c++
class ClassName 
{
  // syntax m_ means private variable
  int m_x = 0; // private
  int m_y = 0; // private
  public:
    ClassName(int x, int y);
    int getX();
    int getY();  
};
```

#### Class Constructor (inefficent)
- this is due to assigning memory and then updating to hold value
```c++
ClassName::ClassName(int x, int y)
{
  m_x = x;
  m_y = y;
}
```

#### Class Constructor (efficient) aka member initilizer lists
- this is better because assigns with value
- default value not used
```c++
ClassName::ClassName(int x, int y)
  : m_x(x) 
  , m_y(y)
{
}
```

#### Class Destructor 
- clean up when destroyed 
```c++
ClassName::~ClassName()
{
  // clean up here
}
```

### First Program Breakdown

```c++
#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "Hello, World!" << std::endl;

    return 0;
}
```

---

```c++
#include <iostream>
```

- this line is a **pre-processor directive**
- it is used to include a c++ library into the current file
  - like imports in other languages
    - python `from library import this`
    - js `import thing from library`
- this library is for input/output streams
- will allow us to use `std::cout` to print

---

```c++
int main(int argc, char *argv[]){}
```

- each C++ program must have a main function which is run when the program starts
- contents of the function enclosed in `{ }`
- Main function has int return type
- `argc` : number of program args
- `argv` : array of string(char \*) args

---

```c++
std::cout << "Hello, World!" << std::endl;
```

- line prints _string_ "Hello World!" to the terminal
- `std` is a `namespace` that contains the `cout` output stream
  - think of it like you are accessing part of the iostream library that was brought into the file
    - if it was js: `iostream = { std: { cout: function(args){} } };`
- `<<` operator _pipes_ the string to `cout`
- can be use to print any base c++ type
- each c++ statement must end in `;`
- c++ is case-sensitive

---

```c++
return 0;
```

- Main has to return type of `int`
- Return 0 if program ran to normal end
- Return something else if there is an error
  - used by other programs to detect errors
- program may compile / run without this, but it is highly recommended to use it.

---

### C++ Standard Library

- Collection of classes and functions available within the c++ language
  - examples
    - Strings / IO / Streams / Files
    - Generic Containers (vector, set, map)
    - Container Functionality (fill, copy, map)
    - Algorithms
- Must use `#include` in your c++ program to bring it in
- Referenced via the `std::` namespace
- Namespaces encapsulate code

In file declaring

```c++
namespace dalton { int ivar = 10; }
```

In another file

```c++
dalton::ivar
```

- Standard Library Examples
  - `std::string`
  - `std::vector`
  - `std::map`

### Source Code Breakdown

**Program files are written in `.cpp` files**

- example: `main.cpp`
  - also named `.C` , `.CPP`
- used for function / class **_definitions_**

**Header files are written in `.h` files**

- example: `math.h` , `MyClass.h`
- used for function / class **_declarations_**

#### Seperation of `.cpp` and `.h`

C++ class code is often seperated into two seperate files.

#### `.h` file is the "header" file with declarations

**Declaration**
What it is.

```c++
int sum(int x, int y);
```

- declarations of class / functions
- include name, return type, argument types, etc
- required by C++ to see all declarations of classes, functions, variables, before use
- `.cpp` file is the "implementation" file with definitions

**Benefits**:

- Allow you to see class functionality at a glance
- Separates design from implementation / functionality
- Headers seldom change, leading to less files requiring recompilation

**Drawbacks**

- More files in your code base
- More tabbing back and forth between header and `.cpp`
- cyclic dependencies can be hard to detect and resolve

#### `.cpp` file is the "functionality" file with declarations

**Definition**
What it does.

```c++
int sum(int x, int y)
{
  return x + y;
}
```

This is where you define the functionality and where the bulk of code is written.

### Compilation Process

- programs are compiled into binary executable files, ran directly by cpu
- no virtual machine like java
- no interpreter like python
- this results in (usually) faster execution, but at the price of lower level programming
- several popular compilers
  - Linuxx/Mac: _GNU C Compiler_ aka gcc (g++ in terminal), clang
  - Windows: Visual Studio, mingw

#### Steps the compiler goes through

1. Source and Header files are run through pre-processor (this checks for errors)
2. Pre-processor output is run through the c++ compiler
3. Object files are created
4. Object files are linked together
5. Executable file is created

## 💻 Commands

### Compile File

```bash
g++ -std=c++17 file_name.cpp
```

Default output name is `a.out`

To run the compiled file.

```bash
./a.out
```

To name a file you use the `-o` flag for output

```bash
g++ -std=c++17 file_name.cpp -o output_name
```
