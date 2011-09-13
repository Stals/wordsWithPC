#ifndef CHECK_H
#define CHECK_H
#include <string>
#include "cases.h"
#include "charFuncs.h"
#include "dictionary.h"

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

    //Возращет стутус в виде строки
    //TODO может переименовать в getStatusAsString?
    static std::string convertStatusToString(Status::Value status){

        switch (status){
        case Status::OK:
            return "Правильный ввод";
            break;
        case Status::WrongFirstLetter:
            return "Неправильный первый символ";
            break;
        case Status::UsedWord:
            return "Это слово уже использовалось";
            break;
        case Status::NotRusWord:
            return "В слове должны быть только русские буквы";
            break;
        case Status::TooShortWord:
            return "Слишком короткое слово";
            break;
        case Status::NoWord:
            return "Сначала введите что-нибудь";
            break;
        case Status::WrongEnd:
            return "Неправильное окончание";
            break;
        case Status::SpaceInWord:
            return "В слове не должно быть пробелов";
            break;
        case Status::NotNewWord:
            return "Введите другое слово";
        default:
            return "Ошибка";
        }
    }
};

//Этот класс занимается проверкой слова введенной пользователем на правильность
class Validator
{
public:
    Validator();
    //проводит проверки и возвращает true , если слово игрока подходит
    bool isWordValid(const std::string& isWordValid,const char& pcLastLetter,Dictionary& dictionary);

    //Меняет статус на status
    void setCurrentStatus(Status::Value status);

    //возвращает статус слова в виде строки
    std::string getCurrentStatus();

private:

    //текущее состояние
    Status::Value currentStatus; 

    //Каждая из функций возвращает true ,если нашлось несоответсвие + меняет currentStatus
    bool hasWrongLength(std::string);                //Проверят длинну слова
    bool isNotRusWord(std::string);                  //Провреряет является ли слово Русским
    bool isUsedWord(std::string, Dictionary&);       //Проверяет было ли использованно слово
    bool hasWrongFirstLast(char,char);               //Проверяет эквивалентен ли первый символ слова игрока последнему в слове компьютера
    bool hasWrongLastLetters(std::string);           //Проверяет чтобы оба последних символа небыли ъ ь ы (абвъы)
    bool hasSpaces(std::string);                     //Проверяет чтобы в строке не было пробела
};

#endif // CHECK_H
