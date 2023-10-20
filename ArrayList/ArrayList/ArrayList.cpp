#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

template <typename T>
class ArrayList
{
private:
    int size;
    int capacity;
    double* data;

    bool CheckIndex(int _index); //проверка на корректность позиции (индекса) в списке

public:
    
    ArrayList()
    {
        size = 0;
        capacity = 0;
        data = nullptr;
    }

    ArrayList(int size); //конструктор класса

    ~ArrayList(); //деструктор класса

    int Get(int _index); //возвращает элемент массива по определенному индексу
    
    int Size(); //возвращает размер массива

    void Resize(int new_size); //изменение размера массива

    void AddEnd(T _data); //добавление в конец массива

    void AddBegin(T _data, int _index);

    void Add(T _data, int _index); //добавление элемента в массив

    void Set(T _data, int _index); //изменение элемента по индексу

    void Clear(); //очистка списка

    void Remove(int _index); //удаление элемента из массива

    void Print();

};

template <typename T>
ArrayList<T>::ArrayList(int size)
{
    size = size;
    capacity = size;
    if (size != 0)
        data = new T[size];
    else
        data = 0;
}

template <typename T>
ArrayList<T>::~ArrayList()
{
    if (size > 0)
        delete[] data;
}

template <typename T>
int ArrayList<T>::Get(int _index) {
    if (CheckIndex(_index)) {
        cout << "Некорректный индекс" << endl;
        return -1;
    }
    cout << data[_index] << "\n\n";
    return data[_index];
}

template <typename T>
int ArrayList<T>::Size() {
    return size;
}

template <typename T>
bool ArrayList<T>::CheckIndex(int _index) {
    return ((_index < 0) || (_index > size));
}

template <typename T>
void ArrayList<T>::Resize(int new_size) {
    if (new_size > capacity)
    {
        int new_capacity = max(new_size, size * 2);
        T* new_data = new T[new_capacity];
        for (int i = 0; i < size; ++i)
            new_data[i] = data[i];
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }
    size = new_size;
}

template <typename T>
void ArrayList<T>::Clear() {
    size = 0;
    int new_size = 2;
    T* data = new T[new_size];

    delete[] data;
}

template <typename T>
void ArrayList<T>::AddBegin(T _data, int _index) {
    for (int i = size - 1; i >= 0; i--) {
        if (i >= _index) {
            data[i + 1] = data[i];
        }
    }
    data[_index] = _data;
    size++;
}

template <typename T>
void ArrayList<T>::AddEnd(T _data) {
    Resize(size + 1);
    data[size - 1] = _data;
}

template <typename T>
void ArrayList<T>::Add(T _data, int _index) {
    if (CheckIndex(_index)) {
        cout << "Некорректный индекс" << endl;
        return;
    }

    for (int i = size - 1; i >= 0; i--) {
        if (i >= _index) {
            data[i + 1] = data[i];
        }
    }
    data[_index] = _data;
    size++;
    
    
}

template <typename T>
void ArrayList<T>::Set(T _data, int _index) {
    data[_index] = _data;
}

template <typename T>
void ArrayList<T>::Remove(int _index) {
    if (CheckIndex(_index)) {
        cout << "Некорректный индекс" << endl;
        return;
    }

    for (int i = _index + 1; i < size; i++) {
        data[i - 1] = data[i];
    }

    data[size--] = 0;
}

template <typename T>
void ArrayList<T>::Print() {
    cout << "Массив List: ";

    if (size == 0) {
        cout << "пустой((" << endl;
        return;
    }

    for (int i = 0; i < size; i++)
        cout << data[i] << " ";

    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    ArrayList<double> List;

    double el;
    int index;
    while (true) {
        system("cls");

        cout << "Выберите действие, которое хотите совершить с массивом\n\n";
        SetConsoleTextAttribute(hConsole, 11);
        cout << "<1> - Найти элемент по индексу\n\n";
        cout << "<2> - Добавить элемент в начало массива (или создать массив, если в нем еще нет элементов)\n\n";
        cout << "<3> - Добавить элемент в конец массива\n\n";
        cout << "<4> - Добавить элемент в заданную позицию массива\n\n";
        cout << "<5> - Изменить элемент в массиве по определенному индексу\n\n";
        cout << "<6> - Удалить элемент с заданной позиции\n\n";
        cout << "<7> - Вывести размер массива (кол-во элементов в нем)\n\n";
        cout << "<8> - Очистить массив\n\n";
        cout << "<9> - Вывод массива\n\n";
        SetConsoleTextAttribute(hConsole, 12);
        cout << "<0> - Выход из программы\n\n";
        SetConsoleTextAttribute(hConsole, 15);

        switch (_getch()) {
        case '0':
            return 0;

        case '1':
            cout << "Введите индекс того элемента, который хотите получить: ";
            cin >> index;
            List.Get(index);
            cout << "\n\n";
            system("pause");
            break;

        case '2':
            cout << "Введите тот элемент, который хотите добавить: ";
            cin >> el;
            index = 0;
            if (List.Size() == 0)
                List.AddEnd(el);
            else
                List.AddBegin(el, index);
            cout << "\n\n";
            system("pause");
            break;

        case '3':
            cout << "Введите тот элемент, который хотите добавить: ";
            cin >> el;
            index = List.Size();
            List.Add(el, index);
            cout << "\n\n";
            system("pause");
            break;

        case '4':
            cout << "Введите тот элемент, который хотите добавить: ";
            cin >> el;
            cout << "\n";
            cout << "Введите индекс для элемента (в это место будет добавлен ваш элемент): ";
            cin >> index;
            List.Add(el, index);
            cout << "\n\n";
            system("pause");
            break;

        case '5':
            cout << "Введите тот элемент, который хотите добавить: ";
            cin >> el;
            cout << "\n";
            cout << "Введите индекс для элемента (в этом месте будет изменен ваш элемент): ";
            cin >> index;
            List.Set(el, index);
            cout << "\n\n";
            system("pause");
            break;

        case '6':
            cout << "Введите индекс того элемента, который хотите удалить: ";
            cin >> index;
            List.Remove(index);
            cout << "\n\n";
            system("pause");
            break;

        case '7':
            cout << "Размер массива равен " << List.Size() << "\n";
            cout << "\n\n";
            system("pause");
            break;

        case '8':
            List.Clear();
            cout << "\n\n";
            system("pause");
            break;

        case '9':
            List.Print();
            cout << "\n\n";
            system("pause");
            break;

        default:
            continue;
            break;
        }
    }






}

