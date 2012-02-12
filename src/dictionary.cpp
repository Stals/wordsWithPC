#include "dictionary.h"
#include <algorithm>
#include <cstdlib>
#include <string.h>
#include <windows.h>
#include <iterator>

#include "utils\charFuncs.h"
#include "utils\inttostr.h"


Dictionary::Dictionary(){
    //Загружаем словарь
    loadDicts();
}


Dictionary::~Dictionary(){
}


void Dictionary::loadDicts(){

    // Создаём вектор файлов словарей для каждой буквы
    std::vector< std::string > files;
    char buf[3];

    for(int i = 1; i < 34; ++i){
        std::string str="dict//";
        itoa( i, buf, 10 );
        str.append( buf );
        files.push_back( str );
    }

    // Добавляем содержимое каждого из файлов в dictionary
    std::vector< std::string >::iterator fileNameIter = files.begin();
    for(; fileNameIter != files.end(); ++fileNameIter){

        //хранит список слов начинающихся на одну букву
        std::vector<std::string> singleDict;

        //читаем и копируем слова из файла
        std::ifstream file((*fileNameIter).c_str());
        std::istream_iterator<std::string> beg(file), end;
        std::copy(beg, end, std::back_inserter(singleDict));

        //Добавляем получившийся словарь на одну букву - в общий словарь
        std::vector<std::string>::iterator firstWord = singleDict.begin();
        char firstLetter = (*firstWord)[0];
        dictionary.insert (std::pair<char,std::vector<std::string> >(firstLetter,singleDict));
        singleDict.clear();
    }
}


void Dictionary::addUsedWord(std::string word){
    //Добавляем Word в usedWords
    usedWords.push_back( word );
}


void Dictionary::removeWord(std::string word){
    randomVector::remove(dictionary[word[0]], word);
}


std::string Dictionary::getRandomWord(char lastLetter){

    //ё->е й->и так как они считаются одним и темже
    charFuncs::changeChar( lastLetter );

    if( dictionary[lastLetter].size() != 0 ){
        // Получим случайное слово из словаря и удалим его оттуда
        std::string randomWord = randomVector::getRandomAndRemove(dictionary[lastLetter]);

        //Добавляем только что найденное слово в использованные
        addUsedWord(randomWord);

        return randomWord;
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

void Dictionary::addNewWord(std::string playerWord){
    //добавление слова в словари компьютера
    //слово на ё й добавлем в словари е и (это предусмотрено в getFileName)

    const std::string fileName = getFileName(playerWord).c_str();

    std::ofstream f(fileName.c_str(), std::ios::app);
    f << ("\n"+playerWord).c_str();
    f.close();
}


bool Dictionary::isInDictionary(std::string playerWord){
    std::map<char, std::vector<std::string> >::iterator it = dictionary.begin();

    for(; it != dictionary.end(); ++it){
        bool wordFound = std::find(it->second.begin(), it->second.end(), playerWord) != it->second.end();
        if(wordFound){
            return true;
        }
    }
    return false;
}


std::string Dictionary::getFileName(std::string newWord){
    std::string fileName;
    switch (newWord[0]){
    case 'ё':
        fileName = "6"; // Слова на ё сохраняем в словарь е
        break;
    case 'й':
        fileName = "10"; // Слова на й сохраняем в словарь и
        break;
    default:
        std::string letters = "абвгдеёжзийклмнопрстуфхцчшщьыъэюя";
        fileName = inttostr( letters.find( newWord[0] ) + 1 );
    }
    fileName = ("dict//" + fileName);
    return fileName;
}



