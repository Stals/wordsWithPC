#ifndef CHECK_H
#define CHECK_H
#include <string>
#include "cases.h"
#include "charFuncs.h"
#include "findword.h"

//Статус введонного слова
enum status{
    OK,              //Ввод нормальный
    WrongFirstLetter,//Неправильный первый символ
    UsedWord,        //Слово уже исспользовалось
    NotRusWord,      //Не русское слово
    TooShortWord,    //Слишком короткое слово
    NoWord,          //Слово 0 длинны
    WrongEnd         //Неправильное окончание
};

//Этот класс занимается проверкой слова введенной пользователем на праильность
class Check
{
public:
    Check();
    //проводит проверки и возвращает true , если слово игрока подходит
    bool playerWord(const std::string& playerWord,const std::string& pcWord,Dictionary& dictionary);

    //возвращает статус слова в виде строки
    std::string stringStatus();

    //хранит текущее состояние
    status statusNum;


private:
    char playerFirstLetter;
    char playerLastLetter;
    char pcLastLetter;

    //Каждая из функций возвращает true ,если нашлось несоответсвие + меняет statusNum
    bool checkLength(std::string); //Проверят длинну слова
    bool rusLetter(char); //Провреряет является ли слово Русским
    bool usedWord(std::string,Dictionary&); //Проверяет было ли использованно слово
    bool firstLast(char,char);//Проверяет эквивалентен ли первый символ слова игрока последнему в слове компьютера
    bool lastLetters(std::string);//Проверяет чтобы оба последних символа небыли ъ ь ы или пробелом (абвъы)
};

#endif // CHECK_H
