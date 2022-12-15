# targil 2
### Instructions on how to run and compile exercise 2:
Run the following commands on the server:
1. git init
2. git clone -b targil2 https://github.com/edenahady/targil_1.git
3. cd targil_1 (in order to enter the folder of the repository)
4. cd project (in order to enter the folder of the files for this part)
5. make
6. ./a.out + "Your arguments"
7. input vector
8. repeat step 7 as you wish

### Our code:
Our main class is KNN where we accept k=number of neighbors, the file which we want to work on and the type of distance we want to calculate with.

In our pair class we create an object called pair which holds the distance between given vector and the vector from the file and the index of the vector from the file.

In knnClass we calculate the distances between the vectors read from the file and the given input, create a vector of pairs, sort the vector and take the first k pair. After that we go over the k pairs and enter them into a map where the classification of the neighbor is the value and the number of neighbors with that classification is the key. Then we find the value with the highest key and return its classification as the most common and therefore the classification of my vector.

***
*Our code works on the 3 files that were given with the assignment: iris, beans and wine as was written in the instructions.

*Our code accepts a vector of the same size as the vectors from the file, where the input is solely numeric and does not start or end with blankspaces.

*If the input vector is anything other than a series of numbers with blank spaces in between (e.g 1 2 3) such as letters or symbols the function will stop and exit, same as for k.

*In the case where the size of the vectors in the file are not the same the function will stop and exit.

*If the file is not found or cant be opened then you will recieve the message "Could not open the file".

