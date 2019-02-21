#include "Audit.hpp"
using namespace audit;
bool Audit::inspectCargoVessel(const CargoVessel& v) 
{
    return v.CompareContainernumAndRealContainers();
}
bool Audit::inspectPassengerVessel(const PassengerVessel& v) 
{
    return v.CompareMaxpaxAndCurpax();
}
bool Audit::isPassengerVesselsInPort(const NavalFreightCompany& nfc) 
{
    return nfc.AreThereShips();
}
void Audit::compare1(const NavalFreightCompany& company1,const NavalFreightCompany& company2) 
{
    if (company1.HowManyShips() < company2.HowManyShips())  std::cout<<"Company 2 is bigger!"<<std::endl;
    else if(company1.HowManyShips() > company2.HowManyShips())  std::cout<<"Company 1 is bigger!"<<std::endl;
    else  std::cout<<"There is a draw!"<<std::endl;
}
void Audit::compare2(const NavalFreightCompany& company1,const NavalFreightCompany& company2) 
{
    if (company1.HowManyRepairedShips() < company2.HowManyRepairedShips())  std::cout<<"Company 1 is more reliable!"<<std::endl;
    else if(company1.HowManyRepairedShips() > company2.HowManyRepairedShips())  std::cout<<"Company 2 is more reliable!"<<std::endl;
    else  std::cout<<"There is a draw!"<<std::endl;
}   