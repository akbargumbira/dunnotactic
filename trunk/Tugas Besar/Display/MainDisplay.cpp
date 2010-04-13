#include "Display.h"
#include "../Job/Job.h"
#include "../Job/Archer.h"
#include "../DunnoTactic.h"

int main() {

	Display d;
        string Info[9];
        DunnoTactic::P1.push_back(new Archer("human"));
        try{
	DunnoTactic::P1[0]->SetXY(5,5);
	d.setAreaMove(5,5,4);
        d.MoveAnimated(5,5,5,2);
	cout << endl << endl;
	
        }
        catch (const char* e)
        {
            cout << e << endl;

        }
	return 0;
}
