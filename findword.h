#ifndef FINDWORD_H
#define FINDWORD_H
#include <string>
#include <iostream>
#include <list>
#include <map>
#include <fstream>
#include <vector>
#include <time.h>//for random
#include <stdlib.h>
class findWord
{
public:
    findWord();
    std::string findRandomWord(char lastLetter);//ищет случайное слово в словарях
    void usedWord(std::string Word);//Добавляет слово в usedWords и убирает его из dictionary ,если оно там есть
    bool checkUsed(std::string playerWord);//true если такого слова не использовалось
private:
    void loadDicts();//загружает словари из файликов  в map - dictionary


       std::map<char,std::list<std::string> > dictionary;//тут хранаятся все возможные варианты ответа компа
       std::list<std::string> singleDict;//словарь на 1 букву записывается сначала сюда
       std::list<std::string> usedWords;//список уже использованных слов
};
//(*mapIter).first[0]; -это буква на которую в словаре начинаются слова
// (*mapIter).second; - это список слов, при этом к отдельному нужно обращаться итератором
#endif // FINDWORD_H
