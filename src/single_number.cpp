
#include <iostream>
#include <vector>
#include <unordered_map>

int singleNumber(int A[], int n) {
  std::unordered_multimap<int,int> m;

  for(int i = 0; i < n; i++){
    m.insert(std::make_pair(A[i],i));
  }
  for(auto l : m) {
    if(m.count(l.first) == 1)
      return l.first;
  }
  throw std::invalid_argument("no single number");
}


void test(int A[], int n) {
  std::cout << singleNumber(A,n) << std::endl;
}

int main(int argc, char** argv) {
  int a1[] ={ 1, 1, 2, 2, 3 };
  test(a1, sizeof(a1)/sizeof(a1[0]) );
  int a1[] ={ 1,  2, 2, 3, 3 };
  test(a1, sizeof(a1)/sizeof(a1[0]) );
}
