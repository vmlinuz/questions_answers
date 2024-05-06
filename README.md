# Questions and Answers CLI Application

## Description
This Command Line Interface (CLI) application allows users to manage a database of questions and their corresponding answers. It offers functionalities to add questions with answers and to query answers for a specific question. If a question is not found, it responds humorously with a reference to "The Hitchhiker's Guide to the Galaxy".

## Features
- **Add Questions**: Input a question followed by one or multiple space-separated answers, a separator between a question and answers is a question mark `?`, every answer resides inside of doublequotes `"` (or every word separated by a space is treated as a separate answer otherwise):
  ```
  <question>? “<answer1>” “<answer2>” “<answerX>”
  ```

- **Query Questions**: Ask a specific question to retrieve all associated answers. A question should end with question mark

## Restrictions:
- A question is a string with max 255 chars
- An answer is a string with max 255 chars
- Every question needs to have at least one answer but can have unlimited answers 

## Prerequisites
Before you build and run this application, make sure you have:
- CMake (version 3.5 or higher)
- A C++ compiler supporting C++17 (e.g., GCC, Clang)
- Google Test installed for unit testing

## Building the Application
To build the application, execute the following commands:

```bash
# Clone the repository
git clone https://github.com/vmlinuz/questions_answers.git
cd questions_answers

# Create a build directory
mkdir build && cd build

# Configure the project with CMake
cmake ..

# Build the application
make
```

This will generate the `questions_answers` executable.

## Running the Application
To run the application after building, use:

```bash
./questions_answers
```

Follow the on-screen prompts to either add questions or query the database.

## Testing
To run unit tests set up with Google Test:

```bash
# Assuming you are still in the build directory after compiling
ctest
```

This command will execute all configured tests and report the results.

## Contributing
Contributions are welcome. Please ensure that any modifications adhere to coding standards and include corresponding tests where applicable.

## License
Apache License 2.0
