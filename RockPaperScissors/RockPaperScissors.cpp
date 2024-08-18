// RockPaperScissors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

const std::string ROCK = "Rock";
const std::string PAPER = "Paper";
const std::string SCISSORS = "Scissors";

int generateRandomNum() {
    return rand() % 3;
}

std::string getComputerChoice() {
    switch (generateRandomNum()) {
    case 0:
        return ROCK;
    case 1:
        return PAPER;
    case 2:
        return SCISSORS;
    default:
        std::cerr << "Error: Invalid random number generated." << std::endl;
        std::exit(EXIT_FAILURE);  // Terminate the program with an error status
    }
}

std::string getUserChoice() {
    std::string choice;
    std::cout << "Enter your choice (r/R/Rock, p/P/Paper, s/S/Scissors): ";
    std::cin >> choice;

    if (choice == "r" || choice == "R" || choice == ROCK || choice == "rock") {
        return ROCK;
    }
    else if (choice == "p" || choice == "P" || choice == PAPER || choice == "paper") {
        return PAPER;
    }
    else if (choice == "s" || choice == "S" || choice == SCISSORS || choice == "scissors") {
        return SCISSORS;
    }
    else {
        return "";
    }
}

void playGame(const std::string& userChoice, int* userScore, int* computerScore) {
    std::string compChoice = getComputerChoice();
    std::cout << "Computer choice: " << compChoice << std::endl;

    if ((userChoice == ROCK && compChoice == SCISSORS) ||
        (userChoice == PAPER && compChoice == ROCK) ||
        (userChoice == SCISSORS && compChoice == PAPER)) {
        std::cout << "Congratulations! You win this round! <3\n";
        (*userScore)++;
    }
    else if ((userChoice == SCISSORS && compChoice == ROCK) ||
        (userChoice == PAPER && compChoice == SCISSORS) ||
        (userChoice == ROCK && compChoice == PAPER)) {
        std::cout << "You lose this round! :(\n";
        (*computerScore)++;
    }
    else if (userChoice == compChoice) {
        std::cout << "It's a tie! No points.\n";
    }
    else {
        std::cout << "Invalid choice. Try again.\n";
    }

    std::cout << "Your Score: " << *userScore << " | Computer Score: " << *computerScore << std::endl;
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    int userScore = 0, computerScore = 0;
    std::string answer = "yes";

    while (answer != "no" && answer != "No") {
        std::string userChoice = getUserChoice();

        if (!userChoice.empty()) {
            playGame(userChoice, &userScore, &computerScore);
        }
        else {
            std::cout << "You chose an invalid option. Please try again.\n";
        }

        std::cout << "Do you want to play again? (yes/No): ";
        std::cin >> answer;
    }

    std::cout << "Thanks for playing! Final Scores -> You: " << userScore << " | Computer: " << computerScore << std::endl;

    return 0;
}
