#include "check.h"
#include <string.h> //strcmp

check::check(){
    statusNum=OK;
}
bool check::playerWord(const std::string& playerWord,const std::string& pcWord,findWord& fw){
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
    else if(lastLetters(playerWord))
        return false;
    else if(rusLetter(playerLastLetter))
        return false;
    else if(usedWord(playerWord,fw))
        return false;
    else if(pcWord!=""){//��� ������ ���� ����� �������
           //�������� ��������� �� ������ ����� ����� ������ � ��������� � ����� ����������
          if(firstLast(playerFirstLetter,pcLastLetter))
              return false;
    }

     //playerWord ������������� ���� ��������

     statusNum=OK;
     return true;

}

std::string check::stringStatus(){
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
    }
    return "������";
}
bool check::checkLength(std::string playerWord){
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
bool check::rusLetter(char letter){
    if(!charFuncs::rusLetter(letter)){
        statusNum=NotRusWord;
        return true;
    }else
        return false;

}
bool check::usedWord(std::string playerWord,findWord& fw){
 if(!fw.checkUsed(playerWord)){
     statusNum=UsedWord;
     return true;
 }else
     return false;
}
bool check::firstLast(char playerFirstLetter,char pcLastLetter){
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

bool check::lastLetters(std::string playerWord){
const int len=playerWord.length();
    if(strchr("��� ", playerWord[len-1])&&strchr("��� ", playerWord[len-2])){
        statusNum=WrongEnd;
        return true;
    }else{
        statusNum=OK;
        return false;
    }
}
