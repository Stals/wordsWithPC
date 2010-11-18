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
    std::string findRandomWord(char lastLetter, std::string playerWord);//ищет случайное слово в словарях

private:
    void loadDicts();//загружает словари из файликов  в map - dictionary

        void usedWord(std::string Word);//Добавляет слово в usedWords и убирает его из dictionary ,если оно там есть
       std::map<std::string,std::list<std::string> > dictionary;//тут хранаятся все возможные варианты ответа компа
       std::list<std::string> singleDict;//словарб на 1 букву записывается сначала сюда
       std::list<std::string> usedWords;//список уже использованных слов
};
//*mapIter).first; -это буква на которую в словаре начинаются слова
// (*mapIter).second; - это список слов, при этом к отдельному нужно обращаться итератором
#endif // FINDWORD_H
