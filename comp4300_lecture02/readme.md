# 📝 Notes

## C++ Basics

### 📖 Background

#### What is it?

- it is a programing language that focuses on run speed and functionality
- is a compiled language
- is a mid-level programming language
  - High Level = Python
  - Low Level = Assembly

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
