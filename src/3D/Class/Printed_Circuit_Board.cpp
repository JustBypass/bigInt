//
// Created by flamy on 13/10/21.
//

#include "Printed_Circuit_Board.h"

//namespace Lab3C {
    printedCircuitBoard::Contact::Contact() {
        type = notStated;
        x = 0;
        y = 0;
        numberOfContact = -1;
    }

    printedCircuitBoard::Contact::Contact(contactType t, int x, int y) {
        if (t != in && t != out)
            throw std::invalid_argument("Incorrect type of contact!");
        type = t;
        this->x = x;
        this->y = y;
        numberOfContact = -1;
    }

    contactType printedCircuitBoard::isCorrectType(int t) {
        if (t == 0)
            return in;
        if (t == 1)
            return out;
        throw std::invalid_argument("Incorrect type of contact");
    }

    bool printedCircuitBoard::isCorrectConnection(short c1, short c2) {
        if (!isCorrectNumber(c1) || !isCorrectNumber(c2))
            throw std::invalid_argument("There is no such contact(s)!");
        if (contacts[c1].type == contacts[c2].type)
            return false;
        if (contacts[c1].numberOfContact != -1 || contacts[c2].numberOfContact != -1)
            return false;
        return true;
    }

    void printedCircuitBoard::establishConnect(short c1, short c2) {
        if (!isCorrectConnection(c1, c2))
            throw std::invalid_argument("Cannot establish connect between these contacts");
        contacts[c1].numberOfContact = c2;
        contacts[c2].numberOfContact = c1;
    }

    printedCircuitBoard printedCircuitBoard::groupOfContacts(unsigned short t) const {
        printedCircuitBoard group;
        contactType type = isCorrectType(t);
        for (int i = 0; i < currentNumber; ++i) {
            if (contacts[i].type == type) {
                group += contacts[i];
            }
        }
        return group;
    }

    bool printedCircuitBoard::isCorrectCoordinates(int x, int y) {
        for (int i = 0; i < currentNumber; ++i) {
            if (contacts[i].x == x && contacts[i].y == y)
                return false;
        }
        return true;
    }

    std::istream &operator>>(std::istream & s, printedCircuitBoard::Contact& c) {
        int x, y, t;
        contactType type;
        s >> t >> x >> y;
        if (!s) {
            s.setstate(std::ios::failbit);
        }
        else {
            type = printedCircuitBoard::isCorrectType(t);
            c.x = x;
            c.y = y;
            c.type = type;
        }
        return s;
    }

    std::ostream &operator<<(std::ostream & s, const printedCircuitBoard & p) {
        if (p.currentNumber == 0)
            s << "The PCB is empty!" << std::endl;
        else {
            for (int i = 0; i < p.currentNumber; ++i) {
                s << std::endl << "Number of contact: --> " << i << std::endl;
                s << p.contacts[i];
            }
        }
        return s;
    }

    printedCircuitBoard& printedCircuitBoard::operator+=(const printedCircuitBoard::Contact& c) {
        if (!isCorrectCoordinates(c.x, c.y))
            throw std::invalid_argument("There is a contact at this place already!");
        if (currentNumber == maxNumber) {
            maxNumber += Quota;
            Contact* old = contacts;
            contacts = new Contact[maxNumber];
            for (int i = 0; i < currentNumber; ++i)
                contacts[i] = old[i];
            delete[] old;
        }
        contacts[currentNumber] = c;
        currentNumber++;
        return *this;
    }

     printedCircuitBoard::Contact& printedCircuitBoard::operator[](short n) {
        if (!isCorrectNumber(n))
            throw std::invalid_argument("There is no such contact in the PCB!");
        return contacts[n];
    }

    std::ostream &operator<<(std::ostream & s, const printedCircuitBoard::Contact & c) {
        s << "Type of contact: --> ";
        if (c.type == in)
            s << "input" << std::endl;
        if (c.type == out)
            s << "output" << std::endl;
        s << "First coordinate: --> " << c.x << std::endl;
        s << "Second coordinate: --> " << c.y << std::endl;
        if (c.numberOfContact == -1)
            s << "This contact is disconnected from other contacts" << std::endl;
        else
            s << "Number of related contact: --> " << c.numberOfContact << std::endl;
        return s;
    }

    double printedCircuitBoard::operator()(short c1, short c2) {
        if (!isCorrectNumber(c1) || !isCorrectNumber(c2))
            throw std::invalid_argument("There are no such contacts");
        if (contacts[c1].numberOfContact != c2) {
            throw std::invalid_argument("These contacts are not connected");
        }
        int x1 = contacts[c1].x;
        int x2 = contacts[c2].x;
        int y1 = contacts[c1].y;
        int y2 = contacts[c2].y;
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }

    printedCircuitBoard &printedCircuitBoard::operator--() {
        if (currentNumber == 0)
            throw std::out_of_range("There is no contacts in the PCB");
        contacts[currentNumber - 1].numberOfContact = -1;
        contacts[currentNumber - 1].type = notStated;
        contacts[currentNumber - 1].x = 0;
        contacts[currentNumber - 1].y = 0;
        currentNumber--;
        return *this;
    }

    const printedCircuitBoard printedCircuitBoard::operator--(int) {
        printedCircuitBoard p = *this;
        --(*this);
        return p;
    }

    printedCircuitBoard::printedCircuitBoard(const printedCircuitBoard &p):currentNumber(p.currentNumber), maxNumber(p.maxNumber) {
        contacts = new Contact[maxNumber];
        for (int i = 0; i < currentNumber; ++i) {
            contacts[i] = p.contacts[i];
        }
    }

    printedCircuitBoard::printedCircuitBoard(printedCircuitBoard && p) noexcept:currentNumber(p.currentNumber), maxNumber(p.maxNumber), contacts(p.contacts) {
        p.currentNumber = 0;
        p.contacts = nullptr;
    }

    printedCircuitBoard& printedCircuitBoard::operator = (const printedCircuitBoard &p) {
        if (this != &p) {
            currentNumber = p.currentNumber;
            maxNumber = p.maxNumber;
            delete[] contacts;
            contacts = new Contact[maxNumber];
            for (int i = 0; i < currentNumber; ++i) {
                contacts[i] = p.contacts[i];
            }
        }
        return *this;
    }

    printedCircuitBoard &printedCircuitBoard::operator = (printedCircuitBoard &&p)  noexcept {
        std::cout << "Move operator\n";
        if (this != &p) {
            delete[] contacts;
            currentNumber = p.currentNumber;
            maxNumber = p.maxNumber;
            contacts = p.contacts;
            p.currentNumber = 0;
            p.contacts = nullptr;
        }
        return *this;
    }

    const printedCircuitBoard::Contact &printedCircuitBoard::operator[](short c) const {
        if (!isCorrectNumber(c))
            throw std::out_of_range("There is no such contact");
        return contacts[c];
    }
//}
