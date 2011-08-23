#include "validator.h"
#include <string.h> //strcmp

Validator::Validator(){
    currentStatus = Status::OK;
}


bool Validator::isWordValid( const std::string &playerWord,
                             const char &pcLastLetter, Dictionary &dictionary ){

    //TODO �������� �������� ������� ������� ����� ������������ ������ playerWord � ����� � ���� ������� ���� �����, ��� ������ � ��������� ������
    //������� ����������� ��� �������
    playerFirstLetter = playerWord[0];

    //������ �� ������� ���������� true ,���� ������� ������������� + ������ currentStatus
    // ���� ���� ���� �� ������� ����� true - ������ � ����� �� ������ ��������
    if( hasWrongFirstLast( playerFirstLetter, pcLastLetter )||
        hasWrongLength( playerWord )||
        hasWrongLastLetters( playerWord )||
        hasSpaces( playerWord )||
        isNotRusWord( playerWord )||
        isUsedWord( playerWord, dictionary )
        ){
            return false;
    }else{
        //����� ����� ������������� ���� �c������
        currentStatus = Status::OK;
        return true;
    }
}


std::string Validator::getStatus(){
    switch (currentStatus){
    case Status::OK:
        return "���������� ����";
        break;
    case Status::WrongFirstLetter:
        return "������������ ������ ������";
        break;
    case Status::UsedWord:
        return "��� ����� ��� ��������������";
        break;
    case Status::NotRusWord:
        return "�� ������� �����";
        break;
    case Status::TooShortWord:
        return "������� �������� �����";
        break;
    case Status::NoWord:
        return "������� ������� ���-������";
        break;
    case Status::WrongEnd:
        return "������������ ���������";
        break;
    case Status::SpaceInWord:
        return "� ����� �� ������ ���� ��������";
        break;
    case Status::NotNewWord:
        return "������� ������ �����";
    default:
        return "������";
    }
}


bool Validator::hasWrongLength(std::string playerWord){
    if(playerWord.length() == 0){
        currentStatus = Status::NoWord;
        return true;
    }
    if(playerWord.length() < 2){
        currentStatus = Status::TooShortWord;
        return true;
    }else{
        return false;
    }

}


bool Validator::isNotRusWord(std::string playerWord){
    for(unsigned int i = 0; i<playerWord.length()-1; ++i){
        if(!charFuncs::isRusLetter( playerWord[i] )){
            currentStatus = Status::NotRusWord;
            return true;
        }
    }
    //���� ��� ����� � ����� ���� ������� �� ����� false
    return false;

}


bool Validator::isUsedWord(std::string playerWord, Dictionary &dictionary){
    if(dictionary.isUsedWord( playerWord )){
        currentStatus = Status::UsedWord;
        return true;
    }else{
        return false;
    }
}


bool Validator::hasWrongFirstLast(char playerFirstLetter, char pcLastLetter){
    if( playerFirstLetter == pcLastLetter){
        return false;

    //NOTE: ��� ��� ��� ������� ����������� ������ ��������� ���� ����� ���������� ��������� �� '�' ,
    // � ����� ������ ����� ���������� �� '�' � ��������
    }else if(( playerFirstLetter == '�' && pcLastLetter == '�' )||
             ( playerFirstLetter == '�' && pcLastLetter == '�' )||
             ( playerFirstLetter == '�' && pcLastLetter == '�' )||
             ( playerFirstLetter == '�' && pcLastLetter == '�' )){
        return false;

    //���� ��� ������ ���
    }else if( pcLastLetter == ' ' ){
        return false;
    }else{
        currentStatus = Status::WrongFirstLetter;
        return true;
    }

}


bool Validator::hasWrongLastLetters(std::string playerWord){
    const int len=playerWord.length();
    if(strchr("���", playerWord[ len-1 ]) && strchr("���", playerWord[ len-2 ])){
        currentStatus = Status::WrongEnd;
        return true;
    }else{
        return false;
    }
}


bool Validator::hasSpaces(std::string playerWord){

    for(unsigned int i = 0; i < playerWord.length(); ++i){
        if(playerWord[i] == ' '){//���� � ������ ���� ������� - ��� ��������� ����
            currentStatus = Status::SpaceInWord;
            return true;
        }
    }
    //���� �������� � ����� ������ �������
    return false;
}

void Validator::notNewWord(){
    currentStatus = Status::NotNewWord;
}
