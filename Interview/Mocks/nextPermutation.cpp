/* Problem: find the lowest number strictly greater than the current number, just using the given numbers.
in:  [1, 2, 3]  
out: [1, 3, 2]

in:  [1, 3, 5, 9, 6, 6, 2]
     [1, 3, 6, 9, 5, 2]
     [1, 3, 6, 2, 5, 9]

in: [2, 3, 4, 8, 6, 3, 4]
out:[2, 3, 4, 8, 6, 4, 3]
    [2, 3, 4, 8, 6, 4, 3]

in: [1, 3, 2]
out:[2, 3, 1]       */

#include<bits/stdc++.h>
using namespace std;

int getFall(vector<int> &array) {
  int pos = -1;
  for(int i = array.size()-1; i > 0; i--) {
    if(array[i - 1] < array[i]) {
      pos = i - 1;
      break;
    }
  }
  return pos;
}

int binarySearch(vector<int> &a, int l, int r, int target) {
  int ans = -1;
  while(l <= r) {
    int m = l + (r - l) / 2;
    if(a[m] > target) {
      ans = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  return ans;
}

void reverse(vector<int> &a, int l, int r) {
  while(l < r) {
    swap(a[l], a[r]);
    l++;
    r--;
  }
}

void nextPermutation(vector<int> &array) {
  int fall = getFall(array);
  if(fall == -1) {
    reverse(array, 0, array.size() - 1);
  } else {
    int posSwap = binarySearch(array, fall + 1, array.size() - 1, array[fall]);
    swap(array[posSwap], array[fall]);
    reverse(array, fall + 1, array.size()-1);
  }
}

int main() {
  vector<int> a = {1, 3, 5, 9, 6, 2};
  nextPermutation(a);
  for (auto& e : a) {
    cout << e << " ";
  }
  return 0;
}