#include "dictionary.h"
#include <algorithm>
#include <cstdlib>
#include <string.h>
#include <windows.h>

#include "utils\charFuncs.h"
#include "utils\inttostr.h"

#include <iterator>
Dictionary::Dictionary(){
    //��������� �������
    loadDicts();
}


Dictionary::~Dictionary(){
}


void Dictionary::loadDicts(){

    // ������ ������ ������ �������� ��� ������ �����
    std::vector< std::string > files;
    char buf[3];

    for(int i = 1; i < 34; ++i){
        std::string str="dict//";
        itoa( i, buf, 10 );
        str.append( buf );
        files.push_back( str );
    }

    // ��������� ���������� ������� �� ������ � dictionary
    std::vector< std::string >::iterator fileNameIter = files.begin();
    for(; fileNameIter != files.end(); ++fileNameIter){

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

void Dictionary::addNewWord(std::string playerWord){
    //���������� ����� � ������� ����������
    //����� �� � � �������� � ������� � � (��� ������������� � getFileName)

    const std::string fileName = getFileName(playerWord).c_str();

    std::ofstream f(fileName.c_str(), std::ios::app);
    f << ("\n"+playerWord).c_str();
    f.close();
}


bool Dictionary::isInDictionary(std::string playerWord){
    for( std::map<char, std::list<std::string> >::iterator it=dictionary.begin();it!=dictionary.end(); ++it){
        if(std::find((*it).second.begin(), (*it).second.end(), playerWord)!=(*it).second.end()){ //���� ����� ���� ������� � �������
            return true;
        }
    }
    return false;
}


std::string Dictionary::getFileName(std::string newWord){
    std::string fileName;
    switch (newWord[0]){
    case '�':
        fileName = "6"; // ����� �� � ��������� � ������� �
        break;
    case '�':
        fileName = "10"; // ����� �� � ��������� � ������� �
        break;
    default:
        std::string letters = "��������������������������������";
        fileName = inttostr( letters.find( newWord[0] ) + 1 );
    }
    fileName = ("dict//" + fileName);
    return fileName;
}



