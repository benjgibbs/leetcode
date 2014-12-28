
#include <iostream>
#include <string>

using namespace std;

int titleToNumber(string s) {
  int result = 0;
  int fact = 1;
  while(s.length() > 0) {
    char c = s[s.length()-1];
    s = s.substr(0,s.length()-1);
    result += fact * ( c -'A' + 1); 
    fact *= 26;
  }

  return result;
}


void check(string s){
  std::cout << s << ": " << titleToNumber(s) << std::endl;
}


int main(int argc, char** argv){
  check("A");
  check("B");
  check("C");
  check("Z");
  check("AA");
  check("AB");

}


