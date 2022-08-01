#include <chrono>
#include <iostream>

const int SMALL_SIZE = 10;
const int MEDIUM_SIZE = 1000;

using namespace std;

void BubbleSort(int numbers[], int size);

int main()
{
    // Initialize random number generator.
    srand(time(nullptr));

    const int size = SMALL_SIZE;
    int numbers[size];

    // Populate the random array with random numbers from 1 to the array size.
    for (int i = 0; i < size; i++)
    {
        numbers[i] = (rand() % size) + 1;
    }

    BubbleSort(numbers, size);

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
