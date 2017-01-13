#ifndef JOCC_H_INCLUDED
#define JOCC_H_INCLUDED

#include <cstdlib>
class masa {

public:
	int vec[23];
	int i;
	int culoare[23];
	int pieseAlbe = 15, pieseNegre = 15;
	int zar1, zar2;
	void initializare();
	void setCuloare();
	void afisare();
	void culori();


};







#endif // JOCC_H_INCLUDED