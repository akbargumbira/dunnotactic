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
                for(int i=0;i<4;++i)
                {
                    cout << CommandParse[i] << " ";
                }
                cout << endl;
            }
            else if (CommandLength==3 && CommandParse[0]=="load" && CommandParse[1]=="map")
            {
                for(int i=0;i<CommandLength;++i)
                {
                    cout << CommandParse[i] << " ";
                }
                cout << endl;
            }
            else if (CommandLength==3 && CommandParse[0]=="save" && CommandParse[1]=="map")
            {
                for(int i=0;i<CommandLength;++i)
                {
                    cout << CommandParse[i] << " ";
                }
                cout << endl;
            }
            else if ((CommandLength==4 || CommandLength==6) && CommandParse[0]=="edit")
            {
                for(int i=0;i<CommandLength;++i)
                {
                    cout << CommandParse[i] << " ";
                }
                cout << endl;
            }
            else if ((CommandLength==6 || CommandLength==10) && CommandParse[0]=="edit")
            {
                for(int i=0;i<CommandLength;++i)
                {
                    cout << CommandParse[i] << " ";
                }
                cout << endl;
            }
            else if (CommandLength==2 && CommandParse[0]=="edit" && CommandParse[1]=="random")
            {
                for(int i=0;i<CommandLength;++i)
                {
                    cout << CommandParse[i] << " ";
                }
                cout << endl;
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
    char take[100];
    CommandLength = 0;

    StringToLower(Command);

    while (Command[i]==' ')
    {
        ++i;
    }

    while (Command[i]!='\0' && Command[i]!='#')
    {
        if (Command[i]==' ')
        {
            while (Command[i]==' ')
            {
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
