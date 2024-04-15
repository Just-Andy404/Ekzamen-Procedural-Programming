/*
Создайте приложение "Склад". Приложение должно реализовывать следующую
функциональность:
Добавление товара на склад.
Удаление товара со склада.
Замена товара.

Поиск товара:
По названию.
По производителю.
По цене.
По группе товара (например, "Минеральная вода" или "Консервы").
По дате поступления на склад.
По сроку годности.

Сортировка товара:
По цене.
По группе товара.
*/
#include <iostream>
#include "Header.h"// Подключение заголовочного файла "Header.h" для использования пользовательских функций и классов
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    // int N = 255; 
    int choice; // Объявление переменной 'choice' для хранения выбора пользователя
    int howManyitems = 0; // Инициализация переменной 'howManyitems' для отслеживания количества элементов, начиная с 0
    bool isTrue = true; // Инициализация переменной 'isTrue' для контроля логики отображения сообщения об ошибке

    // Цикл продолжается до тех пор, пока пользователь не введет ненулевое количество элементов
    while (howManyitems == 0 ) {
        if (!isTrue) {
            cout << "ОШИБКА, попробуйте еще раз" << endl; // Если 'isTrue' ложно, выводится сообщение об ошибке
            isTrue = true;
        }
        cout << "================================\n";
        cout << "Введите сколько предметов будет (не вводите символы !!!): ";
        cin >> howManyitems;
        isTrue = false;
    }
    Product* storage = new Product[howManyitems];
    cout << "\n================================\n";
    for (int i = 0; i < howManyitems; i++) {
        storage[i] = input();
        cout << "================================\n";
    }
    while (true)
    {
        cout << "\n================================\n";
        choice = Menu();
        cout << "\n================================\n";

        switch (choice) {
        case 0:
            delete[] storage; // Освобождаем память перед выходом
            return 0; // Корректно завершаем программу

        case 1: {
            Product newElement = input();
            storage = change(storage, howManyitems, newElement);// Добавление нового продукта в массив
            break;
        }
        case 2:
            for (int i = 0; i < howManyitems; i++) {
                cout << "\n====================\n";
                cout << "el: " << i << endl;
                Print(storage[i]);// Вывод информации об элементе
                cout << "\n====================\n";
            }
            break;
        case 3: {
            int whichItemDelete;
            cout << "Какой элемент вы хотите удалить: ";
            cin >> whichItemDelete;
            if (whichItemDelete >= 0 && whichItemDelete < howManyitems) {
                remove(storage, howManyitems, whichItemDelete);// Удаление элемента, если индекс корректен
            }
            else {
                cout << "Неверный индекс\n";
            }
            break;
        }
        case 4: {
            int whichItemChange;
            cout << "Какой элемент вы хотите изменить: ";
            cin >> whichItemChange;
            if (whichItemChange >= 0 && whichItemChange < howManyitems) {
                Product newElement = input();
                storage = change(storage, howManyitems, newElement);// Замена элемента на новый, введенный пользователем
            }
            else {
                cout << "Неверный индекс\n";
            }
            break;
        }

        case 5:
            char whichTitle[255];
            cout << "Введите название товара: ";
            cin.ignore();
            cin.getline(whichTitle, 255);
            cout << "\n====================\n";
            searchOfTitle(storage, howManyitems, whichTitle);// Поиск товара по названию
            cout << "\n====================\n";
            break;
        case 6:
            char whichMaker[255];
            cout << "Введите производитель товара: ";
            cin.ignore();
            cin.getline(whichMaker, 255);
            cout << "\n====================\n";
            searchOfMaker(storage, howManyitems, whichMaker);// Поиск товара по производителю
            cout << "\n====================\n";
            break;
        case 7:
            int whichPrice;
            cout << "Введите цену товара: ";
            cin >> whichPrice;
            cout << "\n====================\n";
            searchOfPrice(storage, howManyitems, whichPrice);// Поиск товара по цене
            cout << "\n====================\n";
            break;
        case 8:
            char whichProductClass[255];
            cout << "Введите производитель товара: ";
            cin.ignore();
            cin.getline(whichProductClass, 255);
            cout << "\n====================\n";
            searchOfProductClass(storage, howManyitems, whichProductClass);// Поиск товара по классу
            cout << "\n====================\n";
            break;
        case 9: {
            int whichDay1, whichMonth1, whichYear1;
            cout << "Введите дату поступления на склад (ДД ММ ГГГГ): ";
            cin >> whichDay1 >> whichMonth1 >> whichYear1;
            searchOfdate(storage, howManyitems, whichDay1, whichMonth1, whichYear1);// Поиск товара по дате поступления
            break;
        }
        case 10: {
            int whichDay2, whichMonth2, whichYear2;
            cout << "Введите дату срока годности (ДД ММ ГГГГ): ";
            cin >> whichDay2 >> whichMonth2 >> whichYear2;
            searchOfdate(storage, howManyitems, whichDay2, whichMonth2, whichYear2);// Поиск товара по сроку годности
            break;
        }

        case 11:
            storage = sortingOfPrice(storage, howManyitems);// Сортировка товаров по цене
            break;
        case 12:
            storage = sortingOfproduct_class(storage, howManyitems);// Сортировка товаров по классу
            break;


        }
    }
}
