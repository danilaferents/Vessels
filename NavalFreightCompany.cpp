#include "NavalFreightCompany.hpp"
#include <typeinfo>
using namespace navalfreightcompany;
int NavalFreightCompany::HowManyRepairedShips() const
{
    int repairedvessels=0;
    for(auto i=ships.begin();i!=ships.end();i++)
    {
        if((*i)->WasVesselRepaired()) repairedvessels++;;
    }
    return repairedvessels;
}
int NavalFreightCompany::HowManyShips() const
{
    return ships.size();
}
void NavalFreightCompany::add(Vessel* v,Destination* d) 
{
    v=new Vessel(d);
    ships.push_back(v);
}
void NavalFreightCompany::add(Vessel* v)
{   
    ships.push_back(v);

}
void  NavalFreightCompany::remove(Vessel* v)
{
    ships.remove(v);
    delete v;
}
void  NavalFreightCompany::remove(int id)
{
    auto help=find_if(ships.begin(), ships.end(), [id](Vessel* &s) {
    return s->CompareId(id);});
    // auto help=ships.begin();
    // while (!(*help)->CompareId(id))
    // {
    //     help++;
    // } 
    ships.erase(help);
    delete *help;
}
void NavalFreightCompany::draft()
{
    auto it=ships.begin();
    while (it != ships.end())
    {
        if ((*it)->WasVesselRepaired()) 
        {
            Vessel* help=*it;
            it=ships.erase(it);
            delete help;
        }
        else 
        {
            it++;
        }
    }
}
void NavalFreightCompany::printStats() const
{   
    // CargoVessel *help1=new CargoVessel();
    // PassengerVessel *help2=new PassengerVessel();
    // // dynamic_cast<...>
    // auto name1=typeid(*help1).name();
    // auto name2=typeid(*help2).name();
    // int cargos=0,passengers=0;
    // for (auto i=ships.begin();i!=ships.end();i++)
    // {
    //     std::cout<<"TYPE: "<<(typeid(**i).name())<<std::endl;
    //     if ((typeid(**i).name() == name1) && ((*i)->WasVesselDamaged())) 
    //     {
    //         cargos++;
    //         //std::cout<<"Here i was [Cargo]";
    //     }
    //     if ((typeid(**i).name() == name2) && (*i)->WasVesselDamaged()) 
    //     {
    //         passengers++;
    //         //std::cout<<"Here i was [Cargo]";
    //     }
    // }
    int cargos=0,passengers=0;
    for (auto i=ships.begin();i!=ships.end();i++)
    {
        if ((dynamic_cast<CargoVessel*>(*i)) && ((*i)->WasVesselDamaged()))
        {
            cargos++;
        } 
        if ((dynamic_cast<PassengerVessel*>(*i)) && ((*i)->WasVesselDamaged()))
        {
            passengers++;
        } 
    }
    std::cout<<"Number of cargoships:"<<cargos<<std::endl<<"Number of passengerships:"<<passengers<<std::endl;
}
void NavalFreightCompany::markRepaired(int id, std::string* date_repaired)
{
    //std::list<Vessel*>::iterator findIter = std::find(ships.begin(), ships.end(), id);
    auto help=ships.begin();
    while (!(*help)->CompareId(id))
    {
        help++;
    }
    (*help)->ChangeShipPropertiesRepaired(date_repaired);
}
void NavalFreightCompany::markDamaged(int id, std::string* date_damaged)
{
    auto help=ships.begin();
    while (!(*help)->CompareId(id))
    {
        help++;
    }
    (*help)->ChangeShipPropertiesDamaged(date_damaged);
}
void NavalFreightCompany::changeDestination(int id, Destination* dest)
{
    auto help=ships.begin();
    while (!(*help)->CompareId(id))
    {
        help++;
    }
    (*help)->ChangeDestination(dest);
}
void NavalFreightCompany::printHeadingTo(std::string s) const
{
    int numberofvessels=0;
    for (auto i=ships.begin();i!=ships.end();i++)
    {
        if ((*i)->CompareDestination(s)) numberofvessels++;
    }
    std::cout<<"Number of ships to destination "<<s<<":"<<numberofvessels<<std::endl;
}
bool NavalFreightCompany::AreThereShips() const
{
    // PassengerVessel* help2=new PassengerVessel();
    // auto name2=typeid(*help2).name();
    // auto i=ships.begin();
    // int result=0;
    // while ((i!=ships.end()))
    // {
    //    if ((*i) && ((*i)->GetDestination()->GetName() == location->GetName()) && (typeid(**i).name() == name2))  
    //    {
    //         std::cout<<((*i)->GetDestination()->GetName())<<std::endl;
    //         result=1;
    //         return result;
    //     }
    //     i++;
    // }
    auto i=ships.begin();
    int result=0;
    while ((i!=ships.end()))
    {
       if ((*i) && ((*i)->GetDestination()->GetName() == location->GetName()) && (dynamic_cast<PassengerVessel*>(*i)))
       {
            std::cout<<((*i)->GetDestination()->GetName())<<std::endl;
            result=1;
            return result;
        }
        i++;
    }
    return result;
}/*
friend std::ostream& operator<<(std::ostream& os, const NavalFreightCompany& v)
{
	for(auto i=v.ships.begin();i!=v.ships.end();i++)
    {
        os<<**i<<std::endl;
    }
    return os;
}*/
