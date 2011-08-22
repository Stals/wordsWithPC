#ifndef CHECK_H
#define CHECK_H
#include <string>
#include "cases.h"
#include "charFuncs.h"
#include "dictionary.h"



//Этот класс занимается проверкой слова введенной пользователем на правильность
class Validator
{
public:
    Validator();
    //проводит проверки и возвращает true , если слово игрока подходит
    bool isWordValid(const std::string& isWordValid,const char& pcLastLetter,Dictionary& dictionary);

    //Меняет статус на notNewWord
    void notNewWord();

    //возвращает статус слова в виде строки
    std::string getStatus();

private:

    struct Status{
    //Статус введонного слова
        enum Value{
            OK,              //Ввод нормальный
            WrongFirstLetter,//Неправильный первый символ
            UsedWord,        //Слово уже исспользовалось
            NotRusWord,      //Не русское слово
            TooShortWord,    //Слишком короткое слово
            NoWord,          //Слово 0 длинны
            WrongEnd,        //Неправильное окончание
            SpaceInWord,     //В слове есть пробел
            NotNewWord       //Пользователь не захотел добавить слово в словарь
        };
    };

    //текущее состояние
    Status::Value currentStatus;

    char playerFirstLetter;
    char playerLastLetter;

    //Каждая из функций возвращает true ,если нашлось несоответсвие + меняет currentStatus
    bool hasWrongLength(std::string);                //Проверят длинну слова
    bool isNotRusLetter(char);                       //Провреряет является ли слово Русским
    bool isUsedWord(std::string, Dictionary&);       //Проверяет было ли использованно слово
    bool hasWrongFirstLast(char,char);               //Проверяет эквивалентен ли первый символ слова игрока последнему в слове компьютера
    bool hasWrongLastLetters(std::string);           //Проверяет чтобы оба последних символа небыли ъ ь ы (абвъы)
    bool hasSpaces(std::string);                     //Проверяет чтобы в строке не было пробела
};

#endif // CHECK_H
