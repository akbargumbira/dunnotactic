/* 
 * File:   main.cpp
 * Author: rezanachmad
 *
 * Created on March 29, 2010, 10:46 AM
 */

#include <stdlib.h>
#include "DunnoTactic.h"
#include "Job/Knight.h"
#include "Job/Assassin.h"
#include "Map/Map.h"
/*
 * 
 */
int main(int argc, char** argv) {

    DunnoTactic::Main();
    /*
    vector<int> available;

    available.push_back(1);
    available.push_back(5);
    available.push_back(7);
    available.push_back(9);

    for (int i=0;i<available.size();++i)
    {
        cout << i << " " << available[i] << endl;
    }

    vector<int>::iterator begin = available.begin();
    begin = begin + 2;

    available.erase(begin);

    for (int i=0;i<available.size();++i)
    {
        cout << i << " " << available[i] << endl;
    }*/

/*
    DunnoTactic::P1.push_back(new Knight("human"));
    DunnoTactic::P2.push_back(new Assassin("elf"));
    DunnoTactic::P1.push_back(new Assassin("human"));

    vector<Job*>::iterator R;
    vector<Job*>::iterator S;

    R = DunnoTactic::P1.begin()+1;
    S = DunnoTactic::P2.begin();

    cout << (*R)->GetJobName() << endl;
    cout << (*R)->GetAttackPoint() << endl;
    cout << (*S)->GetHP() << endl;
    cout << (*S)->GetSP() << endl;
    cout << (*S)->GetDefensePoint() << endl;
    (*R)->Attack(*(*S));
    cout << (*S)->GetHP() << endl;
   */
/*
    Map M;
    try
    {
        M.SetMapRandom();
        //M.Save("Cob");
        M.Load("Coba");
        M.SetTerrainXY(31,31,3);
        M.Save("Voba2");
    }
    catch (const char* e)
    {
        cout << e << endl;

    }*/
    return (EXIT_SUCCESS);
}

