#include <cmath>
#include <iostream>
#include <ulam/ulam.hh>

bool ulam::is_prime(int number)
{
    // number must be greater than 1
    if (number <= 1)
        return false;

    // 2 is the only even prime number
    if (number == 2)
        return true;
    if (number % 2 == 0)
        return false;

    // if a number is divisible by any number less than itself (down to 2)
    // than the number is not prime
    for (unsigned int i = (unsigned int)sqrt(number); i > 2; i--)
    {
        if (number % i == 0)
            return false;
    }
    return true;
}

void ulam::print_colored_text(const std::string &text, ulam::TextColor color, TextStyle style)
{
    std::cout << "\e[" << (int)style << ";" << (int)color << "m" << text << "\e[0m";
}

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
