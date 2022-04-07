#include <Windows.h>
#include "Header.h"
#include "Header1.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Практическая работа №4 \"Структуризация многоэлементных структур средствами struct.\". Тараканова Евгения." << endl << endl;
    vector <desk> table;
    int count = 0, mode, menu;
    cout << "Выберите пункт:\n1 - Таблица на основе динамического массива \n2 - Таблица на основе контейнера vector \n--->";
    do
    {
        cin >> menu;
        if (menu != 1 && menu != 2)
            cout << "Такого пункта нет. Повторите попытку: ";
    } while (menu != 1 && menu != 2);

    switch (menu)
    {
    case 1:
    {
        int size = 0;
        desk_mas* table_mas = new desk_mas[size];
        do
        {
            cout << "\nВыберите пункт:\n0 - Выход \n1 - Добавить запись о новой операции \n2 - Вывести список операций, проведенных заданной кассой, с указанием стоимости покупки по каждой операции \n" <<
                "3 - Удалить записи по операциям, проведенным определенной кассой \n4 - Вывести таблицу со всеми операциями \n ---> ";
            do
            {
                cin >> mode;
                if (mode < 0 || mode>4)
                    cout << "Такого пункта нет. Повторите попытку: ";
                if (size == 0 && (mode == 2 || mode == 3 || mode == 4))
                    cout << "Данную команду нельзя выполнить, поскольку в таблице нет записей об операциях. Повторите попытку: ";
            } while (mode < 0 || mode>4 || (size == 0 && (mode == 2 || mode == 3 || mode == 4)));

            switch (mode)
            {
            case 1:
            {
                count++;
                cout << endl << "Операция №" << count << endl;
                desk_mas tmp = completion_mas();
                insert_mas(table_mas, size, tmp);
                break;
            }
            case 2:
            {
                int n;
                cout << "Введите номер кассы: ";
                cin >> n;
                print_desk_mas(table_mas, size, n);
                break;
            }
            case 3:
            {
                int n;
                cout << "Введите номер кассы: ";
                cin >> n;
                del_mas(table_mas, size, n);
                break;
            }
            case 4:
                print_table_mas(table_mas, size);
                break;
            }
        } while (mode != 0);
        break;
    }
    case 2:
    {
        do
        {
            cout << "Выберите пункт:\n0 - Выход \n1 - Добавить запись о новой операции \n2 - Вывести список операций, проведенных заданной кассой, с указанием стоимости покупки по каждой операции \n" <<
                "3 - Удалить записи по операциям, проведенным определенной кассой \n4 - Вывести таблицу со всеми операциями \n ---> ";
            do
            {
                cin >> mode;
                if (mode < 0 || mode>4)
                    cout << "Такого пункта нет. Повторите попытку: ";
                if (table.size() == 0 && (mode == 2 || mode == 3 || mode == 4))
                    cout << "Данную команду нельзя выполнить, поскольку в таблице нет записей об операциях. Повторите попытку: ";
            } while (mode < 0 || mode>4 || (table.size() == 0 && (mode == 2 || mode == 3 || mode == 4)));

            switch (mode)
            {
            case 1:
            {
                count++;
                cout << endl << "Операция №" << count << endl;
                desk tmp = completion();
                insert_vec(table, tmp);
                break;
            }
            case 2:
            {
                int n;
                cout << "Введите номер кассы: ";
                cin >> n;
                print_desk_vec(table, n);
                break;
            }
            case 3:
            {
                int n;
                cout << "Введите номер кассы: ";
                cin >> n;
                del_vec(table, n);
                break;
            }
            case 4:
                print_table(table);
                break;
            }
        } while (mode != 0);
        break;
    }
    }
    return 0;


}
