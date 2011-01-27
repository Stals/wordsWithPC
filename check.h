#ifndef CHECK_H
#define CHECK_H
#include <string>
#include "cases.h"
#include "charFuncs.h"
enum status{
OK,             //Ввод нормальный
WrongFirstLetter,//Неправильный первый символ
UsedWord,       //Слово уже исспользовалось
NotRusWord,     //Не русское слово
TooShortWord,   //Слишком короткое слово
NoWord          //Слово 0 длинны
};
class check
{
public:
    void playerWord(std::string,std::string,cases,charFunc);
};

#endif // CHECK_H
