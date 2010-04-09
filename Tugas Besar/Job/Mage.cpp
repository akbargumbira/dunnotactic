//File: Mage.cpp
//Implementasi kelas Mage

#include "Mage.h"

Mage::Mage(){}

Mage::Mage(const string& RaceName) : Job(RaceName){

	Name 	   = "";
	JobName	   = "Mage";
	AttackPoint= int(AttackPoint*0.8);
	Defense    = int(Defense*0.8);
	Acc	       = int(Acc*1.2);
	Evade      = int(Evade*1);
	RangeMove  += 0;
	RangeAttack+= 0;
	HP         = int(HP*0.8);
	SP         = int(SP*1.6);
	HPDefault  = HP;
	SPDefault  = SP;
	AttackPointDefault = AttackPoint;
	RangeAttackDefault = RangeAttack;	
	SpecialArray[0] = "1.Hell Fire            30";

}
Mage::Mage(const Mage& k){
	
	Name 		= k.Name;
	AttackPoint = k.AttackPoint;
	Defense 	= k.Defense;
	RangeMove 	= k.RangeMove;
	RangeAttack = k.RangeAttack;
	HP 			= k.HP;
	SP 			= k.SP;
	Acc 		= k.Acc;
	Evade	    = k.Evade;
	HPDefault   = k.HP;
	SPDefault   = k.SP;
	
}
Mage::~Mage(){
		
    Name		="";
	AttackPoint = 0;
	Defense 	= 0;
	RangeMove 	= 0;
	RangeAttack = 0;
	HP 			= 0;
	SP 			= 0;
	Acc			= 0;
	Evade		 = 0;
	
}
void Mage::SpecialArea (const string & STR){
}
void Mage::Special (const string & STR, Job &Target) {
if (STR == "Hell Fire") {
	if (SP>30) {
	AttackPoint = int(AttackPoint*2.2*SpecialBonus) ; ;
	Attack(Target);
	AttackPoint = AttackPointDefault;
	SP	-= 30;
	AttackTurn = true;}
	else {cout<<"SP tidak mencukupi"<<endl;system("pause");}
	}
else {cout<<"Tidak ada Skill yang dimaksud!"<<endl;system("pause");}
}


