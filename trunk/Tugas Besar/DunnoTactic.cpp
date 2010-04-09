/* 
 * File:   DunnoTactic.cpp
 * Author: rezanachmad
 * 
 * Created on March 29, 2010, 10:47 AM
 */

#include <stdlib.h>
#include <sstream>

#include "DunnoTactic.h"
#include "Display/Display.h"
#include "Job/Knight.h"
#include "Job/Archer.h"
#include "Job/Assassin.h"
#include "Job/Mage.h"
#include "Job/Sage.h"
#include "Job/Warrior.h"

char DunnoTactic::Command[100];
string DunnoTactic::CommandParse[10];
int DunnoTactic::CommandLength;
vector<Job*> DunnoTactic::P1;
vector<Job*> DunnoTactic::P2;
Map DunnoTactic::M;
Display DunnoTactic::D;
int DunnoTactic::NumberChar;
int DunnoTactic::PlayerTurn;

DunnoTactic::DunnoTactic() {
}

DunnoTactic::DunnoTactic(const DunnoTactic& orig) {
}

DunnoTactic::~DunnoTactic() {
}

void DunnoTactic::Main()
{
    while(true)
    {
        cout << "Menu Utama > ";
        cin.getline(Command, 99);
        try
        {
            ParseCommand();
            if (CommandLength==2 && CommandParse[0]=="build" && CommandParse[1]=="mode")
            {
                Build();
            }
            else if (CommandLength==2 && CommandParse[0]=="play" && CommandParse[1]=="mode")
            {
                Play();
            }
            else if (CommandLength==1 && CommandParse[0]=="exit")
            {
                break;
            }
            else if (CommandLength==1 && CommandParse[0]=="help")
            {
                cout << "build mode     membangun peta" << endl;
                cout << "play mode      mulai bermain" << endl;
            }
            else if (CommandLength==1 && CommandParse[0]=="clear")
            {
                system(CommandParse[0].c_str());
            }
            else
            {
                throw "Perintah tidak ditemukan.";
            }
            
        }
        catch(const char *e)
        {
            cout << e << endl;
        }
    }
}

void DunnoTactic::Build()
{
    while(true)
    {
        cout << "build > ";
        cin.getline(Command, 99);
        try
        {
            ParseCommand();
            if (CommandLength==4 && CommandParse[0]=="create" && CommandParse[1]=="map")
            {
                if (!IsInteger(CommandParse[2]) || !IsInteger(CommandParse[3]))
                {
                    throw "Ukuran Map harus dalam integer.";
                }
                else
                {
                    M.CreateMap(atoi(CommandParse[2].c_str()), atoi(CommandParse[3].c_str()));
                }
            }
            else if (CommandLength==3 && CommandParse[0]=="load" && CommandParse[1]=="map")
            {
                M.Load(CommandParse[2]);
            }
            else if (CommandLength==3 && CommandParse[0]=="save" && CommandParse[1]=="map")
            {
                M.Save(CommandParse[2]);
            }
            else if (CommandLength==4 && CommandParse[0]=="edit")
            {
                if (!IsInteger(CommandParse[1]) || !IsInteger(CommandParse[2]))
                {
                    throw "Posisi harus dalam integer.";
                }
                int x = atoi(CommandParse[1].c_str());
                int y = atoi(CommandParse[2].c_str());              
                M.SetTerrainXY(x, y, CommandParse[3]);
            }
            else if (CommandLength==6 && CommandParse[0]=="edit")
            {
                if (!IsInteger(CommandParse[1]) || !IsInteger(CommandParse[2]) || !IsInteger(CommandParse[3]) || !IsInteger(CommandParse[4]))
                {
                    throw "Posisi harus dalam integer.";
                }
                int x = atoi(CommandParse[1].c_str());
                int y = atoi(CommandParse[2].c_str());
                int x1 = atoi(CommandParse[3].c_str());
                int y1 = atoi(CommandParse[4].c_str());
                M.SetTerrainArea(x,y,x1,y1,CommandParse[5]);
            }
            else if (CommandLength==2 && CommandParse[0]=="edit" && CommandParse[1]=="random")
            {
                M.SetMapRandom();
            }
            else if (CommandLength==1 && CommandParse[0]=="exit")
            {
                D.displayBoxMap();
                break;
            }
            else if (CommandLength==1 && CommandParse[0]=="clear")
            {
                system(CommandParse[0].c_str());
            }
            else if (CommandLength==1 && CommandParse[0]=="help")
            {
                cout << "create map size_x size_y                   untuk membuat map baru" << endl;
                cout << "load map \"file\"                            untuk memakai map yang telah ada" << endl;
                cout << "save map \"file\"                            untuk membuat map baru" << endl;
                cout << "edit map [x y] nama_terrain                untuk mengedit isi map pada posisi x y" << endl;
                cout << "edit map [x1 y1] [x2 y2] nama_terrain      untuk mengedit isi map pada area x1,y1 sampau x2,y2"<< endl;
                cout << "edit random                                untuk mengedit isi map secara random" << endl;
                cout << "exit                                       untuk keluar dari menu ini" << endl;
            }
            else
            {
                throw "Perintah tidak ditemukan.";
            }
        }
        catch (const char *e)
        {
            cout << e << endl;
        }
    }
}

void DunnoTactic::ConstructCharacter(vector<Job*> &P, vector<string> Job, string Race, int Player)
{
    for (int i=0;i<NumberChar;++i)
    {
        if (Job[i]=="knight") {
            P.push_back(new Knight(Race));
        }
        if (Job[i]=="archer") {
            P.push_back(new Archer(Race));
        }
        if (Job[i]=="assassin") {
            P.push_back(new Assassin(Race));
        }
        if (Job[i]=="mage") {
            P.push_back(new Mage(Race));
        }
        if (Job[i]=="sage") {
            P.push_back(new Sage(Race));
        }
        if (Job[i]=="warrior") {
            P.push_back(new Warrior(Race));
        }
    }

    int A;
    if (Player==1)
        A = 1;
    else
        A = 501;

    for (int i=0;i<NumberChar;++i)
    {
        P[i]->SetID(A+i);
    }
}

int DunnoTactic::Random(const int& Begin, const int& End)
{
    //srand(time(NULL));
    return (rand()%((End-Begin+1))) + Begin;
}

void DunnoTactic::RandomChacracterPosition(int kuadran, vector<Job*> &P)
{
    int i=0;
    int temp;
    Point tempPoint;
    vector<Point> Available;
    vector<Point>::iterator iter;

    /*if (kuadran==1)
    {
        XB = SizeX - SizeX/2 + 1; XE = SizeX;
        YB = 1; YE = SizeY/2;
    }
    else if (kuadran==2)
    {
        XB = 1; XE = SizeX/2;
        YB = 1; YE = SizeY/2;
    }
    else if (kuadran==3)
    {
        XB = 1; XE = SizeX/2;
        YB = SizeY - SizeY/2 + 1; YE = SizeY;
    }
    else if (kuadran==4)
    {
        XB = SizeX - SizeX/2 + 1; XE = SizeX;
        YB = SizeY - SizeY/2 + 1; YE = SizeY;
    }
    else
    {
        throw "Kuadran tidak valid. Pilihan dari 1 s.d. 4.";
    }
    */
    for (int i=1;i<=M.GetSizeX();++i)
    {
        for (int j=1;j<=M.GetSizeY();++j)
        {
            if (M.GetTerrain(i,j)!=2 && M.GetTerrain(i,j)!=4)
                Available.push_back({i, j});
        }
    }

    iter = Available.begin();

    while (i<NumberChar)
    {
        temp = rand()%Available.size();
        tempPoint = Available[temp];
        Available.erase(iter+temp);
        P[i]->SetXY(tempPoint.X, tempPoint.Y);
        D.SetMapPlayer(tempPoint.X, tempPoint.Y, P[i]->GetID());
        ++i;
    }
}

void DunnoTactic::SelectNumCharacter()
{
    while (true)
    {
        cout << "Jumlah Character : ";
        cin.getline(Command, 99);
        try
        {
            ParseCommand();
            if (CommandLength==1)
            {
                if (IsInteger(CommandParse[0]))
                {
                    int temp = atoi(CommandParse[0].c_str());
                    int max = (M.GetSizeX()/2) * (M.GetSizeY()/2);
                    if (!(temp>0 && temp<=max))
                    {
                        string thr = "Jumlah karakter harus dari 1 s.d. "+ ToString(max) + ".";
                        throw thr.c_str();
                    }
                    NumberChar = atoi(CommandParse[0].c_str());
                    break;
                }
                else
                {
                    throw "Masukan harus dalam integer.";
                }
            }
            else
            {
                throw "Jumlah parameter harus satu.";
            }
        }
        catch (const char* e)
        {
            cout << e << endl;
        }
    }
}

void DunnoTactic::SelectRace(string& Race, const string& Player)
{
    int length = 4;
    string race[length];
    
    race[0] = "Human";
    race[1] = "Elf";
    race[2] = "Fairy";
    race[3] = "Orc";
    
    while(true)
    {
        //system("clear");
        cout << endl;
        for (int i = 0 ;i< length;++i)
        {
            cout << i+1 << ". " << race[i] << endl;
        }

        cout << endl << Player<< endl << "Select Race : ";
        cin.getline(Command, 99);
        try
        {
            ParseCommand();
            if (CommandLength==1 && IsInteger(CommandParse[0]))
            {
                int temp;
                temp = atoi(CommandParse[0].c_str());
                if (temp>=1 && temp<=4)
                {
                    Race = race[temp-1];
                    break;
                }
                else
                {
                    throw "Masukan dari 1 sampai 4";
                }
            }
            else
            {
                throw "Masukan harus integer.";
            }
        }
        catch (const char* e)
        {
            cout << e << endl;
        }
    }
}

void DunnoTactic::SelectJob(vector<string>& Job, const string& Player)
{
    int length=6;
    string job[length];
    int num = 1;
    int menu = 0;

    job[0] = "archer";
    job[1] = "assassin";
    job[2] = "knight";
    job[3] = "mage";
    job[4] = "sage";
    job[5] = "warrior";

    while (true)
    {
        cout << endl << Player << endl << "Select Caharacter Job : " << endl;
        cout << "1. Pilih Manual" << endl;
        cout << "2. Random" << endl << endl;
        cout << "Pilihan Menu : ";
        cin.getline(Command, 99);
        try
        {
            ParseCommand();
            if (CommandLength==1 && IsInteger(CommandParse[0]))
            {
                menu = atoi(CommandParse[0].c_str());

                if (menu>=1 && menu <=2)
                {
                    break;
                }
                else
                {
                    throw "Masukan harus dari 1 s.d 2.";
                }
            }
            else
            {
                throw "Masukan harus dalam integer.";
            }
        }
        catch (const char* e)
        {
            cout << e << endl;
        }
    }

    if (menu==1)
    {
    while (num<=NumberChar)
    {
        while(true)
        {
            //system("clear");
            cout << endl;
            for (int i=0;i<length;++i)
            {
                cout << i+1 << ". " << job[i] << endl;
            }
            cout << endl << Player << endl << "Select Caharacter " << num << " Job : ";
            cin.getline(Command, 99);
            try
            {
                ParseCommand();
                if (CommandLength==1 && IsInteger(CommandParse[0]))
                {
                    int temp = atoi(CommandParse[0].c_str());
                    if (temp>=1 && temp<=length)
                    {
                        Job.push_back(job[temp-1]);
                        break;
                    }
                    else
                    {
                        throw "Masukan harus 1 s.d. 6";
                    }
                }
                else
                {
                    throw "Masukan harus dalam integer.";
                }
            }
            catch(const char* e)
            {
                cout << e << endl;
            }
        }
        ++num;
    }
    }
    else
    {
        srand(time(NULL));
        for (int i=1;i<=NumberChar;++i)
        {
            int k = rand()%6;
            Job.push_back(job[k]);
            cout << "Character " << i << " job is " << job[k] << "." << endl;
        }
    }
}

void DunnoTactic::SelectCharacter()
{
    string P1Race;
    vector<string> P1Job;
    string P2Race;
    vector<string> P2Job;
    string temp;

    SelectNumCharacter();
    SelectRace(P1Race, "Player1");
    SelectJob(P1Job, "Player1");

    SelectRace(P1Race, "Player2");
    SelectJob(P2Job, "Player2");

    ConstructCharacter(P1, P1Job, P1Race, 1);
    //cout << P1[0]->GetJobName() << endl;
    RandomChacracterPosition(1, P1);
    ConstructCharacter(P2, P2Job, P2Race, 2);
    //cout << P2[1]->GetJobName() << endl;
    RandomChacracterPosition(3, P2);
    PlayerTurn = 1;
}

void DunnoTactic::Play()
{
    SelectCharacter();
    D.displayBoxMap();
    while(true)
    {
        cout << "play - Player"<<PlayerTurn<<" > ";
        cin.getline(Command, 99);
        try
        {
            ParseCommand();
            if (CommandLength==1 && CommandParse[0]=="exit")
            {
                break;
            }
            else if (CommandLength==1 && CommandParse[0]=="endturn")
            {
                cout << "Player "<< PlayerTurn <<" turn is Over." << endl;
                if (PlayerTurn==1)
                    ++PlayerTurn;
                else
                    --PlayerTurn;
            }
            else if (CommandLength==2 && CommandParse[0]=="list")
            {
                if (CommandParse[1]=="all")
                {
                    
                }
                else if (CommandParse[1]=="enemy")
                {

                }
                else if (CommandParse[1]=="ally")
                {

                }
                else
                {
                    throw "Perintah tidak ditemukan.";
                }
                for(int i=0;i<CommandLength;++i)
                {
                    cout << CommandParse[i] << " ";
                }
                cout << endl;
            }
            else if ((CommandLength==2 || CommandLength==3) && CommandParse[0]=="select")
            {
                for(int i=0;i<CommandLength;++i)
                {
                    cout << CommandParse[i] << " ";
                }
                cout << endl;
                Select(atoi(CommandParse[1].c_str()));
            }
            else if (CommandLength==3 && CommandParse[0]=="highlight")
            {
                for(int i=0;i<CommandLength;++i)
                {
                    cout << CommandParse[i] << " ";
                }
                cout << endl;
            }
            else if (CommandLength==1 && CommandParse[0]=="clear")
            {
                system(CommandParse[0].c_str());
            }
            else if (CommandLength==1 && CommandParse[0]=="help")
            {
                cout << endl;
            }
            else
            {
                throw "Perintah tidak ditemukan.";
            }
        }
        catch(const char *e)
        {
            cout << e << endl;
        }
    }
}

void DunnoTactic::Select(const int &id)
{
    while (true)
    {
        cout << id << " > ";
        cin.getline(Command, 99);
        try
        {
            ParseCommand();
            if (CommandLength==1 && CommandParse[0]=="cancel")
            {
                break;
            }
            if (CommandLength==1 && CommandParse[0]=="wait")
            {
                cout << "Wait" << endl;
                break;
            }
            else if (!(CommandLength==1 && (CommandParse[0]=="move" || CommandParse[0]=="attack" || CommandParse[0]=="special")))
            {
                throw "Perintah tidak ditemukan.";
            }

            Action(id, CommandParse[0]);
            
        }
        catch(const char* e)
        {
            cout << e << endl;
        }
    }
}

void DunnoTactic::Action(const int& id, string s)
{
    while(true)
    {
        cout << id << " - " << s << " > ";
        cin.getline(Command, 99);
        try
        {
            ParseCommand();
            if(CommandLength==1 && CommandParse[0]=="cancel")
            {
                break;
            }
            else if (CommandLength==2)
            {
                cout << CommandParse[0] << " " << CommandParse[1] << endl;
                break;
            }
            else
            {
                throw "Perintah tidak ditemukan.";
            }
        }
        catch(const char* e)
        {
            cout << e << endl;
        }
    }
}

void DunnoTactic::ParseCommand()
{
    int i=0;
    int j=0;
    int barket=0;
    int petik=0;
    char take[100];
    CommandLength = 0;

    StringToLower(Command);

    while (Command[i]==' ' || Command[i]=='(' || Command[i]==')' || Command[i]=='\"')
    {
        if (Command[i]=='(')
        {
            ++barket;
        }
        if (Command[i]==')')
        {
            --barket;
        }
        if (Command[i]=='\"')
        {
            ++petik;
        }
        ++i;
    }

    while (Command[i]!='\0' && Command[i]!='#')
    {
        if (Command[i]==' '  || Command[i]=='(' || Command[i]==')' || Command[i]=='\"')
        {
            while (Command[i]==' ' || Command[i]=='(' || Command[i]==')' || Command[i]=='\"')
            {
                 if (Command[i]=='(')
                 {
                     ++barket;
                 }
                 if (Command[i]==')')
                 {
                     --barket;
                 }
                 if (Command[i]=='\"')
                 {
                     ++petik;
                 }
                 ++i;
            }
            
            take[j]='\0';
            CommandParse[CommandLength++] = string(take);

            j = 0;
            if (Command[i]=='#' || Command[i]=='\0')
            {
                break;
            }
        }

        take[j] = Command[i];
        ++j; ++i;
    }

    if (Command[i]=='#')
    {
        if(j>0)
        {
            take[j]='\0';
            CommandParse[CommandLength++] = string(take);
        }
        
    }
    else
    {
        throw "Perintah tidak diakhiri dengan #.";
    }

    if (barket!=0)
    {
        throw "Jumlah kurung kurang lengkap.";
    }

    if (petik%2!=0)
    {
        throw "Jumlah petik kurang lengkap.";
    }
}

void DunnoTactic::StringToLower(char* s)
{
    int i = 0;

    while (s[i]!='\0')
    {
        s[i] = tolower(s[i]);
        ++i;
    }
}

bool DunnoTactic::IsInteger(string &s)
{
    for(int i=0;i<s.length();++i)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }

    return true;
}

string DunnoTactic::ToString(const int& n)
{
    ostringstream out;
    out << n;
    return out.str();
}

Job* DunnoTactic::GetCharacter(int X, int Y)
{
    vector<Job*>::iterator i;
    vector<Job*>::iterator end;
    end = P1.end();

    for (i = P1.begin();i!=end;++i)
    {
        if ((*i)->GetX()==X && (*i)->GetY()==Y)
        {
            return *i;
        }
    }

    end = P2.end();
    for (i = P2.begin();i!=end;++i)
    {
        if ((*i)->GetX()==X && (*i)->GetY()==Y)
        {
            return *i;
        }
    }
    
    return NULL;

}