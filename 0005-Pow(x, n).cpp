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


//Iterative approach

double myPow(double base, int power) {
    double result = 1;
    
    //To handle some corner cases
    if( power < -2147483640){
        if(base == 1) return 1;
        else if(base == -1) {
            if(power % 2 == 0) return 1;
            else return -1;
        }
        return 0;
    }
    
    //If power is negative
    if (power < 0) {
        base = 1 / base;
        power = -power;
    }
    
    while(power > 0) {
        
        //If power is power of 2, it will only execute this if condition one time.At the end.See the example
        // 2^8 - 8 --> 4 --> 2 --> 1(executed) --> 0
        //If power isn't power of 2, it will execute this if condition multiple times
        // 2^15 - 15 --> 7 --> 3 --> 1(executed) --> 0
        // 2^24 - 24 --> 12 --> 6 --> 3(executed) --> 1(executed) --> 0
        if(power % 2 == 1) {
            result = (result*base);
        }
        base = (base * base);
        power = power / 2;
    }
    cout << result;
    return result;
}

/*Recursive approach
 
double myPow(double x, int n) {
    if(n<0){
        return (1/x)*myPow(1/x,-(n+1));
    }
    if(n==0)return 1;
    if(n%2==0){
        double temp=myPow(x,n/2);
        return temp*temp;
    }
    else{
        double temp=myPow(x,n/2);
        return x*temp*temp;
    }
}

*/

int main(){
    
    
    double start_s3=clock();
    myPow(2.1, 3);
    double stop_s3=clock();
    cout << "Time: " << (stop_s3-start_s3)/double(CLOCKS_PER_SEC)*1000 << " ms"<< endl;
    
    return 0;
}
