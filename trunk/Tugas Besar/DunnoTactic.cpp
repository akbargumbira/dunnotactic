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
int DunnoTactic::WinPlayer = 0;
Job* DunnoTactic::CurrenctChar;

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
    cout << Race << endl;
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
        A = 101;
    else
        A = 501;

    for (int i=0;i<NumberChar;++i)
    {
        P[i]->SetID(A+i);
        cout << "ID " <<P[i]->GetID()<<endl;;
    }
}

void DunnoTactic::RandomChacracterPosition(int kuadran, vector<Job*> &P)
{
    int i=0;
    int temp;
    Point tempPoint;
    vector<Point> Available;
    vector<Point>::iterator iter;
    
    for (int i=1;i<=M.GetSizeX();++i)
    {
        for (int j=1;j<=M.GetSizeY();++j)
        {
            if (M.GetTerrain(i,j)!=2 && M.GetTerrain(i,j)!=4 && D.GetMapPlayer(i,j)==0)
            {
                Available.push_back({i, j});
            }
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
    
    race[0] = "human";
    race[1] = "elf";
    race[2] = "fairy";
    race[3] = "orc";

    cout << endl;
    for (int i = 0 ;i< length;++i)
    {
        cout << i+1 << ". " << race[i] << endl;
    }

    while(true)
    {
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
                    throw "Masukan harus dari 1 sampai 4.";
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
    
    cout << "1. Pilih Manual" << endl;
    cout << "2. Random" << endl << endl;
    
    while (true)
    {
        cout << endl << Player << endl;
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

    SelectRace(P2Race, "Player2");
    SelectJob(P2Job, "Player2");

    ConstructCharacter(P1, P1Job, P1Race, 1);
    RandomChacracterPosition(1, P1);
    ConstructCharacter(P2, P2Job, P2Race, 2);
    RandomChacracterPosition(3, P2);
    PlayerTurn = 1;
}

void DunnoTactic::DesructCharacter()
{
    vector<Job*>::const_iterator i;
    vector<Job*>::const_iterator end;


    end = P1.end();
    for(i=P1.begin();i!=end;++i)
    {
        delete(*i);
    }
    P1.erase(P1.begin(), P1.end());


    end = P2.end();
    for(i=P2.begin();i!=end;++i)
    {
        delete(*i);
    }
    P2.erase(P2.begin(), P2.end());

    D.clearPlayer();
}

void DunnoTactic::Play()
{
    bool info=false;
    int CountP1Turn=0;
    int CountP2Turn=0;
    SelectCharacter();
    /*for (int i=0;i<P1.size();++i)
    {
        cout <<i+1<<". " << P1[i]->GetX() << " " << P1[i]->GetY() << endl;
    }
    for (int i=0;i<P2.size();++i)
    {
        cout <<i+1<<". " << P2[i]->GetX() << " " << P2[i]->GetY() << endl;
    }*/
    while(true)
    {
        if(!info) {
            D.clearArea();
            D.displayGame();
        }
        info = false;
        if (IsGameOver()) {
            cout << "GameOver" << endl;
            cout << "Player " << WinPlayer << " Win." << endl;
            break;
        }
        cout << "play - Player"<<PlayerTurn<<" > ";
        cin.getline(Command, 99);
        try
        {
            ParseCommand();
            if (CommandLength==1 && CommandParse[0]=="exit")
            {
                DesructCharacter();
                break;
            }
            else if (CommandLength==1 && CommandParse[0]=="endturn")
            {
                cout << "Player "<< PlayerTurn <<" turn is Over." << endl;
                if (PlayerTurn==1) {
                    ++PlayerTurn;
                    ++CountP1Turn;
                } else {
                    --PlayerTurn;
                    ++CountP2Turn;
                }

                if(PlayerTurn==1) {
                    for(int i=0;i<P1.size();++i) {
                        P1[i]->SetAttackTurn(false);
                        P1[i]->SetMoveTurn(false);
                        if (!P1[i]->GetDeath()) {
                            P1[i]->SetEnable(true);
                        }
                        if (CountP1Turn>0) {
                            P1[i]->SetSP(P1[i]->GetSP()+20);
                        }
                    }
                } else {
                    for(int i=0;i<P2.size();++i) {
                        P2[i]->SetAttackTurn(false);
                        P2[i]->SetMoveTurn(false);
                        if (!P2[i]->GetDeath()) {
                            P2[i]->SetEnable(true);
                        }
                        if (CountP2Turn>0) {
                            P2[i]->SetSP(P2[i]->GetSP()+20);
                        }
                    }
                }
            }
            else if (CommandLength==2 && CommandParse[0]=="list")
            {
                if (CommandParse[1]=="all")
                {
                    ListAll(PlayerTurn);
                }
                else if (CommandParse[1]=="enemy")
                {
                    List(PlayerTurn, CommandParse[1]);
                }
                else if (CommandParse[1]=="ally")
                {
                    List(PlayerTurn, CommandParse[1]);
                }
                else
                {
                    throw "Perintah tidak ditemukan.";
                }
                info=true;
            }
            else if ((CommandLength==2 || CommandLength==3) && CommandParse[0]=="select")
            {
                if (CommandLength==2 && IsInteger(CommandParse[1]))
                {
                    int tempID = atoi(CommandParse[1].c_str());
                    CurrenctChar = GetCharacter(tempID);
                    Select();
                }
                else if (CommandLength==3 && IsInteger(CommandParse[1]) && IsInteger(CommandParse[2]))
                {
                    int tempX = atoi(CommandParse[1].c_str());
                    int tempY = atoi(CommandParse[2].c_str());;
                    CurrenctChar = GetCharacter(tempX, tempY);
                    Select();
                }
                else
                {
                    throw "Parameter harus integer.";
                }
            }
            else if (CommandLength==3 && CommandParse[0]=="highlight")
            {
                if (IsInteger(CommandParse[1])&&IsInteger(CommandParse[2]))
                {
                    int tempX = atoi(CommandParse[1].c_str());
                    int tempY = atoi(CommandParse[2].c_str());
                    D.HighlightGrid(tempX, tempY);
                }
                else
                {
                    throw "Masukan harus integer.";
                }
            }
            else if (CommandLength==1 && CommandParse[0]=="clear")
            {
                system(CommandParse[0].c_str());
            }
            else if (CommandLength==1 && CommandParse[0]=="help")
            {
                cout << "endturn            Mengakhiri giliran."<< endl;
                cout << "list all           Melihat seluruh karakter."<< endl;
                cout << "list ally          Melihat karakter milik Anda."<< endl;
                cout << "list enemt         Melihat karakter lawan." << endl;
                cout << "select x y         Memilih karakter yang berada pada posisi (x,y)."<<endl;
                cout << "highlight x y      Melihat informasi yang ada pada grid (x,y)."<<endl;
                cout << "exit               Keluar dari permainan."<<endl;
                cout << "clear              Membersihkan layar."<<endl;
                cout << "help               Menampilkan bantuan ini."<<endl;
                info=true;
            }
            else
            {
                throw "Perintah tidak ditemukan.";
            }
        }
        catch(const char *e)
        {
            D.SetInfo(e,0);
            D.SetInfo("",1);
        }
    }
}

void DunnoTactic::Select()
{
    if (CurrenctChar->GetDeath()) {
        throw "Karakter telah mati.";
    }
    int ID = CurrenctChar->GetID();
    if ((ID>=101 && ID<=500 && PlayerTurn==1) || (ID>=501 && ID<=999 && PlayerTurn==2)) {
        if (!CurrenctChar->GetEnable())
        {
            throw "Karakter tidak bisa dipilih. Tunggu giliran berikutnya.";
        }
    } else {
        throw "Salah pilih. Perhatikan Karakter milik player siapa.";
    }
    D.HighlightGrid(CurrenctChar->GetX(), CurrenctChar->GetY());
    int tempX = CurrenctChar->GetX();
    int tempY = CurrenctChar->GetY();

    while (true)
    {
        if (IsGameOver())
            break;
        
        cout << "Player" << PlayerTurn << " - " << CurrenctChar->GetID() << " > ";
        cin.getline(Command, 99);
        try
        {
            ParseCommand();
            if (CommandLength==1 && CommandParse[0]=="cancel")
            {
                if (CurrenctChar->GetAttackTurn()) {
                    throw "Tidak bisa melakukan cancel, karakter telah menyerang.";
                } else {
                    D.SetMapPlayer(CurrenctChar->GetX(), CurrenctChar->GetY(), 0);
                    CurrenctChar->SetXY(tempX, tempY);
                    D.SetMapPlayer(CurrenctChar->GetX(), CurrenctChar->GetY(), CurrenctChar->GetID());
                    CurrenctChar->SetMoveTurn(false);
                    break;
                }
            }
            if (CommandLength==1 && CommandParse[0]=="wait")
            {
                CurrenctChar->Wait();
                break;
            }
            else if(CommandLength==1 && CommandParse[0]=="move")
            {
                if (CurrenctChar->GetMoveTurn()) {
                    throw "Sebelumnya karakter telah bergerak.";
                } else {
                    D.SelectMove(CurrenctChar->GetX(), CurrenctChar->GetY());
                    Move();
                }
            }
            else if (CommandLength==1 && CommandParse[0]=="attack")
            {
                if (CurrenctChar->GetAttackTurn()) {
                    throw "Sebelumnya karakter telah melakukan serangan.";
                } else {
                    D.SelectAttack(CurrenctChar->GetX(), CurrenctChar->GetY());
                    Attack();
                }
            }
            else if (CommandLength==1 && CommandParse[0]=="special")
            {
                if (CurrenctChar->GetAttackTurn()) {
                    throw "Sebelumnya karakter telah melakukan seranagan.";
                } else {
                    D.SelectAttack(CurrenctChar->GetX(), CurrenctChar->GetY());
                    Special();
                }
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

void DunnoTactic::Move()
{
    while (true) {
        cout << "Player" << PlayerTurn << " - " << CurrenctChar->GetID() << " - Move > ";
        cin.getline(Command, 99);
        try {
            ParseCommand();
            if (CommandLength==1 && CommandParse[0]=="cancel") {
                break;
            } else if (CommandLength==2) {
                if (IsInteger(CommandParse[0]) && IsInteger(CommandParse[1])) {
                    int tempX,tempY;
                    tempX = atoi(CommandParse[0].c_str());
                    tempY = atoi(CommandParse[1].c_str());
                    CurrenctChar->Move(tempX, tempY);
                    break;
                } else {
                    throw "Masukan harus integer.";
                }
            } else {
                throw "Perintah tidak ditemukan.";
            }
        } catch(const char* e) {
            cout << e << endl;
        }
    }
}

void DunnoTactic::Attack() {
    while (true) {
        cout << "Player" << PlayerTurn << " - " << CurrenctChar->GetID() << " - Attack > ";
        cin.getline(Command, 99);
        try {
            ParseCommand();
            if (CommandLength==1 && CommandParse[0]=="cancel") {
                break;
            } else if (CommandLength==2) {
                if (IsInteger(CommandParse[0]) && IsInteger(CommandParse[1])) {
                    int tempX,tempY;
                    tempX = atoi(CommandParse[0].c_str());
                    tempY = atoi(CommandParse[1].c_str());
                    CurrenctChar->Attack(tempX, tempY);
                    break;
                } else {
                    throw "Masukan harus integer.";
                }
            } else {
                throw "Perintah tidak ditemukan.";
            }
        } catch(const char* e) {
            cout << e << endl;
        }
    }
}

void DunnoTactic::Special() {
    int length = CurrenctChar->ShowSpecialArray();
    int pilihan=0;
    cout << endl;
    while(true)  {
        cout << "Player" << PlayerTurn << " - " << CurrenctChar->GetID() << endl;
        cout << "Pilih Special : ";
        cin.getline(Command,99);
        try {
            ParseCommand();
            if (CommandLength==1 && IsInteger(CommandParse[0])) {
                pilihan = atoi(CommandParse[0].c_str());
                if (pilihan < 1 || pilihan > length) {
                    throw "Pilihan diluar jangkuan.";
                } else {
                    break;
                }
            } else {
                throw "Masukan harus integer.";
            }
        } catch (const char* e) {
            cout << e << endl;
        }
    }
    
    while (true) {
        cout << "Player" << PlayerTurn << " - " << CurrenctChar->GetID() << " - Special > ";
        cin.getline(Command, 99);
        try {
            ParseCommand();
            if (CommandLength==1 && CommandParse[0]=="cancel") {
                break;
            } else if (CommandLength==2) {
                if (IsInteger(CommandParse[0]) && IsInteger(CommandParse[1])) {
                    int tempX,tempY;
                    tempX = atoi(CommandParse[0].c_str());
                    tempY = atoi(CommandParse[1].c_str());
                    CurrenctChar->Special(tempX, tempY, pilihan);
                    break;
                } else {
                    throw "Masukan harus integer.";
                }
            } else {
                throw "Perintah tidak ditemukan.";
            }
        } catch(const char* e) {
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
    
    string err = "Error GetCharacter. Tidak ditemukan karakter pada posisi ("+ToString(X)+","+ToString(Y)+").";
    throw err.c_str();
}

Job* DunnoTactic::GetCharacter(int id)
{
    vector<Job*>::iterator i;
    vector<Job*>::iterator end;
    end = P1.end();

    for (i = P1.begin();i!=end;++i)
    {
        if ((*i)->GetID()==id)
        {
            return *i;
        }
    }

    end = P2.end();
    for (i = P2.begin();i!=end;++i)
    {
        if ((*i)->GetID()==id)
        {
            return *i;
        }
    }

    string temp = "Error GetCharacter. Karakter dengan id "+ToString(id)+" tidak ditemukan.";
    throw temp.c_str();
}

void DunnoTactic::List(int Player, string option)
{
    vector<Job*> P;
    if (Player==1)
    {
        P = P1;
        if (option=="enemy")
        {
            P = P2;
        }
    }
    else
    {
        P = P2;
        if (option=="enemy")
        {
            P = P1;
        }
    }

    cout << "Race : " << P[0]->GetRaceName()<< endl;
    cout << "Id \\ Job Name \\ Position \\ HP(HPDefault) \\ SP(SPDefault)"<< endl;
    for(int i=0;i<P.size();++i)
    {
        cout << P[i]->GetID() << " \\ " << P[i]->GetJobName()<< " \\ (" << P[i]->GetX()<< "," << P[i]->GetY() << ") \\ " << P[i]->GetHP();
        cout <<"("<<P[i]->GetHPDefault()<<") \\ "<<P[i]->GetSP()<<"("<<P[i]->GetSPDefault()<<")"<<endl;
    }
}

void DunnoTactic::ListAll(int Player)
{
    cout <<"Ally : "<<endl;
    List(Player, "ally");
    cout << endl <<"Enemy"<<endl;
    List(Player, "enemy");
}

bool DunnoTactic::IsGameOver() {
    int count1 = 0, count2=0;
    for (int i=0;i<NumberChar;++i)
    {
        if (P1[i]->GetDeath()) {
            ++count1;
        }
        if (P2[i]->GetDeath()) {
            ++count2;
        }
    }

    if (count1==NumberChar) {
        WinPlayer=2;
        return true;
    } else if(count2==NumberChar) {
        WinPlayer=1;
        return true;
    }

    return false;
}