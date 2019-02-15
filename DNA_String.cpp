/*a. Scott Cummings
	b. 2317991
	c. scummings@chapman.edu
	d. CPSC 350 - Section 01
	e. Assignment 1
  Overview: This file contains the implementation for class methods found in the DNA_String class. The vast
  majority of the program's overall purpose is contained within the "generateInfo" function. This is done so
  that the program's main function will be relatively short and sweet. Also, it alows for a user to enter
  in another file to generate info for with relative ease.
  */
#include <iostream> // file io
#include <fstream> //file io
#include <string> // using strings
#include <cmath> // exponents
#include <math.h> // srand and rand

#include "DNA_String.h" //my DNA string class header file

using namespace std;
/*
  a. generateInfo
  b. @return - void
  c. @param - string inputFileName: a string that represents the name of the input file that the user would like to
  use to generate the statistics.
              string outputFileName: a string that represents the name of the output file that the user would like to
              append their results to.
  d. no exceptions thrown.
*/
void DNA_String::generateInfo(string inputFileName, string outputFileName)
{
  int lengthOfStrings = 0;
  const double pi = 3.14159;
  double varianceSum = 0;
  double c = 0;
  double d = 0;
    m_inputFile.open(inputFileName);
    if (!m_inputFile)
    {
      cerr << "Input file not found!" << endl;
    }
  if (m_inputFile.is_open())
  {
    while (m_inputFile)
    {
      getline(m_inputFile, m_line);
      ++m_numberOfLines;
      for (int j = 0; j < m_line.length(); j++)
      {
        if (j >= 1)
        {
          m_totalBigramCount++;
        }
        lengthOfStrings++;
        //switch statement for counts, necessary for probability generation
        switch (m_line[j])
        {
        case ('a'):
        case ('A'):
          if (j > 0 && j % 2 == 1)
          {
            if (m_line[j - 1] == 'a' || m_line[j - 1] == 'A')
            {
              m_aaBigramCount++;
            }
            else if (m_line[j - 1] == 'c' || m_line[j - 1] == 'C')
            {
              m_acBigramCount++;
            }
            else if (m_line[j - 1] == 't' || m_line[j - 1] == 'T')
            {
              m_atBigramCount++;
            }
            else if (m_line[j - 1] == 'g' || m_line[j - 1] == 'G')
            {
              m_agBigramCount++;
            }
          }
          m_aCount++;
          break;
        case ('t'):
        case ('T'):
          if (j > 0 && j % 2 == 1)
          {
            if (m_line[j - 1] == 'a' || m_line[j - 1] == 'A')
            {
              m_taBigramCount++;
            }
            else if (m_line[j - 1] == 'c' || m_line[j - 1] == 'C')
            {
              m_tcBigramCount++;
            }
            else if (m_line[j - 1] == 't' || m_line[j - 1] == 'T')
            {
              m_ttBigramCount++;
            }
            else if (m_line[j - 1] == 'g' || m_line[j - 1] == 'G')
            {
              m_tgBigramCount++;
            }
          }
          m_tCount++;
          break;

        case ('c'):
        case ('C'):
          if (j > 0 && j % 2 == 1)
          {
            if (m_line[j - 1] == 'a' || m_line[j - 1] == 'A')
            {
              m_caBigramCount++;
            }
            else if (m_line[j - 1] == 'c' || m_line[j - 1] == 'C')
            {
              m_ccBigramCount++;
            }
            else if (m_line[j - 1] == 't' || m_line[j - 1] == 'T')
            {
              m_ctBigramCount++;
            }
            else if (m_line[j - 1] == 'g' || m_line[j - 1] == 'G')
            {
              m_cgBigramCount++;
            }
          }
          m_cCount++;
          break;
        case ('g'):
        case ('G'):
          if (j > 0 && j % 2 == 1)
          {
            if (m_line[j - 1] == 'a' || m_line[j - 1] == 'A')
            {
              m_gaBigramCount++;
            }
            else if (m_line[j - 1] == 'c' || m_line[j - 1] == 'C')
            {
              m_gcBigramCount++;
            }
            else if (m_line[j - 1] == 't' || m_line[j - 1] == 'T')
            {
              m_gtBigramCount++;
            }
            else if (m_line[j - 1] == 'g' || m_line[j - 1] == 'G')
            {
              m_ggBigramCount++;
            }
          }
          m_gCount++;
          break;
        }
        m_totalNumberOfChars++;
      }
    }
      //compute the sum of the lengths
      m_sumCounter += lengthOfStrings;
      //Calculating the probability of each of the nucleotides
      calculateProbability(aProbability);
      calculateProbability(cProbability);
      calculateProbability(gProbability);
      calculateProbability(tProbability);
      //Checking for bad input from a file
      if (m_totalBigramCount == 0)
      {
        cout << "There were no Bigrams found in the file." << endl;
      }

      //clear the file (go back to the top)
      m_inputFile.clear();
      m_inputFile.seekg(0, ios::beg);
      //compute the mean of the lengths
      m_mean = calculateMean(m_sumCounter, m_numberOfLines);
      for (int i = 0; i < m_numberOfLines; i++)
      {
        getline(m_inputFile, m_line);
        int lengthOfStrings = 0;
        for (int j = 0; m_line[j]; j++)
        {
          lengthOfStrings++;
        }
        //varience calculation
        varianceSum += pow(lengthOfStrings - m_mean, 2);
      }
      m_variance = varianceSum / (m_numberOfLines - 1);
      m_standardDeviation = sqrt(m_variance);
      //Output results to user's file
      ofstream outputFile;
      outputFile.open(outputFileName, ios_base::app);
      //sum, mean, variance, standard deviation
      outputFile << "Generated by: Scott Cummings" << endl;
      outputFile << "Student ID: 2317991" << endl;
      outputFile << "The sum of the lengths is: " << m_sumCounter << endl;
      outputFile << "The mean of the lengths is: " << m_mean << endl;
      outputFile << "The variance of the lengths is: " << m_variance << endl;
      outputFile << "The standard deviation of the lengths is: " << m_standardDeviation << endl;
      //probability of nucleotides
      outputFile << "a Probability = " << calculateProbability(aProbability) << endl;
      outputFile << "c Probability = " << calculateProbability(cProbability) << endl;
      outputFile << "g Probability = " << calculateProbability(gProbability) << endl;
      outputFile << "t Probability = " << calculateProbability(tProbability) << endl;
      //probability of nucleotide bigrams
      outputFile << "AA Bigram Probability: " << calculateProbability(aaBigramProbability) << endl;
      outputFile << "AT Bigram Probability: " << calculateProbability(atBigramProbability) << endl;
      outputFile << "AC Bigram Probability: " << calculateProbability(acBigramProbability) << endl;
      outputFile << "AG Bigram Probability: " << calculateProbability(agBigramProbability) << endl;
      outputFile << "CA Bigram Probability: " << calculateProbability(caBigramProbability) << endl;
      outputFile << "CT Bigram Probability: " << calculateProbability(ctBigramProbability) << endl;
      outputFile << "CC Bigram Probability: " << calculateProbability(ccBigramProbability) << endl;
      outputFile << "CG Bigram Probability: " << calculateProbability(cgBigramProbability) << endl;
      outputFile << "GA Bigram Probability: " << calculateProbability(gaBigramProbability) << endl;
      outputFile << "GC Bigram Probability: " << calculateProbability(gcBigramProbability) << endl;
      outputFile << "GT Bigram Probability: " << calculateProbability(gtBigramProbability) << endl;
      outputFile << "GG Bigram Probability: " << calculateProbability(ggBigramProbability) << endl;
      outputFile << "TA Bigram Probability: " << calculateProbability(taBigramProbability) << endl;
      outputFile << "TC Bigram Probability: " << calculateProbability(tcBigramProbability) << endl;
      outputFile << "TG Bigram Probability: " << calculateProbability(tgBigramProbability) << endl;
      outputFile << "TT Bigram Probability: " << calculateProbability(ttBigramProbability) << endl;
      //generate 1000 DNA strings who have bell curve using previous stats

      //Append this to scottcummings.out

      //Prompt and take in user input

      //lested for loops for Gaussian generation
      for (int i = 0; i < 1000; ++i)
      {
        //generate the random a and b
        double a = ((double)rand() / (RAND_MAX));
        double b = ((double)rand() / (RAND_MAX));
        c = sqrt(-2 * (log(a))) * cos(2 * pi * b);
        d = (m_standardDeviation * c) + m_mean;
        for (int j = 0; j < d; ++j)
        {
          double randomNumber = ((double)rand() / (RAND_MAX));
          if (randomNumber <= calculateProbability(aProbability))
          {
            outputFile << 'A';
          }
          else if (randomNumber > calculateProbability(aProbability) && randomNumber <= calculateProbability(aProbability) + calculateProbability(cProbability))
          {
            outputFile << 'C';
          }
          else if (randomNumber > calculateProbability(aProbability) + calculateProbability(cProbability) && randomNumber <= calculateProbability(aProbability) + calculateProbability(cProbability) + calculateProbability(gProbability))
          {
            outputFile << 'G';
          }
          else if (randomNumber > calculateProbability(aProbability) + calculateProbability(cProbability) + calculateProbability(gProbability) && randomNumber <= 1)
          {
            outputFile << 'T';
          }
          else
          {

          }

        }
        outputFile << "\n";
      }
  }
}
/*
  a. calculateProbability
  b. @return - a double value that represents the probability of the passed in nucleotide or nucleotide bigram
  c. @param - nucleotides someNucleotide - an enum value used so that the switch found side can change implementation
              as necessary.
  d. no exceptions thrown.
*/
double DNA_String::calculateProbability(nucleotides someNucleotide)
{
  switch (someNucleotide)
  {
  case aProbability:
    return m_aCount / m_totalNumberOfChars; //m_totalNumberOfChars is already a double so casting is not needed
    break;
  case cProbability:
    return m_cCount / m_totalNumberOfChars;
    break;
  case gProbability:
    return m_gCount / m_totalNumberOfChars;
    break;
  case tProbability:
    return m_tCount / m_totalNumberOfChars;
    break;
  case aaBigramProbability:
    return static_cast<double>(m_aaBigramCount) / m_totalBigramCount;
    break;
  case acBigramProbability:
    return static_cast<double>(m_acBigramCount) / m_totalBigramCount;
    break;
  case agBigramProbability:
    return static_cast<double>(m_agBigramCount) / m_totalBigramCount;
    break;
  case atBigramProbability:
    return static_cast<double>(m_atBigramCount) / m_totalBigramCount;
    break;
  case caBigramProbability:
    return static_cast<double>(m_caBigramCount) / m_totalBigramCount;
    break;
  case ccBigramProbability:
    return static_cast<double>(m_ccBigramCount) / m_totalBigramCount;
    break;
  case cgBigramProbability:
    return static_cast<double>(m_cgBigramCount) / m_totalBigramCount;
    break;
  case ctBigramProbability:
    return static_cast<double>(m_ctBigramCount) / m_totalBigramCount;
    break;
  case gaBigramProbability:
    return static_cast<double>(m_gaBigramCount) / m_totalBigramCount;
    break;
  case gcBigramProbability:
    return static_cast<double>(m_gcBigramCount) / m_totalBigramCount;
    break;
  case ggBigramProbability:
    return static_cast<double>(m_ggBigramCount) / m_totalBigramCount;
    break;
  case gtBigramProbability:
    return static_cast<double>(m_gtBigramCount) / m_totalBigramCount;
    break;
  case taBigramProbability:
    return static_cast<double>(m_taBigramCount) / m_totalBigramCount;
    break;
  case tcBigramProbability:
    return static_cast<double>(m_tcBigramCount) / m_totalBigramCount;
    break;
  case tgBigramProbability:
    return static_cast<double>(m_tgBigramCount) / m_totalBigramCount;
    break;
  case ttBigramProbability:
    return static_cast<double>(m_ttBigramCount) / m_totalBigramCount;
    break;
  }
}
/*
  a. calculateMean
  b. @return - a double value that represents the mean of the passed in sumCounter and number of lines.
               (The average length of a DNA linee)
  c. @param - int& sumCounter - an int parameter that represents the collective length of each string in the
              output file.
              int& numberOfLines - an int paramter that represents the overall number of lines in the input
              file.
  d. no exceptions thrown.
*/
double DNA_String::calculateMean(int sumCounter, int numberOfLines)
{
  return static_cast<double>(sumCounter) / numberOfLines;
}
/*
  a. calculateStandardDeviation
  b. @return - a double value that represents the standard deviation of the length of the DNA strings found inside the
               input file.
  c. @param - double varience: a double value that represents the variance of the lengths of strings found inside
              the input file.
  d. no exceptions thrown.
*/
double DNA_String::calculateStandardDeviation(double variance)
{
  return sqrt(variance);
}
DNA_String::DNA_String()
{
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
}
