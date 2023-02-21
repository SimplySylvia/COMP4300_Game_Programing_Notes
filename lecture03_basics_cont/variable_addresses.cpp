#include <iostream>

// prints address, value and size in bytes
void pp(int &a)
{
  std::cout << &a << " " << a << " " << sizeof(a) << "\n";
}

int main(int argc, char *argv[])
{
  int a = 10;
  int b = 25;

  // check primitive addresses
  // pp(a);
  // pp(b);

  // check array addresses
  // this creates an array and provides defaults of 0
  int arr[10] = {};

  for (size_t i = 0; i < 10; i++)
  {
    pp(arr[i]);
    // on print each address is exactly 4b apart
    // 0x16bb5f480 0 4
    // 0x16bb5f484 0 4
    // 0x16bb5f488 0 4
    // 0x16bb5f48c 0 4
    // 0x16bb5f490 0 4
    // 0x16bb5f494 0 4
    // 0x16bb5f498 0 4
    // 0x16bb5f49c 0 4
    // 0x16bb5f4a0 0 4
    // 0x16bb5f4a4 0 4s
  }

  // heap array (harr) - [NOTES: this does not release the memory so it is a memory leak]
  // int *harr = new int[10];

  // for (size_t i = 0; i < 10; i++)
  // {
  //   pp(harr[i]);
  // heap memory locations
  // 0x6000001a4210 0 4
  // 0x6000001a4214 0 4
  // 0x6000001a4218 0 4
  // 0x6000001a421c 0 4
  // 0x6000001a4220 0 4
  // 0x6000001a4224 0 4
  // 0x6000001a4228 0 4
  // 0x6000001a422c 0 4
  // 0x6000001a4230 0 4
  // 0x6000001a4234 0 4
  // }

  // pass by value vs ref
  int c = 10;
  int d = 25;
  int *pc = &c;
  int *pd = &d;

  // modify whatever is at b
  *(pd) = 17;
  // pointer arthimetic will allow you to change other values (this is a raw pointer and should not be used due to easy bugs)
  // this changes c
  *(pd - 1) = 10;

  pp(c);
  pp(d);

  return 0;
}