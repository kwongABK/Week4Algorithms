#include <chrono>
#include <iostream>

const int SMALL_SIZE = 10;
const int MEDIUM_SIZE = 1000;

using namespace std;

void FillArray(int numbers[], int size);
void PrintArray(int numbers[], int size);
void BubbleSort(int numbers[], int size);
int AStarSearch(int map[4][4], int size);
int AStarHeuristic(int node);
int FindShortestUnvisitedNode(int distances[], int visited[], int size);
bool AllVisited(int visited[], int size);

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
    cout << "The shortest distance from first node to the last node is " << AStarSearch(map, mapSize) << endl;
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

// Uses the A* algorithm on a graph with "size" nodes to find the shortest path between the first and last nodes.
// Returns the shortest path length, or -1 if the last node is unreachable from the start.
int AStarSearch(int map[4][4], int size)
{
    // Initialize distances for each node as well as an array with the visited state of each node.
    int* distances = new int[size];
    // Set initial distances to max integer.
    for (int i = 0; i < size; i++)
    {
        if (i == 0)
        {
            distances[i] = 0;
        }
        else
        {
            distances[i] = INT_MAX;
        }
    }
    // Default array constructor sets the values to 0.
    int visited[4] = {};
    int currentNode = 0;

    // The end condition is all nodes being visited, or the next node being infinite distance.
    do
    {
        // Update all adjacencies for the current node.
        for (int i = 0; i < size; i++)
        {
            // Only update nodes with a cost that haven't been visited.
            if (map[currentNode][i] > 0 && !visited[i])
            {
                if (distances[currentNode] + map[currentNode][i] + AStarHeuristic(currentNode) < distances[i])
                {
                    distances[i] = distances[currentNode] + map[currentNode][i];
                }
            }
        }
        // Mark current node as visited.
        visited[currentNode] = 1;
        // Find the unvisited row with the smallest distance.
        currentNode = FindShortestUnvisitedNode(distances, visited, size);
    } while (!AllVisited(visited, size) && currentNode);

    int result = distances[size - 1];

    delete[] distances;
    distances = nullptr;
    return result == INT_MAX ? -1 : result;
}

// Placeholder code for an A* heuristic.
int AStarHeuristic(int node)
{
    return 0;
}

// Finds the index of the unvisited node with the shortest distance. Returns -1 if it doesn't exist.
int FindShortestUnvisitedNode(int distances[], int visited[], int size)
{
    int shortestIndex = -1;
    int shortest = INT_MAX;

    for (int i = 0; i < size; i++)
    {
        if (visited[i] == 0 && distances[i] < shortest)
        {
            shortestIndex = i;
            shortest = distances[i];
        }
    }

    return shortestIndex;
}

// Helper method for the AStar algorithm that returns true if all values in the visited array are set to 1.
bool AllVisited(int visited[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (visited[i] != 1)
        {
            return false;
        }
    }
    return true;
}