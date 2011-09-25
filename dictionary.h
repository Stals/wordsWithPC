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

//Класс хранит словарь которым пользвется компьютер а текже предоставляет набор функций для работы со словарём
class Dictionary
{
public:
    Dictionary();

    ~Dictionary();

    //ищет случайное слово в словарях
    std::string findRandomWord(char lastLetter);

    //Добавляет слово в usedWords и убирает его из dictionary ,если оно там есть
    void addUsedWord(std::string word);

    //Убирает слово из словаря если оно там есть
    void removeWord(std::string word);

    //Возвращает true если это слово уже использовалось (компьютером или пользователем)
    bool isUsedWord(std::string playerWord);

    //Возвращает true если этого слова нет в словарях
    bool isNewWord(std::string playerWord);

    //Добавляет новое слово в словарь на диске
    void addNewWord(std::string playerWord);

private:
    //загружает словари из файликов  в map - dictionary
    void loadDicts();

    //Воозвращает путь к файлу в который нужно сохранить слово newWord
    std::string getFileName(std::string newWord);

    //Возвращает true если слово есть в словаре
    bool isInDictionary(std::string playerWord);

    //хранит все возможные варианты ответа компьютера
    std::map<char, std::list<std::string> > dictionary;

    //вектор уже использованных слов
    std::vector<std::string> usedWords;

};
//(*mapIter).first; -это буква на которую в словаре начинаются слова
//(*mapIter).second; - это список слов, при этом к отдельному нужно обращаться итератором
inline bool compareStr(const std::string &str1, const std::string &str2);
#endif // FINDWORD_H
