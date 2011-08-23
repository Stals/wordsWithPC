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
    //TODO ���������� ���� �� newWords � ������� ����������
}

void Dictionary::loadDicts(){ //TODO ��������� ������ ������������� � -1 � -2 c � ������� map, ����� ����� ����� ���� ���������� �� ���� � ������ ��� ��� ����� '�' ����� ����� 3

    // ������ ������ ������ �������� ��� ������ �����
    std::vector< std::string > files;
    char buf[3];

    for( int i=1; i<34; ++i ){
        std::string str="dict//";
        itoa( i, buf, 10 );
        str.append( buf );
        files.push_back( str );
    }

    // ��������� ���������� ������� �� ������ � dictionary
    for( std::vector< std::string >::iterator fileNameIter = files.begin(); fileNameIter != files.end(); ++fileNameIter){

        //������ ������ ���� ������������ �� ���� �����
        std::list<std::string> singleDict;

        //������ � �������� ����� �� �����
        std::ifstream file((*fileNameIter).c_str());
        std::istream_iterator<std::string> beg(file), end;
        std::copy(beg, end, std::back_inserter(singleDict));

        //��������� ������������ ������� �� ���� ����� - � ����� �������
        std::list<std::string>::iterator firstWord = singleDict.begin();
        char firstLetter = (*firstWord)[0];
        dictionary.insert (std::pair<char,std::list<std::string> >(firstLetter,singleDict));
        singleDict.clear();
    }
}


void Dictionary::addUsedWord(std::string word){
    //��������� Word � usedWords
    usedWords.push_back( word );
}

void Dictionary::removeWord(std::string word){
    dictionary[word[0]].remove( word );
}

std::string Dictionary::findRandomWord(char lastLetter){
    srand(time(NULL));

    //�->� �->� ��� ��� ��� ��������� ����� � �����
    charFuncs::changeChar( lastLetter );

    //����� ������������� �������� �� ������ ��� �������
    std::list<std::string>::iterator it = dictionary[lastLetter].begin();

    if( dictionary[lastLetter].size() != 0 ){
        unsigned int randomWordIndex = rand() % dictionary[lastLetter].size();
        //������� ��� ����� ���������
        for( unsigned int i = 0; i < randomWordIndex; ++i ){
            ++it;
        }
        //��������� ������ ��� ��������� ����� � ��������������
        addUsedWord(*it);
        //� ������ ��� �� ��������
        removeWord(*it);

        return (*it);

    }else{
        return "YOU WIN";
    }
}


bool Dictionary::isUsedWord(std::string playerWord){
    for(std::vector< std::string >::iterator it = usedWords.begin(); it != usedWords.end(); ++it){
        if((*it) == playerWord){//����� ��� ����
            return true;
        }
    }
    //���� �� ���� ������ �� �������� ������ ����� - ������ ��� ��� �� ��������������
    return false;
}

bool Dictionary::isNewWord(std::string playerWord){
    if(isInDictionary(playerWord)){
        return false;
    }else{
        return true;
    }

}


bool Dictionary::isInDictionary(std::string playerWord){ //TODO �������� ����� �� ���������� � �������
    //for( std::map<char, std::list<std::string> >::iterator it=dictionary.begin();it!=dictionary.end(); ++it){
    //    (*it).second.find(playerWord)
    //}
    return false;
}

bool Dictionary::addNewWord(std::string playerWord){
    newWords.push_back(playerWord);
}


bool compareStr(const std::string &str1, const std::string &str2){
    if(strcmp(str1.c_str(), str2.c_str())){//���� ������ ������ ������ ��� ������
        return true;
    }else
        return false;
}
