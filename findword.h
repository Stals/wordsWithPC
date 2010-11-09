#ifndef FINDWORD_H
#define FINDWORD_H
#include <string>
#include <iostream>
#include <list>
#include <map>
class findWord
{
public:
    findWord();
private:
       //std::map<std::string;std::list> dictionary;//тут хранаятся все возможные варианты ответа компа
       std::list<std::string> usedWords;//список уже использованных слов
};

#endif // FINDWORD_H
