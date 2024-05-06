cmake_minimum_required(VERSION 3.5)
project(questions_answers LANGUAGES CXX)

# Set C++ standard for the entire project
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Main application
add_executable(questions_answers main.cpp faqmanager.cpp
    README.md)
target_include_directories(questions_answers PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Tests
# Find the installed Google Test
find_package(GTest REQUIRED)  # Requires that Google Test is correctly installed and findable

enable_testing()
add_executable(faq_tests faq_manager_tests.cpp faqmanager.cpp)
target_link_libraries(faq_tests GTest::GTest GTest::Main pthread)
target_include_directories(faq_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

include(GoogleTest)
gtest_discover_tests(faq_tests)

# Install rules
install(TARGETS questions_answers
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
