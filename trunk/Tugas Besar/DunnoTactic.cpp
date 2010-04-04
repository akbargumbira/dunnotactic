/* 
 * File:   DunnoTactic.cpp
 * Author: rezanachmad
 * 
 * Created on March 29, 2010, 10:47 AM
 */

#include <stdlib.h>

#include "DunnoTactic.h"

char DunnoTactic::Command[100];
string DunnoTactic::CommandParse[10];
int DunnoTactic::CommandLength;
vector<Job*> DunnoTactic::P1;
vector<Job*> DunnoTactic::P2;
Map DunnoTactic::M;

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
                if (!IsInteger(CommandParse[1]) || !IsInteger(CommandParse[2]) || !IsInteger(CommandParse[3]))
                {
                    throw "Posisi harus dalam integer.";
                }
                int x = atoi(CommandParse[1].c_str());
                int y = atoi(CommandParse[2].c_str());
                int n = atoi(CommandParse[3].c_str());
                M.SetTerrainXY(x, y, n);
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
                int n = atoi(CommandParse[5].c_str());
                M.SetTerrainArea(x,y,x1,y1,n);
            }
            else if (CommandLength==2 && CommandParse[0]=="edit" && CommandParse[1]=="random")
            {
                M.SetMapRandom();
            }
            else if (CommandLength==1 && CommandParse[0]=="exit")
            {
                break;
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

void DunnoTactic::Play()
{
    while(true)
    {
        cout << "play > ";
        cin.getline(Command, 99);
        try
        {
            ParseCommand();
            if (CommandLength==1 && CommandParse[0]=="exit")
            {
                break;
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
            else if (!(CommandLength==1 && (CommandParse[0]=="move" || CommandParse[0]=="wait" || CommandParse[0]=="attack" || CommandParse[0]=="special")))
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
    char take[100];
    CommandLength = 0;

    StringToLower(Command);

    while (Command[i]==' ' || Command[i]=='(' || Command[i]==')')
    {
        if (Command[i]=='(')
        {
            ++barket;
        }
        if (Command[i]==')')
        {
            --barket;
        }
        ++i;
    }

    while (Command[i]!='\0' && Command[i]!='#')
    {
        if (Command[i]==' '  || Command[i]=='(' || Command[i]==')')
        {
            while (Command[i]==' ' || Command[i]=='(' || Command[i]==')')
            {
                 if (Command[i]=='(')
                 {
                     ++barket;
                 }
                 if (Command[i]==')')
                 {
                     --barket;
                 }
                 ++i;
            }
            
            take[j]='\0';
            CommandParse[CommandLength++] = string(take);

            j = 0;
            if (Command[i]=='#')
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