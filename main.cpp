#include<iostream>
#include<vector>
#include<algorithm>
#include <ctime>

//global variables
int VECTOR_SIZE = 100;

using namespace std;

int main()
{

    //making random number generator more random
    srand(time(NULL));

    //declaring vector to be used as the heap
    vector<int> vector1;

    //loop to populate vector with random numbers between 0-1000
    for(int i = 0; i < VECTOR_SIZE; i++){
        vector1.push_back(rand() % 1000);
    }

    //make heap through the vector
    make_heap(vector1.begin(), vector1.end());
    cout << endl;

    //display max element of heap
    cout << "Max element of heap is: " << vector1.front() << endl;

    //calculating meanValue of heap
    double meanValue = 0;
    for(int i = 0; i < VECTOR_SIZE; i++){
        meanValue += vector1[i];
    }
    meanValue = meanValue/VECTOR_SIZE;

    cout << endl << "Average of all values in vector1: " << meanValue << endl;

    cout << "Pushing meanValue into heap..." << endl;

    //pushing meanValue onto heap
    vector1.push_back((int)meanValue);
    VECTOR_SIZE++;
    //calling push_heap and using the vector to reorder the heap after pushing meanValue
    push_heap(vector1.begin(), vector1.end());

    //popping max value out of the heap
    cout << endl << "Popping max value out of heap..." << endl;
    pop_heap(vector1.begin(), vector1.end());
    vector1.pop_back();

    cout << "The max value of the heap is now: " << vector1.front() << endl << endl;

    return 0;
}