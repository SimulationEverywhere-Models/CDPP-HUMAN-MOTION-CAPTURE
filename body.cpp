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
#include "body.h"      // class Queue
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Body
********************************************************************/
Body::Body( const string &name )
: Atomic( name )
, bodyin1( addInputPort( "bodyin1" ) )
, bodyin2( addInputPort( "bodyin2" ) )
, bodyin3( addInputPort( "bodyin3" ) )
, bodyin4( addInputPort( "bodyin4" ) )
, bodyin5( addInputPort( "bodyin5" ) )
, bodyin6( addInputPort( "bodyin6" ) )
, bodyin7( addInputPort( "bodyin7" ) )
, bodyin8( addInputPort( "bodyin8" ) )
, bodyin9( addInputPort( "bodyin9" ) )
, bodyin10( addInputPort( "bodyin10" ) )
, bodyin11( addInputPort( "bodyin11" ) )
, bodyin12( addInputPort( "bodyin12" ) )
, bodyin13( addInputPort( "bodyin13" ) )
, bodyin14( addInputPort( "bodyin14" ) )
, bodyin15( addInputPort( "bodyin15" ) )
, bodyin16( addInputPort( "bodyin16" ) )
, bodyin17( addInputPort( "bodyin17" ) )
, bodyin18( addInputPort( "bodyin18" ) )
, bodyin19( addInputPort( "bodyin19" ) )
, bodyin20( addInputPort( "bodyin20" ) )
, bodyin21( addInputPort( "bodyin21" ) )
, bodyin22( addInputPort( "bodyin22" ) )
, bodyin23( addInputPort( "bodyin23" ) )
, bodyin24( addInputPort( "bodyin24" ) )
, bodyin25( addInputPort( "bodyin25" ) )
, bodyin26( addInputPort( "bodyin26" ) )
, bodyin27( addInputPort( "bodyin27" ) )
, bodyin28( addInputPort( "bodyin28" ) )
, bodyin29( addInputPort( "bodyin29" ) )
, bodyin30( addInputPort( "bodyin30" ) )
, bodyin31( addInputPort( "bodyin31" ) )
, bodyin32( addInputPort( "bodyin32" ) )
, bodyin33( addInputPort( "bodyin33" ) )
, bodyin34( addInputPort( "bodyin34" ) )
, bodyin35( addInputPort( "bodyin35" ) )
, bodyin36( addInputPort( "bodyin36" ) )
, bodyin37( addInputPort( "bodyin37" ) )
, bodyin38( addInputPort( "bodyin38" ) )
, bodyin39( addInputPort( "bodyin39" ) )
, bodyin40( addInputPort( "bodyin40" ) )
, bodyin41( addInputPort( "bodyin41" ) )
, bodyin42( addInputPort( "bodyin42" ) )
, bodyin43( addInputPort( "bodyin43" ) )
, bodyin44( addInputPort( "bodyin44" ) )
, bodyin45( addInputPort( "bodyin45" ) )
, bodyin46( addInputPort( "bodyin46" ) )
, bodyin47( addInputPort( "bodyin47" ) )
, bodyin48( addInputPort( "bodyin48" ) )
, bodyin49( addInputPort( "bodyin49" ) )
, bodyin50( addInputPort( "bodyin50" ) )
, bodyin51( addInputPort( "bodyin51" ) )
, bodyin52( addInputPort( "bodyin52" ) )
, bodyin53( addInputPort( "bodyin53" ) )
, bodyin54( addInputPort( "bodyin54" ) )
, bodyin55( addInputPort( "bodyin55" ) )
, bodyin56( addInputPort( "bodyin56" ) )
, bodyin57( addInputPort( "bodyin57" ) )
, bodyin58( addInputPort( "bodyin58" ) )
, bodyin59( addInputPort( "bodyin59" ) )
, bodyin60( addInputPort( "bodyin60" ) )
, bodyin61( addInputPort( "bodyin61" ) )
, bodyin62( addInputPort( "bodyin62" ) )
, bodyin63( addInputPort( "bodyin63" ) )
, bodyin64( addInputPort( "bodyin64" ) )
, bodyin65( addInputPort( "bodyin65" ) )
, bodyin66( addInputPort( "bodyin66" ) )
, bodyin67( addInputPort( "bodyin67" ) )
, bodyin68( addInputPort( "bodyin68" ) )
, bodyin69( addInputPort( "bodyin69" ) )
, bodyin70( addInputPort( "bodyin70" ) )
, bodyin71( addInputPort( "bodyin71" ) )
, bodyin72( addInputPort( "bodyin72" ) )
, bodyin73( addInputPort( "bodyin73" ) )
, bodyin74( addInputPort( "bodyin74" ) )
, bodyin75( addInputPort( "bodyin75" ) )
, bodyin76( addInputPort( "bodyin76" ) )
, bodyin77( addInputPort( "bodyin77" ) )
, bodyin78( addInputPort( "bodyin78" ) )
, bodyin79( addInputPort( "bodyin79" ) )
, bodyin80( addInputPort( "bodyin80" ) )
, bodyin81( addInputPort( "bodyin81" ) )
, output( addOutputPort( "output" ) )
, current( addOutputPort( "current" ) )
, preparationTime( 0, 0, 0, 001 )
{
	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	if( time != "" )
		preparationTime = time ;

}

/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &Body::initFunction()
{
	state = wait_row;
	counter=0;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
********************************************************************/
Model &Body::externalFunction( const ExternalMessage &msg )
{
			cout<<"I am counter: "<<counter-1<<"\n";
		if( state == wait_row && counter < 81)
		{
			input_mat[counter] = msg.value();
			counter++;
			cout<<"counter: "<<counter-1<<"\n";
			if (counter==81){
				counter = 0;
				holdIn( active, preparationTime );
				state = wait_row;
			}
		}


	return *this;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &Body::internalFunction( const InternalMessage & )
{
	if (state == output_row){
		state = wait_row;
		passivate();
	}
	else if (state == wait_row){
		state = output_row;
		holdIn( active, preparationTime );
	}

	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &Body::outputFunction( const InternalMessage &msg )
{
		cout<<"I'm here1";
	if (state == wait_row){
		cout<<"I'm here";
		for (int i=0; i < 81; i++){
		sendOutput( msg.time(), output, input_mat[i] );
	}
	}
	else if (state == output_row){
	sendOutput( msg.time(), current, 1 );
	}


	return *this ;
}
