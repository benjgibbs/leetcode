
#include <iostream>
#include <map>
#include <list>


int singleNumber(int A[], int n) {
  std::map<int,std::list<int>> m;
  for(int i = 0; i < n; i++){
    m[A[i]].push_back(i);
  }
  for(auto l : m) {
    if(l.second.size() == 1)
      return l.first;
  }
  throw std::invalid_argument("no single number");
}


void test(int A[], int n) {
  std::cout << singleNumber(A,n) << std::endl;
}

int main(int argc, char** argv) {
  int a1[] ={ 1, 2, 3, 1, 2 };
  test(a1, sizeof(a1)/sizeof(a1[0]) );
}
