#pragma once

/*
   Makes string representation of the number,
    allocates memory for the string and returns it.
*/
char  *ft_itoa(int n);

/*
   Make string representation of the equation

   @param x random generated left operand of the equation
   @param y random generated right operand of the equation
   @param operation char representing operatrin (+-*)

   @return value stored in the str

*/
char* makeEquationString(int x, int y, char operation);
