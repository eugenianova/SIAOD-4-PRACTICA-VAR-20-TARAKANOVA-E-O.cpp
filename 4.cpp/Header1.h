#include <iostream>
using namespace std;

struct desk_mas
{
    unsigned int num; //����� �����
    unsigned int product_code;//��� ������
    unsigned int product_count;//���������� ������
    double product_price; //���� ������
    unsigned int percentages;//���������� ������ �� �����
    double amount;//����� �� ����� � ������ ������
};

desk_mas completion_mas() //���������� ������ ������ ������� ��� ������������� �������
{
    desk_mas tmp;
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

void print_table_mas(desk_mas* table, int size) //����� ���� ������� �� �����, ��� ���. �������
{
    cout << "\t   ����� �����" << "\t  ��� ������" << "\t���������� ������" << "\t���� ������" << "\t���������� ������ �� �����" << "\t��������� �������" << endl;
    for (int i = 0; i < size; i++)
        printf("\t\t%d\t\t%d\t\t%d\t\t  %f\t\t%d\t\t\t\t%f\n", table[i].num, table[i].product_code, table[i].product_count, table[i].product_price, table[i].percentages, table[i].amount);
}

void insert_mas(desk_mas*& table, int& size, desk_mas tmp)//������� ������ ��� �������, ������������� �� ������������ �������
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
            cout << "������� ���������" << endl << endl;
            break;
        }
    if (!flag)
    {
        table[size - 1] = tmp;
        cout << "������� ���������" << endl << endl;
    }
}

void print_desk_mas(desk_mas* table, int size, int n)//����� �� ����� ������� �� ���������, ����������� n-�� ������
{
    bool flag = false;
    for (int i = 0; i < size; i++)
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

void del_mas(desk_mas*& table, int& size, int n) //������� ������ �� ���������, ��������� n-�� ������
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
        cout << "� ������� ��� �������� �� ��������� ������ �����." << endl;
    cout << endl;

    table = (desk_mas*)realloc(table, sizeof(desk_mas) * (size - count));
    size -= count;
}
