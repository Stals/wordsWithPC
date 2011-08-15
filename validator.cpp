#include "validator.h"
#include <string.h> //strcmp

Validator::Validator(){
    currentStatus = OK;
}
bool Validator::isWordValid( const std::string &playerWord,
                             const char &pcLastLetter, Dictionary &dictionary ){

    //������� ����������� ��� �������
    playerFirstLetter = playerWord[0];
    playerLastLetter = charFuncs::getLastLetter( playerWord );

    //�->� �->� ��� ��� ��� ��������� ����� � �����
    //TODO ����������� ������ � mainwindow , ��� ��� �� ������� ��� ����� ������� ��������� ���-�� �������� ������ ������
    charFuncs::changeChar( playerFirstLetter );
    charFuncs::changeChar( playerLastLetter );

    //������ �� ������� ���������� true ,���� ������� ������������� + ������ currentStatus
    // ���� ���� ���� �� ������� ������ true - ������ � ����� �� ������ ��������
    if( hasWrongLength( playerWord )||
        hasWrongLastLetters( playerWord )||
        hasSpaces( playerWord )||
        isNotRusWord( playerLastLetter )||
        isUsedWord( playerWord, dictionary )||
        hasWrongFirstLast( playerFirstLetter, pcLastLetter )
        ){
            return false;
    }else{
        //����� ����� ������������� ���� �c������
        currentStatus = OK;
        return true;
    }
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
    default:
        return "������";
    }
}
bool Validator::hasWrongLength(std::string playerWord){
    if(playerWord == ""){
        currentStatus=NoWord;
        return true;
    }
    if(playerWord.size() < 2){
        currentStatus=TooShortWord;
        return true;
    }else
        return false;

}
bool Validator::isNotRusWord(char letter){
    if(!charFuncs::rusLetter( letter )){
        currentStatus=NotRusWord;
        return true;
    }else
        return false;

}
bool Validator::isUsedWord(std::string playerWord, Dictionary &dictionary){
    if(!dictionary.checkUsed( playerWord )){
        currentStatus=UsedWord;
        return true;
    }else
        return false;
}
bool Validator::hasWrongFirstLast(char playerFirstLetter, char pcLastLetter){
    if( playerFirstLetter == pcLastLetter){
        currentStatus=OK;
        return false;

    //NOTE: ��� ��� � ����� ������ ��� ������������� � � � , � � � , � � ������ ���������� ���, ����� ��� ��������
    }else if(( playerFirstLetter == '�' && pcLastLetter == '�' )||
             ( playerFirstLetter == '�' && pcLastLetter == '�' )){
        currentStatus=OK;
        return false;
    }else if( pcLastLetter == ' ' ){//���� ��� ������ ���
        currentStatus=OK;
        return false;
    }else{
        currentStatus=WrongFirstLetter;
        return true;

    }

}

bool Validator::hasWrongLastLetters(std::string playerWord){
    const int len=playerWord.length();
    if(strchr("���", playerWord[ len-1 ]) && strchr("���", playerWord[ len-2 ])){
        currentStatus=WrongEnd;
        return true;
    }else{
        currentStatus=OK;
        return false;
    }
}

bool Validator::hasSpaces(std::string playerWord){

    for(unsigned int i = 0; i < playerWord.length(); ++i){
        if(playerWord[i] == ' '){//���� � ������ ���� ������� - ��� ��������� ����
            currentStatus=SpaceInWord;
            return true;
        }
    }
    //���� �������� � ����� ������ �������
    return false;


}
