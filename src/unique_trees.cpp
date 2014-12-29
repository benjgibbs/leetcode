#include <iostream>

int numTrees(int n) {
	// Using a catalan number
	long num = 1;
	for(int i = 2*n; i > (n + 1); i--){
		num *= i;
	}

	long denom = 1;
	for(int i = 2; i<=n; i++){
		denom *= i;
	}

	return num/denom;
}

void check(int n){
	std::cout << n << ": " << numTrees(n) << std::endl;
}

int main(int argc, char** argv) {
	check(3);
	check(4);
	check(1);
	check(0);
	check(10);
}
