#include <iostream>
#include <vector>
using namespace std;

class stocks
{
private:
    string name;
    int quantity;
    int price;

public:
    stocks(string a, int b, int c)
    {
        name = a;
        quantity = b;
        price = c;
    }

    int getquantity()
    {
        return quantity;
    }

    string getname()
    {
        return name;
    }

    int getprice()
    {
        return price;
    }

    void addquantity(int q)
    {
        quantity += q;
    }

    void reducequantity(int w)
    {
        quantity -= w;
    }

    double getvalue()
    {
        return quantity * price;
    }

    void display()
    {
        cout << "Name: " << name << "  ";
        cout << "Quantity: " << quantity << "  ";
        cout << "Price: " << price << "  ";
        cout << "Value: " << getvalue() << endl;
    }
};

class classification
{
private:
    vector<stocks> records;

public:
    void buystock()
    {
        string name;
        int quantity;
        int price;

        cout << "Enter stock name: ";
        cin >> name;
        cout << "Enter quantity: ";
        cin >> quantity;
        cout << "Enter price: ";
        cin >> price;

        for (int i = 0; i < records.size(); i++)
        {
            if (records[i].getname() == name)
            {
                records[i].addquantity(quantity);
                cout << "Stock updated" << endl;
                return;
            }
        }

        stocks s(name, quantity, price);
        records.push_back(s);
        cout << "Stock added" << endl;
    }

    void sellstock()
    {
        string name;
        int quantity;

        cout << "Enter stock name: ";
        cin >> name;
        cout << "Enter quantity to sell: ";
        cin >> quantity;

        for (int i = 0; i < records.size(); i++)
        {
            if (records[i].getname() == name)
            {
                if (records[i].getquantity() >= quantity)
                {
                    records[i].reducequantity(quantity);
                    cout << "Stock sold" << endl;
                }
                else
                {
                    cout << "Not enough quantity" << endl;
                }
                return;
            }
        }

        cout << "Stock not found" << endl;
    }

    void showportfolio()
    {
        cout << endl;
        for (int i = 0; i < records.size(); i++)
        {
            records[i].display();
        }
    }

    void totalvalue()
    {
        double total = 0;

        for (int i = 0; i < records.size(); i++)
        {
            total += records[i].getvalue();
        }

        cout << "Total portfolio value: " << total << endl;
    }
};

int main()
{
    classification obj;
    int choice;

    do
    {
        cout << endl;
        cout << "1 Buy stock" << endl;
        cout << "2 Sell stock" << endl;
        cout << "3 Show portfolio" << endl;
        cout << "4 Total value" << endl;
        cout << "5 Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
            obj.buystock();
        else if (choice == 2)
            obj.sellstock();
        else if (choice == 3)
            obj.showportfolio();
        else if (choice == 4)
            obj.totalvalue();

    } while (choice != 5);

    return 0;
}
