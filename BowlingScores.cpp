/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/   Write a program to calculate a bowling league's average bowling scores.                                                                        /
/   You will need to read the input data from the file BowlingScores.txt                                                                           /
/   Note: The file format is guaranteed to remain the same.                                                                                        /
/                                                                                                                                                  /
/   You must use three arrays :                                                                                                                    /
/       a one - dimensional array to store the bowler's names.                                                                                     /
/                                                                                                                                                  /
/       a(parallel) two - dimensional array to store the bowling scores.                                                                           /
/                                                                                                                                                  /
/       a one - dimensional array to store the bowler's average score.                                                                             /
/                                                                                                                                                  /
/   Your program must contain at least the following functions :                                                                                   /
/       a function called GetBowlingData to read and store data into two arrays.                                                                   /
/       The function should take as input parameters the file name and both empty arrays,                                                          /
/       which it should fill from the file(BowlingScores.txt) and return a status of either success or failure(i.e true or false).                 /
/                                                                                                                                                  /
/       a function called GetAverageScore that is used to calculate the average bowling score.                                                     /
/       The function should take as input the populated arrays and return the average score of each bowler in a separate array.                    /
/                                                                                                                                                  /
/       a function called PrettyPrintResults to output the results, i.e., bowler name, scoresand average.                                          /
/                                                                                                                                                  /
/   Don't use Vectors or any other newfangled container, use only old school C arrays like in the book.                                            /
/   Use repetition structures(loops) in your functions to perform calculations and printing.                                                       /
/   Remember "dimensions = loops".So, a 2 - dimensional array will require 2 loops to completely iterate over all of the elements in the array.    /
/   Don't use magic numbers. Instead use global constants at the top of the program under the includes.                                            /
/                                                                                                                                                  /
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// BY ISSA HABEEB */


#include <iostream>   // GIVES "cin" AND "cout"
#include <fstream>    // INPUTS/OUTPUTS TO A FILE
#include <iomanip>    // GIVES "setfill(char)", "setw(int)" AND "setprecision(int)"
#include <string>     // GIVES "string" DATA TYPE
using namespace std;

// CONSTANT VARIABLES
const int NUM_OF_BOWLERS = 11;
const int NUM_OF_SCORES = 5;


// To read and store data into two arrays. The function should take as input parameters the file name and both empty arrays
bool GetBowlingData(string INPUTFILENAME, string bowler_names[], int bowler_scores[][NUM_OF_SCORES])
{
    // Opens file
    ifstream InputStream;
    InputStream.open(INPUTFILENAME);
    // Checks if file opened correctly
    if (!InputStream)
    {
        cout << "'" << INPUTFILENAME << "' file could not be found\n" << endl;
        system("pause");
        return false;
    }
    else
        cout << "Loading file: '" << INPUTFILENAME << "'...\n\n" << endl; 

    // Variables to store into
    string get_name;
    int get_score1;
    int get_score2;
    int get_score3;
    int get_score4;
    int get_score5;

    // One dimension array
    for (int row = 0; row < NUM_OF_BOWLERS; row++)
    { 
        // Gets data
        InputStream >> get_name >> get_score1 >> get_score2 >> get_score3 >> get_score4 >> get_score5;
        // Sstores names based off index
        bowler_names[row] += get_name;

        enum scores {FIRST_SCORE, SECOND_SCORE, THIRD_SCORE, FOURTH_SCORE, FIFTH_SCORE};

        // Two dimension array
        for (int column = 0; column < NUM_OF_SCORES; column++)
        {
            // Stores score based off index
            switch (column)
            {
            case FIRST_SCORE:
                bowler_scores[row][column] = get_score1;
                break;
            case SECOND_SCORE:
                bowler_scores[row][column] = get_score2;
                break;
            case THIRD_SCORE:
                bowler_scores[row][column] = get_score3;
                break;
            case FOURTH_SCORE:
                bowler_scores[row][column] = get_score4;
                break;
            case FIFTH_SCORE:
                bowler_scores[row][column] = get_score5;
                break;
            }
        }
    }
    // Closes file and returns true
    InputStream.close();
    return true;
}

//  Calculate the average bowling score. The function should take as input the populated arrays and return the average score of each bowler in a separate array.
void GetAverageScore(string bowler_names[], int bowler_scores[][NUM_OF_SCORES], int bowler_average[])
{
    // One dimension array
    for (int row = 0; row < NUM_OF_BOWLERS; row++)
    {
        // Initially set everything in the array to 0
        bowler_average[row] = 0;
        // Two dimension array
        for (int column = 0; column < NUM_OF_SCORES; column++)
        {
            // Technically gets the total and not the average
            bowler_average[row] += bowler_scores[row][column];
        }
        // Divdes the total by number of scores to get average
        bowler_average[row] = bowler_average[row] / NUM_OF_SCORES;
    }
}

// Output the results, i.e., bowler name, scores and average.
void PrettyPrintResults(string bowler_names[], int bowler_scores[][NUM_OF_SCORES], int bowler_average[])
{
    cout << setfill(' ');
    // One dimension array
    for (int row = 0; row < NUM_OF_BOWLERS; row++)
    {
        // Outputs name
        cout << "Name: " << bowler_names[row] << setw(20 - bowler_names[row].length()) << "Scores: ";
        // Two dimension array
        for (int column = 0; column < NUM_OF_SCORES; column++)
        {
            // Outputs scores
            cout << bowler_scores[row][column] << " ";
        }
        // Outputs average
        cout << "\n" << setw(27) << "Average: " << bowler_average[row] << "\n" << endl;
    }
    cout << endl;
}


int main()
{
    // Txt file name
    const string INPUTFILENAME = "BowlingScores.txt";

    // Bowler names list
    string bowler_names[NUM_OF_BOWLERS];

    // Bowler scores list
    int bowler_scores[NUM_OF_BOWLERS][NUM_OF_SCORES];

    // Bowler average list
    int bowler_average[NUM_OF_BOWLERS];


    // Functions with arguments being passed (mostly arrays)
    GetBowlingData(INPUTFILENAME, bowler_names, bowler_scores);
    GetAverageScore(bowler_names, bowler_scores, bowler_average);
    PrettyPrintResults(bowler_names, bowler_scores, bowler_average);

    // Pauses console and "int main()" return 0 after function completion. 
    system("pause");
    return 0;
}


/*

    while (InputStream >> get_name >> get_score1 >> get_score2 >> get_score3 >> get_score4)
    {
        cout << get_name << " " << get_score1 << " " << get_score2 << " " << get_score3 << " " << get_score4 << endl;
        bowler_names[index] += get_name;
        index++;

        for (int i = 0; i < NUM_OF_BOWLERS; i++)
            for (int j = 0; j < NUM_OF_SCORES; j++)
            {
                switch (j)
                {
                case 0:
                bowler_scores[i][j] += get_score1;
                break;
                case 1:
                bowler_scores[i][j] += get_score2;
                break;
                case 2:
                bowler_scores[i][j] += get_score3;
                break;
                case 3:
                bowler_scores[i][j] += get_score4;
                break;
                }

                cout << bowler_scores[i][j] << endl;
            }
    }

    ^old broken code

    I was really struggling at this assignment because I had a lot of trouble passing in arguments for function parameters. 
    The reason for that was due to the debugger confusing me. When I debugged my code with parameters I couldn't really see
    all the values in my arrays/lists from Autos but I think it has to do with it being a pointer or something. 
    Without parameters and arguments I could easily see the values more clearly in Autos. 

*/
