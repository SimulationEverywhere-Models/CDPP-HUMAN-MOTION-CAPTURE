/*******************************************************************
*
*  DESCRIPTION: Simulator::registerNewAtomics()
*
*  AUTHOR: Seyed Ali Etemad
*
*  EMAIL: mailto://etemad@sce.carleton.ca
*
*  DATE: 4/11/2009
*
*******************************************************************/

#include "modeladm.h"
#include "mainsimu.h"
#include "brain.h"        // class Brain
#include "cord.h"        // class Cord
#include "body.h"        // class Body


void MainSimulator::registerNewAtomics()
{

	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Brain>(), "Brain" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Cord>(), "Cord" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Body>(), "Body" ) ;


}
