#pragma once

#include <string>
#include <unordered_map>
#include <vector>

class FAQManager {
private:
    std::unordered_map<std::string, std::vector<std::string>> faqs;

public:
    void addQuestion(const std::string& question, const std::vector<std::string>& answers);

    std::vector<std::string> getAnswers(const std::string& question) const;

    bool hasQuestion(const std::string& question) const;
};
