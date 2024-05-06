#include <gtest/gtest.h>

#include "faqmanager.h"

// Test adding a question and retrieving answers
TEST(FAQManagerTest, AddAndGetAnswers) {
    FAQManager faqManager;
    std::vector<std::string> answers = {"Pizza", "Spaghetti", "Ice cream"};
    std::string question = "What is Peter's favorite food?";

    faqManager.addQuestion(question, answers);
    std::vector<std::string> retrievedAnswers = faqManager.getAnswers(question);

    EXPECT_EQ(answers, retrievedAnswers);
}

// Test querying a question that does not exist
TEST(FAQManagerTest, QueryNonexistentQuestion) {
    FAQManager faqManager;
    std::string question = "When is Peter's birthday?";

    std::vector<std::string> expected = {"the answer to life, universe and everything is 42"};
    std::vector<std::string> answer = faqManager.getAnswers(question);

    EXPECT_EQ(expected, answer);
}

// You can add more tests to cover all functionalities

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
