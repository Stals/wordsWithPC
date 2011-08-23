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

    //добавл€ет новые слова из newWords в словари на диске
    ~Dictionary();

    //ищет случайное слово в словар€х
    std::string findRandomWord(char lastLetter);

    //ƒобавл€ет слово в usedWords и убирает его из dictionary ,если оно там есть
    void addUsedWord(std::string word);

    //”бирает слово из словар€ если оно там есть
    void removeWord(std::string word);

    //¬озвращает true если это слово уже использовалось (компьютером или пользователем)
    bool isUsedWord(std::string playerWord);

    //¬озвращает true если этого слова нет в словар€х
    bool isNewWord(std::string playerWord);

    //ƒобавл€ет новое слово в словар newWords , а
    bool addNewWord(std::string playerWord);

private:
    //загружает словари из файликов  в map - dictionary
    void loadDicts();

    //¬озвращает true если слово есть в словаре
    bool isInDictionary(std::string playerWord);

    //хранит все возможные варианты ответа компьютера
    std::map<char, std::list<std::string> > dictionary;

    //вектор уже использованных слов
    std::vector<std::string> usedWords;

    //вектор новых слов ,которые при завершении программы дабав€тс€ в словари компьютера
    std::vector<std::string> newWords;

    //map который позвол€ет пон€ть номер буквы в русском алфавите
    std::map<char,std::string> charToNum; //TODO инициализировать не в конструкоторе
};
//(*mapIter).first; -это буква на которую в словаре начинаютс€ слова
//(*mapIter).second; - это список слов, при этом к отдельному нужно обращатьс€ итератором
inline bool compareStr(const std::string &str1, const std::string &str2);
#endif // FINDWORD_H
