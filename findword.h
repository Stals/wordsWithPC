#ifndef FINDWORD_H
#define FINDWORD_H
#include <string>
#include <iostream>
#include <list>
#include <map>
#include <fstream>
#include <vector>
class findWord
{
public:
    findWord();
    std::string findRandomWord(char firstLetter, std::string playerWord);//ищет случайное слово в словарях

private:
    void loadDicts();//загружает словари из файликов  в map - dictionary

        void usedWord(char firstLetter, std::string playerWord);//Добавляет слово в usedWords и убирает его из dictionary ,если оно там есть
       std::map<std::string,std::list<std::string> > dictionary;//тут хранаятся все возможные варианты ответа компа
       std::list<std::string> singleDict;//словарб на 1 букву записывается сначала сюда
       std::list<std::string> usedWords;//список уже использованных слов
};

#endif // FINDWORD_H
