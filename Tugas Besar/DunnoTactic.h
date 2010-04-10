/* 
 * File:   DunnoTactic.h
 * Author: rezanachmad
 *
 * Created on March 29, 2010, 10:47 AM
 */

#ifndef _DUNNOTACTIC_H
#define	_DUNNOTACTIC_H


#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <string.h>

#include "Job/Job.h"
#include "Map/Map.h"
#include "Display/Display.h"

using namespace std;

class DunnoTactic {
public:
    DunnoTactic();
    DunnoTactic(const DunnoTactic& orig);
    virtual ~DunnoTactic();

    static void Main();
    static void Play();
    static void ConstructCharacter(vector<Job*> &P, vector<string> Job, string Race, int Player);
    static void RandomChacracterPosition(int kuadran, vector<Job*> &P);
    static void SelectNumCharacter();
    static void SelectCharacter();
    static void SelectJob(vector<string> &Job, const string& Player);
    static void SelectRace(string& Race, const string& Player);
    static void Build();
    static void Select(const int &id);
    static void ParseCommand();
    static void StringToLower(char* s);
    static bool IsInteger(string &s);
    static string ToString(const int& n);
    static Job* GetCharacter(int X, int Y);
    static Job* GetCharacter(int id);
    static void ListAll(int Player);
    static void List(int Player, string option);
    static void DesructCharacter();
    struct Point {
        int X;
        int Y;
    };

    static char Command[100];
    static string CommandParse[10];
    static int CommandLength;

    static vector<Job*> P1;
    static vector<Job*> P2;

    static int NumberChar;
    static int PlayerTurn;
    static Map M;
    static Display D;
    
private:
    
};

#endif	/* _DUNNOTACTIC_H */

