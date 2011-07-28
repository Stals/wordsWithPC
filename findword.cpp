#include "findword.h"
#include <algorithm>
#include <cstdlib>
#include <string.h>
#include <windows.h>
findWord::findWord()
{
    loadDicts();
}
void findWord::loadDicts(){

    //std::string filesArray[] =  { "dict//1","dict//2","dict//3","dict//4","dict//5","dict//6","dict//7","dict//8","dict//9","dict//10","dict//11","dict//12","dict//13","dict//14","dict//15","dict//16","dict//17","dict//18","dict//19","dict//20","dict//21","dict//22","dict//23","dict//24","dict//25","dict//26","dict//27","dict//28","dict//29","dict//30","dict//31","dict//32","dict//33" };
    //std::vector<std::string> files (filesArray, filesArray + sizeof(filesArray) / sizeof(std::string) );
    std::vector<std::string> files;
    char buf[3];
    for(int i=1 ; i<34 ; ++i){
        std::string str="dict//";
        itoa(i,buf,10);
        str.append(buf);
        files.push_back(str);
    }

    for( std::vector<std::string>::iterator it=files.begin();it!=files.end();++it){
        std::ifstream f((*it).c_str());
        int num;//number of words
        std::string letter;
        std::string newWord;
        f>>letter;
        f>>num;

        for(int i=0;i<num;++i){

            f>>newWord;
            singleDict.push_back(newWord);
        }
        f.close();
        dictionary.insert ( std::pair<char,std::list<std::string> >(letter[0],singleDict) );
        singleDict.clear();
    }


}
void findWord::usedWord(std::string Word,char lastLetter){

    //добавляем в usedWords
    usedWords.push_back(Word);
    //убираем из dictionary ,если там оно есть
    dictionary[lastLetter].remove(Word);

}

std::string findWord::findRandomWord(char lastLetter){
    srand(time(NULL));
    //сразу устанавливаем итератор на нужный нам словарь
    std::list<std::string>::iterator it = dictionary[lastLetter].begin();

    if(dictionary['а'].size()!=0){

        for(unsigned int i=0;i<rand()%dictionary[lastLetter].size();++i){
            ++it;
        }

        usedWord((*it),lastLetter);
        return (*it);

    }else{
        return "YOU WIN";
    }

    return "YOU WIN";
}

bool findWord::checkUsed(std::string playerWord){
    for(std::vector<std::string>::iterator it=usedWords.begin();it!=usedWords.end();++it){

        if((*it)==playerWord){//слово уже было
            return false;
        }

    }
    //если за весь список не встретил такого слово- говорим что оно еще не использовалось
    return true;

}
bool compareStr(const std::string &str1,const std::string &str2){
    if(strcmp(str1.c_str(),str2.c_str())){//Если первая строка больще чем вторая
        return true;
    }else
        return false;
}
