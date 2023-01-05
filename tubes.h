#include <iostream>

using namespace std;

struct Mentor{
    string Name;
    Mentor *Next;
};

struct Apprentice{
    string Name;
    string Email;
    int PerformenceScore;
    Apprentice *Next;
    Mentor *Parent;
};

void AddMentor(string Name);
void ShowMentor();
void AddApprentice(string Name, string Email, int PerformenceScore);
void ShowApprentice();
void Connect(string Apprentice, string Mentor);
void ShowConnection();
bool FindMentor(string Name);
bool FindApprentice(string Name);
void HighestPerformenceScore();
