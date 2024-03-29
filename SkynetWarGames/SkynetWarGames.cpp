// SkynetWarGames.cpp
//Nathaniel Grimsley
//October 16, 2018
//Version 1.0.0

//We are including the following dependancies.
#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//we start the main function, where the project begins and ends
int main()
{
	// set a kill variable for the game loop.
	char playAgain = 'y';
	//start the game loop which will end if the user inputs anything other than 'y' at the end of the game.
	while (playAgain == 'y')
	{
		//seed the random number generator
		srand(static_cast<unsigned int>(time(0)));
		
		//we instantiate and set two integers, one for the bottom limit of the grid and the other for the top limit.
		int searchGridLowNumber = 1;
		int searchGridHighNumber = 64;
		//each of these integers are instantiated to store the number of tries it takes to find the enemy with each method.
		int binaryTries = 0;
		int linearTries = 0;
		int randomTries = 0;
		int humanTries = 0;
		//this is a random number between 1 and 64, which is the target's location.
		int targetLocation = rand() % 64 + 1;
		//these are set up to later store the AIs prediction for the location of the enemy.
		int binaryLocationPrediction = 0;
		int linearLocationPrediction = 0;
		int randomLocationPrediction = 0;
		int humanLocationPrediction = 0;

		//push the introduction to the program to the console.
		cout << "\n\nGenerate Random enemy location on 8x8 grid..." << endl;
		cout << "The enemy is located at location #[classified] on 8x8 grid with 1-64 sectors." << endl;
		cout << "Skynet HK-Aerial Initializing software....." << endl;

		//start a while loop for the human guess which will run until the human's guess is equal to the target's location
		while (humanLocationPrediction != targetLocation)
		{
			//increment the amount of tries for the user.
			humanTries++;

			//we are asking the user to pick a number between the known low number and high number
			cout << "Where is the target? Choose between " << searchGridLowNumber << " and " << searchGridHighNumber << ": ";
			//we accept user input into the humanLocationPrediction variable.
			cin >> humanLocationPrediction;

			//we are starting an if statement to test whether the prediction is too high or too low.
			if (humanLocationPrediction > targetLocation)
			{
				//we change the high number on the search grid since the target will not be between your
				//current guess and the current high number.
				searchGridHighNumber = humanLocationPrediction - 1;
				//We begin pushing the new data to the console.
				cout << "=========================================================================" << endl;
				cout << "Skynet HK-Aerial Radar sending out ping #" << humanTries << endl;
				cout << "The target location prediction of " << humanLocationPrediction << " was higher than the actual enemy location of [classified]." << endl;
				cout << "The new searchGridHighNumber = " << searchGridHighNumber << endl;
			}
			//we are starting an else if in case the number was too low.
			else if (humanLocationPrediction < targetLocation)
			{
				//We change the low number on the search grid since the targer will not be between your
			//current guess and the current high number.
				searchGridLowNumber = humanLocationPrediction + 1;
				//We begin pushing the new data to the console.
				cout << "=========================================================================" << endl;
				cout << "Skynet HK-Aerial Radar sending out ping #" << humanTries << endl;
				cout << "The target location prediction of " << humanLocationPrediction << " was lower than the actual enemy location of [classified]." << endl;
				cout << "The new searchGridLowNumber = " << searchGridLowNumber << endl;
			}
			//otherwise, if the prediction is the same as the target's location.
			else
			{
				//We reset the high and low numbers for the search grid for the next AI
				searchGridLowNumber = 1;
				searchGridHighNumber = 64;

				//We push the final data to the console.
				cout << "=========================================================================" << endl;
				cout << "Skynet HK-Aerial Radar sending out ping #" << humanTries << endl;
				cout << "Enemy was hiding at location #" << targetLocation << endl;
				cout << "Target was found at location #" << humanLocationPrediction << endl;
				cout << "Skynet HK-Aerial Software took " << humanTries << " predictions to find the enemy location on a grid size of 8x8 (64)\n\n" << endl;
			}
		}
		
		//start a while loop for the random guess which will run until the random guess is equal to the target's location
		while (randomLocationPrediction != targetLocation)
		{
			//increment the amount of tries for random AI.
			randomTries++;

			//As long as the low number and the high number are not the same, we use the randomLocationPrediction formula
			//We do this because if the numbers are the same and we try to use the formula, the modulus operator tries
			//to divide by zero.
			if (searchGridLowNumber != searchGridHighNumber)
			{
				//we store a random number for the random AI's guess.
			//This number is random, but is updated to use a list of numbers between the current
			//searchGridHighNumber and the SearchGridLowNumber
				randomLocationPrediction = (rand() % (searchGridHighNumber - searchGridLowNumber)) + searchGridLowNumber;
			}
			//if the numbers are the same, we just set the randomLocationPrediction equal to that number
			else
			{
				//set the randomLocationPrediction equal to the searchGridLowNumber
				randomLocationPrediction = searchGridLowNumber;
			}

			//we are starting an if statement to test whether the prediction is too high or too low.
			if (randomLocationPrediction > targetLocation)
			{
				//We begin pushing the new data to the console.
				cout << "=========================================================================" << endl;
				cout << "Skynet HK-Aerial Radar sending out ping #" << randomTries << endl;
				cout << "Picking a number between " << searchGridLowNumber << " and " << searchGridHighNumber << endl;
				cout << "The target location prediction of " << randomLocationPrediction << " was higher than the actual enemy location of " << targetLocation << "." << endl;
				
				//we change the high number on the search grid since the target will not be between your
				//current guess and the current high number.
				searchGridHighNumber = randomLocationPrediction - 1;
				
				cout << "The new searchGridHighNumber = " << searchGridHighNumber << endl;
			}
			//we are starting an else if in case the number was too low.
			else if (randomLocationPrediction < targetLocation)
			{
				//We begin pushing the new data to the console.
				cout << "=========================================================================" << endl;
				cout << "Skynet HK-Aerial Radar sending out ping #" << randomTries << endl;
				cout << "Picking a number between " << searchGridLowNumber << " and " << searchGridHighNumber << endl;
				cout << "The target location prediction of " << randomLocationPrediction << " was lower than the actual enemy location of "<< targetLocation << "."  << endl;

				//We change the low number on the search grid since the targer will not be between your
				//current guess and the current high number.
				searchGridLowNumber = randomLocationPrediction + 1;

				cout << "The new searchGridLowNumber = " << searchGridLowNumber << endl;

			}
			//otherwise, if the prediction is the same as the target's location.
			else
			{
				//We reset the high and low numbers for the search grid for the next AI
				searchGridLowNumber = 1;
				searchGridHighNumber = 64;

				//We push the final data to the console.
				cout << "=========================================================================" << endl;
				cout << "Skynet HK-Aerial Radar sending out ping #" << randomTries << endl;
				cout << "Enemy was hiding at location #" << targetLocation << endl;
				cout << "Target was found at location #" << randomLocationPrediction << endl;
				cout << "Skynet HK-Aerial Software took " << randomTries << " predictions to find the enemy location on a grid size of 8x8 (64)\n\n" << endl;
			}
		}

		//start a while loop for the linear guess which will run until the linear guess is equal to the target's location
		while (linearLocationPrediction != targetLocation)
		{
			//increment the amount of tries for random AI.
			linearTries++;

			//increment the linear variable each loop, so it increases by one.
			linearLocationPrediction++;

			//start an if statement to run if the AIs prediction is lower than the target location.
			if (linearLocationPrediction < targetLocation)
			{
				//We begin pushing the new data to the console.
				cout << "=========================================================================" << endl;
				cout << "Skynet HK-Aerial Radar sending out ping #" << linearTries << endl;
				cout << "The target location prediction of " << linearLocationPrediction << " was lower than the actual enemy location of " << targetLocation << "." << endl;
			}
			else
			{
				//We push the final data to the console.
				cout << "=========================================================================" << endl;
				cout << "Skynet HK-Aerial Radar sending out ping #" << linearTries << endl;
				cout << "Enemy was hiding at location #" << targetLocation << endl;
				cout << "Target was found at location #" << linearLocationPrediction << endl;
				cout << "Skynet HK-Aerial Software took " << linearTries << " predictions to find the enemy location on a grid size of 8x8 (64)\n\n" << endl;
			}
		}

		//This while loop runs until the predicted target location is the same as the target's actual location.
		while (binaryLocationPrediction != targetLocation)
		{
			//we set a new value to targetLocationPrediction according to a binary algorithm.
			binaryLocationPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
			//We increment the number of tries every try.
			binaryTries++;

			//if our new prediction is higher than the target's location
			if (binaryLocationPrediction > targetLocation)
			{
				//we change the high number on the search grid since the target will not be between your
				//current guess and the current high number.
				searchGridHighNumber = binaryLocationPrediction - 1;
				//We begin pushing the new data to the console.
				cout << "=========================================================================" << endl;
				cout << "Skynet HK-Aerial Radar sending out ping #" << binaryTries << endl;
				cout << "The target location prediction of " << binaryLocationPrediction << " was higher than the actual enemy location of " << targetLocation << "." << endl;
				cout << "The new searchGridHighNumber = " << searchGridHighNumber << endl;
			}
			//otherwise if the prediction is lower than the target's location
			else if (binaryLocationPrediction < targetLocation)
			{
				//We change the low number on the search grid since the targer will not be between your
				//current guess and the current high number.
				searchGridLowNumber = binaryLocationPrediction + 1;
				//We begin pushing the new data to the console.
				cout << "=========================================================================" << endl;
				cout << "Skynet HK-Aerial Radar sending out ping #" << binaryTries << endl;
				cout << "The target location prediction of " << binaryLocationPrediction << " was lower than the actual enemy location of " << targetLocation << "." << endl;
				cout << "The new searchGridLowNumber = " << searchGridLowNumber << endl;
			}
			//otherwise, if the prediction is the same as the target's location.
			else
			{
				//We push the final data to the console.
				cout << "=========================================================================" << endl;
				cout << "Skynet HK-Aerial Radar sending out ping #" << binaryTries << endl;
				cout << "Enemy was hiding at location #" << targetLocation << endl;
				cout << "Target was found at location #" << binaryLocationPrediction << endl;
				cout << "Skynet HK-Aerial Software took " << binaryTries << " predictions to find the enemy location on a grid size of 8x8 (64)\n\n" << endl;
			}

		}
		
		//push the final data to the console
		cout << "=========================================================================" << endl;
		cout << "= All drones have found the enemy.\n";
		cout << "= The enemy was hiding at location " << targetLocation << ".\n";
		cout << "=\n";
		cout << "= The human player using a human search took " << humanTries <<" guesses to find the enemy location final target prediction was " << humanLocationPrediction << "\n";
		cout << "= The AI player using a Random search took " << randomTries << " guesses to find the enemy location final target prediction was " << randomLocationPrediction << "\n";
		cout << "= The AI player using a Linear search took " << linearTries << " guesses to find the enemy location final target prediction was " << linearLocationPrediction << "\n";
		cout << "= The AI player using a Binary search took " << binaryTries << " guesses to find the enemy location final target prediction was " << binaryLocationPrediction << "\n";
		cout << "=========================================================================" << endl;

		//we see if the player would like to play again and store the answer in our playAgain variable.
		cout << "\n\n Would you like to play again? (y/n): ";
		cin >> playAgain;
	}

	//as main is an integer, we return a number.
	return 0;
}
