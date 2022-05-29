[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=7921994&assignment_repo_type=AssignmentRepo)

# HW1 EE538 - Computing Principles for Electrical Engineers

- Please clone the repository, edit [README.md](README.md) to answer the questions, and fill up functions to finish the homework.
- For non-coding questions, fill out the answers below each question. Please write your answer there.
- For coding questions, please make sure that your code can run ```bazel run/test```. In this homework, you will need to fill up [cpplib.cc](src/lib/cpplib.cc) and tests in [tests](tests). **Do Not change or modify any given function names and input or output formats in both [cpplib.cc](src/lib/cpplib.cc) and tests in [tests](tests). Unexpected changes will result in **zero** credit.**
- For coding questions, there is a black box test for each question. All points are only based on passing the test cases or not (i.e. we don't grade your work by your source code). So, try to do comprehensive testing before your final submission.
- For submission, please push your answers to Github before the deadline.
- Deadline: **Friday, June 3rd by 12 pm (noon)**
- Total: 130 points. 100 points is considered full credit.

## Question 1 (10 Points. Easy)

Create an account on GitHub and Stack Overflow and paste the link to your profile.

GitHub profile link: https://github.com/GabrielMartinHsia/

Stack Overflow profile link: https://stackoverflow.com/users/19208035/gabriel

## Question 2 (20 Points. Medium)

Write a function called **FindMedian**, which returns the median of the inputs of a vector of integers. Use the steps the following steps:
1. Clearly specify input and output.
2. Write some example input and outputs. Try to cover corner cases. Feel free to make reasonable assumptions for the corner cases.
3. Implement your algorithm.
4. Write several unit tests that cover all corner cases, and test your algorithm using bazel.
You will need to only submit your algorithm implementation and the unit tests.

## Question 3 (20 Points. Medium)

Compute the worst case run-time complexity of the below functions. Please provide both the computation process and final result for full credit.

```cpp
void Example1(int n) { // 1 (call)
   int i = 1;          // 1 (assignment)
   while (i < n) {     // 1 (comparison), log2(n) times
       i *= 2;         // 1 (assignment), log2(n) times... i = 1, 2, 4, 8, ... 
   }
}
```

Answer: 

The run-time complexity is $O(\log_2(n))$. As the `while` loop repeats, $i$ evolves as:

$i = [1, 2, 4, 8, ..., (n-1)] = 2^0, 2^1, 2^2, 2^3, ..., 2^k$

where $k$ is the number of times the loop evaluates, so, looking to the last element of these sequences, we can write:
$\log_2(2^k) = k = \log_2(n-1) \approx \log(n)$
i.e., the loop iterates $\log(n)$ times.

as commented above, line-by-line we have:

$1 + 1 + \log(n) + \log(n) = 2 + 2\log(n) \approx log(n)$

$\therefore$ run-time complexity is: $O(\log(n))$

```cpp
void Example2(int n) {                              // 1 (call)
   int count = 0;                                   // 1 (assignment)
   for (int i = 1; i <= n; i = i * 2) {             // 2 (1 assignment, 1 comparison), log2(n) times
       for (int j = 1; j <= n; j++) {               // 2 (1 assignment, 1 comparison),       n times
           for (int k = 1; k <= n; k = k * 3) {     // 2 (1 assignment, 1 comparison), log3(n) times
               count++;                             // 1 (assignment) incremented each time through the nested loops
           }
       }
   }
}
```

Answer:

The run-time complexity is $O(n\log(n)^2)$. As each loop repeats, indices $i$, $j$, and $k$ evolve as:

* $i = [1, 2, 4, 8, ..., n] = 2^0, 2^1, 2^2, 2^3, ..., 2^q \rightarrow n = 2^q \rightarrow \log_2(n) = \log_2(2^q) \therefore q = \log_2(n)$
* $j = [1, 2, 3, 4, ..., n] \therefore q = n$
* $k = [1, 3, 9, 27,..., n] = 3^0, 3^1, 3^2, 3^3, ..., 3^q \rightarrow n = 3^q \therefore q = \log_3(n)$

where $q$ is the number of times each loop evaluates.

As commented above, line-by-line we have:

$1 + 1 + (2\log_2(n)\times 2n \times 2\log_3(n))\times 1 = 2 + 8(n\log_2(n)\log_3(n)) \approx n\log(n)^2$

$\therefore$ run-time complexity is: $O(n\log(n)^2)$

```cpp
void Example3(int n) {                  // 1 (call)
   int count = 0;                       // 1 (assignmnet)        
   for (int i = 0; i < n; i++)          // 2 (1 assignment, 1 comparison), n times
       for (int j = i; j < i*i*i; j++)  // 2 (1 assignment, 1 comparison), ...
            std::cout<<"*";             // 1 (print) 
}
```

Hint: Note the ```j < i*i*i``` in the inner loop and compute the cube sequence to get the final result.

Answer:

So I definitely just googled "sum of cubic series" and found this:

https://proofwiki.org/wiki/Sum_of_Sequence_of_Cubes

which says:

$1 + 1^3 + 2^3 + 3^3 + ... = \sum_{i=1}^{n} i^3 = \frac{n^2(n^2+1)^2}{4}$

so, if we simplify that, we get:

$\frac{n^4 + 2n^3 +n^2}{4} \approx n^4$

Bear in mind this is the combination of both the $i$ and $j$ loops. As $i$ iterates from $1$ to $n$, $j$ iterates from the present value of $i$ to $i^3$ via single-integer increments. So, as we iterate through each of the loops, we'll see the following from each index:

* $i = [0, 1, 2, ..., n]$
* $j = [1 \rightarrow 1, 2 \rightarrow 8, 3 \rightarrow 27, ..., n \rightarrow n^3]$ ... where each "$\rightarrow$" is a stand-in for all integers between the values shown.

The overall run-time complexity is the sum of all integer steps taken in each element listed for $j$. Note that this is very close to the cubic series sum from the *proofwiki.org* link above, but it is not quite the same, since we're not summing all the steps from $0$ to $i^3$ for each iteration of $j$, but rather only the steps from $i$ to $i^3$. So, we really just need to *subtract* the simple integer series $\sum_{i=0}^{n}i$ from the cubic series sum ... but if we are simplifying the polynomial by taking only its highest-degree term anyway, I guess this is kind of a moot point, since the effect of this subtraction is simply to cancel the $n^2$ term, which we're already ignoring.

so, yeah, I think the run-time complexity here is $O(n^4)$

```cpp
int Example4(int n) {                       // 1 (call)
   int count = 0;                           // 1 (assignment)
   for (int i = 1; i < n; i *= 3) {         // 2 (1 assignment, 1 comparison), log3(n) times
      for (int j = n; j > 0; j /= 3) {      // 2 (1 assignment, 1 comparison), log3(n) times
          for (int k = 0; k < j; k++) {     // 2 (1 assignment, 1 comparison),       j times
              count += 1;                   // 1 (assignment) incremented each time through the nested loops
          }
      }
   }
   return count;
}
```

Hint: Note the ```i /= 3``` in the outer loop and compute the geometric sequence to get the final result.

Answer:

The run-time complexity is $O(n\log(n))$. As each loop repeats, indices $i$, $j$, and $k$ evolve as:

* $i = [1, 3, 9, 27,..., (n-1)] = 3^0, 3^1, 3^2, 3^3, ..., 3^q \rightarrow n-1 = 3^q \therefore q_i = \log_3(n-1) \approx \log_3(n)$
* $j = [n, \frac{n}{3}, \frac{n}{9}, \frac{n}{27}, ..., (1>0)] = \frac{n}{3^0}, \frac{n}{3^1}, \frac{n}{3^2}, \frac{n}{3^3}, ..., \frac{n}{3^q} \rightarrow n = 3^q \therefore q_j = \log_3(n)$... but wait though, let's see what happens next...
* $k = [0, 1, 2, 3, ..., j]$... The first time through, $j=n$, so $k$ will iterate $n$ times. The next time through, this value will be one third its previous value, and so on, until we get down to $j=1$. 

So as we iterate through the middle $j$ and inner $k$ loops, we'll add all of these values up as the series:

$n + \frac{n}{3} + \frac{n}{9} + \frac{n}{27} + ... = n(1 + \frac{1}{3} + \frac{1}{9} + \frac{1}{27} + ...)$

which happens to look a lot like the standard geometric series:

$1 + x + x^2 + x^3 + ... = \frac{1}{1-x}$ 

where we see that in our case, $x=\frac{1}{3}$

So, we could say that for a given input size $n$, the inner two loops give us a run-time complexity of:

$n(1 + (\frac{1}{3}) + (\frac{1}{3})^2 + (\frac{1}{3})^3 + ...) = n(\frac{1}{1-(\frac{1}{3})}) = \frac{n}{\frac{2}{3}} = \frac{3n}{2}$



so, all together we have:

$1 + 1 + (2\log_3(n)\times 2(\frac{3n}{2}))\times 1 \approx n\log(n)$


$\therefore$ run-time complexity is: $O(n\log(n))$

## Question 4 (10 Points. Easy)

Write a function **RandomCase** to manipulate the input string so that the case of each character of the string is selected randomly. Write some tests using GTest for for your function in [tests/q4_student_test.cc](tests/q4_student_test.cc).  

Example input & output:
```
Input: "Random"
Possible Outputs: "rAnDom" or "RAndOM" or "rANdOm"
```


## Question 5 (15 Points. Easy)

Write a simple function ```std::string CPPLib::PrintIntro()``` in [cpplib.cc](src/lib/cpplib.cc) which takes three strings: your first name, last name, and your programming experiences, and returns a string which is: Hi, my name is "{first_name} {last_name}, and my programming experiences are: {experiences}.". Write some tests using GTest for your function in [tests/q5_student_test.cc](tests/q5_student_test.cc). We will run your code and see your printout!

Please create your test cases and run the following command to verify the functionality of your program.

```bash
bazel test tests:q5_student_test
```

## Question 6 (25 Points. Medium)

 Write a function ```std::vector<int> CPPLib::Flatten3DVector(const std::vector< std::vector< std::vector<int> > > &input)``` in [cpplib.cc](src/lib/cpplib.cc) to flatten a 3D vector into a 1D vector.

Example:\
Input: inputs = [[[1, 2], [3, 4]], [[5], [6], []], [[7, 8]]].\
Output: result = [1, 2, 3, 4, 5, 6, 7, 8].

Write several tests using GTest for your function in [tests/q6_student_test.cc](tests/q6_student_test.cc).\
(Hint: include cases with empty vectors)

Please create your test cases and run the following command to verify the functionality of your program.
```
bazel test tests:q6_student_test
```
What is the worst case runtime complexity of your implementation?

Answer:

## Question 7 (30 Points. Medium)

Write a function ```int CPPLib::climbStairs(int n)``` in [cpplib.cc](src/lib/cpplib.cc) using recursion to find how many distinct ways you can climb to the top. Your function should accept positive numbers less than 45 and return the number of ways. Further, write several tests using GTest for your function in [tests/q7_student_test.cc](tests/q7_student_test.cc) and compute the time complexity of your implementation.

*Rules of the climb stairs*\
You are climbing a staircase. Each time you can either climb 1 or 2 steps. It takes n steps to reach the top.

If there are 0 stairs, there is 0 way to the top. For negative input, please return -1.

For example, if the stairs number is 4(n = 4), it should have 5 ways to the top.\
1 + 1 + 1 + 1\
1 + 1 + 2\
1 + 2 + 1\
2 + 1 + 1\
2 + 2

Please create your test cases and run the following command to verify the functionality of your program.

```bash
bazel test tests:q7_student_test
```
**Hint**: Try to write a recursive relationship.
What is the complexity of your implementation?

Answer:
