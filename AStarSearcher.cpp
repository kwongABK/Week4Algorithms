#include "AStarSearcher.h"
#include <climits>

int AStarHeuristic(int node);
int FindShortestUnvisitedNode(int distances[], int visited[], int size);
bool AllVisited(int visited[], int size);

// Uses the A* algorithm on a graph with "size" nodes to find the shortest path between the first and last nodes.
// Returns the shortest path length, or -1 if the last node is unreachable from the start.
int AStarSearcher::AStarSearch(int map[4][4], int size)
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
    // Set initial visited state to false.
    int* visited = new int[size];
    for (int i = 0; i < size; i++)
    {
        visited[i] = 0;
    }
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
    delete[] visited;
    visited = nullptr;

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