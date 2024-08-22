#include <iostream>
#include "robot.h"
using namespace std;

int main(int argc, char const *argv[])
{
    while (true)
    {
        cout << "Enter the direction to move the robot: ";
        char direction;
        cin >> direction;
        if (direction == 'w')
        {
            move_forward();
        }
        else if (direction == 's')
        {
            move_backward();
        }
        else if (direction == 'a')
        {
            move_left();
        }
        else if (direction == 'd')
        {
            move_right();
        }
        else
        {
            cout << "Invalid direction" << endl;
            break;
        }
    }
    return 0;
}