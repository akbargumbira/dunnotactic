#ifndef _Job_H
#define _Job_H

#include <iostream>
#include <string>
#include <stdlib.h>
//Job, merupakan penambahan attribut untuk suatu Job yang dipilih
using namespace std;
class Job {
protected :
 
      int       ID;
      string    Name;
	  string 	JobName;
	  string 	RaceName;
      
      //attribut
      int       AttackPoint;
      int       Defense;
      int       Acc;
      int       Evade;
      float     SpecialBonus;
      int       RangeMove;
      int       RangeAttack;
      
      int       HP;
	  int		HPDefault;
      int       SP;
	  int		SPDefault;
	  Job*		Enemy[10];
      
      //Kordinat karakter
      int       X;
      int       Y; 	        
 
 public :
      //METHOD
      //Constructor dan destructor
      Job ();
	  Job (const string&);
      virtual ~Job ();
      
      //Attribute
      int GetAttackPoint ();     //mengembalikan nilai attack_point
      int GetDefensePoint ();    //mengembalikan nilai defense_point
      int GetAcc ();             //mengembalikan nilai acc
      int GetEvade ();           //mengembalikan nilai evade
      float GetSpecialBonus ();  //mengembalikan nilai spsial_bonus
      int GetRangeMove ();       //mengembalikan nilai range_move
      int GetRangeAttack();      //mengembalikan nilai range_attack
      int GetHP();               //mengembalikan nilai HP
      int GetSP();               //mengembalikan nilai SP
	  int GetHPDefault();
	  int GetSPDefault();
	  string GetName();
	  string GetJobName();
	  void SetName(const string&);
	  
	  //Method Lain	  
	  int RangeCostAxis(const int &);
	  int RangeCostOrdinat (const int &);
	  void SetEnemy (Job &);	
      
      //Posisi
      int GetX ();               //mengembalikan nilai X
      int GetY ();               //mengembalikan nilai Y
      
      //Method Karakter
	  void Move (const int &, const int &);
	  void Attack (Job &Target);
      void ReceiveAttack (const int& );
      void ReceiveHP (const int& );
	  virtual void Special (Job &Target);
};      
      
#endif
