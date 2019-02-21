#pragma once
#ifndef Vessels_hpp
#define Vessels_hpp
#include <iostream>
//#include "main.hpp"
#include "Destination.hpp"
#include "ShipProperties.hpp"
using namespace destination;
class Vessel 
{
    private:
        // уникальный идентификатор
        int id;
        // пункт назначения
        Destination* destination;
        // сколько дней осталось время до прибытия
        int eta;
        // свойства корабля
        ShipProperties* props;
    public:
    	//constructors
        Vessel()
        {
            this->id =0;
            this->destination=nullptr;
            this->eta=2147483647;
            this->props=nullptr;
        }
        Vessel(Destination* dest)
        {
            this->id=0;
            this->destination=dest;
            this->eta=2147483647;
            this->props=nullptr;
        }
        Vessel(int id, Destination* dest, int eta, ShipProperties* props) 
        {
            this->id = id;
            this->destination = dest;
            this->eta = eta;
            this->props = props;
        }
        virtual ~Vessel()
        {
            if(destination) delete destination;
            if (props) delete props;

        }
        Vessel (Vessel& cargo)
        {
            id=cargo.id;
            if (cargo.destination) 
            {
                destination=new Destination;
                destination->SetName(cargo.destination->GetName());
                destination->SetCoordinates(cargo.destination->GetCoordinates());
            }
            else 
            {
                destination=nullptr;
            }
            eta=cargo.eta;
            if (cargo.props) 
            {
                props=new ShipProperties(cargo.props->GetDamaged(),cargo.props->GetRepaired());
            }
            else 
            {
                props=nullptr;
            }
        }
        Destination* GetDestination() const;
        void ChangeDestination(Destination* );
        void ChangeShipPropertiesDamaged(std::string* date_repaired);
        void ChangeShipPropertiesRepaired(std::string* date_repaired);
        bool WasVesselRepaired() const;
        bool WasVesselDamaged() const;
       // virtual Vessel* clone();
        bool CompareDestination(std::string) const;
        bool CompareId(int id1) const;
        // Печать судна
        friend std::ostream& operator<<(std::ostream& os, const Vessel& v)
        {
            os << "Unique Idetifier: " <<v.id <<"."<<std::endl;
            if (v.destination)
            {
                os<<"Coordinates of the port: x= "<<(v.destination->GetCoordinates()).first<<", y= "<<(v.destination->GetCoordinates()).second<<"."<<std::endl;
                os<<"Name of the port of destination: "<<v.destination->GetName()<<"."<<std::endl;
            }
            os<<v.eta<<"  Days to destination"<<std::endl;
            if ((v.props) && (v.props->damaged) && ((*(v.props->damaged)).size()))
             {
                os<<"Date of the damage: "<<*(v.props->damaged)<<"."<<std::endl;
                
            }
            else 
            {
                os<<"No damages!"<<std::endl;
            }
            if ((v.props)&& (v.props->repaired) && ((*(v.props->repaired)).size()))
            {
                os<<"Date of the repair: "<<*(v.props->repaired)<<"."<<std::endl;
            }
            else
            {
                os<<"No repairs! "<<std::endl;
            }
            return os;
        }
};
#endif 
