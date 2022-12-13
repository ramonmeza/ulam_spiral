#include <iostream>
#include <ulam/ulam.hh>

void ulam::print_table(int data[], int size, int max_cols)
{
    int i = 0;
    int *current = data;

    do
    {
        std::cout << *current << "\t";
        if (++i % max_cols == 0)
        {
            std::cout << std::endl;
        }
        current++;
    } while (i < size);
}

int *ulam::get_value(int data[], int width, int x, int y)
{
    int offset = (y * width) + x;
    return data + offset;
}
