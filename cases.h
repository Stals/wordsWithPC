#ifndef CASES_H
#define CASES_H
#include <string>
namespace cases{
   inline char toLowerCase(char ch){//������ ������� ������� �� ��������, ��������� �� ������
        switch (ch){
        case '�':
        return '�';
        case '�':
        return '�';
        case '�':
        return '�';
        case '�':
        return '�';
        case '�':
        return '�';
        case '�':
        return '�';
        case '�':
        return '�';
        case '�':
        return '�';
        case '�':
        return '�';
        case '�':
        return '�';
        case '�':
        return '�';
        case '�':
        return '�';
        case '�':
        return '�';
        case '�':
        return '�';
        case '�':
        return '�';
        case '�':
        return '�';
        case '�':
        return '�';
        case '�':
        return '�';
        case '�':
        return '�';
        case '�':
        return '�';
        case '�':
        return '�';
        case '�':
        return '�';
        case '�':
        return '�';
        case '�':
        return '�';
        case '�':
        return '�';
        case '�':
        return '�';
        case '�':
        return '�';
        case '�':
        return '�';
        case '�':
        return 'a';
        case '�':
        return '�';
        case '�':
        return '�';
        case '�':
        return '�';
        case '�':
        return '�';

        }
    return ch;
    }
   inline std::string toLowerCase(std::string& word){
        for(size_t i=0;i<word.length();++i){
            word[i]=toLowerCase(word[i]); // �������� ������������� toLowerCase
        }
        return word;
    }
}

#endif // CASES_H
