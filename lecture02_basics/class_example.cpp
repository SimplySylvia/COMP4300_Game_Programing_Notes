#include <iostream>
#include <vector>

class Student
{
  std::string m_first = "First";
  std::string m_last = "Last";
  int m_id = 0;
  float m_avg = 0;

public:
  Student() {}

  Student(std::string first, std::string last, int id, float avg)
      : m_first(first), m_last(last), m_id(id), m_avg(avg)
  {
  }

  // const correctness
  // declare const on all functions that do not change anything in the class
  int getAvg() const
  {
    return m_avg;
  }

  int getId() const
  {
    return m_id;
  }

  std::string getFirst() const
  {
    return m_first;
  }

  std::string getLast() const
  {
    return m_last;
  }

  // no return and does not change object
  void print() const
  {
    std::cout << m_first << " " << m_last << " ";
    std::cout << m_id << " " << m_id << "\n";
  }
};

int main(int argc, char *argv[])
{
  // class constructors

  // default no values
  Student s1;
  // with values
  const Student s2("Dalton", "Justis-Hart", 1, 30);
  const Student s3("Britt", "Justis-Hart", 1, 28);

  s3.print();

  return 0;
}