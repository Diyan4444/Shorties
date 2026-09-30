#include<iostream>
using namespace std;

int computer()
{
    int r = (rand() % 3) + 1;
    return r;
}
void check(int score_user,int score_comp)
{
    if(score_comp>score_user)
    {
        cout<<"The computer Won, You Lost, Better Luck next time!"<<endl;
    }
    else if(score_comp<score_user)
    {
        cout<<"The user won! with a score of: "<<score_user<<endl;
    }
    else{}
}
void compare(int user,int comp,int& score_user,int& score_comp)
{
    if(user==1 && comp==2)
    {
        ++score_comp;
        cout<<"Computer gets the point!\n";
        cout<<"Your score: "<<score_user<<endl;
        cout<<"Computer Score"<<score_comp<<endl;
    }
    else if(user==2 && comp==3)
    {
        ++score_comp;
        cout<<"Computer gets the point!\n";
        cout<<"Your score: "<<score_user<<endl;
        cout<<"Computer Score"<<score_comp<<endl;
    }
    else if(user==3 && comp==1)
    {
        ++score_comp;
        cout<<"Computer gets the point!\n";
        cout<<"Your score: "<<score_user<<endl;
        cout<<"Computer Score"<<score_comp<<endl;
    }
    else if(user==1 && comp==3)
    {
        ++score_user;
        cout<<"User gets the point!\n";
        cout<<"Your score: "<<score_user<<endl;
        cout<<"Computer Score"<<score_comp<<endl;
    }
    else if(user==2 && comp==1)
    {
        ++score_user;
        cout<<"User gets the point!\n";
        cout<<"Your score: "<<score_user<<endl;
        cout<<"Computer Score"<<score_comp<<endl;
    }
    else if(user==3 && comp==2)
    {
        ++score_user;
        cout<<"User gets the point!\n";
        cout<<"Your score: "<<score_user<<endl;
        cout<<"Computer Score"<<score_comp<<endl;
    }
    else
    {
        cout<<"This is a Tie!"<<endl;
        cout<<"Your score: "<<score_user<<endl;
        cout<<"Computer Score"<<score_comp<<endl;
    }
}

int main()
{
    cout<<"Welcome to Rock Paper Sissors: \n";
    cout<<"Rock: 1"<<endl;
    cout<<"Paper 2"<<endl;
    cout<<"Sissors: 3"<<endl;
    cout<<"Best of 3 points..."<<endl<<"The game begins now->"<<endl;
    int score_user = 0;
    int score_comp = 0;
    while(score_comp<3 && score_user<3)
    {
        int user = 0;
        cout<<"Enter the number: "<<endl;
        cin>>user;
        int comp = computer();
        cout<<"The computer choose: "<<comp<<endl;
        compare(user,comp,score_user,score_comp);
        check(score_user,score_comp);
    }
    return 0;
}