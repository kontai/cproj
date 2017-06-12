#include <iostream>
//#include<fstream>
#include <algorithm>
#include <list>

using namespace std;

class GT_cls {
public:
  GT_cls(int x = 0) : num(x) {}
  bool operator()(int g) { return num >= g; }

private:
  int num;
};

int main() {
  GT_cls a(26); // declare
  list<int> lin;

  for (size_t i = 0; i < 40; i += 2)
    lin.push_back(i);

    cout<< count_if(lin.begin(), lin.end(), a);

  return 0;
}
