#include <gtest/gtest.h>
#include "faqmanager.h"

class FAQManagerTest : public ::testing::Test {
protected:
    FAQManager faqManager;

    void SetUp() override {
        // This setup runs before each test if needed.
    }
};

TEST_F(FAQManagerTest, AddAndGetSingleAnswer) {
    // Arrange
    std::string question = "What is Peter's favorite food?";
    std::vector<std::string> answers = {"Pizza"};

    // Act
    faqManager.addQuestion(question, answers);
    std::vector<std::string> retrievedAnswers = faqManager.getAnswers(question);

    // Assert
    EXPECT_EQ(answers, retrievedAnswers);
}

TEST_F(FAQManagerTest, AddAndGetMultipleAnswers) {
    // Arrange
    std::string question = "What is Peter's favorite food?";
    std::vector<std::string> answers = {"Pizza", "Spaghetti", "Ice cream"};

    // Act
    faqManager.addQuestion(question, answers);
    std::vector<std::string> retrievedAnswers = faqManager.getAnswers(question);

    // Assert
    EXPECT_EQ(answers, retrievedAnswers);
}

TEST_F(FAQManagerTest, NonExistentQuestion) {
    // Arrange
    std::string question = "When is Peter's birthday?";

    // Act
    std::vector<std::string> retrievedAnswers = faqManager.getAnswers(question);

    // Assert
    std::vector<std::string> expected = {"the answer to life, universe and everything is 42"};
    EXPECT_EQ(expected, retrievedAnswers);
}

TEST_F(FAQManagerTest, OverwriteQuestion) {
    // Arrange
    std::string question = "What is the best programming language?";
    std::vector<std::string> firstAnswers = {"C++"};
    std::vector<std::string> secondAnswers = {"Python", "JavaScript"};

    // Act
    faqManager.addQuestion(question, firstAnswers);
    faqManager.addQuestion(question, secondAnswers);
    std::vector<std::string> retrievedAnswers = faqManager.getAnswers(question);

    // Assert
    EXPECT_EQ(secondAnswers, retrievedAnswers);
}

TEST_F(FAQManagerTest, MaxLengthInput) {
    // Arrange
    std::string question(255, 'a'); // 255 'a' characters
    std::string answer(255, 'b'); // 255 'b' characters
    std::vector<std::string> answers = {answer};

    // Act
    faqManager.addQuestion(question, answers);
    std::vector<std::string> retrievedAnswers = faqManager.getAnswers(question);

    // Assert
    EXPECT_EQ(answers, retrievedAnswers);
}

TEST_F(FAQManagerTest, SpecialCharacters) {
    // Arrange
    std::string question = "Is it correct to use ? and * in names?";
    std::vector<std::string> answers = {"Yes, in some cases.", "No, it's generally bad practice."};

    // Act
    faqManager.addQuestion(question, answers);
    std::vector<std::string> retrievedAnswers = faqManager.getAnswers(question);

    // Assert
    EXPECT_EQ(answers, retrievedAnswers);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
