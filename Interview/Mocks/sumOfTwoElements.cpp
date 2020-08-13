/*Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Given nums = [2, 7, 11, 2, 2,15], target = 13

return [0, 2]
4 - 2 = 2

map:
  K: int
  v : vector<int> size = 2
  k   v
  2 - [0, 4]
  7 - [1]
  11 - [2]
  15 - 3

pos = 0
13 - 2 = 11
  --> pos = 2
  
13 - 7 = 6
13 - 11 = 2 
13 - 15 = -2
... 
a[2], target = 4
4 - 2 = 2

nums = [2, -8, 11, 3, 3, 3], target = -5  
return [1, 3]
*/

pair<int, int> sum(vector<int> &n, int target) {
  map<int, vector<int>> m;
  /*
    m[2] = 0
    m[-8] = 1
    m[11] = 3
    m[3] = 4, 5
  */
  for(int i = 0; i < n.size(); i++) {
    if(m[n[i]].size() < 2) {
      m[n[i]].push_back(i);
    }
  }
  
  int f = -1, s = -1;
  for(int i = 0; i < n.size(); i++) { 
    int sub = target - n[i]; // sub = -5 + 8 = 3
    if(sub == n[i]) {
      if(m[sub].size() == 2) {
        f = m[sub][0];
        s =  m[sub][1];
        break;
      }
    } else if(m[sub].size() >= 1) { // YES
      f = i; // f = 1
      s = m[sub][0]; // 4
      break;
    }
  }
  return make_pair(f, s);
}


