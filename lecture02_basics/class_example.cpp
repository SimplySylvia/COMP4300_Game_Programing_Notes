#include <iostream>
#include <vector>
#include <fstream>

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
    std::cout << m_id << " " << m_avg << "\n";
  }
};

class Course
{
  std::string m_name = "Course";
  std::vector<Student> m_students;

public:
  Course() {}

  // adding & will be a refrence. Adding const makes it so you can not modify it
  Course(const std::string &name)
      : m_name(name)
  {
  }

  void addStudent(const Student &s)
  {
    m_students.push_back(s);
  }

  const std::vector<Student> &getStudents() const
  {
    return m_students;
  }

  void print() const
  {
    for (const auto &s : m_students)
    {
      s.print();
    }
  }

  // loading files off machine
  void loadFromFile(const std::string &filename)
  {
    std::ifstream fileIn(filename);
    std::string first, last;
    int id;
    float avg;

    while (fileIn >> first)
    {
      fileIn >> last >> id >> avg;

      addStudent(Student(first, last, id, avg));
    }
  }
};

int main(int argc, char *argv[])
{
  // class constructors

  // default no values
  // Student s1;
  // with values
  // const Student s2("Dalton", "Justis-Hart", 1, 30);
  // const Student s3("Britt", "Justis-Hart", 2, 28);

  Course comp4300("COMP 4300");
  comp4300.loadFromFile("students.txt");
  comp4300.print();

  return 0;
}