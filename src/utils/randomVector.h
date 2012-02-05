#ifndef RANDOM_VECTOR
#define RANDOM_VECTOR

#include <vector>
#include <time.h>

// ��� ������� Vector � �������� ���� ����������� ������� �������� �� ������� �� ����������� �����, �� � ������� �����������
template <class T>
class randomVector: public std::vector<T>{
public:
        void deleteByIndex(size_t index);
        size_t getRandomIndex();
        T getRandomElement();
        T getRandomAndDelete();
        bool remove(T element);
};

// ������� ������� ������� �� �������
template <class T>
void randomVector<T>::deleteByIndex(size_t index){
        if(this->size() > 0){
                if(index+1 <= this->size()){
                        if(index+1 == this->size()){
                                // ������ ��������� �� ��������� ������� - ������ ������ ���
                                this->pop_back();
                        }else{
                                // ���� ��� �� ��������� �������
                                // ������ ������� ��� ��� ����� ������� � ��������� �������
                                std::swap((*this)[index],(*this)[this->size()-1]);
                                this->pop_back();
                        }
                }else{
                        // ������ ������ ��� ������ �������
                        // exception
                }
        }
}

// ���������� ��������� ����� ����� 0 � vector.size() - 1
template <class T>
size_t randomVector<T>::getRandomIndex(){
        srand ( time(NULL) );
        size_t randomIndex = rand() % this->size();
        return randomIndex;
}

// ���������� �������� ������� �� �������
template <class T>
T randomVector<T>::getRandomElement(){
        return (*this)[getRandomIndex()];
}

// ���������� ��������� ������� � ������� ��� �� �������
template <class T>
T randomVector<T>::getRandomAndDelete(){
        size_t randomIndex = getRandomIndex();
        T randomElement = (*this)[randomIndex];
        this->deleteByIndex(randomIndex);
        return randomElement;
}

// ������� ������� �� �������
// ���������� true ���� ������� ��� � ������� ,� ����� false
// Note: ����� ������������ deleteById() , ��� ��� �� ������� �� O(1), � ���� ����� �� O(n)
template <class T>
bool randomVector<T>::remove(T element){
        if(this->size() > 0){
                //���� ���� - �������, ����� ������� false
                for (size_t i = 0; i < this->size(); ++i){
                        if ((*this)[i] == element){
                                this->deleteByIndex(i);
                                return true;
                        }
                }
        }
        return false;
}

#endif // RANDOM_VECTOR
