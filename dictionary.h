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

// ласс хранит словарь которым пользветс€ компьютер а текже предоставл€ет набор функций дл€ работы со словарЄм
class Dictionary
{
public:
    Dictionary();

    //ищет случайное слово в словар€х
    std::string findRandomWord(char lastLetter);

    //ƒобавл€ет слово в usedWords и убирает его из dictionary ,если оно там есть
    void usedWord(std::string Word,char lastLetter);

    //¬озвращает true если такого слова не использовалось
    bool checkUsed(std::string playerWord);

private:
    //загружает словари из файликов  в map - dictionary
    void loadDicts();

    //хранит все возможные варианты ответа компьютера
    std::map<char,std::list<std::string> > dictionary;
    //словарь на 1 букву записываетс€ сначала сюда
    std::list<std::string> singleDict;
    //вектор уже использованных слов
    std::vector<std::string> usedWords;
};
//(*mapIter).first; -это буква на которую в словаре начинаютс€ слова
//(*mapIter).second; - это список слов, при этом к отдельному нужно обращатьс€ итератором
inline bool compareStr(const std::string &str1,const std::string &str2);
#endif // FINDWORD_H
