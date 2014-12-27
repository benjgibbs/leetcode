#include <iostream>
#include <string>
#include <map>

using namespace std;

int lengthOfLongestSubstring(string s) {
  int lastSeen[255];
  for(int i = 0; i < 255; i++){
    lastSeen[i] = -1;
  }

  int l = 0;
  int lastStart = -1;
  for(int i = 0; i < s.length(); i++){
    char c = s[i];
    int pos = lastStart;
    if(lastSeen[c] > -1 ){
      pos = std::max(lastSeen[c], lastStart);
      lastStart = std::max(lastSeen[c], lastStart);
    }
    int dist = i - pos;
    if(dist > l) l = dist;
    lastSeen[c] = i;
  }
  return l;
}

void check(string s) {
  cout << s << ": " << lengthOfLongestSubstring(s) << endl;
}

int main(int argc, char** argv){
  check("abcabcbb");
  check("bbbbb");
  check("1234512345612");
  check("ruowzgiooobpple");
  check("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco");
}
