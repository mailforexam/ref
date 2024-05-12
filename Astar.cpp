#include<bits/stdc++.h>
using namespace std;

// Define a structure for representing a state
struct State
{
    int x, y;      // Coordinates
    int cost;      // Cost so far
    int heuristic; // Heuristic value
    State(int _x, int _y, int _cost, int _heuristic) : x(_x), y(_y), cost(_cost), heuristic(_heuristic) {}
    bool operator<(const State &other) const
    {
        // Define the priority queue comparator based on total estimated cost
        return cost + heuristic > other.cost + other.heuristic;
    }
};

// A* search algorithm
int astar(vector<vector<int>> &grid, pair<int, int> &start, pair<int, int> &goal)
{
    // Define possible moves (up, down, left, right)
    vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Initialize priority queue for open states
    priority_queue<State> open;

    // Map to store visited states and their costs
    map<pair<int, int>, int> visited;

    // Add the start state to the priority queue
    open.push(State(start.first, start.second, 0, abs(start.first - goal.first) + abs(start.second - goal.second)));

    // A* search loop
    while (!open.empty())
    {
        // Get the current state with the lowest estimated total cost
        State current = open.top();
        open.pop();

        // Check if the current state is the goal state
        if (current.x == goal.first && current.y == goal.second)
        {
            return current.cost;
        }

        // Explore neighbors
        for (auto &move : moves)
        {
            int nx = current.x + move.first;
            int ny = current.y + move.second;
            int ncost = current.cost + 1; // Cost for each move is 1

            // Check if the neighbor is within bounds and not blocked
            if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] != 1)
            {
                // Calculate heuristic value (Manhattan distance to the goal)
                int nheuristic = abs(nx - goal.first) + abs(ny - goal.second);

                // Check if the neighbor has not been visited or a better path is found
                if (!visited.count({nx, ny}) || ncost < visited[{nx, ny}])
                {
                    // Update visited map and push the neighbor to the priority queue
                    visited[{nx, ny}] = ncost;
                    open.push(State(nx, ny, ncost, nheuristic));
                }
            }
        }
    }

    // If no path to the goal is found
    return -1;
}

int main()
{
    // Example grid
    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 1, 0}};

    pair<int, int> start = {0, 0}; // Start position
    pair<int, int> goal = {3, 3};  // Goal position

    // Find the shortest path using A* algorithm
    int shortestPath = astar(grid, start, goal);

    // Output the result
    if (shortestPath == -1)
    {
        cout << "No path to the goal found." << endl;
    }
    else
    {
        cout << "Shortest path to the goal: " << shortestPath << " steps." << endl;
    }

    return 0;
}
