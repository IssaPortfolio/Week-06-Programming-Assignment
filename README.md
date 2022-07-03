Write a program to calculate a bowling league's average bowling scores. 
You will need to read the input data from the file BowlingScores.txt)
Note: The file format is guaranteed to remain the same.
    
    • You must use three arrays:
      • a one-dimensional array to store the bowler's names.
      • a (parallel) two-dimensional array to store the bowling scores.
      • a one-dimensional array to store the bowler's average score.
  
    • Your program must contain at least the following functions:
      • a function called GetBowlingData to read and store data into two arrays. 
        The function should take as input parameters the file name and both empty arrays, 
        which it should fill from the file (BowlingScores.txt)
        and return a status of either success or failure (i.e true or false). 
      • a function called GetAverageScore that is used to calculate the average bowling score. 
        The function should take as input the populated arrays and return the average score of 
        each bowler in a separate array.
      • a function called PrettyPrintResults to output the results, i.e., bowler name, scores and average.
      
    • Don't use Vectors or any other newfangled container, use only old school C arrays like in the book.
    • Use repetition structures (loops) in your functions to perform calculations and printing. 
      Remember "dimensions = loops". 
      So, a 2-dimensional array will require 2 loops to completely iterate over all of the elements in the array.
    • Don't use magic numbers. Instead use global constants at the top of the program under the includes.

--------------------------------------------------------------------------------------------------------------------------------------

Added new bowler, "IssaHabeeb," and added fifth score to each bowler.
