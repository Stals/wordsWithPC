#ifndef RANDOM_VECTOR
#define RANDOM_VECTOR

#include <vector>
#include <time.h>

// Это обычный Vector у которого есть возможность удалять элементи по индексу за константное время, но с потерей очередности
template <class T>
class randomVector: public std::vector<T>{
public:
        void deleteByIndex(size_t index);
        size_t getRandomIndex();
        T getRandomElement();
        T getRandomAndDelete();
        bool remove(T element);
};

// Удаляет элемент вектора по индексу
template <class T>
void randomVector<T>::deleteByIndex(size_t index){
        if(this->size() > 0){
                if(index+1 <= this->size()){
                        if(index+1 == this->size()){
                                // Индекс указывает на последний элемент - просто удалим его
                                this->pop_back();
                        }else{
                                // Если это не последний элемент
                                // Меняем местами тот что нужно удалить и последний элемент
                                std::swap((*this)[index],(*this)[this->size()-1]);
                                this->pop_back();
                        }
                }else{
                        // Индекс больше чем размер вектора
                        // exception
                }
        }
}

// Возвращает Случайное число между 0 и vector.size() - 1
template <class T>
size_t randomVector<T>::getRandomIndex(){
        srand ( time(NULL) );
        size_t randomIndex = rand() % this->size();
        return randomIndex;
}

// Возвращает случайны элемент из вектора
template <class T>
T randomVector<T>::getRandomElement(){
        return (*this)[getRandomIndex()];
}

// Возвращает случайный элемент и удаляет его из вектора
template <class T>
T randomVector<T>::getRandomAndDelete(){
        size_t randomIndex = getRandomIndex();
        T randomElement = (*this)[randomIndex];
        this->deleteByIndex(randomIndex);
        return randomElement;
}

// Удаляет Элемент из Вектора
// Возвращает true если элемент был в векторе ,а иначе false
// Note: Лучше использовать deleteById() , так как он удаляет за O(1), а этот метод за O(n)
template <class T>
bool randomVector<T>::remove(T element){
        if(this->size() > 0){
                //Если есть - удалить, иначе вернуть false
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
