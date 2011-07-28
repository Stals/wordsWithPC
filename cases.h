#ifndef CASES_H
#define CASES_H
#include <string>
namespace cases{
// Меняет Русский большие на маленьки, остальные не меняет
inline char toLowerCase(char ch){
    switch (ch){
    case 'А':
        return 'а';
    case 'Б':
        return 'б';
    case 'В':
        return 'в';
    case 'Г':
        return 'г';
    case 'Д':
        return 'д';
    case 'Е':
        return 'е';
    case 'Ё':
        return 'ё';
    case 'Ж':
        return 'ж';
    case 'З':
        return 'з';
    case 'И':
        return 'и';
    case 'Й':
        return 'й';
    case 'К':
        return 'к';
    case 'Л':
        return 'л';
    case 'М':
        return 'м';
    case 'Н':
        return 'н';
    case 'О':
        return 'о';
    case 'П':
        return 'п';
    case 'Р':
        return 'р';
    case 'С':
        return 'с';
    case 'Т':
        return 'т';
    case 'У':
        return 'у';
    case 'Ф':
        return 'ф';
    case 'Х':
        return 'х';
    case 'Ц':
        return 'ц';
    case 'Ч':
        return 'ч';
    case 'Ш':
        return 'ш';
    case 'Щ':
        return 'щ';
    case 'Ь':
        return 'ь';
    case 'Ы':
        return 'a';
    case 'Ъ':
        return 'ъ';
    case 'Э':
        return 'э';
    case 'Ю':
        return 'ю';
    case 'Я':
        return 'я';

    }
    return ch;
}
//Приводит все русские буквы в слове к нижнему регистру
inline std::string toLowerCase(std::string& word){
    for(size_t i=0;i<word.length();++i){
        // вызывает перегруженный toLowerCase
        word[i]=toLowerCase(word[i]);
    }
    return word;
}
}

#endif // CASES_H
