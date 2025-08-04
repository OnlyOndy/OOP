// Title:  Book.cpp
// Desc:   Definds functionality of Book class.
// Name:   An Tran

#include <string>
#include <iostream>

#include "Book.h"

// constuctors
Book::Book
(
) : title{""},
    author{""}, 
    format{""},
    pubYear{0},
    numOfPages{0}
{
};

Book::Book
(
    std::string title, 
    std::string author
) : title{title},
    author{author}, 
    format{""},
    pubYear{0},
    numOfPages{0}
{
};

Book::Book
(
    std::string title,
    std::string author,
    int choiceNumFormat,
    int pubYear,
    int numOfPages
) : title{title},
    author{author}, 
    format{""},
    pubYear{pubYear},
    numOfPages{numOfPages}
{
    setFormat(choiceNumFormat);
};

// getters
std::string Book::getTitle()
{
    return title;
};

std::string Book::getAuthor()
{
    return author;
};

std::string Book::getFormat()
{
    return format;
};

int Book::getPubYear()
{
    return pubYear;
};

int Book::getNumOfPages()
{
    return numOfPages;
};

//setters
void Book::setTitle(std::string newTitle)
{
    title = newTitle;
};

void Book::setAuthor(std::string newAuthor)
{
    author = newAuthor;
};

void Book::setFormat(int choiceNumFormat)
{
    // To be used before calling setFormat()
    // std::cout << "Enter number choice for book format: " << std::endl 
    //           << "1. Hardcover" << std::endl
    //           << "2. Paperback" << std::endl
    //           << "3. Audiobook" << std::endl
    //           << "4. Ebook" << std::endl
    //           << "Enter number choice: ";
    // std::cin >> choiceNumFormat;
    // setFormat(choiceNumFormat);

    switch(choiceNumFormat){
    case 1:
        format = ("Hardcover");
        break;
    case 2:
        format = ("Paperback");
        break;
    case 3:
        format = ("Audiobook");
        break;
    case 4:
        format = ("EBook");
        break;
    default:
        std::cout << "Invalid format choice." << std::endl;
        break;
        }
};

void Book::setPubYear(int newPubYear)
{
    pubYear = newPubYear;
};

void Book::setNumOfPages(int newNumOfPages)
{
    numOfPages = newNumOfPages;
};

// other functions
void Book::setBook
(
    std::string newTitle, 
    std::string newAuthor, 
    int choiceNumFormat, 
    int newPubYear, 
    int newNumOfPages
)
{
    title = newTitle;

    author = newAuthor;

    setFormat(choiceNumFormat);

    pubYear = newPubYear;

    numOfPages = newNumOfPages;
};

void Book::displayBook()
{
    std::cout << "Title : " << title << std::endl;
    std::cout << "Author : " << author << std::endl;
    std::cout << "Format : " << format << std::endl;
    std::cout << "Publication Year : " << pubYear << std::endl;
    std::cout << "Number of Pages : " << numOfPages << std::endl;
};

float Book::estimatedBookWeight()
{
    float totalBookWeight{0};
    float peiceOfPaperWeight{0.176};
    float hardCoverCoverWeight{2.1};
    float paperBackCoverWeight{0.4};
    // digital format books wiegh nothing

    // this will add the cover weight to the total book weight or return 0 if the book is digital
    if (format == "Audiobook" || format == "EBook")
    {
        return totalBookWeight; // initialized as 0
    } else if (format == "Hardcover")
    {
        totalBookWeight += hardCoverCoverWeight;
    } else if (format == "Paperback")
    {
        totalBookWeight += paperBackCoverWeight;
    } else 
    {
        std::cout << "Please set a format for your book" << std::endl;
        return -1.0f;
    }

    // this calculates and adds to the total book wieght based on page number
    // note that one peice of paper contains 2 book pages
    // without using cmath libary, here is my solution for an odd number of numOfPages
    if (numOfPages % 2 == 0)
    {
        totalBookWeight += (numOfPages / 2) * peiceOfPaperWeight;
    } else
    {
        totalBookWeight += ((numOfPages + 1) / 2) * peiceOfPaperWeight; // adds 1 to account for extra page for odd page number
    };

    return totalBookWeight;

};

float Book::estimatedReadingTime()
{
    float readingTime{0.0};
    float readingSpeed {0.0};

    std::cout << "What is your reading speed in pages per minutes? ";
    std::cin >> readingSpeed;

    readingTime = numOfPages / readingSpeed;

    return readingTime;
};

