#include<iostream>
using namespace std;
int quiz()
{
    int score = 0;
    string answer;
    cout << "Welcome to the Quiz!" << endl;

    cout << "Question 1: What is the capital of France?" << endl;
    cin >> answer;
    if (answer == "Paris" || answer == "paris") {
        score++;
        cout << "Correct!" << endl;
    } else {
        cout << "Incorrect. The correct answer is Paris." << endl;
    }

    cout << "Question 2: What is 5 + 7?" << endl;
    cin >> answer;
    if (answer == "12") {
        score++;
        cout << "Correct!" << endl;
    } else {
        cout << "Incorrect. The correct answer is 12." << endl;
    }

    cout << "Question 3: Who wrote 'Romeo and Juliet'?" << endl;
    cin >> answer;
    if (answer == "Shakespeare" || answer == "shakespeare") {
        score++;
        cout << "Correct!" << endl;
    } else {
        cout << "Incorrect. The correct answer is Shakespeare." << endl;
    }

    cout << "Your final score is: " << score << "/3" << endl;

    return 0;
}
int main()
{
    quiz();
    return 0;
}