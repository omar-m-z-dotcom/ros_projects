#include <iostream>

struct Point
{
    double x;
    float y;
    float z;

    bool operator==(const Point &other) const
    {
        return x == other.x && y == other.y && z == other.z;
    }
};

void GoalReached(const Point &goal, const Point &current)
{
    if (goal == current)
    {
        std::cout << "Goal reached!" << std::endl;
    }
    else
    {
        std::cout << "Goal not reached!" << std::endl;
    }
}

int main()
{
    Point goal = {1.0, 2.0, 3.0};
    Point current = {1.0, 2.0, 3.0};

    GoalReached(goal, current);

    return 0;
}
