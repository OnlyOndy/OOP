// Title:  Book.h
// Desc:   Header file for Book.cpp
// Name:   An Tran

#include <string>

/* TODO: Function Descriptions
    // constructors
	explicit Book(); // defult

    explicit Date(int aYear, int aMonth, int aDay);

    explicit Book(std::string title, std::string author, int choiceNumFormat, int pubYear, int numOfPages);
    // note:        sets format based on input of choiceNumFormat


    // getters
    std::string getTitle();
    // description: 
    // receives:    nothing
    // returns:     title as string

    std::string getAuthor();
    // description: 
    // receives:    nothing
    // returns:     author as string

    std::string getFormat();
    // description: 
    // receives:    nothing
    // returns:     format as string

    int getPubYear();
    // description: 
    // receives:    nothing
    // returns:     pubYear as int

    int getNumOfPages();
    // description: 
    // receives:    nothing
    // returns:     numOfpages as int


    // setters
    void setTitle (std::string newTitle);
    // description: 
    // receives:    newTitle as a string
    // returns:     nothing

    void setAuthor (std::string newAuthor);
    // description: 
    // receives:    newAuthor as a string
    // returns:     nothing

    void setFormat(int choiceNumFormat);
    // description: 
    // receives:    choiceNumFormat as in int
    // returns:     nothing

    void setPubYear(int pubYear);
    // description: 
    // receives:    pubYear as an int
    // returns:     nothing

    void setNumOfPages(int numOfPages);
    // description: 
    // receives:    numOfPages as an int
    // returns:     nothing


    // other functions
    void setBook(std::string newTitle, std::string newAuthor, int choiceNumFormat, int newPubYear, int newNumOfPages);
    // description: takes parameters and sets to corresponding member varibales of object
    // receives:    newTitle and newAuthor as an int
                    choiceNumFormat, newPubYear, and newNumOf as strings
    // returns:     nothing

    void displayBook();
    // description: displays member variables of object
    // receives:    nothing
    // returns:     nothing

    float estimatedBookWeight();
    // description: calculates object's weight
                    each piece of paper weights 0.176 oz
                    each hardcover's cover weights 2.1 oz
                    each paperback's cover weights 0.4 oz
                    digital format books weigh nothing
                    note that each pair of page number counts as one peice of paper
    // receives:    nothing
    // returns:     calculated weight of object as a float

    float estimatedReadingTime();
    // description: calculates how long it will take to read the object based on user inputed readingSpeed and numOfPages
                    readingSpeed is in pages per minute
    // receives:    nothing
    // returns:     calculated estimated time to complete book as a float
*/

#ifndef BOOK_H
#define BOOK_H

class Book 
{
private:
    // member variables
    std::string title{""}; // holds title of a book
    std::string author{""}; // holds author of a book
    std::string format{""}; // holds format of a book. Either: "Hardcover", "Paperback", "Audiobook", "Ebook"
    int pubYear{0}; // holds year of the book was published
    int numOfPages{0}; // holds number of pages in the book

public:
    // constuctors
    explicit Book(); // default
    explicit Book(std::string title, std::string author);
    explicit Book(std::string title, std::string author, int choiceNumFormat, int pubYear, int numOfPages);


    // member functions
    // getters
    std::string getTitle();
    std::string getAuthor();
    std::string getFormat();
    int getPubYear();
    int getNumOfPages();

    // setters
    void setTitle (std::string newTitle);
    void setAuthor (std::string newAuthor);
    void setFormat(int choiceNumFormat);
    void setPubYear(int newPubYear);
    void setNumOfPages(int newNumOfPages);

    // other functions
    void setBook(std::string newTitle, std::string newAuthor, int choiceNumFormat, int newPubYear, int newNumOfPages);
    
    void displayBook();

    float estimatedBookWeight();

    float estimatedReadingTime();
};

#endif
