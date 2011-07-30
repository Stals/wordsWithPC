#include "check.h"
#include <string.h> //strcmp

Validator::Validator(){
    statusNum=OK;
}
bool Validator::checkPlayerWord(const std::string& playerWord,const std::string& pcWord,Dictionary& dictionary){
    //������� ����������� ��� �������
    playerFirstLetter=playerWord[0];
    playerLastLetter=charFuncs::getLastLetter(playerWord);
    pcLastLetter=charFuncs::getLastLetter(pcWord);

    //�->� �->� ��� ��� ��� ��������� ����� � �����
    charFuncs::changeChar(playerFirstLetter);
    charFuncs::changeChar(playerLastLetter);

    // playerWord[0]=playerFirstLetter;//����� ����� � ������� � ��������� ���� ���� ���������

    //������� ������ ������ statusNum,���� ��������� ������
    if(checkLength(playerWord))//���� ������ � ������
        return false;
    else if(checkLastLetters(playerWord))
        return false;
    else if(checkSingleWord(playerWord))
        return false;
    else if(checkRusLetter(playerLastLetter))
        return false;
    else if(checkUsedWord(playerWord,dictionary))
        return false;
    else if(pcWord!=""){//��� ������ ���� ����� �������
        //�������� ��������� �� ������ ����� ����� ������ � ��������� � ����� ����������
        if(checkFirstLast(playerFirstLetter,pcLastLetter))
            return false;
    }

    //playerWord ������������� ���� ��������

    statusNum=OK;
    return true;

}

std::string Validator::stringStatus(){
    switch (statusNum){
    case OK:
        return "���������� ����";
        break;
    case WrongFirstLetter:
        return "������������ ������ ������";
        break;
    case UsedWord:
        return "��� ����� ��� ��������������";
        break;
    case NotRusWord:
        return "�� ������� �����";
        break;
    case TooShortWord:
        return "������� �������� �����";
        break;
    case NoWord:
        return "������� ������� ���-������";
        break;
    case WrongEnd:
        return "������������ ���������";
        break;
    case NotSingleWord:
        return "������� ������ ���� �����";
        break;
    }
    return "������";
}
bool Validator::checkLength(std::string playerWord){
    if(playerWord==""){
        statusNum=NoWord;
        return true;
    }
    if(playerWord.size()<2){
        statusNum=TooShortWord;
        return true;
    }else
        return false;

}
bool Validator::checkRusLetter(char letter){
    if(!charFuncs::rusLetter(letter)){
        statusNum=NotRusWord;
        return true;
    }else
        return false;

}
bool Validator::checkUsedWord(std::string playerWord,Dictionary& dictionary){
    if(!dictionary.checkUsed(playerWord)){
        statusNum=UsedWord;
        return true;
    }else
        return false;
}
bool Validator::checkFirstLast(char playerFirstLetter,char pcLastLetter){
    if( playerFirstLetter==pcLastLetter){
        statusNum=OK;
        return false;
    }else if( (playerFirstLetter=='�'&&pcLastLetter=='�')){
        statusNum=OK;
        return false;

    }else if(( playerFirstLetter=='�'&&pcLastLetter=='�')){
        statusNum=OK;
        return false;
    }else{
        statusNum=WrongFirstLetter;
        return true;

    }

}

bool Validator::checkLastLetters(std::string playerWord){
    const int len=playerWord.length();
    if(strchr("���", playerWord[len-1])&&strchr("���", playerWord[len-2])){
        statusNum=WrongEnd;
        return true;
    }else{
        statusNum=OK;
        return false;
    }
}

bool Validator::checkSingleWord(std::string playerWord){

    for(int i = 0; i<playerWord.length();++i){
        if(playerWord[i]==' '){//���� � ������ ���� ������� - ��� ��������� ����
            statusNum=NotSingleWord;
            return true;
        }
    }
    return false; //���� �������� � ����� ������ �������


}
