#include "tubes.h"

Mentor *FirstListMentor, *LastListMentor, *TempM, *NewDataMentor;
Apprentice *FirstListApprentice, *LastListApprentice, *TempA, *NewDataApprentice;

void AddMentor(string Name){
    if(FirstListMentor == NULL){
        FirstListMentor = new Mentor();
        FirstListMentor->Name = Name;
        FirstListMentor->Next = NULL;
        LastListMentor = FirstListMentor;
    }else{
        NewDataMentor = new Mentor();
        NewDataMentor->Name = Name;
        NewDataMentor->Next = NULL;

        if(FirstListMentor == LastListMentor){
            FirstListMentor->Next = NewDataMentor;
            LastListMentor = NewDataMentor;
        }else{
            LastListMentor->Next = NewDataMentor;
            LastListMentor = NewDataMentor;
        }
    }
}

void ShowMentor(){
    TempM = FirstListMentor;

    cout << "This is the list of mentor : " << endl << endl;

    while(TempM != NULL){
        cout << "Name : " << TempM->Name  << endl << endl;
        TempM = TempM->Next;
    }

    cout << endl;
}

void AddApprentice(string Name, string Email, int PerformenceScore){
    if(FirstListApprentice == NULL){
        FirstListApprentice = new Apprentice();
        FirstListApprentice->Name = Name;
        FirstListApprentice->Email = Email;
        FirstListApprentice->PerformenceScore = PerformenceScore;
        FirstListApprentice->Next = NULL;
        FirstListApprentice->Parent = NULL;
        LastListApprentice = FirstListApprentice;
    }else{
        NewDataApprentice = new Apprentice();
        NewDataApprentice->Name = Name;
        NewDataApprentice->Email = Email;
        NewDataApprentice->PerformenceScore = PerformenceScore;
        NewDataApprentice->Next = NULL;
        NewDataApprentice->Parent = NULL;

        if(FirstListApprentice == LastListApprentice){
            FirstListApprentice->Next = NewDataApprentice;
            LastListApprentice = NewDataApprentice;
        }else{
            LastListApprentice->Next = NewDataApprentice;
            LastListApprentice = NewDataApprentice;
        }
    }
}

void ShowApprentice(){
    TempA = FirstListApprentice;

    cout << "This is the list of apprentice : " << endl << endl;

    while(TempA != NULL){
        cout << "Name : " << TempA->Name << endl << endl;
        cout << "Email : " << TempA->Email << endl << endl;
        cout << "Performence Score : " << TempA->PerformenceScore << endl << endl << endl;
        TempA = TempA->Next;
    }

    cout << endl;
}

void Connect(string Apprentice, string Mentor){
    TempM = FirstListMentor;
    TempA = FirstListApprentice;

    while(TempM != NULL){
        if(TempM->Name == Mentor){
            while(TempA != NULL){
                if(TempA->Name == Apprentice){
                    TempA->Parent = TempM;
                }
                TempA = TempA->Next;
            }
        }
        TempM = TempM->Next;
    }
}

void ShowConnection(){
    TempA = FirstListApprentice;

    while(TempA != NULL){
        if(TempA->Parent == NULL){
            cout << " " << TempA->Name << " dont have any mentor" << endl << endl;
        }else{
            cout << " " << TempA->Name << " mentor is " << TempA->Parent->Name << endl << endl;
        }
        TempA = TempA->Next;
    }
}

bool FindMentor(string Name){
    TempM = FirstListMentor;
    bool Result = false;

    while(TempM != NULL){
        if(TempM->Name == Name){
            Result = true;
            break;
        }
        TempM = TempM->Next;
    }

    return Result;
}

bool FindApprentice(string Name){
    TempA = FirstListApprentice;
    bool Result = false;

    while(TempA != NULL){
        if(TempA->Name == Name){
            Result = true;
            break;
        }
        TempA = TempA->Next;
    }

    return Result;
}

void HighestPerformenceScore(){
    TempA = FirstListApprentice;
    int HighestScore = 0;
    string ResultName;
    string ResultEmail;

    while(TempA != NULL){
        if(TempA->PerformenceScore > HighestScore){
            HighestScore = TempA->PerformenceScore;
            ResultName = TempA->Name;
            ResultEmail = TempA->Email;
        }
        TempA = TempA->Next;
    }

    cout << " Highest apprentice performence : " << endl << endl;
    cout << " Name : " << ResultName << endl << endl;
    cout << " Email : " << ResultEmail << endl << endl;
    cout << " Performence Score : " << HighestScore << endl << endl;
}
