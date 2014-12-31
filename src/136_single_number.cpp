
#include <iostream>

int singleNumber(int A[], int n) {
  int result = A[0];
  for(int i = 1; i < n; i++){
    result = result ^ A[i];
  }
  return result;
}


void test(int A[], int n) {
  std::cout << singleNumber(A,n) << std::endl;
}

int main(int argc, char** argv) {
  int a1[] ={ 1, 1, 2, 2, 3 };
  test(a1, sizeof(a1)/sizeof(a1[0]) );
  int a2[] ={ 1,  2, 2, 3, 3 };
  test(a2, sizeof(a2)/sizeof(a2[0]) );
  int a3[] ={ 1,3,1,-1,3 };
  test(a3, sizeof(a3)/sizeof(a3[0]) );
}
