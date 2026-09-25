#include <iostream>
using namespace std;
int guess(int n)
{
    cout<<"Enter a number between 1 and 100: ";
    int guess;
    cin>>guess;
    if(guess==n)
    {
        cout<<"Congratulations! You guessed the correct number."<<endl;
        return 1;
    }
    else if(guess<n)
    {
        cout<<"Your guess is too low. Try again."<<endl;
        return 0;
    }
    else
    {
        cout<<"Your guess is too high. Try again."<<endl;
        return 0;
    }
}
int main()
{
    int n;
    cout << "Enter a number between 1 and 100 for the user to guess: ";
    cin >> n;
    while (guess(n) == 0){}
    return 0;
}