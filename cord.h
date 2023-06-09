/*******************************************************************
*
*  DESCRIPTION: Atomic Model brain
*
*  AUTHOR: Seyed Ali Etemad
*
*  EMAIL: mailto://etemad@sce.carleton.ca
*
*  DATE: 11/12/2009
*
*******************************************************************/

#ifndef __CORD_H
#define __CORD_H

//#include <list>
#include "atomic.h"     // class Atomic

class Cord : public Atomic
{
public:
	Cord( const string &name = "Cord" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &brainout;
	Port &cordout1, &cordout2, &cordout3, &cordout4, &cordout5, &cordout6, &cordout7, &cordout8, &cordout9, &cordout10, &cordout11, &cordout12, &cordout13, &cordout14, &cordout15, &cordout16, &cordout17, &cordout18, &cordout19, &cordout20, &cordout21, &cordout22, &cordout23, &cordout24, &cordout25, &cordout26, &cordout27, &cordout28, &cordout29, &cordout30, &cordout31, &cordout32, &cordout33, &cordout34, &cordout35, &cordout36, &cordout37, &cordout38, &cordout39, &cordout40, &cordout41, &cordout42, &cordout43, &cordout44, &cordout45, &cordout46, &cordout47, &cordout48, &cordout49, &cordout50, &cordout51, &cordout52, &cordout53, &cordout54, &cordout55, &cordout56, &cordout57, &cordout58, &cordout59, &cordout60, &cordout61, &cordout62, &cordout63, &cordout64, &cordout65, &cordout66, &cordout67, &cordout68, &cordout69, &cordout70, &cordout71, &cordout72, &cordout73, &cordout74, &cordout75, &cordout76, &cordout77, &cordout78, &cordout79, &cordout80, &cordout81;
	Time preparationTime;
	int counter;
	int input_mat[81];

		enum State{
			wait_row,
			output_row,
		};
		State state;

};	// class cord

// ** inline ** //
inline
string Cord::className() const
{
	return "Cord" ;
}

#endif   //__CORD_H
