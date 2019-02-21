#include "Vessels.hpp"
bool Vessel::CompareId(int id1) const
{ 
    return  (id1==id);
}
void Vessel::ChangeDestination(Destination* dest)
{
    if (destination) delete (destination);
    destination=dest;
}
bool Vessel::WasVesselRepaired() const
{
    if ((props) && (props->repaired) && ((*(props->repaired)).size() != 0)) 
     {   
        //std::cout<<((props->repaired)->size())<<std::endl;            
        return 1;
    }
    else return 0;
}
bool Vessel::WasVesselDamaged() const
{
    if ((props) && (props->damaged) && ((*(props->damaged)).size() != 0)) 
    {   
        //std::cout<<((props->damaged))->size()<<std::endl;
        return 1;
    }
    else return 0;
}
bool Vessel::CompareDestination(std::string dest) const
{
    if (destination) return (dest == destination->GetName());
    else return 0;
}
void Vessel::ChangeShipPropertiesDamaged(std::string* date_damaged)
{
    if (props->damaged) delete (props->damaged);
    props->damaged=date_damaged;
}
void Vessel::ChangeShipPropertiesRepaired(std::string* date_repaired)
{
    if (props->repaired) delete (props->repaired);
    props->repaired=date_repaired;
}
Destination* Vessel::GetDestination() const
{
    if (destination) return destination;
    else return nullptr;
}
