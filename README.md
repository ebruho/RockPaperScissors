# Rock-Paper-Scissors Game

This repository contains a simple command-line implementation of the classic Rock-Paper-Scissors game written in C++.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [How It Works](#how-it-works)
- [Code Structure](#code-structure)
- [Contribution](#contribution)
- [License](#license)

## Introduction

Rock-Paper-Scissors is a hand game usually played between two people. Each player simultaneously forms one of three shapes with their hand:

- **Rock**: A fist
- **Paper**: An open hand
- **Scissors**: A fist with the index and middle fingers extended, forming a V.

The game has simple rules:

- Rock crushes Scissors
- Scissors cut Paper
- Paper covers Rock

This program allows a user to play against the computer in this classic game.

## Features

- Simple command-line interface.
- Random computer choice using C++'s random number generation.
- Input validation to handle different forms of user input.
- Score tracking across rounds.

## Installation

To get started with the Rock-Paper-Scissors game, follow these steps:

1. **Clone the repository:**

   ```bash
   git clone https://github.com/yourusername/RockPaperScissors.git
   cd RockPaperScissors
   ```
   
2. Build the project:

    
   You can compile the code using a C++ compiler like g++:

   ```bash
    g++ -o RockPaperScissors RockPaperScissors.cpp
   ```
3. Run the executable:

    After building the project, you can run the game:

   ```bash
     ./RockPaperScissors
   ```
## Usage
Upon running the program, you will be prompted to enter your choice of Rock, Paper, or Scissors. You can enter the full name or just the first letter (case-insensitive). The program will then display the computer's choice and the result of the round.

Example session:
  ```bash
  Enter your choice (r/R/Rock, p/P/Paper, s/S/Scissors): Rock
  Computer choice: Scissors
  Congratulations! You win this round! <3
  Your Score: 1 | Computer Score: 0

  Do you want to play again? (yes/No): yes

  ```
The game continues until you decide to stop by entering No.

## How It Works
1. **Random Computer Choice:** The computer's choice is determined using a random number generator that produces a number between 0 and 2, corresponding to Rock, Paper, or Scissors.

  ```cpp
  int generateRandomNum() {
    return rand() % 3;
}

std::string getComputerChoice() {
    switch (generateRandomNum()) {
    case 0:
        return "Rock";
    case 1:
        return "Paper";
    case 2:
        return "Scissors";
    default:
        return "Rock";  // This should never happen, but Rock is returned as a fallback
    }
}

  ```
2. **User Input:** The user's input is validated to accept various forms (r, R, Rock, rock, etc.).
  
   ```cpp
    std::string getUserChoice() {
    std::string choice;
    std::cout << "Enter your choice (r/R/Rock, p/P/Paper, s/S/Scissors): ";
    std::cin >> choice;

    if (choice == "r" || choice == "R" || choice == "Rock" || choice == "rock") {
        return "Rock";
    } else if (choice == "p" || choice == "P" || choice == "Paper" || choice == "paper") {
        return "Paper";
    } else if (choice == "s" || choice == "S" || choice == "Scissors" || choice == "scissors") {
        return "Scissors";
    } else {
        return "";
    }
   }
  
  
3. **Game Logic:** The game checks the user's choice against the computer's choice to determine the winner of each round.
   ```cpp
      void playGame(const std::string& userChoice, int* userScore, int* computerScore) {
    std::string compChoice = getComputerChoice();
    std::cout << "Computer choice: " << compChoice << std::endl;

    if ((userChoice == "Rock" && compChoice == "Scissors") ||
        (userChoice == "Paper" && compChoice == "Rock") ||
        (userChoice == "Scissors" && compChoice == "Paper")) {
        std::cout << "Congratulations! You win this round! <3\n";
        (*userScore)++;
    } else if ((userChoice == "Scissors" && compChoice == "Rock") ||
               (userChoice == "Paper" && compChoice == "Scissors") ||
               (userChoice == "Rock" && compChoice == "Paper")) {
        std::cout << "You lose this round! :(\n";
        (*computerScore)++;
    } else if (userChoice == compChoice) {
        std::cout << "It's a tie! No points.\n";
    } else {
        std::cout << "Invalid choice. Try again.\n";
    }

    std::cout << "Your Score: " << *userScore << " | Computer Score: " << *computerScore << std::endl;
   }
    ```
   
4. **Score Tracking:** Scores are tracked across multiple rounds and displayed after each game.

## Code Structure
- main() function:
  - Initializes the game.
  - Handles user input and game loop.
  - Tracks and displays scores
  ```cpp
    int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    int userScore = 0, computerScore = 0;
    std::string answer = "yes";

    while (answer != "no" && answer != "No") {
        std::string userChoice = getUserChoice();

        if (!userChoice.empty()) {
            playGame(userChoice, &userScore, &computerScore);
        } else {
            std::cout << "You chose an invalid option. Please try again.\n";
        }

        std::cout << "Do you want to play again? (yes/No): ";
        std::cin >> answer;
    }

    std::cout << "Thanks for playing! Final Scores -> You: " << userScore << " | Computer: " << computerScore << std::endl;

    return 0;
  }
  ```
- generateRandomNum() function:
  - Generates a random number to decide the computer's move.
- getComputerChoice() function:
  - Returns the computer's choice as a string based on the generated random number.
- getUserChoice() function:
  - Prompts the user for their choice and validates it.
- playGame() function:
  - Compares the user's choice with the computer's choice and updates scores.
  - Displays the outcome of each round.

 ## Contribution
  Contributions are welcome! If you have suggestions for improvements or new features, feel free to create an issue or submit a pull request.
