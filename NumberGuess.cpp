#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    // To store the random number
    int number;

    // To store the user's guess
    int guess;
    
    // Generate a random number between 1 and 100
    srand(time(0));

    number = rand() % 100 + 1;

    // Loop until the user guesses the correct number
    do
    {
        cout << "Enter your guess: ";
        cin >> guess;

        // Check if the guess is too high, too low, or correct
        if (guess > number)
        {
            cout << "Your guess is too high." << endl;
        }
        else if (guess < number)
        {
            cout << "Your guess is too low." << endl;
        }
        else
        {
            cout << "You guessed it right!" << endl;
        }
    } while (guess != number);

    return 0;
}
