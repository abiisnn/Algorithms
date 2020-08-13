#include <iostream>
using namespace std;

/* Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

[-1, -3, -6, -2, -1]

[-2,1,-3,4,-1,2,1,-5,4]
acummulate = -2
accumulate = 0

= / = answer
-1 , 1 is better than -1

best = -INF // BEGGINNING
acum = -2, best = -2
acum = 1, best = 1
acum = 1 - 3= -2
acum =  4 best = 4
acum = 4 -1 = 3
acum = 3 + 2 = 5 best = 5

acum = v[0], best = -INF
for all the array:
  if(acum <= 0)  
    acum = v[i]
    best = max(best, acumulate)
  else 
    best = max(best, acumulate)
    acum += v[i]
  
best = max(best, acum)

*/
#define INF 1e8
int max(int &a, int &b) {
  if(b > a) return b;
  return a;
}
// [-2,1,-3,4,-1,2,1,-5,4]
// [-2]
// Time complexity: O(n) where n is the size of the vector
// Space complexity: O(2)
int largestSum(vector<int> &v) {
  if(!v.size()) return -INF;
  int acum = v[0], best = -INF; // acum = 6, best = 6
  for(int i = 1; i < v.size(); i++) { 
    if(acum <= 0) {
      acum = v[i]; // acum = 4
      best = max(best, acum); // best = 4
    } else {
      best = max(best, acumulate); // best = 6
      acum += v[i]; // acum = 5
    }
  }
  best = max(best, acum); //best = 6
  return best;
}

/* Given an unsorted integer array, find the first missing positive integer.

Example:
Given [1,2,0] return 3,

[3,4,-1,1] return 2,

[-8, -7, -6] returns 1

// MEX algorithm
n * log(n)
[] size of this array is n 
loop -> n | MAX ?
O(n)
set {vector} 
for 1 to MAX:
  if( elemenet exists in the set) continue;
  return element


If a sort the array
sort() O(n * log(n))
[-1, 1, 3, 4] Time complexity O(n* log(n) + n) = O(n * log(n)) n: size of the array
*/

void firstMissing(vector<int> &v) {
  sort(v.begin(), v.end());
  
  if(v.size() == 1) {
    if(v[0] == 1) return 2;
    return 1;
  }
  int firstM = 1 greater = 0; bool flag = false;
  for(int i = 0; i < v.size()-1; i++) {
    if(v[i+1] - v[i] > 1) {
        if(v[i+1]-1 >= 0) {
            firstM = v[i+1] - 1;
            break;
        }
    }
    if(v[i] == 1) flag = true;
    greater = max(greater, v[i]);
  }
  if(firstM == 1 && flag) return greater+1;
  return firsM;
}