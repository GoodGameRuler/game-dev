#ifndef ARRAY_LIST
#define ARRAY_LIST

#include <iostream>

template<class T>
class ArrayList {
    public:
        ArrayList(int size = 10)
            : _size{0}, _max_size{size}
        {
            _list = (T*) calloc(_max_size, sizeof(T));
        };

        ~ArrayList() {};

        void push(T element) {
            _size += 1;
            if(_size >= _max_size) {
                _max_size *= 2;
                _list = (T*) realloc(_list, _max_size * sizeof(T));
            }

            if(_list == nullptr) {
                std::cout << "ArrayList Error: ArrayList couldn't be realloced\n";
            }


            for(int i = _size; i < _max_size; i++) {
                _list[i] = 0;
            }

            _list[_size - 1] = element;
        }

        void push_front(T);
        T pop() {
            if(!_size) {
                return nullptr;
            }

            T return_item = _list[_size - 1];
            _list[_size - 1] = nullptr;
            return return_item;
        }

        T pop(T element){
            T pop = nullptr;
            int pop_index = -1;
            for(int i = 0; i < _size && pop == nullptr; i++) {
                if(_list[i] == element) {
                    pop = nullptr;
                    pop_index = i;
                    _list[i] = nullptr;
                }
            }

            if(pop == nullptr) {
                return nullptr;
            }

            for(int i = pop_index; i < _size; i++) {
                if(i == _max_size) {
                    _list[i] = nullptr;
                } else {
                    _list[i] = _list[i + 1];
                }
            }

            return pop;
        } 

        T pop_front();
        T pop_front(T);
        int size() const {return _size;};
        void print() {
            for(int i = 0; i < _max_size; i++) {
                if(i != _size) {
                    std::cout << _list[i] << ", ";
                }
            }
            std::cout << _list[_size] << "\n";
        }

        T& operator [](int index) {
            return _list[index];
        }

        T operator [](int index) const {
            return _list[index];
        }

    private:
        T* _list;
        int _size;
        int _max_size;
};

#endif // !ARRAY_LIST
