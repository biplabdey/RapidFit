/** @class Bd2JpsiPhi_mistagParameter_withTimeRes_withAverageAngAcc Bd2JpsiPhi_mistagParameter_withTimeRes_withAverageAngAcc.h
 *
 *  RapidFit PDF for Bd2JpsiKstar
 *
 *  @author Ailsa Sparkes
 *  @date 2011-01-26
 */

#ifndef Bd2JpsiKstar_sWave_H
#define Bd2JpsiKstar_sWave_H

#include "BasePDF.h"

class Bd2JpsiKstar_sWave : public BasePDF
{
	public:
		Bd2JpsiKstar_sWave();
		~Bd2JpsiKstar_sWave();

		//Calculate the PDF value
		virtual double Evaluate(DataPoint*);
		virtual bool SetPhysicsParameters(ParameterSet*);
		//Return a list of parameters not to be integrated
                virtual vector<string> GetDoNotIntegrateList();

	protected:
		//Calculate the PDF normalisation
		virtual double Normalisation(DataPoint*, PhaseSpaceBoundary*);

	private:
		void MakePrototypes();

		//Cached values
		double cachedAzeroAzeroIntB, cachedAparaAparaIntB, cachedAperpAperpIntB;
		double cachedAparaAperpIntB, cachedAzeroAparaIntB, cachedAzeroAperpIntB;
		double cachedAsAsIntB, cachedAparaAsIntB, cachedAperpAsIntB, cachedAzeroAsIntB;

		double cachedSinDeltaPerpPara, cachedCosDeltaPara, cachedSinDeltaPerp, cachedCosDeltaParaS, cachedSinDeltaPerpS, cachedCosDeltaS;


		double cachedAzero, cachedApara, cachedAperp, cachedAs;
		bool normalisationCacheValid, evaluationCacheValid;

		// These contain the strings that correspond
		// to the physics parameter names that will be
		// used in the minimiser.
		string gammaName;		// gamma
		string deltaMName;		// delta mass
		string Azero_sqName;	// amplitude
		string Apara_sqName;	// amplitude
		string Aperp_sqName;	// amplitude
		string As_sqName;
		string delta_zeroName;	// strong phase, set to 0
		string delta_paraName;	// strong phase
		string delta_perpName;
		string delta_sName;
		string angAccI1Name;		// Pre-calculated angular integrals including acceptance
		string angAccI2Name;		//
		string angAccI3Name;		//
		string angAccI4Name;		//
		string angAccI5Name;		//
		string angAccI6Name;
		string angAccI7Name;
		string angAccI8Name;
		string angAccI9Name;
		string angAccI10Name;
		string timeRes1Name;
		string timeRes2Name;
		string timeRes1FractionName;

		// Member variables that will contain the parameter values
                double gamma;
                double deltaMs;
                double Azero_sq;
                double Apara_sq;
                double Aperp_sq;
		double As_sq;
                double AzeroApara;
                double AzeroAperp;
                double AparaAperp;
		double AparaAs;
		double AperpAs;
		double AzeroAs;
                double delta_zero;
                double delta_para;
                double delta_perp;
		double delta_s;
                double omega;
                double timeRes;	 // This is the member variable used in the "builder" functions
                double timeRes1; // These are the physics parameters varied in the fit and passed from the XML
                double timeRes2;
                double timeRes1Frac;
		double angAccI1;
		double angAccI2;
		double angAccI3;
		double angAccI4;
		double angAccI5;
		double angAccI6;
		double angAccI7;
		double angAccI8;
		double angAccI9;
		double angAccI10;

		// These contain the strings that correspond
		// to the observable names that are used in the
		// PDF.
		string timeName;		// proper time
		string cosThetaName;	// cos of angle of mu+ wrt z-axis in Jpsi frame
		string phiName;		// azimuthal angle of the mu+ in Jpsi frame
		string cosPsiName;		// helicity angle between K+ and -ve Jpsi direction
		//kaonIDName;				// in phi rest frame

		// Member variables for the observables
		double time;
		double cosTheta;
		double phi;
		double cosPsi;
		//int kaonID;

		double tlow, thigh; // Integration limits

		double buildPDFnumerator();
		double buildPDFdenominator();
		void getTimeDependentAmplitudes( double&, double&, double&, double&, double&, double&, double&, double&, double&, double&);
		void getTimeAmplitudeIntegrals(double&, double&, double&, double&, double&, double&, double&, double&, double&, double&);
};

#endif
