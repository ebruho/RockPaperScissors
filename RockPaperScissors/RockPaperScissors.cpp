// RockPaperScissors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cstdlib>
#include<ctime>
#include <string>


int generateRandomNum() {
    srand(static_cast<unsigned>(time(nullptr)));
    int computerChoice = rand() % 3;
    return computerChoice;
}

std::string computerChoice() {

    std::string choice = "";

    switch (generateRandomNum())
    {
    case 0:
        choice += "Rock";
        break;
    case 1:
        choice += "Paper";
        break;
    case 2:
        choice += "Scissors";
        break;
    default:
        break;
    }

    return choice;
}

void game(std::string usersChoice,int* userScore, int *computerScore = 0) {
    
    std::string compChoice = computerChoice();


    if ((usersChoice == "Rock" && compChoice == "Scissors") ||
        (usersChoice == "Paper" && compChoice == "Rock") ||
        (usersChoice == "Scissors" && compChoice == "Paper"))
    {
        std::cout << "Congratulations! \nYou win this round! <3";
        (*userScore)++;
    }
    else if((usersChoice == "Scissors" && compChoice == "Rock") ||
        (usersChoice == "Paper" && compChoice == "Scissors") ||
        (usersChoice == "Rock" && compChoice == "Paper"))
    {
        std::cout << "You lose this round! :(";
        (*computerScore)++;
    }
    else if (usersChoice == compChoice) {
        std::cout << "No points";
    }

    std::cout << std::endl << "Your Score " << "| " << "Computer Score ";
    std::cout << std::endl << "\t" << *userScore << "  -  " << *computerScore;
}

int main()
{

    /*
    srand(static_cast<unsigned>(time(nullptr)));
    int computerChoice = rand() % 4;
    std::cout << computerChoice;
    std::cout << " \n";
    */

    std::string answer;

    int userScore = 0, computerScore = 0;

    while (answer != "No")
    {
        std::string usersChoice;
        std::cout << "Enter your choice: ";
        std::cin >> usersChoice;



        std::cout << std::endl;

        //std::cout << generateRandomNum();
        //std::cout << "\n";

        std::cout << "Computer choice: " + computerChoice() << std::endl;

        game(usersChoice, &userScore, &computerScore);

        std::cout << std::endl;

        std::cout << "Do you want to play again? - Yes/No " << std::endl;
        std::cin >> answer;

    }

    
}

