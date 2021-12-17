#pragma once
#include <iostream>
#include <string>
using namespace std;


class Medication
{
protected: //keeps everything encapsulated 
    int m_numoftablets;
    string m_time;
    string m_name;
public:

    //Default Constructor
    Medication() { //default values for variables
        m_numoftablets = 1;
        std::string m_time = "6:00";
    }

    //Overload Constructor
    Medication(string medname, string medtime, int tablets) {
        m_name = medname;
        m_time = medtime;
        m_numoftablets = tablets;
    }


    void setName(std::string name) { m_name = name; }
    void setTime(std::string time) { m_time = time; }
    void setNumoftablets(int num) { m_numoftablets = num; }

    std::string getName() { return m_name; } //reveals encapsulated variables
    std::string getTime() { return m_time; }
    int getNumoftablets() { return m_numoftablets; }
};
