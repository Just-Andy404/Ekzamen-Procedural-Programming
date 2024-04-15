#pragma once
#include <iostream>
#include <cstring> // for strcpy
using namespace std;



struct Date {
    int year;
    int month;
    int day;
};

struct Product {
    char title[255];
    char maker[255];
    double price;
    char product_class[255];
    Date arrival_date_in_stock; // Дата поступления на склад
    Date shelf_life; // Срок годности
};


// Добавление товара на склад.
Product input() {
    Product aProduct; // Создание нового объекта структуры Product
    int day, month, year;
    cin.ignore();
    cout << "Введите название: ";
    cin.getline(aProduct.title, 255);
    cout << "Введите производителя: ";
    cin.getline(aProduct.maker, 255);
    cout << "Введите цену: ";
    cin >> aProduct.price;
    cin.ignore();
    cout << "Введите класс продукта: ";
    cin.getline(aProduct.product_class, 255);
    cout << "Введите даты поступления на склад (ДД ММ ГГГГ): ";
    cin >> day >> month >> year;
    aProduct.arrival_date_in_stock = { day, month, year };
    cout << "Введите дату истечения срока действия: ";
    cin >> day >> month >> year;
    aProduct.shelf_life = { day, month, year };

    return aProduct;
}

//Меню
int Menu() {
    int choice;
    cout << "1)Добавление товара на склад\n"
        << "2)Печать всех книг\n"
        << "3)Удаление товара со склада\n"
        << "4)Замена товара\n"
        << "5)Поиск товара по названию\n"
        << "6)Поиск товара По производителю\n"
        << "7)Поиск товара По цене\n"
        << "8)Поиск товара По группе товара\n"
        << "9)Поиск товара По дате поступления на склад\n"
        << "10)Поиск товара По сроку годности\n"
        << "11)Сортировка товара По цене\n"
        << "12)Сортировк а товара По группе товара\n"
        << "0)exit\n"
        << "Choice what do you need: \n";
    cin >> choice;
    return choice;
}


// Вывод данных со склада
void Print(Product aProduct) {
    cout << "Название: " << aProduct.title << endl;
    cout << "Производитель: " << aProduct.maker << endl;
    cout << "Цена: " << aProduct.price << endl;
    cout << "Класс продукта: " << aProduct.product_class << endl;
    cout << "Дата поступления на склад: " << aProduct.arrival_date_in_stock.day << "." <<
        aProduct.arrival_date_in_stock.month << "." << aProduct.arrival_date_in_stock.year << endl;
    cout << "Дата по сроку годности: " << aProduct.shelf_life.day << "." <<
        aProduct.shelf_life.month << "." << aProduct.shelf_life.year << endl;
}

// Удаление товара со склада
void remove(Product aProduct[], int& size, int indexToDelete) {
    if (indexToDelete < 0 || indexToDelete >= size) {
        cout << "Неверный индекс\n";
        return;
    }
    // Сдвиг оставшихся элементов влево
    for (int i = indexToDelete; i < size - 1; ++i) {
        aProduct[i] = aProduct[i + 1];
    }

    // Уменьшение размера массива
    size--;
}


Product* change(Product*& array, int& size, Product newElement) {
    // Создаем новый массив на один элемент больше
    Product* newArray = new Product[size + 1];

    // Копируем существующие элементы в новый массив
    for (int i = 0; i < size; ++i) {
        newArray[i] = array[i];
    }

    // Добавляем новый элемент
    newArray[size] = newElement;

    // Удаляем старый массив
    delete[] array;

    // Увеличиваем размер
    ++size;

    return newArray;
}

// Поиск товара: По названию
void searchOfTitle(Product aProduct[], int size, const char* whichTitle) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (strcmp(aProduct[i].title, whichTitle) == 0) {
            Print(aProduct[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "товар по названию не найдены: " << whichTitle << endl;
    }
}

//Поиск товара: По производителю
void searchOfMaker(Product aProduct[], int size, const char* whichMaker) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (strcmp(aProduct[i].maker, whichMaker) == 0) {
            Print(aProduct[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "товар по производителю не найдено: " << whichMaker << endl;
    }
}

//Поиск товара: По цене
void searchOfPrice(Product aProduct[], int size, int whichPrice) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (aProduct[i].price == whichPrice) {
            Print(aProduct[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "товар по цене не найдено: " << whichPrice << endl;
    }
}

//Поиск товара: По группе товара
void searchOfProductClass(Product aProduct[], int size, const char* whichProductClass) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (strcmp(aProduct[i].product_class, whichProductClass) == 0) {
            Print(aProduct[i]);
            found = true;
        }
    }
    if (!found) {
        cout << " товар автора не найдены: " << whichProductClass << endl;
    }
}

//Поиск товара: По дате поступления
void searchOfdate(Product aProduct[], int size, int whichDay, int whichMonth, int whichYear) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (aProduct[i].arrival_date_in_stock.day == whichDay) {
            if (aProduct[i].arrival_date_in_stock.month == whichMonth) {
                if (aProduct[i].arrival_date_in_stock.year == whichYear) {
                    Print(aProduct[i]);
                    found = true;
                }
            }
        }
    }
    if (!found) {
        cout << "товар по цене не найдено: " << whichDay << "." << whichMonth << "." << whichYear << endl;
    }
}

//Сортировка товара:По цене
Product* sortingOfPrice(Product aProduct[], int ROWS) {
    bool swapped;
    for (int i = 0; i < ROWS - 1; i++) {
        swapped = false;
        for (int j = 0; j < ROWS - i - 1; j++) {
            if (aProduct[j].price > aProduct[j + 1].price) {
                // Своп элементов
                Product temp = aProduct[j];
                aProduct[j] = aProduct[j + 1];
                aProduct[j + 1] = temp;
                swapped = true;
            }
        }
        // Если не было свопа, массив отсортирован
        if (!swapped)
            break;
    }
    return aProduct;
}

//Сортировка товара:По группе товара
Product* sortingOfproduct_class(Product* aProduct, int ROWS) {
    bool swapped;
    for (int i = 0; i < ROWS - 1; i++) {
        swapped = false;
        for (int j = 0; j < ROWS - i - 1; j++) {
            if (strcmp(aProduct[j].product_class, aProduct[j + 1].product_class) > 0) {
                // Своп элементов
                Product temp = aProduct[j];
                aProduct[j] = aProduct[j + 1];
                aProduct[j + 1] = temp;
                swapped = true;
            }
        }
        // Если не было свопа, массив отсортирован
        if (!swapped)
            break;
    }
    return aProduct;
}
