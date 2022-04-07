#include <iostream>
#include <vector>
using namespace std;

struct desk
{
    unsigned int num; //Номер кассы
    unsigned int product_code;//Код товара
    unsigned int product_count;//Количество товара
    double product_price; //Цена товара
    unsigned int percentages;//Процентная скидка на товар
    double amount;//Сумма за товар с учётом скидки
};

desk completion() //Заполнение пустой записи таблицы для контейнера vector
{
    desk tmp;
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

void insert_vec(vector <desk>& table, desk tmp)//Вставка записи для таблицы, реализованной на векторе
{
    bool flag = false;
    for (int i = 0; i < table.size(); i++)
        if (table[i].num == tmp.num)
        {
            table.insert(table.begin() + i, tmp);
            flag = true;
            cout << "Вставка выполнена" << endl << endl;
            break;
        }
    if (!flag)
    {
        table.push_back(tmp);
        cout << "Вставка выполнена" << endl << endl;
    }
}

void print_table(vector <desk> table)
{
    cout << "\t   Номер кассы" << "\t  Код товара" << "\tКоличество товара" << "\tЦена товара" << "\tПроцентная скидка на товар" << "\tСтоимость покупки" << endl;
    for (int i = 0; i < table.size(); i++)
        printf("\t\t%d\t\t%d\t\t%d\t\t  %f\t\t%d\t\t\t\t%f\n", table[i].num, table[i].product_code, table[i].product_count, table[i].product_price, table[i].percentages, table[i].amount);
}

void print_desk_vec(vector <desk> table, int n)
{
    bool flag = false;
    for (int i = 0; i < table.size(); i++)
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

void del_vec(vector <desk>& table, int n)
{
    bool flag = false;
    for (int i = 0; i < table.size(); i++) {
        if (table[i].num == n)
            table.erase(table.begin() + i);
    }
    if (!flag)
        cout << "В таблице нет сведений об операциях данной кассы." << endl;
    cout << endl;
}

