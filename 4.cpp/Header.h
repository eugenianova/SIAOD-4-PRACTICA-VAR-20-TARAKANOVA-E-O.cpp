#include <iostream>
#include <vector>
using namespace std;

struct desk
{
    unsigned int num; //����� �����
    unsigned int product_code;//��� ������
    unsigned int product_count;//���������� ������
    double product_price; //���� ������
    unsigned int percentages;//���������� ������ �� �����
    double amount;//����� �� ����� � ������ ������
};

desk completion() //���������� ������ ������ ������� ��� ���������� vector
{
    desk tmp;
    cout << "������� ����� �����: ";
    cin >> tmp.num;
    cout << "������� ��� ������: ";
    cin >> tmp.product_code;
    cout << "������� ���������� ������: ";
    cin >> tmp.product_count;
    cout << "������� ���� ������: ";
    cin >> tmp.product_price;
    cout << "������� ���������� ������ �� �����: ";
    cin >> tmp.percentages;
    tmp.amount = tmp.product_count * tmp.product_price * (1 - tmp.percentages / 100.0);
    return tmp;
}

void insert_vec(vector <desk>& table, desk tmp)//������� ������ ��� �������, ������������� �� �������
{
    bool flag = false;
    for (int i = 0; i < table.size(); i++)
        if (table[i].num == tmp.num)
        {
            table.insert(table.begin() + i, tmp);
            flag = true;
            cout << "������� ���������" << endl << endl;
            break;
        }
    if (!flag)
    {
        table.push_back(tmp);
        cout << "������� ���������" << endl << endl;
    }
}

void print_table(vector <desk> table)
{
    cout << "\t   ����� �����" << "\t  ��� ������" << "\t���������� ������" << "\t���� ������" << "\t���������� ������ �� �����" << "\t��������� �������" << endl;
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
                cout << "\t   ����� �����" << "\t  ��� ������" << "\t���������� ������" << "\t���� ������" << "\t���������� ������ �� �����" << "\t��������� �������" << endl;
            printf("\t\t%d\t\t%d\t\t%d\t\t  %f\t\t%d\t\t\t\t%f\n", table[i].num, table[i].product_code, table[i].product_count, table[i].product_price, table[i].percentages, table[i].amount);
            flag = true;
        }
    }
    if (!flag)
        cout << "� ������� ��� �������� �� ��������� ������ �����." << endl;
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
        cout << "� ������� ��� �������� �� ��������� ������ �����." << endl;
    cout << endl;
}

