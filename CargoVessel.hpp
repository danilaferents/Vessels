#pragma once
#ifndef CargoVessel_hpp
#define CargoVessel_hpp
#include "main.hpp"
#include "Vessels.hpp"
using namespace destination;
namespace cargovessel
{
    class CargoVessel : public Vessel 
    {   // Типы  груза 
        public:
        enum CargoType {FOOD, WOOD, GOOD};
        private:
            
            // максимальная грузоподъемность
            int maxcargo;
            // сколько сейчас загружено
            int curcargo;
            // массив контейнеров,
            int container_num;
            CargoType* containercontent;
        public:

            // Конструктор 
            CargoVessel()
            {
                maxcargo=0;
                curcargo=0;
                container_num=0;
                containercontent=nullptr;
            }
            CargoVessel(int id, Destination* dest, int eta, ShipProperties* props,int maxcargo, int curcargo, int container_num, std::initializer_list<CargoType> values) : Vessel(id,dest,eta,props)
            {
                containercontent=new CargoType[container_num];
                //va_list Cargo;
                //va_start(Cargo,cargotype);
                this->maxcargo=maxcargo;
                this->curcargo=curcargo;
                this->container_num=container_num;
                int i=0;
                for(auto& value : values)
                {
                    containercontent[i]=value;
                    i++;
                }
                /*
                for (int i=0;i<container_num;i++)
                {
                    //CargoType ourcargo=va_arg(Cargo,CargoType);
                    //std::cout<<std::endl<<"WTF.  "<<cargotype<<ourcargo<<std::endl;
                    //(containercontent)[i]=ourcargo;
                    containercontent[i]=cargotype;
                }
            */
                //va_end(Cargo);
            }
            //destructor
            ~CargoVessel()
            {
                if (containercontent) delete containercontent;
            }
    		CargoVessel(CargoVessel& cargoVessel) : Vessel(cargoVessel)
            {       
               // maxcargo=cargoVessel.GetMaxCargo();
                maxcargo=cargoVessel.maxcargo;
                //curcargo=cargoVessel.GetCurCargo();
                curcargo=cargoVessel.curcargo;
                //container_num=cargoVessel.GetConteinerNum();
                container_num=cargoVessel.container_num;
                //if (cargoVessel.GetConteinerContent())
                if (cargoVessel.containercontent)
                {
                    containercontent=new CargoType[cargoVessel.container_num];
                    for (int i=0;i<cargoVessel.container_num;i++)
                    {
                         //containercontent[i]=cargoVessel.GetConteinerContent()[i];
                        containercontent[i]=cargoVessel.containercontent[i];
                    }
                }
                else
                {
                    containercontent=nullptr;
                }
            }
            int GetMaxCargo() const;
            int GetCurCargo() const;
            int GetContainerNum() const;
            bool CompareContainernumAndRealContainers() const;
            CargoType *GetContainerContent() const;
                // Печать грузового судна
            friend std::ostream& operator<<(std::ostream& os, const CargoVessel& v)
            {
                os << (const Vessel &) v;
                os << "Maxcargo: " <<v.maxcargo<< std::endl;
                os<<"How much cargo now: "<<v.curcargo<<std::endl;
                os<<"How many containers: "<<v.container_num<<std::endl;
                for (int i=0;i<v.container_num;i++) 
                {
                    os<<(v.containercontent)[i]<<" ";
                }
                os<<std::endl;
                return os;
            }
    };
}
#endif 
