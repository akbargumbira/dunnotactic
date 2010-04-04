#include "Display.h"

int main() {

	Display d;
	d.displayBoxTurn(1);
	d.displayBoxTurnWithName("Mukhammad Ifanto");
	d.setArea(5,5,4);
	d.displayBoxMap(15,15);
	cout << endl << endl;
	d.displayBoxInfo();
	return 0;
}
