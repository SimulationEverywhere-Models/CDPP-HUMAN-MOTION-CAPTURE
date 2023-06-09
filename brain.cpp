/*******************************************************************
*
*  DESCRIPTION: Atomicf Model PC
*
*  AUTHOR: Seyed Ali Etemad
*
*  EMAIL: mailto://etemad@sce.carleton.ca
*
*  DATE: 11/12/2009
*
*******************************************************************/

/** include files **/
#include "brain.h"      // class Queue
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )
#include <fstream>
#include <sstream>
#include <string>

/** public functions **/

/*******************************************************************
* Function Name: Brain
********************************************************************/
Brain::Brain( const string &name )
: Atomic( name )
, input( addInputPort( "input" ) )
, current( addInputPort( "current" ) )
, brainout( addOutputPort( "brainout" ) )
, preparationTime( 0, 0, 0, 40 )
{
	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	if( time != "" )
		preparationTime = time ;


  ifstream in("matrix.in", ios::in);
  if(!in) {
    cout << "Cannot open file.\n";
    return ;
  }

  double t1;
  for(int i=0 ;i < 45; i++){
	for (int j = 0;!in.eof() &&  j < 81; j++){
		in >> t1;
		walk1[i][j]=t1;//insert in array
//		cout<<walk1[i][j]<<" ";
	}// end for
//	cout<<"\n";
  }//end for

in.close();

//	for (int j = 0; j < 81; j++){
//		cout<<"00:00:01:10  input  "<<walk1[8][j]<<"\n";
//	}// end for





}

/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &Brain::initFunction()
{
	state = rcv_in;
	counter=0;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
********************************************************************/
Model &Brain::externalFunction( const ExternalMessage &msg )
{
	int j;
		bool found = false;
		if( state == rcv_in && msg.port() == input && counter < 81)
			{
			input_mat[counter] = msg.value();
			counter++;

			if (counter == 81){
				for (int i = 0; i < 45; i++){
					for (j = 0; j < 81; j++){
					//cout<<"input_mat["<<j<<"]: "<<input_mat[j]<<"!="<<walk1[i][j]<<" :walk["<<i<<"]["<<j<<"]\n";
						if (input_mat[j]!=walk1[i][j]){
							break;
						}
					}
					//cout<<"j: "<<j<<"\n";
					if (j == 81){
					found = true;
					//cout<<"I'm here, index_out: "<<index_out<<"\n";
					index_out = i+1;
					break;
					}
				}
			holdIn( active, preparationTime );
			state = rcv_in;
			counter = 0;
			found = false;
			}
			}

		else if( state == rcv_stat && msg.port() == current )
			{
			state = rcv_in;
			passivate();
			}


	return *this;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &Brain::internalFunction( const InternalMessage & )
{
	if (state == rcv_in ){
		index_out++;
		if (index_out == 45){
			state = rcv_stat;
			passivate();
		}
		else if (index_out < 45){
			holdIn( active, preparationTime );
		}
	}

	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &Brain::outputFunction( const InternalMessage &msg )
{
	for (int i = 0; i < 81; i++){
		sendOutput( msg.time(), brainout, walk1[index_out][i] );
	}


	return *this ;
}

