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
