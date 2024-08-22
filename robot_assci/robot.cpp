#include <iostream>

using namespace std;

// pointer to function robot move forward
void move_forward()
{
    cout << "Robot is moving forward" << endl;
}

// pointer to function robot move backward
void move_backward()
{
    cout << "Robot is moving backward" << endl;
}

// pointer to function robot move left
void move_left()
{
    cout << "Robot is moving left" << endl;
}

// pointer to function robot move right
void move_right()
{
    cout << "Robot is moving right" << endl;
}

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
