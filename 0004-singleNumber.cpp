#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <regex>
using namespace std;

int singleNumber(vector<int>& nums) {
    
    //This is the fastest solution
    int result=0;
    for(int i=0; i<nums.size(); i++){
        //It will xor all numbers. For example, if numbers are 1, 1, 2(binary forms of them are 10, 10, 11), when we xor 10,10,11
        //Result will be 11 and 11 = 2. It is the answer. ( 10(XOR)10 = 00, 00(XOR)11=11 )
        result = result ^ nums[i];
    }
    return result;
}

int main(){
    
    vector<int> A = {17,12,5,-6,12,4,17,-5,2,-3,2,4,5,16,-3,-4,15,15,-4,-5,-6};
    
    singleNumber(A);
    
    return 0;
}
