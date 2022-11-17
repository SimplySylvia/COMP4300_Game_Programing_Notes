#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
  std::vector<int> vec;
  vec.push_back(42);
  vec.push_back(10);

  // looping through a vector standard
  for (size_t i = 0; i < vec.size(); i++)
  {
    std::cout << vec[i] << "\n";
  };

  // loop and create a variable for each index in the vector
  for (auto a : vec)
  {
    std::cout << a << "\n";
  };

  return 0;
}