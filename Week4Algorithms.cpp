#include <chrono>
#include <iostream>
#include "AStarSearcher.h"

const int SMALL_SIZE = 10;
const int MEDIUM_SIZE = 1000;

using namespace std;

void FillArray(int numbers[], int size);
void PrintArray(int numbers[], int size);
void BubbleSort(int numbers[], int size);

int main()
{
    // Initialize random number generator using system time as a seed.
    srand(time(nullptr));

    // Create an array of the specified size and sort it.
    const int size = SMALL_SIZE;
    int numbers[size];
    FillArray(numbers, size);

    BubbleSort(numbers, size);
    PrintArray(numbers, size);

    // Create a hardcoded adjacency matrix and process it using A* search.
    const int mapSize = 4;
    int map[mapSize][mapSize] = { {0, 5, 0, 7}, {5, 0, 1, 0}, {0, 1, 0, 1}, {7, 0, 1, 0} };
    cout << "The shortest distance from first node to the last node is ";
    cout << AStarSearcher::AStarSearch(map, mapSize) << endl;
}

// Sets each value in an array to a random number from 1 to the array size.
void FillArray(int numbers[], int size)
{
    for (int i = 0; i < size; i++)
    {
        numbers[i] = (rand() % size) + 1;
    }
}

// Prints an array to standard output.
void PrintArray(int numbers[], int size)
{
    // Print the sorted array.
    for (int i = 0; i < size; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;
}

// Use Bubble Sort algorithm to sort an int array in ascending order.
void BubbleSort(int numbers[], int size)
{
    // Create a swap counter to track if more passes need to be made.
    // If no swaps occur on a pass (everything is in order), we are done!
    int swaps = 0;

    do
    {
        swaps = 0;
        for (int i = 0; i < size - 1; i++)
        {
            if (numbers[i] > numbers[i + 1])
            {
                int temp = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = temp;
                swaps++;
            }
        }
    } while (swaps != 0);
}