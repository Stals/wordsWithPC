#include "validator.h"
#include <string.h> //strcmp

Validator::Validator(){
    currentStatus=OK;
}
status Validator::checkPlayerWord(const std::string& playerWord,const std::string& pcWord,Dictionary& dictionary){
    //������� ����������� ��� �������
    playerFirstLetter=playerWord[0];
    playerLastLetter=charFuncs::getLastLetter(playerWord);
    pcLastLetter=charFuncs::getLastLetter(pcWord);

    //�->� �->� ��� ��� ��� ��������� ����� � �����
    //TODO ����������� ������ � mainwindow , ��� ��� �� ������� ��� ����� ������� ��������� ���-�� �������� ������ ������
    charFuncs::changeChar(playerFirstLetter);
    charFuncs::changeChar(playerLastLetter);

    //������� ������ ������ statusNum,���� ��������� ������
    if(checkLength(playerWord))
        return currentStatus;

    else if(checkLastLetters(playerWord))
        return currentStatus;

    else if(checkSpaces(playerWord))
        return currentStatus;

    else if(checkRusLetter(playerLastLetter))
        return currentStatus;

    else if(checkUsedWord(playerWord,dictionary))
        return currentStatus;

    else if(pcWord!=""){//��� ������ ���� ����� �������
        if(checkFirstLast(playerFirstLetter,pcLastLetter))
            return currentStatus;
    }else{
        //playerWord ������������� ���� ��������
        currentStatus=OK;
    }
    return currentStatus;

}

std::string Validator::getStatus(){
    switch (currentStatus){
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
    case SpaceInWord:
        return "� ����� �� ������ ���� ��������";
        break;
    }
    return "������";
}
bool Validator::checkLength(std::string playerWord){
    if(playerWord==""){
        currentStatus=NoWord;
        return true;
    }
    if(playerWord.size()<2){
        currentStatus=TooShortWord;
        return true;
    }else
        return false;

}
bool Validator::checkRusLetter(char letter){
    if(!charFuncs::rusLetter(letter)){
        currentStatus=NotRusWord;
        return true;
    }else
        return false;

}
bool Validator::checkUsedWord(std::string playerWord,Dictionary& dictionary){
    if(!dictionary.checkUsed(playerWord)){
        currentStatus=UsedWord;
        return true;
    }else
        return false;
}
bool Validator::checkFirstLast(char playerFirstLetter,char pcLastLetter){
    if( playerFirstLetter==pcLastLetter){
        currentStatus=OK;
        return false;

        //NOTE: ��� ��� � ����� ������ ��� ������������� � � � , � � � , � � ������ ���������� ���, ����� ��� ��������
    }else if( (playerFirstLetter=='�'&&pcLastLetter=='�')){
        currentStatus=OK;
        return false;

    }else if(( playerFirstLetter=='�'&&pcLastLetter=='�')){
        currentStatus=OK;
        return false;
    }else{
        currentStatus=WrongFirstLetter;
        return true;

    }

}

bool Validator::checkLastLetters(std::string playerWord){
    const int len=playerWord.length();
    if(strchr("���", playerWord[len-1])&&strchr("���", playerWord[len-2])){
        currentStatus=WrongEnd;
        return true;
    }else{
        currentStatus=OK;
        return false;
    }
}

bool Validator::checkSpaces(std::string playerWord){

    for(unsigned int i = 0; i<playerWord.length();++i){
        if(playerWord[i]==' '){//���� � ������ ���� ������� - ��� ��������� ����
            currentStatus=SpaceInWord;
            return true;
        }
    }
    //���� �������� � ����� ������ �������
    return false;


}
