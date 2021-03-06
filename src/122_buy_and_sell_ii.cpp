#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices) {
  if (prices.size() < 2) return 0;
  int profit = 0;
  int i = 0;
  int p1 = prices[0];
  for(int i = 1; i < prices.size(); i++) {
    int p2 = prices[i];
    if(p2 > p1) {
      profit += p2 - p1;
    }
    p1 = p2;
  }
  return profit;
}

int main(int argc, char** argv) {
  vector<int> v1{ 1, 2 }; 
  std::cout << maxProfit(v1) << std::endl;
  
  vector<int> v2{ 1, 1 }; 
  std::cout << maxProfit(v2) << std::endl;
  
  vector<int> v3{ 2, 1 }; 
  std::cout << maxProfit(v3) << std::endl;
  
  vector<int> v4{ 1, 2, 3, 4, 5}; 
  std::cout << maxProfit(v4) << std::endl;
  
  vector<int> v5{ 2, 1, 2, 3, 2, 4, 1}; 
  std::cout << maxProfit(v5) << std::endl;
}
