#include <iostream>
using namespace std;

struct desk_mas
{
    unsigned int num; //Номер кассы
    unsigned int product_code;//Код товара
    unsigned int product_count;//Количество товара
    double product_price; //Цена товара
    unsigned int percentages;//Процентная скидка на товар
    double amount;//Сумма за товар с учётом скидки
};

desk_mas completion_mas() //Заполнение пустой записи таблицы для динамического массива
{
    desk_mas tmp;
    cout << "Введите номер кассы: ";
    cin >> tmp.num;
    cout << "Введите код товара: ";
    cin >> tmp.product_code;
    cout << "Введите количество товара: ";
    cin >> tmp.product_count;
    cout << "Введите цену товара: ";
    cin >> tmp.product_price;
    cout << "Введите процентную скидку на товар: ";
    cin >> tmp.percentages;
    tmp.amount = tmp.product_count * tmp.product_price * (1 - tmp.percentages / 100.0);
    return tmp;
}

void print_table_mas(desk_mas* table, int size) //Вывод всей таблицы на экран, для дин. массива
{
    cout << "\t   Номер кассы" << "\t  Код товара" << "\tКоличество товара" << "\tЦена товара" << "\tПроцентная скидка на товар" << "\tСтоимость покупки" << endl;
    for (int i = 0; i < size; i++)
        printf("\t\t%d\t\t%d\t\t%d\t\t  %f\t\t%d\t\t\t\t%f\n", table[i].num, table[i].product_code, table[i].product_count, table[i].product_price, table[i].percentages, table[i].amount);
}

void insert_mas(desk_mas*& table, int& size, desk_mas tmp)//Вставка записи для таблицы, реализованной на динамическом массиве
{
    size++;
    table = (desk_mas*)realloc(table, sizeof(desk_mas) * size);
    bool flag = false;
    for (int i = 0; i < size - 1; i++)
        if (table[i].num == tmp.num)
        {
            for (int j = size - 1; j > i; j--)
                table[j] = table[j - 1];
            table[i] = tmp;
            flag = true;
            cout << "Вставка выполнена" << endl << endl;
            break;
        }
    if (!flag)
    {
        table[size - 1] = tmp;
        cout << "Вставка выполнена" << endl << endl;
    }
}

void print_desk_mas(desk_mas* table, int size, int n)//Вывод на экран записей об операциях, совершённых n-ой кассой
{
    bool flag = false;
    for (int i = 0; i < size; i++)
    {
        if (table[i].num == n)
        {
            if (flag == false)
                cout << "\t   Номер кассы" << "\t  Код товара" << "\tКоличество товара" << "\tЦена товара" << "\tПроцентная скидка на товар" << "\tСтоимость покупки" << endl;
            printf("\t\t%d\t\t%d\t\t%d\t\t  %f\t\t%d\t\t\t\t%f\n", table[i].num, table[i].product_code, table[i].product_count, table[i].product_price, table[i].percentages, table[i].amount);
            flag = true;
        }
    }
    if (!flag)
        cout << "В таблице нет сведений об операциях данной кассы." << endl;
    cout << endl;
}

void del_mas(desk_mas*& table, int& size, int n) //Удаляет записи об операциях, сделанных n-ой кассой
{
    int count = 0;
    bool flag = false;
    int start = -1;
    for (int i = 0; i < size; i++) {
        if (table[i].num == n) {
            if (start == -1)
                start = i;
            count++;
            flag = true;
        }
    }
    if (flag)
        for (int i = start; i + count < size; i++)
            table[i] = table[i + count];

    if (!flag)
        cout << "В таблице нет сведений об операциях данной кассы." << endl;
    cout << endl;

    table = (desk_mas*)realloc(table, sizeof(desk_mas) * (size - count));
    size -= count;
}
