/**
  @class ResolutionModel

  A class for implementing a decay time resolution model

  This one is a single Gaussian event-by-event model, with a single scale factor

  @author Pete Clarke
  @data 2013-06-03
  */

#pragma once
#ifndef DoubleFixedResolution_Model_H
#define DoubleFixedResolution_Model_H

//	RapidFir Headers
#include "ParameterSet.h"
#include "DataPoint.h"
#include "PDFConfigurator.h"
#include "Observable.h"
#include "IResolutionModel.h"
//	System Headers
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace::std;

//=======================================

class DoubleFixedResModel : public IResolutionModel
{
	public:

		DoubleFixedResModel( PDFConfigurator* configurator, bool quiet=false ) ;

		void addParameters( vector<string> & parameterNames ) ;
		void setParameters( ParameterSet & parameters ) ;

		void addObservables( vector<string> & observableNames ) ;
		void setObservables( DataPoint * measurement ) ;

		double Exp( double time, double gamma ) ;
		double ExpInt( double tlow, double thigh, double gamma ) ;

		double ExpSin( double time, double gamma, double dms ) ;
		double ExpSinInt( double tlow, double thigh, double gamma, double dms ) ;

		double ExpCos( double time, double gamma, double dms ) ;
		double ExpCosInt( double tlow, double thigh, double gamma, double dms ) ;

		bool isPerEvent() ;

		bool CacheValid() const;

	protected:

		unsigned int numComponents();
		void requestComponent( unsigned int );

		double GetFraction( unsigned int );

	private:

		bool isCacheValid;

		double GetThisScale();

		ObservableRef Resolution1Name;			// Scale to multiply e-by-e resolution
		ObservableRef Resolution2Name;
		double Resolution1;
		double Resolution2;

		ObservableRef ResolutionScaleName;  // Event-by-event resolution observable
		double ResolutionScale;

		unsigned int numberComponents;
		unsigned int wantedComponent;

		ObservableRef Resolution2FractionName;
		double Resolution2Fraction;
};

#endif

