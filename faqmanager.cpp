#include "faqmanager.h"
#include <algorithm>
#include <set>

bool FAQManager::isValidInput(const std::string& input, bool isQuestion) const {
    return !(input.empty() || input.size() > MAX_LENGTH || (isQuestion && input.back() != '?'));
}

void FAQManager::addQuestion(const std::string &question, const std::vector<std::string> &answers) {
    if (!isValidInput(question, true) || std::any_of(answers.begin(), answers.end(), [&](const std::string &answer) {
            return !isValidInput(answer);
        })) {
        faqs[question] = {INVALID_INPUT};
        return;
    }

    std::set<std::string> seen;
    std::vector<std::string> uniqueAnswers;
    for (const auto& answer : answers) {
        if (seen.insert(answer).second) {
            uniqueAnswers.push_back(answer);
        }
    }
    faqs[question] = uniqueAnswers;
}

std::vector<std::string> FAQManager::getAnswers(const std::string &question) const {
    auto it = faqs.find(question);
    if (it != faqs.end()) {
        return it->second;
    }
    return {DEFAULT_ANSWER};
}

bool FAQManager::hasQuestion(const std::string &question) const {
    return faqs.count(question) > 0;
}
