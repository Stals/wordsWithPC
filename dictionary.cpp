#include "dictionary.h"
#include <algorithm>
#include <cstdlib>
#include <string.h>
#include <windows.h>
Dictionary::Dictionary()
{
    loadDicts();
}
void Dictionary::loadDicts(){

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
        int num; //number of words
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
void Dictionary::usedWord(std::string Word,char lastLetter){

    //��������� � usedWords
    usedWords.push_back(Word);
    //������� �� dictionary ,���� ��� ��� ����
    dictionary[lastLetter].remove(Word);

}

std::string Dictionary::findRandomWord(char lastLetter){
    srand(time(NULL));
    //����� ������������� �������� �� ������ ��� �������
    std::list<std::string>::iterator it = dictionary[lastLetter].begin();

    if(dictionary[lastLetter].size()!=0){
        unsigned int randomWordIndex = rand()%dictionary[lastLetter].size();
        //������� ��� ����� ���������
        for(unsigned int i = 0; i < randomWordIndex; ++i){
            ++it;
        }
        //��������� ������ ��� ��������� ����� � ��������������
        usedWord((*it),lastLetter);

        return (*it);

    }else{
        return "YOU WIN";
    }

    return "YOU WIN";
}

bool Dictionary::checkUsed(std::string playerWord){
    for(std::vector<std::string>::iterator it=usedWords.begin();it!=usedWords.end();++it){

        if((*it)==playerWord){//����� ��� ����
            return false;
        }
    }
    //���� �� ���� ������ �� �������� ������ ����� - ������ ��� ��� �� ��������������
    return true;

}
bool compareStr(const std::string &str1,const std::string &str2){
    if(strcmp(str1.c_str(),str2.c_str())){//���� ������ ������ ������ ��� ������
        return true;
    }else
        return false;
}
