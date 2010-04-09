#ifndef display_H
#define display_H

#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

class Display {
	public:
		// constructor
		Display();
		// copy constructor
		Display(const Display&);
		// operator assignment
		Display& operator= (const Display&);
		// destructor
		~Display();
		
		// method
		void displayBoxTurn(int Turn);
		void displayBoxTurnWithName(string Name);
		void displayBoxMap();
                void displayBoxInfo();
		void setAreaMove(int initX, int initY, int range);
                void setAreaAttack(int x, int y, int range);
		void MoveAnimated(int initX, int initY, int targetX, int targetY);
                void SelectGrid(int x, int y);
                void HighlightGrid(int x, int y);
                // method get dan set
                void SetInfo(string Infox, int id);
                void SetMapPlayer(int x,int y,int id);
                string GetInfo(int id);
                int GetMapPlayer(int x, int y);
                
		
	private:
		// data member
		int MapPlayer[30][30];
		int MapArea[30][30];
                string Info[9];
                int pointerX;
                int pointerY;
		
		// private method
                void color(string text, string bg);
                void printCursor();
                bool PassTerrain(int x, int y);
		bool PassPlayer(int x1, int y1, int x2, int y2);
                void printTerrain(int x, int y);
                void printPlayer(int x, int y, int line);
                void setDistanceMove(int x, int y, int range);
		int Min2(int a, int b);
		int MinAround(int x, int y);
		bool IsTree(int x, int y);
		bool IsWater(int x, int y);
		bool IsLumpur(int x, int y);
		int IdPlayer(int x, int y);
		bool IsFriend(int x1, int y1, int x2, int y2);
		
};

#endif
