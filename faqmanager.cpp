#include "faqmanager.h"

#include <algorithm>
#include <set>

const std::string DEFAULT_ANSWER = "the answer to life, universe and everything is 42";
const size_t MAX_LENGTH = 255;

void FAQManager::addQuestion(const std::string &question, const std::vector<std::string> &answers) {
    if (question.empty() || question.size() > MAX_LENGTH || question.back() != '?' ||
        std::any_of(answers.begin(), answers.end(), [&](const std::string &answer) {
            return answer.empty() || answer.size() > MAX_LENGTH;
        })) {
        // If invalid, return appropriate message.
        faqs[question] = {"Invalid input"};
        return;
    }

    // Maintain order but remove duplicates
    std::vector<std::string> uniqueAnswers;
    std::set<std::string> seen;
    for (const auto& answer : answers) {
        if (seen.insert(answer).second) { // Check if insertion took place (i.e., item was not already present)
            uniqueAnswers.push_back(answer);
        }
    }

    // Overwrite the existing question with new answers
    faqs[question] = uniqueAnswers;
}

std::vector<std::string> FAQManager::getAnswers(const std::string &question) const {
    auto it = faqs.find(question);
    if (it != faqs.end()) {
        return it->second;
    }
    return {DEFAULT_ANSWER};  // Return default answer if not found
}

bool FAQManager::hasQuestion(const std::string &question) const {
    return faqs.count(question) > 0;
}
