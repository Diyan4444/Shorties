#include<iostream>
using namespace std;
int expense(int amount)
{
    cout << "Total expense: " << amount << endl;
    return amount;
}
int savings(int income, int expense)
{
    int total_savings = income - expense;
    cout << "Total savings: " << total_savings << endl;
    return total_savings;
}
int main()
{
    char check = 'y';
    while( check == 'y' || check == 'Y')
    {
        int income, expense_amount;
        cout << "Enter your income: ";
        cin >> income;
        cout << "Enter your expense amount: ";
        cin >> expense_amount;
        int total_savings = savings(income, expense_amount);
        if (total_savings < 0) 
        {
        cout << "You are overspending by: " << abs(total_savings) << endl;
        }
        cout<< "Do you want to continue? (y for Yes, n for No): ";
        cin >> check;
    }
    return 0;
}