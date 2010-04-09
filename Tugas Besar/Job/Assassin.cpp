//File: Assassin.cpp
//Implementasi kelas Assassin

#include "Assassin.h"

Assassin::Assassin(){}

Assassin::Assassin(const string& RaceName) : Job(RaceName){

	Name 	   = "";
	JobName	   = "Assassin";
	AttackPoint= int(AttackPoint*0.6);
	Defense    = int(Defense*1.4);
	Acc	       = int(Acc*1.6);
	Evade      = int(Evade*1.6);
	RangeMove  += 3;
	RangeAttack+= 4;
	HP         = int(HP*1);
	SP         = int(SP*1);
	HPDefault  = HP;
	SPDefault  = SP;
	AttackPointDefault = AttackPoint;
	RangeAttackDefault = RangeAttack;	
	AccDefault = Acc;
	SpecialArray[0] = "1.Hell Chain            30";
	AttackTurn = false;
	Enable     = false;
	MoveTurn   = false;
	Death	   = false;

}
Assassin::Assassin(const Assassin& k){
	
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
	AttackPointDefault = k.AttackPointDefault;
	RangeAttackDefault = k.RangeAttackDefault;	
	AccDefault = Acc;
	SpecialArray[0] = k.SpecialArray[0];
	AttackTurn = k.AttackTurn;
	Enable   = k.Enable;
	MoveTurn   = k.MoveTurn;
	Death	   = k.Death;
	
}
Assassin::~Assassin(){
		
}
void Assassin::SpecialArea (const int & SPC){
}

void Assassin::Special (const int & SPC, Job &Target) {
if (AttackTurn == false) {
	if (SPC == 1) {
		if (SP>40) {
		AttackPoint = int(AttackPoint*0.8*SpecialBonus) ; 
		RangeAttack += 2;
		Acc =int (Acc*2.3);
		Attack(Target);
		AttackPoint = AttackPointDefault;
		RangeAttack = RangeAttackDefault;
		Acc = AccDefault;
		SP	-= 40;
		AttackTurn = true;}
		else {throw "SP tidak mencukupi.";}
		}
	else {throw "Tidak ada Skill yang dimaksud!.";}
	}
}
