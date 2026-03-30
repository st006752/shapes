#pragma once 

class Identi{
	int ID;
public:
    Identi(int id = 0) : ID(id) {}
    int getID() const { return ID; }
    bool operator==(const Identi& other) const {
        return ID == other.ID;
    }
};
