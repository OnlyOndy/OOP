// Title  : CollegePerson.h
// Desc   : Header file for CollegePerson.cpp which is a public derived class of Person
// Name   : An Tran

#include "Person.h"

#ifndef COLLEGEPERSON_H
#define COLLEGEPERSON_H

class CollegePerson : public Person{
    private:
        string university{""};
        string college{""};
        int id{0};
        float earned{0.0};
        float total{0.0};
        float grade{0.0};
        float gpa{0.0};
        string letterGrade{""};

    public:
        // constructor
        CollegePerson();
        CollegePerson(string newName, int newAge, string newUniv, string newCollege, int newId);

        // getter
        string getUniv();
        string getCollege();
        int getID();
        float getEarned();
        float getTotal();
        float getGrade();
        float getgpa();
        string getLetterGrade();
        
        // setter
        void setUniv(string newUniv);
        void setCollege(string newCollege);
        void setID(int newID);
        void setEarned(float newEarned);
        void setTotal(float newTotal);
        void setGrade(float newGrade);
        void setgpa(float newgpa);
        void setLetterGrade(string newLetterGrade);

};

#endif
