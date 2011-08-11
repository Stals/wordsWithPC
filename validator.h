#ifndef CHECK_H
#define CHECK_H
#include <string>
#include "cases.h"
#include "charFuncs.h"
#include "dictionary.h"

//Статус введонного слова
enum status{
    OK,              //Ввод нормальный
    WrongFirstLetter,//Неправильный первый символ
    UsedWord,        //Слово уже исспользовалось
    NotRusWord,      //Не русское слово
    TooShortWord,    //Слишком короткое слово
    NoWord,          //Слово 0 длинны
    WrongEnd,        //Неправильное окончание
    SpaceInWord      //В слове есть пробел
};

//Этот класс занимается проверкой слова введенной пользователем на правильность
class Validator
{
public:
    Validator();
    //проводит проверки и возвращает true , если слово игрока подходит
    status checkPlayerWord(const std::string& checkPlayerWord,const std::string& pcWord,Dictionary& dictionary);

    //возвращает статус слова в виде строки
    std::string getStatus();

    //хранит текущее состояние
    status currentStatus;


private:
    char playerFirstLetter;
    char playerLastLetter;
    char pcLastLetter;

    //Каждая из функций возвращает true ,если нашлось несоответсвие + меняет currentStatus
    bool checkLength(std::string);                //Проверят длинну слова
    bool checkRusLetter(char);                    //Провреряет является ли слово Русским
    bool checkUsedWord(std::string,Dictionary&);  //Проверяет было ли использованно слово
    bool checkFirstLast(char,char);               //Проверяет эквивалентен ли первый символ слова игрока последнему в слове компьютера
    bool checkLastLetters(std::string);           //Проверяет чтобы оба последних символа небыли ъ ь ы (абвъы)
    bool checkSpaces(std::string);                //Проверяет чтобы в строке не было пробела
};

#endif // CHECK_H
