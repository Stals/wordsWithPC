#ifndef CHECK_H
#define CHECK_H
#include <string>
#include "cases.h"
#include "charFuncs.h"
#include "findword.h"
enum status{
    OK,             //Ввод нормальный
    WrongFirstLetter,//Неправильный первый символ
    UsedWord,       //Слово уже исспользовалось
    NotRusWord,     //Не русское слово
    TooShortWord,   //Слишком короткое слово
    NoWord,          //Слово 0 длинны
    WrongEnd        //Неправильное окончание
};
class check
{
public:
    check();
    bool playerWord(const std::string&,const std::string&,findWord&); //провеодит проверки и возвращает true , если слово игрока подходит
    status statusNum;//хранит текущее состояние

    std::string stringStatus();//врзвращает строку в зависимости от текущего статусв
private:
    char playerFirstLetter;
    char playerLastLetter;
    char pcLastLetter;

    //true ,если нашлось несоответсвие + меняет statusNum
    bool checkLength(std::string);
    bool rusLetter(char);
    bool usedWord(std::string,findWord&);
    bool firstLast(char,char);//Проверяет эквивалентен ли первый символ слова игрока последнему в словае Компа
    bool lastLetters(std::string);//Проверяет чтобы оба последних символа небыли ъ ь ы или пробелом (абвъы)
};

#endif // CHECK_H
