#ifndef RANDOM_VECTOR
#define RANDOM_VECTOR

#include <vector>
#include <time.h>

// ����� ������� ����������� �������� �������� ��������� ������� �� O(1),
// �� ��� ���� �������� �����������
namespace randomVector{

    // ���������� ��������� ����� ����� 0 � vector.size() - 1
    template <class T>
    size_t getRandomIndex(std::vector<T>&v){
        srand ( time(NULL) );
        size_t randomIndex = rand() % v.size();
        return randomIndex;
    }

    // ������� ������� ������� �� �������
    template <class T>
    void removeByIndex(std::vector<T>&v, size_t index){
        if(!v.empty()){
            if(index <= v.size()-1){
                if(index != v.size()-1){
                    // ���� ��� �� ��������� �������
                    // ������ ������� ��� ��� ����� ������� � ��������� �������
                    std::swap(v[index], v[v.size()-1]);
                    v.pop_back();
                }else{
                    // ������ ��������� �� ��������� ������� - ������ ������ ���
                    v.pop_back();
                }
        }else{
                // ������ ������ ��� ������ �������
                //throw std::out_of_range("index out of range");
            }
        }
    }

    // ���������� ��������� ������� � ������� ��� �� �������
    template <class T>
    T getRandomAndRemove(std::vector<T>&v)
    {
        size_t randomIndex = getRandomIndex(v);
        T randomElement = v[randomIndex];
        removeByIndex(v, randomIndex);
        return randomElement;
    }

    // ������� ������� �� �������
    // ���������� true ���� ������� ��� � ������� ,� ����� false
    // Note: ����� ������������ removeById() , ��� ��� �� ������� �� O(1), � ���� ����� �� O(n), ���� � 2 ���� ������� ��� ������� ��������
    // ������������ ����� remove<std::string>(vec, "element") , ����� ������� ������ ������ ���� "element", ���� ��� �� ����������
    template <typename T>
    bool remove(std::vector<T>&v, T element){
        if(!v.empty()){
            for (size_t i = 0; i < v.size(); ++i){
                if (v[i] == element){
                    removeByIndex(v, i);
                    return true;
                }
            }
        }
        return false;
    }

}
#endif // RANDOM_VECTOR
