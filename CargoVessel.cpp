#include "CargoVessel.hpp"
using namespace cargovessel;
bool CargoVessel::CompareContainernumAndRealContainers() const
{
    if ((sizeof(containercontent)/(sizeof(CargoType)))<=container_num) return 1;
    return 0;
}
int CargoVessel::GetMaxCargo() const
{
    return maxcargo;
}
int CargoVessel::GetCurCargo() const
{
    return curcargo;
}
int CargoVessel::GetContainerNum() const
{
    return container_num;
}
CargoVessel::CargoType *CargoVessel::GetContainerContent() const
{
    return containercontent;
}
/*
CargoVessel* CargoVessel::clone()
{
    return new CargoVessel(*this);
}*/
/*
friend std::ostream& operator<<(std::ostream& os, const CargoVessel& v)
{
	os << (const Vessel &) v;
	os << "Maxcargo: " <<v.maxcargo<< std::endl;
	os<<"How much cargo now: "<<v.curcargo<<std::endl;
	os<<"How many containers: "<<v.container_num<<std::endl;
	for (int i=0;i<v.container_num;i++) 
	{
		os<<v.containercontent[i]<<"/t";
	}
	os<<std::endl;
	return os;
}*/