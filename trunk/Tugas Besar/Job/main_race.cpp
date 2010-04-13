#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "Knight.h"
#include "Archer.h"
#include "Mage.h"
#include "Sage.h"
#include "Warrior.h"
#include "Assassin.h"

using namespace std;
vector<Job *> Player;
vector<Job *> Enemy;
vector<Job *>::iterator i;
Job * obj_job;
Job * obj_job2;

int main (){
try {

Player.push_back(new Archer ("human"));
Player.push_back(new Knight("orc"));

i = Player.begin();
obj_job  = *i;				
obj_job->SetName("Terra");
i = Player.begin()+1;
obj_job  = *i;
obj_job->SetName("Amaterasu");	

cout<<"Status masing - masing :"<<endl<<endl;
i = Player.begin();
obj_job  = *i;
cout<<obj_job->GetName()<<" / "<< obj_job->GetJobName()<<" / "<<obj_job->GetRaceName()<<endl;
cout<<"HP = "<< obj_job->GetHP ()<< "/"<<obj_job->GetHPDefault ()<< " SP = "<< obj_job->GetSP ()<< "/"<<obj_job->GetSPDefault ()<<endl;
cout<<"Attack point  = "<< obj_job->GetAttackPoint ()<<endl;
cout<<"Defense point = "<< obj_job->GetDefensePoint ()<<endl;
cout<<"Attack point  = "<< obj_job->GetAttackPoint ()<<endl;
cout<<"Accuracy      = "<< obj_job->GetAcc()<<endl;
cout<<"Evade         = "<< obj_job->GetAttackPoint ()<<endl;
cout<<"Range Move    = "<< obj_job->GetRangeMove ()<<endl;
cout<<"Range Attck   = "<< obj_job->GetRangeAttack ()<<endl<<endl;
cout<<"Special       = "<< obj_job->ShowSpecialArray()<<endl<<endl;
i = Player.begin()+1;
obj_job  = *i;
cout<<obj_job->GetName()<<" / "<< obj_job->GetJobName()<<" / "<<obj_job->GetRaceName()<<endl;
cout<<"HP = "<< obj_job->GetHP ()<< "/"<<obj_job->GetHPDefault ()<< " SP = "<< obj_job->GetSP ()<< "/"<<obj_job->GetSPDefault ()<<endl;
cout<<"Attack point  = "<< obj_job->GetAttackPoint ()<<endl;
cout<<"Defense point = "<< obj_job->GetDefensePoint ()<<endl;
cout<<"Attack point  = "<< obj_job->GetAttackPoint ()<<endl;
cout<<"Accuracy      = "<< obj_job->GetAcc()<<endl;
cout<<"Evade         = "<< obj_job->GetAttackPoint ()<<endl;
cout<<"Range Move    = "<< obj_job->GetRangeMove ()<<endl;
cout<<"Range Attck   = "<< obj_job->GetRangeAttack ()<<endl<<endl;
cout<<"Special       = "<< obj_job->ShowSpecialArray()<<endl<<endl<<endl;

i = Player.begin();
obj_job  = *i;
i = Player.begin()+1;
obj_job2  = *i;

cout<<"Terra Attack Amaterasu"<<endl;
obj_job->Attack (*obj_job2);
cout<<endl<<"Status Terra"<<endl;
cout<<obj_job->GetName()<<" / "<< obj_job->GetJobName()<<" / "<<obj_job->GetRaceName()<<endl;
cout<<"HP = "<< obj_job->GetHP ()<< "/"<<obj_job->GetHPDefault ()<< " SP = "<< obj_job->GetSP ()<< "/"<<obj_job->GetSPDefault ()<<endl<<endl;
cout<<endl<<"Status Amaterasu"<<endl;
cout<<obj_job2->GetName()<<" / "<< obj_job2->GetJobName()<<" / "<<obj_job2->GetRaceName()<<endl;
cout<<"HP = "<< obj_job2->GetHP ()<< "/"<<obj_job2->GetHPDefault ()<< " SP = "<< obj_job2->GetSP ()<< "/"<<obj_job2->GetSPDefault ()<<endl<<endl;

cout<<"Terra Mengisi SP 100"<<endl;
obj_job->SetSP(100);
cout<<obj_job->GetName()<<" / "<< obj_job->GetJobName()<<" / "<<obj_job->GetRaceName()<<endl;
cout<<"HP = "<< obj_job->GetHP ()<< "/"<<obj_job->GetHPDefault ()<< " SP = "<< obj_job->GetSP ()<< "/"<<obj_job->GetSPDefault ()<<endl<<endl;
cout<<"Terra Special Amaterasu"<<endl;
obj_job->SetAttackTurn(false);
//obj_job->Special(1,*obj_job2);
cout<<endl<<"Terra wait"<<endl;
cout<<"Status Terra"<<endl;
cout<<obj_job->GetName()<<" / "<< obj_job->GetJobName()<<" / "<<obj_job->GetRaceName()<<endl;
cout<<"HP = "<< obj_job->GetHP ()<< "/"<<obj_job->GetHPDefault ()<< " SP = "<< obj_job->GetSP ()<< "/"<<obj_job->GetSPDefault ()<<endl<<endl;
cout<<endl<<"Status Amaterasu"<<endl;
cout<<obj_job2->GetName()<<" / "<< obj_job2->GetJobName()<<" / "<<obj_job2->GetRaceName()<<endl;
cout<<"HP = "<< obj_job2->GetHP ()<< "/"<<obj_job2->GetHPDefault ()<< " SP = "<< obj_job2->GetSP ()<< "/"<<obj_job2->GetSPDefault ()<<endl<<endl;

obj_job->Wait();
obj_job->Status();
}
catch (const char* e)
{
cout << e << endl;
}



return 0;}
    

