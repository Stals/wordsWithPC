#ifndef RANDOM_VECTOR
#define RANDOM_VECTOR

#include <vector>
#include <time.h>

// Набор функций позволяющих ускорить удаление элементов вектора до O(1),
// но при этом теряется очередность
namespace randomVector{

    // Возвращает Случайное число между 0 и vector.size() - 1
    template <class T>
    size_t getRandomIndex(std::vector<T>&v){
        srand ( time(NULL) );
        size_t randomIndex = rand() % v.size();
        return randomIndex;
    }

    // Удаляет элемент вектора по индексу
    template <class T>
    void removeByIndex(std::vector<T>&v, size_t index){
        if(!v.empty()){
            if(index <= v.size()-1){
                if(index != v.size()-1){
                    // Если это не последний элемент
                    // Меняем местами тот что нужно удалить и последний элемент
                    std::swap(v[index], v[v.size()-1]);
                    v.pop_back();
                }else{
                    // Индекс указывает на последний элемент - просто удалим его
                    v.pop_back();
                }
        }else{
                // Индекс больше чем размер вектора
                //throw std::out_of_range("index out of range");
            }
        }
    }

    // Возвращает случайный элемент и удаляет его из вектора
    template <class T>
    T getRandomAndRemove(std::vector<T>&v)
    {
        size_t randomIndex = getRandomIndex(v);
        T randomElement = v[randomIndex];
        removeByIndex(v, randomIndex);
        return randomElement;
    }

    // Удаляет Элемент из Вектора
    // Возвращает true если элемент был в векторе ,а иначе false
    // Note: Лучше использовать removeById() , так как он удаляет за O(1), а этот метод за O(n), хоть и 2 раза быстрее чем обычное удаление
    // Использовать нужно remove<std::string>(vec, "element") , чтобы указать какого именни типа "element", если это не переменная
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
