#pragma once
#ifndef ShipProperties_hpp
#define ShipProperties_hpp
struct ShipProperties 
{
    // дата повреждения
    std::string* damaged;
    // дата ремонта
    std::string* repaired;
    ShipProperties()
    {
    	damaged=nullptr;
    	repaired=nullptr;
    }
    ShipProperties(std::string damaged,std::string repaired)
    {
    	std::string *Damaged=new std::string;
    	*Damaged=damaged;
    	std::string *Repaired=new std::string;
    	*Repaired=repaired;
    	this->damaged=Damaged;
    	this->repaired=Repaired;
    }
    ~ShipProperties()
    {
        //std::cout<<"HERE I WAS(2)";
        if (damaged) delete(damaged);
        if (repaired) delete(repaired);
    }
    std::string GetDamaged()
    {
        return *damaged;
    }
    std::string GetRepaired()
    {
        return *repaired;
    }
    ShipProperties& operator=(const ShipProperties& a)
    {
        if (&a == this)
        {
            return *this;
        }
        damaged=a.damaged;
        repaired=a.repaired;
        return *this;
    }
};
#endif