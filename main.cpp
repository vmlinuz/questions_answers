#include "faqmanager.h"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


void printMenu() {
    std::cout << "Choose an option:\n"
              << "1. Add a question and its answers\n"
              << "2. Ask a question\n"
              << "3. Exit\n"
              << "> ";
}

std::vector<std::string> parseAnswers(std::istringstream& iss) {
    std::vector<std::string> answers;
    std::string answer;
    while (iss >> std::quoted(answer)) {
        answers.push_back(answer);
    }
    return answers;
}

int main() {
    FAQManager faqManager;
    int choice;
    std::string input;

    while (true) {
        printMenu();
        std::cin >> choice;
        std::cin.ignore(); // Ignore newline after integer input

        if (choice == 1) {
            std::cout << "Enter the question followed by a '?', then the answers enclosed in quotes:\n";
            std::getline(std::cin, input);
            std::size_t pos = input.find('?');
            if (pos != std::string::npos) {
                std::string question = input.substr(0, pos + 1);
                std::istringstream iss(input.substr(pos + 1));
                std::vector<std::string> answers = parseAnswers(iss);
                faqManager.addQuestion(question, answers);
                std::cout << "Question added successfully.\n";
            } else {
                std::cout << "Invalid format. Please ensure the question ends with a '?' followed by answers.\n";
            }
        } else if (choice == 2) {
            std::cout << "Enter the question to retrieve the answers:\n";
            std::getline(std::cin, input);
            std::vector<std::string> answers = faqManager.getAnswers(input);
            std::cout << "Answers:\n";
            for (const auto& answer : answers) {
                std::cout << "- " << answer << std::endl;
            }
        } else if (choice == 3) {
            break;  // Exit the program
        } else {
            std::cout << "Invalid choice. Please select a valid option.\n";
        }
    }

    return 0;
}
