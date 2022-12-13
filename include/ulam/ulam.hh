#include <string>

namespace ulam
{
    const int RIGHT = 0;
    const int UP = 1;
    const int LEFT = 2;
    const int DOWN = 3;

    enum TextColor
    {
        black = 30,
        red,
        green,
        yellow,
        blue,
        magenta,
        cyan,
        white
    };

    enum TextStyle
    {
        reset = 0,
        bold = 1,
        bright = 1,
        underline = 4,
        inverse = 7,
        bold_off = 21,
        bright_off = 21,
        underline_off = 24,
        iinverse_off = 27
    };

    bool is_prime(int number);
    void print_colored_text(const std::string &text, TextColor color, TextStyle style = TextStyle::reset);
    void print_table(int data[], int size, int max_cols);
    int *get_value(int data[], int width, int x, int y);
}
