#include <iostream>
using namespace std;
int add(int a, int b)
{
    return a + b;
}
int subtract(int a, int b)
{
    return a - b;
}
int divide(int a, int b)
{
    return a / b;
}
int multiply(int a, int b)
{
    return a * b;
}
int remainder(int a, int b)
{
    return a % b;
}
int power(int a, int b)
{
    int result = 1;
    for (int i = 0; i < b; i++)
    {
        result *= a;
    }
    return result;
}
int factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}
int square(int a)
{
    return a * a;
}


int main()
{
    int a, b;
    int choice;
    cout << "Select operation: \n1. Addition\n2. Subtraction\n3. Division\n4. Multiplication\n5. Modulus\n6. Power\n7. Factorial\n8. Square\n";
    cin >> choice;

    if (choice >= 1 && choice <= 6)
    {
        cout << "Enter two numbers: ";
        cin >> a >> b;
    }
    else if (choice == 7 || choice == 8)
    {
        cout << "Enter a number: ";
        cin >> a;
        b = 0;
    }
    else
    {
        cout << "Invalid choice!" << endl;
        return 0;
    }
    switch (choice)
    {
        case 1:
            cout << "Result: " << add(a, b) << endl;
            break;
        case 2:
            cout << "Result: " << subtract(a, b) << endl;
            break;
        case 3:
            cout << "Result: " << divide(a, b) << endl;
            break;
        case 4:
            cout << "Result: " << multiply(a, b) << endl;
            break;
        case 5:
            cout << "Result: " << remainder(a, b) << endl;
            break;
        case 6:
            cout << "Result: " << power(a, b) << endl;
            break;
        case 7:
            cout << "Result: " << factorial(a) << endl;
            break;
        case 8:
            cout << "Result: " << square(a) << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
    }
    cout << "Do you want to perform another operation? (y/n): ";
    char cont;
    cin >> cont;
    if (cont == 'y' || cont == 'Y')
    {
        main();
    }
    else
    {
        cout << "Exiting the program." << endl;
    }
    return 0;
}