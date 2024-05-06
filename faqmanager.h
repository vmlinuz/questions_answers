#pragma once

#include <string>
#include <unordered_map>
#include <vector>

class FAQManager {
private:
    std::unordered_map<std::string, std::vector<std::string>> faqs;
    static constexpr size_t MAX_LENGTH = 255;
    static constexpr const char* DEFAULT_ANSWER = "the answer to life, universe and everything is 42";
    static constexpr const char* INVALID_INPUT = "Invalid input";

    bool isValidInput(const std::string& input, bool isQuestion = false) const;

public:
    void addQuestion(const std::string& question, const std::vector<std::string>& answers);
    std::vector<std::string> getAnswers(const std::string& question) const;
    bool hasQuestion(const std::string& question) const;
};
