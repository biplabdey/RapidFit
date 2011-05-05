/**
        @class ResultFormatter

        A collection of static methods for outputting RapidFit data objects

        @author Benjamin M Wynne bwynne@cern.ch
	@date 2009-10-02
*/

#ifndef RESULT_FORMATTER_H
#define RESULT_FORMATTER_H

//	RapidFit Headers
#include "IDataSet.h"
#include "FitResult.h"
#include "ToyStudyResult.h"
#include "LLscanResult.h"
#include "LLscanResult2D.h"
//	System Headers
#include <string>
#include <vector>

using namespace std;

class ResultFormatter
{
	public:
		static void MakeRootDataFile( string, vector<IDataSet*> );
		static void DebugOutputFitResult( FitResult* );
		static void LatexOutputFitResult( FitResult* );
		static void ReviewOutput( FitResult * OutputData );
		static void LatexOutputCovarianceMatrix( FitResult* );
		static void PlotFitContours( FitResult*, string );
		static double GetElementFromCovarianceMatrix( vector<double>, int, int);		
		static bool IsParameterFree( FitResult*, string );

		//MakePullPlots chooses the appropriate method based on the first string argument
		static void MakePullPlots( string, string, ToyStudyResult* );
		static void FlatNTuplePullPlots( string, ToyStudyResult* );
		static void WriteFlatNtuple( string , ToyStudyResult* );
		static void SeparateParameterPullPlots( string, ToyStudyResult* );
		static void MakeLLscanPlots( vector<LLscanResult*> scanResults, string filename ); 
		static void MakeLLcontourPlots( vector<LLscanResult2D*> scanResults, string filename );

		static void CorrMatrixOutput( string FileName, ToyStudyResult * ToyResult );

		static LLscanResult* LLScan( ToyStudyResult*, string );
		static LLscanResult2D* LLScan2D( vector<ToyStudyResult*>, string, string );
};

#endif
