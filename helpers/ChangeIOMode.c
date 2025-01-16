#include <unistd.h>
#include <termios.h>


struct termios saved_attributes;

extern void reset (void)
{
    tcsetattr (STDIN_FILENO, TCSANOW, &saved_attributes);
}

extern void set (void)
{
    struct termios tattr;

    /* Save the terminal attributes so we can restore them later. */
    tcgetattr (STDIN_FILENO, &saved_attributes);

    /* Set the funny terminal modes. */
    tcgetattr (STDIN_FILENO, &tattr);
    tattr.c_lflag &= ~(ICANON|ECHO); /* Clear ICANON and ECHO. */

    tcsetattr (STDIN_FILENO, TCSAFLUSH, &tattr);
}