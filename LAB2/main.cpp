#include <iostream>
using namespace std;
#include "IntList.h"
int main() {
  IntList x = IntList();
  x.push_front (1);
  cout << x;
}
