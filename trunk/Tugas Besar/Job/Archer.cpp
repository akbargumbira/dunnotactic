//File: Archer.cpp
//Implementasi kelas Archer

#include "Archer.h"

Archer::Archer(){}

Archer::Archer(const string& RaceName) : Job(RaceName){

	Name 	   = "";
	JobName	   = "Archer";
	AttackPoint= int(AttackPoint*1);
	Defense    = int(Defense*0.8);
	Acc	       = int(Acc*1.4);
	Evade      = int(Evade*1.4);
	RangeMove  += 1;
	RangeAttack+= 6;
	HP         = int(HP*1);
	SP         = int(SP*1.2);
	HPDefault  = HP;
	SPDefault  = SP;

}
Archer::Archer(const Archer& k){
	
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
Archer::~Archer(){
		
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
void Archer::Special (Job &Target) {
	
}

