#include <iostream>
using namespace std;
struct Who
{
    static const char* who;
    static const int id = -1;
    virtual void saund() { cout << "..."; }
};
struct Parrot : public Who
{
    static const char* who;
    static const int id = 0;
    virtual void saund() { cout << "Kesha"; }
};
struct Dog : public Who
{
    static const char* who;
    static const int id = 1;
    virtual void saund() { cout << "Gav"; }
};
struct Cat : public Who
{
    static const char* who;
    static const int id = 2;
    virtual void saund() { cout << "Meow"; }
};
const char*
Who::who = "Who";
const char*
Parrot::who = "Parrot";
const char*
Dog::who = "Dog";
const char*
Cat::who = "Cat";
int main(int argc, char* argv[])
{
    int who_parrot_dog_cat[] = { 0,0,0 };
    const char* who_are[] = { Parrot::who, Dog::who, Cat::who };
    int numb_who = sizeof(who_parrot_dog_cat) / sizeof(who_parrot_dog_cat[0]);
    for (int i = 0; i < numb_who; i++)
    {
            cout << "Enter the number of objects named \"" << who_are[i] << "\" in the room: ";
            cin >> who_parrot_dog_cat[i];
    }
    int whole_number = 0;
    for (int i = 0; i < numb_who; i++)whole_number += who_parrot_dog_cat[i];
    if (whole_number < 1)
    {
        cout << "Something wrong with whole_number with value " << whole_number << endl;
        system("pause");
        return 1;
    }
    Who** who_s_there = new Who * [whole_number];
    int ind = 0;
    for (int i = 0; i < numb_who; i++)
        for (int j = 0; j < who_parrot_dog_cat[i]; j++)
        {
            switch (i)
            {
            case Parrot::id:who_s_there[ind++] = new Parrot(); break;
            case Dog::id:who_s_there[ind++] = new Dog(); break;
            case Cat::id:who_s_there[ind++] = new Cat(); break;
            default:who_s_there[ind++] = new Who(); break;
            }
        }
    cout << "In the room you can hear:" << endl << endl;
    for (int i = 0; i < whole_number; i++)
    {
        who_s_there[i]->saund();
        if (i == whole_number - 1)
            cout << '!';
        else
            cout << '-';

    }
    for (int i = 0; i < whole_number; i++)
        delete who_s_there[i];
    delete[] who_s_there;
    cout << endl << endl;
    system("pause");
    return 0;
}