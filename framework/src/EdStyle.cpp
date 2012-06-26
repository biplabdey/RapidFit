// $Id: EdStyle.cpp,v 1.1 2009/11/10 10:35:46 gcowan Exp $
/**
  @class EdStyle

  Default style for RapidFit plots

  @author Greig A Cowan greig.alan.cowan@cern.ch
  @date 2009-10-02
 */

// Include files

//	ROOT Headers
#include "TLatex.h"
#include "TText.h"
#include "TPaveText.h"
#include "TROOT.h"
//	RapidFit Headers
#include "EdStyle.h"
//	System Headers
#include <iostream>
#include <string.h>
#include <sstream>
#include <cstdlib>

using namespace::std;

//-----------------------------------------------------------------------------
// Implementation file for class : EdStyle
//
// 2007-12-07 : Greig Cowan
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================

EdStyle::EdStyle( ) : edStyle(), icol(), font(), tsize()
{
}

EdStyle::~EdStyle()
{
}

void EdStyle::SetStyle()
/*!
 * Compared to: Erasmus/trunk/RootTools/LHCbStyle/src/lhcbStyle.C -r 139227
 *
 * From: svn co svn+ssh://svn.cern.ch/reps/lhcb/Erasmus/trunk/RootTools/LHCbStyle/src
 */
{

	//Start of LHCb Style choices

	// use helvetica-bold-r-normal, precision 2 (rotatable)
	Font_t lhcbFont = 132;

	// line thickness
	Width_t lhcbWidth = 1.; //Width_t is a SHORT INT, NOT a double

	// text size
	Double_t lhcbTSize = 0.06;

	gStyle->SetFrameBorderMode(0);
	gStyle->SetCanvasBorderMode(0);
	gStyle->SetPadBorderMode(0);
	gStyle->SetPadColor(0);
	gStyle->SetCanvasColor(0);
	gStyle->SetStatColor(0);
	gStyle->SetFrameFillColor(0);
	gStyle->SetLegendBorderSize(0);
	gStyle->SetPalette(1);
	gStyle->SetFillStyle(1001);
	gStyle->SetFillColor(1);
	gStyle->SetPalette(1);

	int colors[8] = {0,5,7,3,6,2,4,1};
	gStyle->SetPalette(8,colors);


	gStyle->SetPaperSize(20,26);
        gStyle->SetPadLeftMargin( (Float_t) 0.13 );
        gStyle->SetPadBottomMargin( (Float_t) 0.16 );
        gStyle->SetPadRightMargin( (Float_t)0.08 ); // increase for colz plots!!
        gStyle->SetPadTopMargin( (Float_t)0.05 );


	//      Set default fonts for axis and titles on all plots
        gStyle->SetTextFont( lhcbFont );
	gStyle->SetTextSize( (Float_t) lhcbTSize );
	gStyle->SetLabelFont( lhcbFont, "xyz" );
	gStyle->SetLabelSize( (Float_t)lhcbTSize, "xyz" );
	gStyle->SetTitleFont( lhcbFont, "xyz" );
	gStyle->SetTitleSize( (Float_t)1.2*(Float_t)lhcbTSize, "xyz" );
	gStyle->SetStatFont( lhcbFont );

	// use bold lines and markers
        gStyle->SetLineWidth( lhcbWidth );
        gStyle->SetFrameLineWidth( lhcbWidth );
        gStyle->SetHistLineWidth( lhcbWidth );
        gStyle->SetFuncWidth( lhcbWidth );
        gStyle->SetGridWidth( lhcbWidth );
        gStyle->SetLineStyleString( 2, "[12 12]"); // postscript dashes
        gStyle->SetMarkerStyle( 20 );
        gStyle->SetMarkerSize( (Float_t)2.1 );


	// label offsets
        gStyle->SetLabelOffset( (Float_t)0.010, "X" );
	gStyle->SetLabelOffset( (Float_t)0.010, "Y" );


	// by default, do not display histogram decorations:
        gStyle->SetOptStat(0);  // show only nent, mean, rms
        gStyle->SetOptStat("emr");
        gStyle->SetStatFormat("6.3g");
        gStyle->SetOptTitle(0);
        gStyle->SetOptFit(0);


	//titles
	gStyle->SetTitleOffset((Float_t)0.95,"X");
	gStyle->SetTitleOffset((Float_t)0.95,"Y");
	gStyle->SetTitleOffset((Float_t)1.2,"Z");
	gStyle->SetTitleFillColor(0);
	gStyle->SetTitleStyle(0);
	gStyle->SetTitleBorderSize(0);
	gStyle->SetTitleFont(lhcbFont,"title");
	gStyle->SetTitleX(0.0);
	gStyle->SetTitleY(1.0); 
	gStyle->SetTitleW(1.0);
	gStyle->SetTitleH((Float_t)0.05);

	// look of the statistics box:
        gStyle->SetStatBorderSize( 0 );
        gStyle->SetStatFont( lhcbFont );
        gStyle->SetStatFontSize( (Float_t)0.05 );
        gStyle->SetStatX( (Float_t)0.9 );
        gStyle->SetStatY( (Float_t)0.9 );
        gStyle->SetStatW( (Float_t)0.25 );
        gStyle->SetStatH( (Float_t)0.15 );

	// put tick marks on top and RHS of plots
        gStyle->SetPadTickX( 1 );
        gStyle->SetPadTickY( 1 );

	// histogram divisions: only 5 in x to avoid label overlaps
        gStyle->SetNdivisions( 505, "x" );
        gStyle->SetNdivisions( 510, "y" );



	//End of LHCb Style choices




	//	Custom choice by Edinburgh
	gStyle->SetTitleFillColor(0);
	gStyle->SetStatBorderSize(1);


	// label offsets

	//gStyle->SetTitleOffset( (Float_t)1.25, "xyz" );	//	Stop ALL titles overlapping the numbers on the axis

	//	0 to use RGB, 1 to use CKYM... CKYM does make more sence
	gStyle->SetColorModelPS( 1 );

	//define style for text
	TText *lhcbLabel = new TText();
	lhcbLabel->SetTextFont(lhcbFont);
	lhcbLabel->SetTextColor(1);
	lhcbLabel->SetTextSize( (Float_t)0.04 );
	lhcbLabel->SetTextAlign(12);

	// define style of latex text
	TLatex *lhcbLatex = new TLatex();
	lhcbLatex->SetTextFont(lhcbFont);
	lhcbLatex->SetTextColor(1);
	lhcbLatex->SetTextSize((Float_t)0.04);
	lhcbLatex->SetTextAlign(12);

	gROOT->UseCurrentStyle();
	gROOT->ForceStyle( true );
}


void EdStyle::FormatTText( TText* input )
{
	Font_t lhcbFont=62;
	input->SetTextFont(lhcbFont);
	input->SetTextColor(1);
	input->SetTextSize((Float_t)0.04);
	input->SetTextAlign(12);
}

void EdStyle::FormatTLatex( TLatex* input )
{
	Font_t lhcbFont=62;
	input->SetTextFont(lhcbFont);
	input->SetTextColor(1);
	input->SetTextSize((Float_t)0.04);
	input->SetTextAlign(12);
}

//  These functions are not guaranteed correct but will people please add to them
//  it can save time in editing tables out of RapidFit if we can at least call one standard function for things like this
//	This could be cleaner but given where this occurs in the program I officially cba

TString EdStyle::GetParamRootUnit( string Param_Name )
{
	TString returnable_string;

	if( Param_Name == "gamma" )
	{
		returnable_string = "[ps^{-1}]";

	} else if( Param_Name == "deltaGamma" ) { 

		returnable_string = "[ps^{-1}]";

	} else if( Param_Name == "Phi_s" ) {

		returnable_string = "[rad]";

	} else if ( Param_Name == "Azero_sq" ) {

		returnable_string = "[unitless]";

	} else if ( Param_Name == "Aperp_sq" ) {

		returnable_string = "[unitless]";

	} else if ( Param_Name == "Apara_sq" ) {

		returnable_string = "[unitless]";

	} else if ( Param_Name == "As_sq" ) {

		returnable_string = "[unitless]";

	} else if ( Param_Name == "delta_para" ) {

		returnable_string = "[rad]";

	} else if ( Param_Name == "delta_perp" ) {

		returnable_string = "[rad]";

	} else if ( Param_Name == "delta_s" ) {

		returnable_string = "[rad]";

	} else if ( Param_Name == "deltaM" ) {

		//returnable_string = "MeV/c^{2}";
		returnable_string = "[ps^{-1}]";
	}

	return returnable_string;
}

TString EdStyle::GetParamLatexUnit( string Param_Name )
{
	(void) Param_Name;
	//	I will write this when I can be bothered...
	TString Unit("$");
	Unit.Append("$");
	return Unit;
}

TString EdStyle::GetParamRootName( string Param_Name_orig )
{
	string Param_Name = Param_Name_orig;
	int suffix = Test_Suffix( Param_Name_orig );
	if( suffix != -1 )
	{
		Param_Name = Remove_Suffix( Param_Name_orig );
	}
	TString returnable_string;
	if( Param_Name == "LLscan" ) {

		returnable_string = "-#Delta Log Likelihood";

	} else if( Param_Name == "gamma" ) {

		returnable_string = "#Gamma";

	} else if ( Param_Name == "deltaGamma" ) {

		returnable_string = "#Delta#Gamma_{s}";

	} else if ( Param_Name == "Azero_sq" ) {

		returnable_string = "A_{0}^{2}";

	} else if ( Param_Name == "Aperp_sq" ) {

		returnable_string = "A_{#perp}^{2}";

	} else if ( Param_Name == "Apara_sq" ) {

		returnable_string = "A_{#parallel}^{2}";

	} else if ( Param_Name == "As_sq" ) {

		returnable_string = "A_{s}^{2}";

	} else if ( Param_Name == "delta_para" ) {

		returnable_string = "#delta_{#parallel}";

	} else if ( Param_Name == "delta_perp" ) {

		returnable_string = "#delta_{#perp} ";

	} else if ( Param_Name == "delta_s" ) {

		returnable_string = "#delta_{s}";

	} else if ( Param_Name == "Phi_s" ) {

		returnable_string = "#phi_{s}";

	} else if ( Param_Name == "m_Bs" ) {

		returnable_string = "m_{B_s}";

	} else if (Param_Name == "sigma_m1" ) {

		returnable_string = "{#sigma_{m}}^{1}";

	} else if (Param_Name == "sigma_m2" ) {

		returnable_string = "{#sigma_{m}}^{2}";

	} else if (Param_Name == "f_sig_m1" ) {

		returnable_string = "f_{{#sigma_{m}}^{1}}";

	} else if (Param_Name == "mistag" ) {

		returnable_string = "#omega";

	} else if (Param_Name == "angAccI1" ) {

		returnable_string = "#zeta_{1}";

	} else if (Param_Name == "angAccI2" ) {

		returnable_string = "#zeta_{2}";

	} else if (Param_Name == "angAccI3" ) {

		returnable_string = "#zeta_{3}";

	} else if (Param_Name == "angAccI4" ) {

		returnable_string = "#zeta_{4}";

	} else if (Param_Name == "angAccI5" ) {

		returnable_string = "#zeta_{5}";

	} else if (Param_Name == "angAccI6" ) {

		returnable_string = "#zeta_{6}";

	} else if (Param_Name == "angAccI7" ) {

		returnable_string = "#zeta_{7}";

	} else if (Param_Name == "angAccI8" ) {

		returnable_string = "#zeta_{8}";

	} else if (Param_Name == "angAccI9" ) {

		returnable_string = "#zeta_{9}";

	} else if (Param_Name == "angAccI10" ) {

		returnable_string = "#zeta_{10}";

	} else if (Param_Name =="deltaM" ) {

		returnable_string =  "#Delta m_{s}" ;

	} else if (Param_Name =="delta_zero") {

		returnable_string = "#delta_{0}";

	} else {

		returnable_string = Param_Name;
	}

	if( suffix != -1 )
	{
		returnable_string += Get_Suffix( Param_Name_orig );
	}
	return returnable_string;
}

TString EdStyle::GetParamLatexName( string Param_Name_orig )
{
	TString Param_Name = Param_Name_orig;
	TString Name("$");
	int suffix = Test_Suffix( Param_Name_orig );
	if( suffix != -1 )
	{
		Param_Name = Remove_Suffix( Param_Name_orig );
	}
	if( Param_Name == "LLscan" ) {

		Name.Append("\\Delta\\text{LL}");
	}
	if( Param_Name == "gamma" ) {

		Name.Append("\\Gamma");

	} else if ( Param_Name == "deltaGamma" ) {

		Name.Append("\\Delta\\Gamma");

	} else if ( Param_Name == "Azero_sq" ) {

		Name.Append("{A_0}^2");

	} else if ( Param_Name == "Aperp_sq" ) {

		Name.Append("{A_{\\hspace{-1pt}\\perp}}^{\\hspace{-2pt}2}");

	} else if ( Param_Name == "Apara_sq" ) {

		Name.Append("{A_{\\parallel}}^2");

	} else if ( Param_Name == "As_sq" ) {

		Name.Append("{A_s}^2");

	} else if ( Param_Name == "delta_para" ) {

		Name.Append("\\delta_\\parallel");

	} else if ( Param_Name == "delta_perp" ) {

		Name.Append("\\delta_\\perp");

	} else if ( Param_Name == "delta_s" ) {

		Name.Append("\\delta_s");

	} else if ( Param_Name == "Phi_s" ) {

		Name.Append("\\phi_s");

	} else if ( Param_Name == "m_Bs" ) {

		Name.Append("m_{B_s}");

	} else if (Param_Name == "sigma_m1" ) {

		Name.Append("{\\sigma_m}^1");

	} else if (Param_Name == "sigma_m2" ) {

		Name.Append("{\\sigma_m}^2");

	} else if (Param_Name == "f_sig_m1" ) {

		Name.Append("f_{{\\sigma_m}^1}");

	} else if (Param_Name == "timeOffset" ) {

		Name.Append("\\tau_{Offset}");

	} else if (Param_Name == "timeResolution1" ) {

		Name.Append("\\tau_1");

	} else if (Param_Name == "timeResolution2" ) {

		Name.Append("\\tau_2");

	} else if (Param_Name == "timeResolution1Fraction" ) {

		Name.Append("f_{\\tau_1}");

	} else if (Param_Name == "mistag" ) {

		Name.Append("\\omega");

	} else if (Param_Name == "angAccI1" ) {

		Name.Append("\\zeta_1");

	} else if (Param_Name == "angAccI2" ) {

		Name.Append("\\zeta_2");

	} else if (Param_Name == "angAccI3" ) {

		Name.Append("\\zeta_3");

	} else if (Param_Name == "angAccI4" ) {

		Name.Append("\\zeta_4");

	} else if (Param_Name == "angAccI5" ) {

		Name.Append("\\zeta_5");

	} else if (Param_Name == "angAccI6" ) {

		Name.Append("\\zeta_6");

	} else if (Param_Name == "angAccI7" ) {

		Name.Append("\\zeta_7");

	} else if (Param_Name == "angAccI8" ) {

		Name.Append("\\zeta_8");

	} else if (Param_Name == "angAccI9" ) {

		Name.Append("\\zeta_9");

	} else if (Param_Name == "angAccI10" ) {

		Name.Append("\\zeta_10");

	} else if (Param_Name =="deltaM" ) {

		Name.Append( "\\Delta m_s");

	} else if (Param_Name =="delta_zero") {

		Name.Append("\\delta_0");

	} else if (Param_Name == "SignalFractionUBT") {

		Name.Append("{f_{UB}}^T");

	} else if (Param_Name == "SignalFractionUBU") {

		Name.Append("{f_{UB}}^{UT}");

	} else if (Param_Name == "SignalFractionBT") {

		Name.Append("{f_{B}}^T");

	} else if (Param_Name == "SignalFractionBU") {

		Name.Append("{f_{B}}^{UT}");

	} else if (Param_Name == "mistagOffset") {

		Name.Append("\\omega_{Offset}");

	} else if (Param_Name == "mistagScale") {

		Name.Append("\\omega_{Scale}");

	} else if (Param_Name == "timeResLL1Frac") {

		Name.Append("f_{\\tau_{LL1}}");

	} else if (Param_Name == "As_sq") {

		Name.Append("{A_s}^2");

	} else if (Param_Name == "sigma_LL1") {

		Name.Append("\\sigma_{LL1}");

	} else if (Param_Name == "sigma_LL2") {

		Name.Append("\\sigma_{LL2}");

	} else if (Param_Name == "tau_LL1") {

		Name.Append("\\tau_{LL1}");

	} else if (Param_Name == "tau_LL2") {

		Name.Append("\\tau_{LL2}");

	} else if (Param_Name == "alphaM_pr") {

		Name.Append("\\alpha M_{pr}");

	}  else if (Param_Name == "delta_s") {

		Name.Append("\\delta_s");

	}  else if (Param_Name == "f_LL1") {

		Name.Append("f_{LL1}");

	} else {
		Name.Append("\\text{");
		Name.Append(Param_Name);
		Name.Append("}");
	}

	Name.Append("$");

	if( suffix != -1 )
	{
		Name.Append( Get_Suffix( Param_Name_orig ) );
	}

	return Name;
}

int EdStyle::Test_Suffix( string arg )
{
	vector<string> sufficies;
	sufficies.push_back( "_value" );
	sufficies.push_back( "_error" );
	sufficies.push_back( "_gen" );
	sufficies.push_back( "_pull" );
	sufficies.push_back( "_scan" );
	int suffix_index = -1;

	for( unsigned int i=0; i< sufficies.size(); ++i )
	{
		size_t found = arg.find( sufficies[i] );
		if( found != string::npos )
		{
			suffix_index=(int)i;
			break;
		}
	}
	return suffix_index;
}

string EdStyle::Remove_Suffix( string arg )
{
	vector<string> sufficies;
	sufficies.push_back( "_value" );
	sufficies.push_back( "_error" );
	sufficies.push_back( "_gen" );
	sufficies.push_back( "_pull" );
	sufficies.push_back( "_scan" );
	int suffix_index = -1;
	size_t found;
	for( unsigned int i=0; i< sufficies.size(); ++i )
	{
		found = arg.find( sufficies[i] );
		if( found != string::npos )
		{
			suffix_index=(int)i;
			break;
		}
	}
	if( suffix_index >= 0 )
	{
		stringstream output;
		for( unsigned int i=0; i< found; ++i )
		{
			output << arg[i];
		}
		return output.str();
	}

	return arg;
}

string EdStyle::Get_Suffix( string arg )
{
	vector<string> sufficies_output;
	sufficies_output.push_back( " value" );
	sufficies_output.push_back( " error" );
	sufficies_output.push_back( " gen" );
	sufficies_output.push_back( " pull" );
	sufficies_output.push_back( " scan" );
	int suffix_index= Test_Suffix( arg );

	if( suffix_index >=0 )
	{
		return sufficies_output[ (unsigned)suffix_index ];
	}
	return "";
}


//	Wrapper functions
TString EdStyle::GetParamLatexUnit( TString arg )
{
	return GetParamLatexUnit( string( arg.Data() ) );
}
TString EdStyle::GetParamRootUnit( TString arg )
{
	return GetParamRootUnit( string( arg.Data() ) );
}
TString EdStyle::GetParamLatexName( TString arg )
{
	return GetParamLatexName( string( arg.Data() ) );
} 
TString EdStyle::GetParamRootName( TString arg )
{
	return GetParamRootName( string( arg.Data() ) );
}
int EdStyle::Test_Suffix( TString arg )
{
	return Test_Suffix( string( arg.Data() ) );
}
TString EdStyle::Get_Suffix( TString arg )
{
	return Get_Suffix( string( arg.Data() ) );
}
TString EdStyle::Remove_Suffix( TString arg )
{
	return Remove_Suffix( string( arg.Data() ) );
}

TLegend* EdStyle::LHCbLegend()
{
	TLegend* thisLegend = new TLegend( 0.75, 0.65, 0.9, 0.9 );
	thisLegend->SetFillColor( kWhite );
	thisLegend->SetFillStyle( 3001 );
	return thisLegend;
}

