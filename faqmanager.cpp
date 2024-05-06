#include "faqmanager.h"

// Constants for default messages and commands
const std::string DEFAULT_ANSWER = "the answer to life, universe and everything is 42";

void FAQManager::addQuestion(const std::string &question, const std::vector<std::string> &answers) {
    faqs[question] = answers;
}

std::vector<std::string> FAQManager::getAnswers(const std::string &question) const {
    if (faqs.find(question) != faqs.end()) {
        return faqs.at(question);
    } else {
        return {DEFAULT_ANSWER};
    }
}

bool FAQManager::hasQuestion(const std::string &question) const {
    return faqs.find(question) != faqs.end();
}
