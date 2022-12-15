# Targil_1
## (Exercise 2 is in the branch targil2)
### Instructions on how to run and compile part 2 of exercise 1:
Run the following commands on the server:
1. git init
2. git clone https://github.com/edenahady/targil_1.git
3. cd targil_1 (in order to enter the folder of the repository)
4. cd project (in order to enter the folder of the files for this part)
5. g++ distances.h
6. g++ -std=c++11 *.cpp -o a
7. ./a
8. Enter arguments of your choice

### Our code:
Our code has one file which includes 5 functions that accepts 2 vectors as inputs and calculates 5 different distances (according to Wikipedia):
1. Euclidean
2. Manhattan
3. Chebyshev
4. Canberra*
5. Minkowski


*In the Canberra distance we chose that p=2 and calculates the answer according to that.

Our code accepts two vectors of the same size as inputs where the input is solely numeric and does not start or end with blankspaces.

If the input is anything other than a series of numbers with blank spaces in between (e.g 1 2 3) such as letters or symbols, the function will stop and exit.
