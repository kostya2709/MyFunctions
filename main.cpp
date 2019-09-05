///@file
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>



int my_strcmp (char *str1, char *str2);

int my_puts (char *s);

int my_atoi (char *str);

char *my_itoa (int num, char *str, int radix);

char *my_fgets (char *str, int num, FILE *stream);


/*!
@brief Hello! This is my own library of functions!
*/


int main()
{

    return 0;
}

///------------------------------------------------------------------------------------
/*!

@brief This function reads a string consisting of less than num symbols
from the file stream to the char pointer str. It returns the pointer str
if everything is alright and NULL if the length of the string is more than
the maximal amount of chars in the string.

@param[in] *str a char pointer to the line, where to write the string down
@param[in] num the maximum amount of chars in the string
@param[in] stream the stream where to read the string from
\return a char pointer to the line, where to write the string down
*/

///------------------------------------------------------------------------------------

char *my_fgets (char *str, int num, FILE *stream)
    {
        assert (str);
        assert (isfinite(num));
        assert (stream);

        int counter = 0;
        char *str1 = str;
        char c;
        str--;
        while ((c = fgetc (stream)) != EOF && c != '\n' && ++counter < num)
            *str++ = c;
        if (counter == num)
        {
            printf ("Error! Too many symbols!\n");
            return NULL;
        }
        *str = '\0';
        return str1;
    }

/*!
@brief This function reads a string from the pointer *s and displays it on the screen.

@param[in] *s a pointer where the function receives a string from.

\return In the case of success the function returns the symbol of the end of the line,
else it returns EOF

*/

int my_puts(char *s)
    {
        assert (s);

        if (!s)
        {
            printf ("Error! A void pointer is accepted!\n");
            return EOF;
        }
        while (*s)
            putchar (*s++);
        putchar (*s);
        return '\n';
    }

/*!
@brief This function compares two strings lexicographically.

@param[in] *str1 The pointer to the first string needs comparing
@param[in] *str2 The pointer to the second string needs comparing

\return The function returns an integer number.
If the first line is longer than the second one it returns a number that is more than 0;
if the second line is longer than the first one it returns a number that is less than 0;
if the lines are equal the function returns 0.

*/

int my_strcmp (char *str1, char *str2)
    {
        assert (str1);
        assert (str2);

        if (!str1 || !str2)
            printf ("Error! A void pointer is accepted!\n");

        while (*str1 && *str2 && (*str1 == *str2))
        {
            *str1++;
            *str2++;
        }
        return *str1 - *str2;
    }

/*!

   @brief This function converts a string to a number.

   @param[in] *str A pointer to a string, where the number is to be taken from.

   \return It returns an integer number. If the symbols in the string are incorrect and do not compose a number the function returns 0.
   If the the string is like a float number (e.g. '123.45')
   it is converted to an integer with no part after a point '123'.

*/

int my_atoi (char *str)
    {
        assert (str);

        char *nstr = str;

        while (*str == ' ')
            str++;

        int sign = 1;
        if (*str == '-')
            sign = -1;
        if (*str == '-' || *str == '+')
            str++;

        int number = 0;
        while (*str)
        {
            if (*str >= '0' && *str <= '9')
                number = number * 10 + *str - '0';
            else
                if (!number)
                    return 0;
                else return number * sign;

            str++;
        }
        return number * sign;
    }

/*!
@brief This function converts an integer number num to a string to the pointer *str.
The number is in the number system based on radix.

@param[in] num The number needs converting to a string
@param[in] *str The pointer to a string where to put the string to
@param[in] radix The base of number system of the num in the string

\return It returns a pointer to the string *str

\warning The maximum amount of the line is 17 symbols!

*/

char *my_itoa (int num, char *str, int radix)
    {
        assert (isfinite(num));
        assert (str);
        assert (radix);

        char *str1 = str;
        char str2[17] = {};
        int counter = 0;
        while (num)
        {
            int rest = num % radix;
            str2[counter] = rest + ((rest < 10) ? '0' : 'A' - 10);
            num /= radix;
            counter ++;
        }

        while (counter)
        {
            counter--;
            *str = str2[counter];
            str++;
        }
        return str1;
    }
