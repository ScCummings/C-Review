/*a. Scott Cummings
	b. 2317991
	c. scummings@chapman.edu
	d. CPSC 350 - Section 01
	e. Assignment 1
  Overview:
  Header file for the DNA_String class. This class mostly exists to minimize repeated code through the use of functions as
  well as the implementation of a clean, object-oriented design.
  */
#include <string>
#include <fstream>

using namespace std;
class DNA_String
{
private:
	double m_variance = 0;
	int m_aaBigramCount = 0;
	int m_acBigramCount = 0;
	int m_atBigramCount = 0;
	int m_agBigramCount = 0;
	int m_caBigramCount = 0;
	int m_ctBigramCount = 0;
	int m_ccBigramCount = 0;
	int m_cgBigramCount = 0;
	int m_gaBigramCount = 0;
	int m_ggBigramCount = 0;
	int m_gcBigramCount = 0;
	int m_gtBigramCount = 0;
	int m_ttBigramCount = 0;
	int m_tgBigramCount = 0;
	int m_tcBigramCount = 0;
	int m_taBigramCount = 0;
	int m_totalBigramCount = 0;
	int m_sumCounter = 0;
	double m_mean;
	double m_standardDeviation;
	int m_aCount = 0;
	int m_gCount = 0;
	int m_cCount = 0;
	int m_tCount = 0;
	double m_totalNumberOfChars = 0;
	int m_numberOfLines = 0;
	string m_line;
	ifstream m_inputFile;
public:
	enum nucleotides
	{
		aProbability,
		cProbability,
		gProbability,
		tProbability,
		aaBigramProbability,
		acBigramProbability,
		agBigramProbability,
		atBigramProbability,
		caBigramProbability,
		ccBigramProbability,
		cgBigramProbability,
		ctBigramProbability,
		gaBigramProbability,
		gcBigramProbability,
		ggBigramProbability,
		gtBigramProbability,
		taBigramProbability,
		tcBigramProbability,
		tgBigramProbability,
		ttBigramProbability,
	};
  void generateInfo(string inputFileName, string outputFileName);
  double calculateProbability(nucleotides someNucleotide);
  double calculateMean(int sumCounter, int numberOfLines);
	double calculateStandardDeviation(double variance);
	DNA_String();
};
