//
// Created by flamy on 13/10/21.
//

#ifndef LAB3_C_PRINTED_CIRCUIT_BOARD_H
#define LAB3_C_PRINTED_CIRCUIT_BOARD_H

#include <iostream>
#include <cmath>

namespace Lab3C {

    enum errorType {
        ok,
        incorrectInput,
        eof
    };

    enum contactType {
        in = 0,
        out = 1,
        notStated = -1
    };

    class printedCircuitBoard {
    public:
        struct Contact {
            contactType type;
            int x;
            int y;
            short numberOfContact;
            Contact();
            explicit Contact(contactType t, int x, int y);
        };
    private:
        //State of class
        const static unsigned short Quota = 1;
        unsigned short maxNumber;
        Contact* contacts;
        unsigned short currentNumber;
        //Methods
        bool isCorrectCoordinates (int x, int y);
        static contactType isCorrectType (int t);
        [[nodiscard]] bool isCorrectNumber (short n) const {return (n < currentNumber && n >= 0);}
        bool isCorrectConnection (short c1, short c2);
    public:
        printedCircuitBoard():currentNumber(0), maxNumber(Quota), contacts(new Contact[Quota]) {}; //Implementation is empty because when this constructor is called, constructor of each contact is called too
        ~printedCircuitBoard() {currentNumber = 0; delete[] contacts;};
        printedCircuitBoard(const printedCircuitBoard&);
        printedCircuitBoard(printedCircuitBoard&&) noexcept ;
        printedCircuitBoard& operator = (const printedCircuitBoard&);
        printedCircuitBoard& operator = (printedCircuitBoard&&) noexcept ;
        friend std::istream & operator >> (std::istream &, printedCircuitBoard::Contact &);//input of contact
        friend std::ostream & operator << (std::ostream &, const printedCircuitBoard &);//output for PCB
        printedCircuitBoard & operator += (const Contact &);//adding contact to PCB
        void establishConnect (short, short);
        printedCircuitBoard& operator -- ();//prefix, deleting last contact
        const printedCircuitBoard operator -- (int);//postfix, doing the same thing
        const Contact& operator[] (short) const;//get contact by its number
        Contact& operator[] (short);
        double operator() (short, short);//get length of track between contacts
        [[nodiscard]] printedCircuitBoard groupOfContacts(unsigned short) const;
        [[nodiscard]] unsigned short getCurrentNumber () const {return currentNumber;};
        [[nodiscard]] unsigned short getMaxNumber () const {return maxNumber;};
    };

    std::ostream& operator << (std::ostream &, const printedCircuitBoard::Contact &);//output for contact

    template <class T>
    errorType input (T &a){
        std::cin >> a;
        if (!std::cin.good()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return incorrectInput;
        }
        if (std::cin.eof())
            return eof;
        return ok;
    }

    template <class T>
    void checkInput (T &a) {
        errorType error;
        do {
            error = input(a);
            if (error == eof || error == incorrectInput)
                std::cout << "Enter only numbers, please!" << std::endl;
        } while (error != ok);
    }
}

#endif //LAB3_C_PRINTED_CIRCUIT_BOARD_H
