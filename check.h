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
    check();
    void playerWord(const std::string&,const std::string&,cases&,charFunc&);
    status statusNum;

private:
    char playerFirstLetter;
    char playerLastLetter;
    char pcLastLetter;
};

#endif // CHECK_H
