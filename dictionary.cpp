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
}

void Dictionary::loadDicts(){ //TODO составить список сопоставлений а -1 б -2 c с помощью map, чтобы потом можно было обратитьс€ по мэпу и пон€ть что дл€ буквы 'в' нужно число 3

    // —оздаЄм вектор файлов словарей дл€ каждой буквы
    std::vector< std::string > files;
    char buf[3];

    for( int i=1; i<34; ++i ){
        std::string str="dict//";
        itoa( i, buf, 10 );
        str.append( buf );
        files.push_back( str );
    }

    // ƒобавл€ем содержимое каждого из файлов в dictionary
    for( std::vector< std::string >::iterator fileNameIter = files.begin(); fileNameIter != files.end(); ++fileNameIter){

        //хранит список слов начинающихс€ на одну букву
        std::list<std::string> singleDict;

        //читаем и копируем слова из файла
        std::ifstream file((*fileNameIter).c_str());
        std::istream_iterator<std::string> beg(file), end;
        std::copy(beg, end, std::back_inserter(singleDict));

        //ƒобавл€ем получившийс€ словарь на одну букву - в общий словарь
        std::list<std::string>::iterator firstWord = singleDict.begin();
        char firstLetter = (*firstWord)[0];
        dictionary.insert (std::pair<char,std::list<std::string> >(firstLetter,singleDict));
        singleDict.clear();
    }
}


void Dictionary::addUsedWord(std::string word){
    //ƒобавл€ем Word в usedWords
    usedWords.push_back( word );
}

void Dictionary::removeWord(std::string word){
    dictionary[word[0]].remove( word );
}

std::string Dictionary::findRandomWord(char lastLetter){
    srand(time(NULL));

    //Є->е й->и так как они считаютс€ одним и темже
    charFuncs::changeChar( lastLetter );

    //сразу устанавливаем итератор на нужный нам словарь
    std::list<std::string>::iterator it = dictionary[lastLetter].begin();

    if( dictionary[lastLetter].size() != 0 ){
        unsigned int randomWordIndex = rand() % dictionary[lastLetter].size();
        //Ќаходим это слово перебором
        for( unsigned int i = 0; i < randomWordIndex; ++i ){
            ++it;
        }
        //ƒобавл€ем только что найденное слово в использованные
        addUsedWord(*it);
        //» уберем его из словарей
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

bool Dictionary::addNewWord(std::string playerWord){
    newWords.push_back(playerWord);
}


bool compareStr(const std::string &str1, const std::string &str2){
    if(strcmp(str1.c_str(), str2.c_str())){//≈сли перва€ строка больще чем втора€
        return true;
    }else
        return false;
}
