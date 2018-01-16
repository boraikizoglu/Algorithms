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

void printVector(vector<int> &vectorName) {
    for(int i=0; i<vectorName.size(); i++){
        cout << vectorName[i] << " ";
    }
    cout << endl;
}

int solution(vector<int> &A) {
    
    int sum = 0;
    vector<int> leftSums,rightSums;
    
    //Creates the sum, and vectors
    for(int i=0;i<A.size();i++){
        sum += A[i];
        leftSums.push_back(0);
        rightSums.push_back(0);
    }
    
    //cout << sum << endl;
    leftSums[0] = 0;
    rightSums[0] = sum-A[0];
    
    //beforeNumers vector keeps the sum of numbers before the current index
    //rightSums vector keeps the sum of numbers after the current index
    /*At the end of the given index --> {-1,3,-4,5,1,-6,2,1};
     leftSums --> 0 -1 2 -2 3 4 -2 0
     rightSums --> 2 -1 3 -2 -3 3 1 0
     so it will basically return 1 since index 1 of both vector is -1
     */
    
    for(int i=1;i<A.size(); i++){
        leftSums[i] = leftSums[i-1]+A[i-1];
        rightSums[i] = sum - (A[i]+leftSums[i]);
    }
    
    
    printVector(leftSums);
    printVector(rightSums);
    
    for(int i=0; i<A.size(); i++){
        //If it finds a same number, it returns the index of this number
        if(rightSums[i] == leftSums[i]) return i;
    }
    
    //If it can't find a equilibrium index, it returns -1
    return -1;
}

int main() {
    
    vector<int> A = {-1,3,-4,5,1,-6,2,1};
    
    solution(A);
    
    cin.get();
    cin.ignore();
    return 0;
}



