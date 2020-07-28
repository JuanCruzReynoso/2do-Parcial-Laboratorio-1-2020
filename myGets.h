#ifndef MYGETS_H_INCLUDED
#define MYGETS_H_INCLUDED

///---------- GETS SIMPLES ----------

int getInt(char mensaje[]);

float getFloat(char mensaje[]);

char getChar(char mensaje[]);

void getString(char mensaje[], char auxString[]);

///---------- VALIDACIONES ----------

void stringToUpper(char str[]);

int isOnlyNumbers(char str[]);

int isOnlyLetters(char str[]);

int isAlphaNumeric(char str[]);

///---------- GETS VALIDADOS ----------

void getStringOnlyLetters(char mensaje[], char str[]);

void getStringOnlyNumbers(char mensaje[], char str[]);

void getStringAlphaNumeric(char mensaje[], char str[]);

#endif // MYGETS_H_INCLUDED
