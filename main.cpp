#include "tubes.h"

int main()
{
    int Option;

    while(true){
        cout << "********CHOOSE A NUMBER!!!*******" << endl << endl;
        cout << " 1) ADD A MENTOR" << endl;
        cout << " 2) ADD A APPRENTICE" << endl;
        cout << " 3) CONNECT APPRENTICE TO A MENTOR" << endl;
        cout << " 4) SHOW ALL CONNECTION" << endl;
        cout << " 5) SHOW THE HIGHEST APPRENTICE PERFORMENCE" << endl;
        cout << " 0) EXIT PROGRAM" << endl << endl;
        cout << " ENTER A NUMBER : ";
        cin >> Option;
        cout << endl;

        if(Option == 1){
            cout << "********ADD A MENTOR!!!*******" << endl << endl;
            string Name;
            cout << "Enter mentor name : ";
            cin >> Name;
            cout << endl;
            AddMentor(Name);
            cout << "Mentor has been successfully added" << endl << endl;
        }else if(Option == 2){
            cout << "********ADD A APRENTICE!!!*******" << endl << endl;
            string Name;
            string Email;
            int PerformenceScore;
            cout << "Enter apprentice name : ";
            cin >> Name;
            cout << endl;
            cout << "Enter apprentice email : ";
            cin >> Email;
            cout << endl;
            cout << "Enter apprentice performence score (from 1-10) : ";
            cin >> PerformenceScore;
            cout << endl << endl;
            AddApprentice(Name,Email,PerformenceScore);
            cout << "Apprentice has been successfully added" << endl << endl;
        }else if(Option == 3){
            cout << "********CONNECT APPRENTICE TO A MENTOR!!!*******" << endl << endl;
            string Apprentice;
            string Mentor;
            ShowMentor();
            ShowApprentice();
            cout << "Apprentice name : ";
            cin >> Apprentice;
            cout << endl;
            while(FindApprentice(Apprentice) != true){
                cout << Apprentice << " hasn't beed registered!!!" << endl << endl;
                cout << "Enter another apprentice name : ";
                cin >> Apprentice;
                cout << endl;
            }
            cout << "Mentor name : ";
            cin >> Mentor;
            cout << endl;
            while(FindMentor(Mentor) != true){
                cout << Mentor << " hasn't beed registered!!!" << endl << endl;
                cout << "Enter another mentor name : ";
                cin >> Mentor;
                cout << endl;
            }
            Connect(Apprentice,Mentor);
            cout << "Succeed" << endl << endl;
        }else if(Option == 4){
            ShowConnection();
        }else if(Option == 5){
            HighestPerformenceScore();
        }else if(Option == 0){
            cout << "********THANK YOU AND BYE BYE*******" << endl << endl;
            break;
        }
    }
}
