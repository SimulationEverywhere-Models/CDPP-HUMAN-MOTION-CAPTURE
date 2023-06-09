/*******************************************************************
*
*  DESCRIPTION: Atomic Model body
*
*  AUTHOR: Seyed Ali Etemad
*
*  EMAIL: mailto://etemad@sce.carleton.ca
*
*  DATE: 11/12/2009
*
*******************************************************************/

#ifndef __BODY_H
#define __BODY_H

//#include <list>
#include "atomic.h"     // class Atomic

class Body : public Atomic
{
public:
	Body( const string &name = "Body" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &bodyin1, &bodyin2, &bodyin3, &bodyin4, &bodyin5, &bodyin6, &bodyin7, &bodyin8, &bodyin9, &bodyin10, &bodyin11, &bodyin12, &bodyin13, &bodyin14, &bodyin15, &bodyin16, &bodyin17, &bodyin18, &bodyin19, &bodyin20, &bodyin21, &bodyin22, &bodyin23, &bodyin24, &bodyin25, &bodyin26, &bodyin27, &bodyin28, &bodyin29, &bodyin30, &bodyin31, &bodyin32, &bodyin33, &bodyin34, &bodyin35, &bodyin36, &bodyin37, &bodyin38, &bodyin39, &bodyin40, &bodyin41, &bodyin42, &bodyin43, &bodyin44, &bodyin45, &bodyin46, &bodyin47, &bodyin48, &bodyin49, &bodyin50, &bodyin51, &bodyin52, &bodyin53, &bodyin54, &bodyin55, &bodyin56, &bodyin57, &bodyin58, &bodyin59, &bodyin60, &bodyin61, &bodyin62, &bodyin63, &bodyin64, &bodyin65, &bodyin66, &bodyin67, &bodyin68, &bodyin69, &bodyin70, &bodyin71, &bodyin72, &bodyin73, &bodyin74, &bodyin75, &bodyin76, &bodyin77, &bodyin78, &bodyin79, &bodyin80, &bodyin81;
	Port &output;
	Port &current;
	Time preparationTime;
	int counter;
	int input_mat[81];

		enum State{
			wait_row,
			output_row,
		};
		State state;

};	// class body

// ** inline ** //
inline
string Body::className() const
{
	return "Body" ;
}

#endif   //__BODY_H
