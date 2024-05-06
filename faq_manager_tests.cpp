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
    std::string question(254, 'a'); // 254 'a' characters
    question.append("?");
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

TEST_F(FAQManagerTest, EmptyQuestion) {
    // Arrange
    std::string question = "";
    std::vector<std::string> answers = {"Irrelevant"};

    // Act
    faqManager.addQuestion(question, answers);
    auto retrievedAnswers = faqManager.getAnswers(question);

    // Assert
    EXPECT_TRUE(retrievedAnswers == std::vector<std::string>{"Invalid input"});
}

TEST_F(FAQManagerTest, EmptyAnswer) {
    // Arrange
    std::string question = "What is empty?";
    std::vector<std::string> answers = {""};

    // Act
    faqManager.addQuestion(question, answers);
    auto retrievedAnswers = faqManager.getAnswers(question);

    // Assert
    EXPECT_TRUE(retrievedAnswers == std::vector<std::string>{"Invalid input"});
}

TEST_F(FAQManagerTest, ExceedingMaxLengthQuestion) {
    // Arrange
    std::string question(256, 'q'); // 256 'q' characters
    std::vector<std::string> answers = {"Valid answer"};

    // Act
    faqManager.addQuestion(question, answers);
    auto retrievedAnswers = faqManager.getAnswers(question);

    // Assert
    EXPECT_TRUE(retrievedAnswers == std::vector<std::string>{"Invalid input"});
}

TEST_F(FAQManagerTest, ExceedingMaxLengthAnswer) {
    // Arrange
    std::string question = "What is too long?";
    std::string longAnswer(256, 'a'); // 256 'a' characters
    std::vector<std::string> answers = {longAnswer};

    // Act
    faqManager.addQuestion(question, answers);
    auto retrievedAnswers = faqManager.getAnswers(question);

    // Assert
    EXPECT_TRUE(retrievedAnswers == std::vector<std::string>{"Invalid input"});
}

TEST_F(FAQManagerTest, InvalidFormatNoQuestionMark) {
    // Arrange
    std::string question = "Is this a question";
    std::vector<std::string> answers = {"Yes"};

    // Act
    faqManager.addQuestion(question, answers);
    auto retrievedAnswers = faqManager.getAnswers(question);

    // Assert
    EXPECT_TRUE(retrievedAnswers == std::vector<std::string>{"Invalid input"});
}

TEST_F(FAQManagerTest, DuplicateAnswers) {
    // Arrange
    std::string question = "What are common colors?";
    std::vector<std::string> answers = {"Blue", "Blue"};

    // Act
    faqManager.addQuestion(question, answers);
    auto retrievedAnswers = faqManager.getAnswers(question);

    // Assert
    std::vector<std::string> expectedAnswers = {"Blue"};  // Assuming your system filters out duplicates
    EXPECT_EQ(retrievedAnswers, expectedAnswers);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
