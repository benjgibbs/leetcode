#include <string>
#include <iostream>

using std::string;


class Solution {
  public:
    string convertToTitle(int n) {
      string s;
      do {
				n=n-1;
        char c = (char)(65 + (n % 26));
        char c2[] = {c,'\0'};
        s = string(c2) + s;
        n = n / 26;
      } while(n > 0);
      return s;
    }
};

Solution s;

void check(int n) {
  std::cout << n << ": " << s.convertToTitle(n) << std::endl;
}

int main(int argc, char** argv) {
  std::cout<< (int)'A' << std::endl;
  check(1);
  check(2);
  check(3);
  check(5);
  check(26);
  check(27);
  check(28);
  check(29);
  return 0;
}
