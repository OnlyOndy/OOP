// Title:  main.cpp
// Desc:   Testing functionality of Book.h and Book.cpp
// Name:   An Tran

#include <iostream>
#include "Book.h"

int main()
{
    // std::string aTitle{"Test Title"};
    // std::string anAuthor{"Test Author"};
    // int choiceNumFormat{0};

    // Book testBook1 = Book(aTitle, anAuthor);

    // std::cout << "Enter number choice for book format: " << std::endl 
    //           << "1. Hardcover" << std::endl
    //           << "2. Paperback" << std::endl
    //           << "3. Audiobook" << std::endl
    //           << "4. Ebook" << std::endl
    //           << "Enter number choice: ";
    // std::cin >> choiceNumFormat;
    // testBook1.setFormat(choiceNumFormat);

    // std::cout << testBook1.getFormat() << std::endl;

    // return 0;

    Book testBook2 = Book("Test Title", "Test Author", 1, 2000, 100);
    float readingTime{0.0};

    testBook2.displayBook();
    std::cout << "Estimated book weight: " << testBook2.estimatedBookWeight() << std::endl;
    readingTime = testBook2.estimatedReadingTime();
    std::cout << "Estimated reading time: " << readingTime << std::endl;

    testBook2.setBook("Test Title 2", "Test Author 2", 2, 3000, 101);

    testBook2.displayBook();
    std::cout << "Estimated book weight: " << testBook2.estimatedBookWeight() << std::endl;
    readingTime = testBook2.estimatedReadingTime();
    std::cout << "Estimated reading time: " << readingTime << std::endl;
};
