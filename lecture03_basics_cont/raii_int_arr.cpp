#include <iostream>

// prints address, value and size in bytes
void pp(int &a)
{
  std::cout << &a << " " << a << " " << sizeof(a) << "\n";
}

// templates aka generics allow for changing types within a class
template <typename T>
class DynamicArray
{
  size_t m_size;
  T *m_arr;

public:
  // constructor
  DynamicArray(size_t size)
      : m_size(size),
        m_arr(new T[size])
  {
    std::cout << "Array Constructor\n";
  }

  // deconstructor
  ~DynamicArray()
  {
    delete[] m_arr;
    std::cout << "Array Destructor\n";
  }

  // Methods
  T get(size_t index) const
  {
    return m_arr[index];
  }

  void set(size_t index, T val)
  {
    m_arr[index] = val;
  }

  void print() const
  {
    for (size_t i = 0; i < m_size; i++)
    {
      std::cout << i << " " << m_arr[i] << "\n";
    }
  }

  // operator overloading
  // get ref and return it
  T &operator[](size_t index)
  {
    return m_arr[index];
  }

  // allows for const access but not setting
  const T &operator[](size_t index) const
  {
    return m_arr[index];
  }
};

int main(int argc, char *argv[])
{
  // ints only
  DynamicArray<int> myArray(10);

  myArray.set(4, 7);
  myArray.set(2, 134);

  myArray.print();

  // now its floats
  DynamicArray<float> floatArr(5);
  floatArr.set(1, 4.7);
  floatArr.set(2, 8.5);

  // using the override operator
  floatArr[1] = 3.145;

  floatArr.print();

  // const dynamic arr
  const DynamicArray<int> conArr(5);

  std::cout << conArr[1] << "\n";

  return 0;
}