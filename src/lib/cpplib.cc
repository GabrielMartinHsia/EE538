#include "cpplib.h"
#include "limits"
#include <algorithm> //for std::sort
#include <vector>    //for std::vector
/* Helpful refs:
https://www.cplusplus.com/reference/algorithm/sort/
https://www.tutorialspoint.com/program-for-mean-and-median-of-an-unsorted-array-in-cplusplus
*/

std::string CPPLib::PrintHelloWorld() { return "**** Hello World ****"; }

// NOTE: write your own function declaration q2 here
float FindMedian(std::vector<int> &v){
    sort(v.begin(), v.end());
    if (v.size()%2 != 0) //if odd number of elements in vector
        return v[v.size()/2]; //index middle element, otherwise...
    return (v[(v.size()-1)/2] + v[(v.size())/2]) / 2.0; //average of middle 2 elms
}

// Question 4: RandomCase
std::string CPPLib::RandomCase(std::string input_str){


}

// Question 5 Print your self-introduction
std::string CPPLib::PrintIntro() {
    // Please fill up this function.
    return ""; 
}

// Question 6
std::vector<int> CPPLib::Flatten3DVector(const std::vector< std::vector< std::vector<int> > > &input){
    // Please fill up this function.
    std::vector<int> res;
    return res;
}

// Question 7 Climbing Stairs
int CPPLib::climbStairs(int n){
    // Please fill up this function.
    return 0;
}
