/*
    Author: Tyler Wilcock
    Date: February 1st, 2014
    Description: The goal of this program is to solve a 6 city traveling salesman problem using a bruteforce method.
                 I would like to, at some point, make this program dynamic so that I can change the number of cities
                 and give the coordinates to each city as input.  This would obviously require reconstruction of the 
                 program from the bottom up.   
*/

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
        int numOfPoints = 6;
        int comboCounter = 0;
        int lowestDistancePoint;
        int points[numOfPoints][2]; // Number of cities in the first dimension, and 2 spots for the x and y coordinates in the second dimension
        int numOfPointsMultiplied = numOfPoints * numOfPoints * numOfPoints * numOfPoints * numOfPoints * numOfPoints;
        double results[numOfPointsMultiplied];
        double lowestDistance = 1000000000;  //set the lowest distance impossibly high to start.  There's probably a better way to accomplish this same result
        int resultsArray[numOfPointsMultiplied][numOfPoints];  //Used for storing the value of each for loop (or "city") within the final for loop

        //enter x, y coordinates given to us
        points [0][0] = 38;
        points [0][1] = 58;
        points [1][0] = 15;
        points [1][1] = 51;
        points [2][0] = 10;
        points [2][1] = 19;
        points [3][0] = 86;
        points [3][1] = 49;
        points [4][0] = 84;
        points [4][1] = 60;
        points [5][0] = 40;
        points [5][1] = 20;
	
	    //Iterate through 6 for loops to generate points for all 6 cities
        for(int i = 0; i < numOfPoints; i++)
        {
                for(int j = 0; j < numOfPoints; j++)
                {
                        for(int k = 0; k < numOfPoints; k++)
                        {
                                for(int a = 0; a < numOfPoints; a++)
                                {
                                        for(int z = 0; z < numOfPoints; z++)
                                        {
                                                for(int d = 0; d < numOfPoints; d++)
                                                {
                                                        //Store the value of each for loop value - each is a city
                                                        resultsArray[comboCounter][0] = i;
                                                        resultsArray[comboCounter][1] = j;
                                                        resultsArray[comboCounter][2] = k;
                                                        resultsArray[comboCounter][3] = a;
                                                        resultsArray[comboCounter][4] = z;
                                                        resultsArray[comboCounter][5] = d;

                                                        //Check to make sure each city isn't the same to ensure a proper path.  There's probably a better way to do this.

                                                        //For example, a proper path would be; 0 5 3 2 1 4 0.  Improper path would be: 0 5 5 3 1 2 0, 5 is repeated and 4 is //subsequently excluded.

                                                        if(i != j && i != k && i != a && i != z && i != d && i != 0 && j != 0 && j != k && j != a && j != k && j != a && j != z && j != d && k != a && k != z && k != d && k != 0 && a != z && a != d && a != 0 && z != 0 && d != 0)
                                                        {
								                                results[comboCounter] =
                                                                sqrt((points[0][0] - points[i][0]) * (points[0][0] - points[i][0]) + (points[0][1] - points[i][1]) * (points[0][1] - points[i][1])) +
                                                                sqrt((points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1])) +
                                                                sqrt((points[j][0] - points[k][0]) * (points[j][0] - points[k][0]) + (points[j][1] - points[k][1]) * (points[j][1] - points[k][1])) +
                                                                sqrt((points[k][0] - points[a][0]) * (points[k][0] - points[a][0]) + (points[k][1] - points[a][1]) * (points[k][1] - points[a][1])) +
                                                                sqrt((points[a][0] - points[z][0]) * (points[a][0] - points[z][0]) + (points[a][1] - points[z][1]) * (points[a][1] - points[z][1])) +
                                                                sqrt((points[z][0] - points[d][0]) * (points[z][0] - points[d][0]) + (points[z][1] - points[d][1]) * (points[z][1] - points[d][1])) +
                                                                sqrt((points[d][0] - points[0][0]) * (points[d][0] - points[0][0]) + (points[d][1] - points[0][1]) * (points[d][1] - points[0][1]));
                                                                cout << "Combination number " << comboCounter << " is " << results[comboCounter] << "\n";
                                                                comboCounter++;
                                                        }//end if
                                                }//end for d
                                        }//end for z
                                }//end for a
                        }//end for k
                }//end for j
        }//end for i

        for(int x = 0; x < comboCounter; x++)
        {
                if(lowestDistance > results[x] && lowestDistance != results[x] && results[x] != 0)
                {
                        lowestDistance = results[x];
                        lowestDistancePoint = x;
                }//end if
        }//end for x

        cout << "\n\n\nThe lowest distance path is:\n0 ";
        cout << resultsArray[lowestDistancePoint][0] << " " << resultsArray[lowestDistancePoint][1] << " " << resultsArray[lowestDistancePoint][2]
             << " " << resultsArray[lowestDistancePoint][3] << " " << resultsArray[lowestDistancePoint][4] << " 0\n";

        cout << "Distance traveled: " << lowestDistance << "\n\n\n";

}//end main