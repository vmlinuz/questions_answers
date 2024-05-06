#include <gtest/gtest.h>

#include "faqmanager.h"

class FAQManagerTest : public ::testing::Test {
protected:
    FAQManager faqManager;
    const std::vector<std::string> invalidInputResponse{FAQManager::INVALID_INPUT};

    void SetUp() override {
        // This setup runs before each test if needed.
    }
};

TEST_F(FAQManagerTest, AddAndGetSingleAnswer) {
    std::string question = "What is Peter's favorite food?";
    std::vector<std::string> answers = {"Pizza"};

    faqManager.addQuestion(question, answers);
    auto retrievedAnswers = faqManager.getAnswers(question);

    EXPECT_EQ(answers, retrievedAnswers);
}

TEST_F(FAQManagerTest, AddAndGetMultipleAnswers) {
    std::string question = "What is Peter's favorite food?";
    std::vector<std::string> answers = {"Pizza", "Spaghetti", "Ice cream"};

    faqManager.addQuestion(question, answers);
    auto retrievedAnswers = faqManager.getAnswers(question);

    EXPECT_EQ(answers, retrievedAnswers);
}

TEST_F(FAQManagerTest, NonExistentQuestion) {
    std::string question = "When is Peter's birthday?";

    auto retrievedAnswers = faqManager.getAnswers(question);

    EXPECT_EQ(retrievedAnswers, std::vector<std::string>{FAQManager::DEFAULT_ANSWER});
}

TEST_F(FAQManagerTest, OverwriteQuestion) {
    std::string question = "What is the best programming language?";
    std::vector<std::string> firstAnswers = {"C++"};
    std::vector<std::string> secondAnswers = {"Python", "JavaScript"};

    faqManager.addQuestion(question, firstAnswers);
    faqManager.addQuestion(question, secondAnswers);
    auto retrievedAnswers = faqManager.getAnswers(question);

    EXPECT_EQ(secondAnswers, retrievedAnswers);
}

TEST_F(FAQManagerTest, MaxLengthInput) {
    std::string question(254, 'a'); // 254 'a' characters
    question += "?";
    std::string answer(255, 'b'); // 255 'b' characters
    std::vector<std::string> answers = {answer};

    faqManager.addQuestion(question, answers);
    auto retrievedAnswers = faqManager.getAnswers(question);

    EXPECT_EQ(answers, retrievedAnswers);
}

TEST_F(FAQManagerTest, SpecialCharacters) {
    std::string question = "Is it correct to use ? and * in names?";
    std::vector<std::string> answers = {"Yes, in some cases.", "No, it's generally bad practice."};

    faqManager.addQuestion(question, answers);
    auto retrievedAnswers = faqManager.getAnswers(question);

    EXPECT_EQ(answers, retrievedAnswers);
}

TEST_F(FAQManagerTest, EmptyQuestion) {
    std::string question = "";
    std::vector<std::string> answers = {"Irrelevant"};

    faqManager.addQuestion(question, answers);
    auto retrievedAnswers = faqManager.getAnswers(question);

    EXPECT_EQ(retrievedAnswers, invalidInputResponse);
}

TEST_F(FAQManagerTest, EmptyAnswer) {
    std::string question = "What is empty?";
    std::vector<std::string> answers = {""};

    faqManager.addQuestion(question, answers);
    auto retrievedAnswers = faqManager.getAnswers(question);

    EXPECT_EQ(retrievedAnswers, invalidInputResponse);
}

TEST_F(FAQManagerTest, ExceedingMaxLengthQuestion) {
    std::string question(256, 'q'); // 256 'q' characters
    std::vector<std::string> answers = {"Valid answer"};

    faqManager.addQuestion(question, answers);
    auto retrievedAnswers = faqManager.getAnswers(question);

    EXPECT_EQ(retrievedAnswers, invalidInputResponse);
}

TEST_F(FAQManagerTest, ExceedingMaxLengthAnswer) {
    std::string question = "What is too long?";
    std::string longAnswer(256, 'a'); // 256 'a' characters
    std::vector<std::string> answers = {longAnswer};

    faqManager.addQuestion(question, answers);
    auto retrievedAnswers = faqManager.getAnswers(question);

    EXPECT_EQ(retrievedAnswers, invalidInputResponse);
}

TEST_F(FAQManagerTest, InvalidFormatNoQuestionMark) {
    std::string question = "Is this a question";
    std::vector<std::string> answers = {"Yes"};

    faqManager.addQuestion(question, answers);
    auto retrievedAnswers = faqManager.getAnswers(question);

    EXPECT_EQ(retrievedAnswers, invalidInputResponse);
}

TEST_F(FAQManagerTest, DuplicateAnswers) {
    std::string question = "What are common colors?";
    std::vector<std::string> answers = {"Blue", "Blue"};

    faqManager.addQuestion(question, answers);
    auto retrievedAnswers = faqManager.getAnswers(question);

    std::vector<std::string> expectedAnswers = {"Blue"};
    EXPECT_EQ(retrievedAnswers, expectedAnswers);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
