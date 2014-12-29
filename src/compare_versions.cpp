#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> parts(string s) {
	vector<int> result;
	do{
		string n = s.substr(0,s.find("."));
		result.push_back(atoi(n.c_str()));	
		int end = s.find(".");
		if(end == -1) {
			end = s.length();
		} else {
			end++;
		}
		s = s.substr(end);
	} while(!s.empty());
	return result;
}

//If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
int compareVersion(string version1, string version2) {
	if(version1 == version2) return 0;
	
	vector<int> parts1 = parts(version1);	
	vector<int> parts2 = parts(version2);	
	int max = std::max(parts1.size(), parts2.size());
	for(int i = 0; i < max; i++){
		int p1 = parts1.size() > i ? parts1[i] : 0;
		int p2 = parts2.size() > i ? parts2[i] : 0;
		if(p1 > p2) return 1;
		if(p1 < p2) return -1;
	}
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
	std::cout << "1 < 1.1: " << compareVersion("1", "1.1") << std::endl;	
}
