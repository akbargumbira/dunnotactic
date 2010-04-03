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
/*
 * 
 */
int main(int argc, char** argv) {
    DunnoTactic::Main();
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
    return (EXIT_SUCCESS);
}

