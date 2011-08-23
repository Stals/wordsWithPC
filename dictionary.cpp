#include "dictionary.h"
#include <algorithm>
#include <cstdlib>
#include <string.h>
#include <windows.h>
#include "charFuncs.h"

#include <iterator>
Dictionary::Dictionary(){
    loadDicts();
}
Dictionary::~Dictionary(){
    //TODO добавление слов из newWords в словари компьютера
    //слово на ё й добавлем в словари е и  и при этом не меням букву
}

void Dictionary::loadDicts(){ //TODO составить список сопоставлений а -1 б -2 c с помощью map, чтобы потом можно было обратиться по мэпу и понять что для буквы 'в' нужно число 3

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
    for( std::vector< std::string >::iterator fileNameIter = files.begin(); fileNameIter != files.end(); ++fileNameIter){

        //хранит список слов начинающихся на одну букву
        std::list<std::string> singleDict;

        //читаем и копируем слова из файла
        std::ifstream file((*fileNameIter).c_str());
        std::istream_iterator<std::string> beg(file), end;
        std::copy(beg, end, std::back_inserter(singleDict));

        //Добавляем получившийся словарь на одну букву - в общий словарь
        std::list<std::string>::iterator firstWord = singleDict.begin();
        char firstLetter = (*firstWord)[0];
        dictionary.insert (std::pair<char,std::list<std::string> >(firstLetter,singleDict));
        singleDict.clear();
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


bool Dictionary::isInDictionary(std::string playerWord){
    for( std::map<char, std::list<std::string> >::iterator it=dictionary.begin();it!=dictionary.end(); ++it){
        if(std::find((*it).second.begin(), (*it).second.end(), playerWord)!=(*it).second.end()){ //Если слово было найдено в словаре
            return true;
        }
    }
    return false;
}

bool Dictionary::addNewWord(std::string playerWord){
    newWords.push_back(playerWord);
}


bool compareStr(const std::string &str1, const std::string &str2){
    if(strcmp(str1.c_str(), str2.c_str())){//Если первая строка больще чем вторая
        return true;
    }else
        return false;
}
