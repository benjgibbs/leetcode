#include <vector>
#include <iostream>
#include <map>

using std::vector;
using std::cout;
using std::endl;
using std::map;

vector<int> twoSum(vector<int> &numbers, int target) {
  map<int,int> m; 
  for(int i = 0; i < numbers.size(); i++){
    int n = numbers[i];
    int diff = target-n;
    auto pos = m.find(diff);
    if(pos != m.end()){
      vector<int> result;
      result.push_back(pos->second+1);
      result.push_back(i+1);
      return result;
    }
    m[n] = i;
  }
  throw std::invalid_argument("No two sum");
}


void check(vector<int> & numbers, int target) {
  cout << "[";
  bool first  = true;
  for(auto i : numbers){
    if(first){
      first=false;
    }else{
      cout << ","; 
    }
    cout << i;
  }
  auto res = twoSum(numbers, target);
  cout << "] " << res[0] << "," << res[1] << " should make " << target << endl;
}

int main(int argc, char** argv){
  vector<int> v1 = {1,2,3,4,5};
  check(v1,3); 
  check(v1,9);
  
  vector<int> v2 = {2, 7, 11, 15};
  check(v2,9);
   
}
