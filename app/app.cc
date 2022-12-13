#include <cstdio>
#include <iostream>
#include <ulam/ulam.hh>

int main(int argc, char **argv)
{
    // variables
    int *values = nullptr;               // an array to hold values for our spiral
    int values_size = 0;                 // size of the values array
    int max_cols = 0;                    // max number of columns to print out
    int current_index = 0;               // index into the values array
    int x, y = 0;                        // current position in the array
    int current_direction = ulam::RIGHT; // the current direction the spiral is going
    int steps_needed = 1;                // steps needed in a given direction
    int steps_completed = 0;             // a counter which counts to 2 and signifies we need to update our number of steps per direction

    // get user input
    std::cout << "Enter select an odd value: ";
    std::cin >> max_cols;
    if (max_cols % 2 == 0)
    {
        std::cout << "INFO: Changed max_cols from " << max_cols << " to " << --max_cols << std::endl;
    }

    // create the values array
    values_size = max_cols * max_cols;
    values = new int[values_size];

    for (unsigned int i = 0; i < values_size; i++)
    {
        values[i] = 0;
    }

    // set starting point to the center of the array
    x = (int)(max_cols / 2);
    y = x;

    // populate the values array in a spiral
    for (unsigned int i = 0; i < values_size;)
    {
        // take how ever many steps in the correct direction
        for (unsigned int step = 0; step < steps_needed; step++)
        {
            *ulam::get_value(values, max_cols, x, y) = ++i;

            // get next position
            switch (current_direction)
            {
            case ulam::RIGHT:
                x++;
                break;

            case ulam::UP:
                y--;
                break;

            case ulam::LEFT:
                x--;
                break;

            case ulam::DOWN:
                y++;
                break;

            default:
                break;
            }
        }
        steps_completed++;

        // update the direction for next loop
        ++current_direction %= 4;
        if (steps_completed % 2 == 0)
        {
            steps_needed++;
        }
    }

    // print the spiral as a table
    ulam::print_table(values, values_size, max_cols);

    // free memory
    delete values;
    values = nullptr;

    // return
    std::cout << "Press enter to continue...";
    std::cin >> x; // dummy variable
    return EXIT_SUCCESS;
}
