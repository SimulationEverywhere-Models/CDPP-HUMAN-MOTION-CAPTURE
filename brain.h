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

#ifndef __BRAIN_H
#define __BRAIN_H

//#include <list>
#include "atomic.h"     // class Atomic

class Brain : public Atomic
{
public:
	Brain( const string &name = "Brain" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &input;
	const Port &current;
	Port &brainout;
	Time preparationTime;
	int counter;
	int input_mat[81];
	int walk1[45][81];
	int index_out;
	int i;
	int j;

		enum State{
			rcv_in,
			rcv_stat,
		};
		State state;

};	// class brain

// ** inline ** //
inline
string Brain::className() const
{
	return "Brain" ;
}

#endif   //__BRAIN_H
