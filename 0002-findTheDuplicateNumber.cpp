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

using namespace std;

//Bora Ikizoglu

////This is my another approach. If all numbers are positive, we can find the duplicating array with a similiar idea to counting sort.

////javascript solution
//var findDuplicate = function(nums) {
//
//    let newArray = [];
//    debugger;
//    for(let i=0; i<nums.length; i++){
//        if(newArray[nums[i]] == undefined){
//            newArray[nums[i]]++;
//        }
//        else{
//            return nums[i];
//        }
//    }
//
};


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        //We created an iterator and hash table
        unordered_map<int,int>::iterator it;
        unordered_map<int, int> map;
        
        //Now we will iterate over the given vector
        for(int i=0; i<nums.size(); i++){
            
            //We will search the current number in the hash table
            it = map.find(nums[i]);
            
            //If current number doesn't exist in the hash table, we will insert it to hash table
            if(it == map.end()){
                map.insert(pair<int, int>(nums[i], 1));
            }
            //If current number exists in the hash table, we understand that it is a duplicate, so we will return it
            else{
                return nums[i];
            }
        }
    return 0;
  }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        
        //Input should be like [1,2,3,5,3,2,2,4,6]
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().findDuplicate(nums);
        
        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
