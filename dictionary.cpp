#include "dictionary.h"
#include <algorithm>
#include <cstdlib>
#include <string.h>
#include <windows.h>
#include "charFuncs.h"
Dictionary::Dictionary(){
    loadDicts();
}
Dictionary::~Dictionary(){
//TODO добавление слов из newWords в словари компьютера

}

void Dictionary::loadDicts(){
    // Создаём вектор файлов словарей для каждой буквы
    std::vector< std::string > files;
    char buf[3];

    for( int i=1; i<34; ++i ){
        std::string str="dict//";
        itoa( i, buf, 10 );
        str.append( buf );
        files.push_back( str );
    }

    // Добавляем содержимое каждого из файлов в dictionary
    for( std::vector< std::string >::iterator it = files.begin(); it != files.end(); ++it){
        std::ifstream f( (*it).c_str() );

        int num; //number of words
        std::string letter;
        std::string newWord;
        //хранит список слов начинающихся на одну букву
        std::list<std::string> singleDict;

        f >> letter;
        f >> num;

        for(int i = 0; i < num; ++i){
            f >> newWord;
            singleDict.push_back( newWord );
        }
        dictionary.insert (std::pair<char,std::list<std::string> >(letter[0],singleDict));
        singleDict.clear();

        f.close();
    }
}


void Dictionary::addUsedWord(std::string word){
    //Добавляем Word в usedWords
    usedWords.push_back( word );
}

void Dictionary::removeWord(std::string word){
    dictionary[word[0]].remove( word );
}

std::string Dictionary::findRandomWord(char lastLetter){
     srand(time(NULL));

    //ё->е й->и так как они считаются одним и темже
    charFuncs::changeChar( lastLetter );

    //сразу устанавливаем итератор на нужный нам словарь
    std::list<std::string>::iterator it = dictionary[lastLetter].begin();

    if( dictionary[lastLetter].size() != 0 ){
        unsigned int randomWordIndex = rand() % dictionary[lastLetter].size();
        //Находим это слово перебором
        for( unsigned int i = 0; i < randomWordIndex; ++i ){
            ++it;
        }
        //Добавляем только что найденное слово в использованные
        addUsedWord(*it);
        //И уберем его из словарей
        removeWord(*it);

        return (*it);

    }else{
        return "YOU WIN";
    }
}


bool Dictionary::isUsedWord(std::string playerWord){
    for(std::vector< std::string >::iterator it = usedWords.begin(); it != usedWords.end(); ++it){
        if((*it) == playerWord){//слово уже было
            return true;
        }
    }
    //если за весь список не встретил такого слово - значит оно еще не использовалось
    return false;
}

bool Dictionary::isNewWord(std::string playerWord){
    if(isInDictionary(playerWord)){
        return false;
    }else{
        return true;
    }

}


bool Dictionary::isInDictionary(std::string playerWord){ //TODO проверка слова на нахождение в словаре
    //for( std::map<char, std::list<std::string> >::iterator it=dictionary.begin();it!=dictionary.end(); ++it){
    //    (*it).second.find(playerWord)
    //}
return false;
}

bool Dictionary::addNewWord(std::string playerWord){//TODO добавка слова в вектор newWords

}


bool compareStr(const std::string &str1, const std::string &str2){
    if(strcmp(str1.c_str(), str2.c_str())){//Если первая строка больще чем вторая
        return true;
    }else
        return false;
}
