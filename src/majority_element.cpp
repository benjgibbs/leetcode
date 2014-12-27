#include <vector>
#include <map>
#include <exception>
#include <iostream>

using std::vector;


class Solution {
  public:
    int majorityElement(vector<int> &num) {
      std::map<int,int> m;
      for(auto n : num){
        m[n]++;
        if(m[n] > num.size()/2)
          return n;
      }
      throw std::invalid_argument("no majority element");
    }
};

int main(int argc, char** argv) {
  Solution s;
  vector<int> v1 = {1,2,3,4,5,1,1,1,1};
  std::cout << v1.size() << " has majority Element: " << s.majorityElement(v1) << std::endl;
  vector<int> v2 = {1};
  std::cout << v2.size() << " has majority Element: " << s.majorityElement(v2) << std::endl;
  vector<int> v3 = {-1,-2,-3,1,1,2,1,1,1};
  std::cout << v3.size() << " has majority Element: " << s.majorityElement(v3) << std::endl;
}
