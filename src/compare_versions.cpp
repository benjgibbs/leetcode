#include <iostream>
#include <string>
#include <vector>

using namespace std;



vector<int> parts(string s) {
	vector<int> result;
	while(s.find(".") != s.end()) {
		
	}
	int loc1 = version1.find(".");
	int v11 = atoi(version1.substr(0,loc1).c_str());
	int v12 = atoi(version1.substr(loc1+1).c_str());
	return result;
}



//If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
int compareVersion(string version1, string version2) {
	if(version1 == version2) return 0;
	
	int loc1 = version1.find(".");
	int v11 = atoi(version1.substr(0,loc1).c_str());
	int v12 = atoi(version1.substr(loc1+1).c_str());
	
	int loc2 = version2.find(".");
	int v21 = atoi(version2.substr(0,loc2).c_str());
	int v22 = atoi(version2.substr(loc2+1).c_str());
	
	if(v11 > v21) return 1;
	if(v11 < v21) return -1;
	if(v12 > v22) return 1;
	if(v12 < v22)	return -1;	
	return 0;
}

int main(int argc, char** argv){
	string v1 = "0.1";
	string v2 = "1.1";
	string v3 = "1.2";
	string v4 = "13.37";
	std::cout << "v1 < v2: " << compareVersion(v1,v2) << std::endl;	
	std::cout << "v2 < v3: " << compareVersion(v2,v3) << std::endl;	
	std::cout << "v3 < v4: " << compareVersion(v2,v4) << std::endl;	
	
}
