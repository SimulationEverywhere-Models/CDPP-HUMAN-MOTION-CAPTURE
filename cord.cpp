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
#include "cord.h"      // class Queue
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Cord
********************************************************************/
Cord::Cord( const string &name )
: Atomic( name )
, brainout( addInputPort( "brainout" ) )
, cordout1( addOutputPort( "cordout1" ) )
, cordout2( addOutputPort( "cordout2" ) )
, cordout3( addOutputPort( "cordout3" ) )
, cordout4( addOutputPort( "cordout4" ) )
, cordout5( addOutputPort( "cordout5" ) )
, cordout6( addOutputPort( "cordout6" ) )
, cordout7( addOutputPort( "cordout7" ) )
, cordout8( addOutputPort( "cordout8" ) )
, cordout9( addOutputPort( "cordout9" ) )
, cordout10( addOutputPort( "cordout10" ) )
, cordout11( addOutputPort( "cordout11" ) )
, cordout12( addOutputPort( "cordout12" ) )
, cordout13( addOutputPort( "cordout13" ) )
, cordout14( addOutputPort( "cordout14" ) )
, cordout15( addOutputPort( "cordout15" ) )
, cordout16( addOutputPort( "cordout16" ) )
, cordout17( addOutputPort( "cordout17" ) )
, cordout18( addOutputPort( "cordout18" ) )
, cordout19( addOutputPort( "cordout19" ) )
, cordout20( addOutputPort( "cordout20" ) )
, cordout21( addOutputPort( "cordout21" ) )
, cordout22( addOutputPort( "cordout22" ) )
, cordout23( addOutputPort( "cordout23" ) )
, cordout24( addOutputPort( "cordout24" ) )
, cordout25( addOutputPort( "cordout25" ) )
, cordout26( addOutputPort( "cordout26" ) )
, cordout27( addOutputPort( "cordout27" ) )
, cordout28( addOutputPort( "cordout28" ) )
, cordout29( addOutputPort( "cordout29" ) )
, cordout30( addOutputPort( "cordout30" ) )
, cordout31( addOutputPort( "cordout31" ) )
, cordout32( addOutputPort( "cordout32" ) )
, cordout33( addOutputPort( "cordout33" ) )
, cordout34( addOutputPort( "cordout34" ) )
, cordout35( addOutputPort( "cordout35" ) )
, cordout36( addOutputPort( "cordout36" ) )
, cordout37( addOutputPort( "cordout37" ) )
, cordout38( addOutputPort( "cordout38" ) )
, cordout39( addOutputPort( "cordout39" ) )
, cordout40( addOutputPort( "cordout40" ) )
, cordout41( addOutputPort( "cordout41" ) )
, cordout42( addOutputPort( "cordout42" ) )
, cordout43( addOutputPort( "cordout43" ) )
, cordout44( addOutputPort( "cordout44" ) )
, cordout45( addOutputPort( "cordout45" ) )
, cordout46( addOutputPort( "cordout46" ) )
, cordout47( addOutputPort( "cordout47" ) )
, cordout48( addOutputPort( "cordout48" ) )
, cordout49( addOutputPort( "cordout49" ) )
, cordout50( addOutputPort( "cordout50" ) )
, cordout51( addOutputPort( "cordout51" ) )
, cordout52( addOutputPort( "cordout52" ) )
, cordout53( addOutputPort( "cordout53" ) )
, cordout54( addOutputPort( "cordout54" ) )
, cordout55( addOutputPort( "cordout55" ) )
, cordout56( addOutputPort( "cordout56" ) )
, cordout57( addOutputPort( "cordout57" ) )
, cordout58( addOutputPort( "cordout58" ) )
, cordout59( addOutputPort( "cordout59" ) )
, cordout60( addOutputPort( "cordout60" ) )
, cordout61( addOutputPort( "cordout61" ) )
, cordout62( addOutputPort( "cordout62" ) )
, cordout63( addOutputPort( "cordout63" ) )
, cordout64( addOutputPort( "cordout64" ) )
, cordout65( addOutputPort( "cordout65" ) )
, cordout66( addOutputPort( "cordout66" ) )
, cordout67( addOutputPort( "cordout67" ) )
, cordout68( addOutputPort( "cordout68" ) )
, cordout69( addOutputPort( "cordout69" ) )
, cordout70( addOutputPort( "cordout70" ) )
, cordout71( addOutputPort( "cordout71" ) )
, cordout72( addOutputPort( "cordout72" ) )
, cordout73( addOutputPort( "cordout73" ) )
, cordout74( addOutputPort( "cordout74" ) )
, cordout75( addOutputPort( "cordout75" ) )
, cordout76( addOutputPort( "cordout76" ) )
, cordout77( addOutputPort( "cordout77" ) )
, cordout78( addOutputPort( "cordout78" ) )
, cordout79( addOutputPort( "cordout79" ) )
, cordout80( addOutputPort( "cordout80" ) )
, cordout81( addOutputPort( "cordout81" ) )
, preparationTime( 0, 0, 0, 001 )
{
	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	if( time != "" )
		preparationTime = time ;

}

/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &Cord::initFunction()
{
	state = wait_row;
	counter=0;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
********************************************************************/
Model &Cord::externalFunction( const ExternalMessage &msg )
{
		if( state == wait_row && msg.port() == brainout && counter < 81)
		{
			input_mat[counter] = msg.value();
			counter++;
			cout<<"input_mat["<<counter-1<<"]: "<<input_mat[counter-1]<<"\n";
			if (counter == 81){
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
Model &Cord::internalFunction( const InternalMessage & )
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
Model &Cord::outputFunction( const InternalMessage &msg )
{
	if (state == wait_row){
		cout<<"input_mat[0]: "<<input_mat[0]<<"\n";
		sendOutput( msg.time(), cordout1, input_mat[0] );
		sendOutput( msg.time(), cordout2, input_mat[1] );
		sendOutput( msg.time(), cordout3, input_mat[2] );
		sendOutput( msg.time(), cordout4, input_mat[3] );
		sendOutput( msg.time(), cordout5, input_mat[4] );
		sendOutput( msg.time(), cordout6, input_mat[5] );
		sendOutput( msg.time(), cordout7, input_mat[6] );
		sendOutput( msg.time(), cordout8, input_mat[7] );
		sendOutput( msg.time(), cordout9, input_mat[8] );
		sendOutput( msg.time(), cordout10, input_mat[9] );
		sendOutput( msg.time(), cordout11, input_mat[10] );
		sendOutput( msg.time(), cordout12, input_mat[11] );
		sendOutput( msg.time(), cordout13, input_mat[12] );
		sendOutput( msg.time(), cordout14, input_mat[13] );
		sendOutput( msg.time(), cordout15, input_mat[14] );
		sendOutput( msg.time(), cordout16, input_mat[15] );
		sendOutput( msg.time(), cordout17, input_mat[16] );
		sendOutput( msg.time(), cordout18, input_mat[17] );
		sendOutput( msg.time(), cordout19, input_mat[18] );
		sendOutput( msg.time(), cordout20, input_mat[19] );
		sendOutput( msg.time(), cordout21, input_mat[20] );
		sendOutput( msg.time(), cordout22, input_mat[21] );
		sendOutput( msg.time(), cordout23, input_mat[22] );
		sendOutput( msg.time(), cordout24, input_mat[23] );
		sendOutput( msg.time(), cordout25, input_mat[24] );
		sendOutput( msg.time(), cordout26, input_mat[25] );
		sendOutput( msg.time(), cordout27, input_mat[26] );
		sendOutput( msg.time(), cordout28, input_mat[27] );
		sendOutput( msg.time(), cordout29, input_mat[28] );
		sendOutput( msg.time(), cordout30, input_mat[29] );
		sendOutput( msg.time(), cordout31, input_mat[30] );
		sendOutput( msg.time(), cordout32, input_mat[31] );
		sendOutput( msg.time(), cordout33, input_mat[32] );
		sendOutput( msg.time(), cordout34, input_mat[33] );
		sendOutput( msg.time(), cordout35, input_mat[34] );
		sendOutput( msg.time(), cordout36, input_mat[35] );
		sendOutput( msg.time(), cordout37, input_mat[36] );
		sendOutput( msg.time(), cordout38, input_mat[37] );
		sendOutput( msg.time(), cordout39, input_mat[38] );
		sendOutput( msg.time(), cordout40, input_mat[39] );
		sendOutput( msg.time(), cordout41, input_mat[40] );
		sendOutput( msg.time(), cordout42, input_mat[41] );
		sendOutput( msg.time(), cordout43, input_mat[42] );
		sendOutput( msg.time(), cordout44, input_mat[43] );
		sendOutput( msg.time(), cordout45, input_mat[44] );
		sendOutput( msg.time(), cordout46, input_mat[45] );
		sendOutput( msg.time(), cordout47, input_mat[46] );
		sendOutput( msg.time(), cordout48, input_mat[47] );
		sendOutput( msg.time(), cordout49, input_mat[48] );
		sendOutput( msg.time(), cordout50, input_mat[49] );
		sendOutput( msg.time(), cordout51, input_mat[50] );
		sendOutput( msg.time(), cordout52, input_mat[51] );
		sendOutput( msg.time(), cordout53, input_mat[52] );
		sendOutput( msg.time(), cordout54, input_mat[53] );
		sendOutput( msg.time(), cordout55, input_mat[54] );
		sendOutput( msg.time(), cordout56, input_mat[55] );
		sendOutput( msg.time(), cordout57, input_mat[56] );
		sendOutput( msg.time(), cordout58, input_mat[57] );
		sendOutput( msg.time(), cordout59, input_mat[58] );
		sendOutput( msg.time(), cordout60, input_mat[59] );
		sendOutput( msg.time(), cordout61, input_mat[60] );
		sendOutput( msg.time(), cordout62, input_mat[61] );
		sendOutput( msg.time(), cordout63, input_mat[62] );
		sendOutput( msg.time(), cordout64, input_mat[63] );
		sendOutput( msg.time(), cordout65, input_mat[64] );
		sendOutput( msg.time(), cordout66, input_mat[65] );
		sendOutput( msg.time(), cordout67, input_mat[66] );
		sendOutput( msg.time(), cordout68, input_mat[67] );
		sendOutput( msg.time(), cordout69, input_mat[68] );
		sendOutput( msg.time(), cordout70, input_mat[69] );
		sendOutput( msg.time(), cordout71, input_mat[70] );
		sendOutput( msg.time(), cordout72, input_mat[71] );
		sendOutput( msg.time(), cordout73, input_mat[72] );
		sendOutput( msg.time(), cordout74, input_mat[73] );
		sendOutput( msg.time(), cordout75, input_mat[74] );
		sendOutput( msg.time(), cordout76, input_mat[75] );
		sendOutput( msg.time(), cordout77, input_mat[76] );
		sendOutput( msg.time(), cordout78, input_mat[77] );
		sendOutput( msg.time(), cordout79, input_mat[78] );
		sendOutput( msg.time(), cordout80, input_mat[79] );
		sendOutput( msg.time(), cordout81, input_mat[80] );
	}


	return *this ;
}
