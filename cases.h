#ifndef CASES_H
#define CASES_H
#include <string>
#include <locale>
namespace cases{

//�������� ��� ����� � ����� � ������� ��������
inline std::string toLowerCase(std::string& word){
    for(size_t i = 0; i < word.length(); ++i){
        //NOTE : ��� ������ � ����� qt 4.7 �������� � ������� �������� ���� ������� �����
        word[i] = tolower( word[i] );
    }
    return word;
}
}

#endif // CASES_H
