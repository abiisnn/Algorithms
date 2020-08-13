/*
S = Aaaaa
S = aaaaa
S = AAAAA

S = aAaA 
Size = 4, 2 lower, 2 upp
How many lower case
  Empty --> false
1. Count how many lower case. 
    * Take the ascii code 
2. Options:
    * 1 upper case:
      * Verify the first char is the 
      * Other case: A
    * All the letters are lower case == stringSize
    * All the letters are upper case == stringSize
*/
bool isLower(char c) {
  bool ans = false;
  if(c >= 97) {
    ans = true;
  }
  return ans;
}
bool correctString(string str) {
  bool ans = false; 
  int lower = 0;
  int upper = 0;
  for(int i = 0; i < str.size(); i++) {
    if(isLower(str[i])) { // 
      lower++; 
    }
  }
  upper = str.size() - lower;
  
  if(str.size() > 0) {
    if(lower == str.size()) {
      ans = true;
    } else if(upper == str.size()) {
      ans = true;
    } else if(str.size() > 0) {
      if((upper == 1) && !(isLower(str[0]))) {
        ans = true;
      }
    }
  }
  return ans;
}

///////////////////////////////

// ahponli
// ihponla

/*
  aaaaie  = eiaaa
  .    .
  eaaaia
   .  .
  eiaaaa
    ..
  eiaaaa
  --> r < l
  --> If my two pointers have a vowel l++ , r--
  O(N)
  eiaa
  avvei
  tsttu
*/

void changeString(string &str) {
  int l = 0, r = str.size() - 1;
  
  while(l <= r) {
    if(isVowel(str[l]) && isVowel(str[r])) {
      swap(str[l], str[r]);
      l++;
      r--;
    }
    if(!isVowel(str[l])) {
      l++;
    }
    if(!isVowel(str[r]) {
      r--;
    }
  }
}
