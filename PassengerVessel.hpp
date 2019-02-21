#pragma once
#ifndef PassengerVessel_hpp
#define PassengerVessel_hpp
#include "main.hpp"
#include "Vessels.hpp"
#include <initializer_list>
using namespace destination;
namespace passengervessel
{
    class PassengerVessel : public Vessel 
    {
        public:
            // типы кают
            enum CabinType {LUX, FIRSTCLASS, SECONDCLASS};
        private:
            // максимальная вместимость пассажиров
            int maxpax;
            // сколько сейчас пассажиров
            int curpax;
            
            // сколько кают на данном корабле
            int cabin_num;
            // список кают с типом
            CabinType* cabincontent;

        public:
            // конструктор
            PassengerVessel(int id, Destination* dest, int eta, ShipProperties* props, int maxpax, int curpax, int cabin_num, std::initializer_list<CabinType> values) : Vessel(id,dest,eta,props)
            {
                cabincontent=new CabinType[cabin_num];
                //va_list Cargo;
                // va_start(Cargo,cabin_num);
                // va_arg(Cargo,int);
                this->maxpax=maxpax;
                this->curpax=curpax;
                this->cabin_num=cabin_num;
                /*if(cabin_num < values.size()) 
                {
                    std::cout<<"Error. Please input less arguments!";
                }*/
                int i=0;
                for(auto& value : values)
                {
                    cabincontent[i]=value;
                    i++;
                }
                // va_end(Cargo);
            };
            PassengerVessel()
            {
                maxpax=0;
                curpax=0;
                cabin_num=0;
                cabincontent=nullptr;
            }
            ~PassengerVessel()
            {
                if (cabincontent) 
                {
                    delete cabincontent;
                }
            }
            PassengerVessel(PassengerVessel& passengervessel) : Vessel(passengervessel)
            {
                maxpax=passengervessel.maxpax;
                curpax=passengervessel.curpax;
                cabin_num=passengervessel.cabin_num;
                if (passengervessel.cabincontent)
                {
                    cabincontent=new CabinType[passengervessel.cabin_num];
                    for (int i=0;i<passengervessel.cabin_num;i++)
                    {
                        cabincontent[i]=passengervessel.cabincontent[i];
                    }
                }
                else
                {
                    cabincontent=nullptr;
                }
            }
            bool CompareMaxpaxAndCurpax() const;
            // Печать пассажирского судна
            friend std::ostream& operator<<(std::ostream& os, const PassengerVessel& v)
            {
                os << (const Vessel &) v;
                os << "Max passengers: " <<v.maxpax<< std::endl;
                os<<"How much passengers now: "<<v.curpax<<std::endl;
                os<<"How many cabins: "<<v.cabin_num<<std::endl;
                for (int i=0;i<v.cabin_num;i++) 
                {
                    os<<v.cabincontent[i]<<" "<<std::endl;
                }
                os<<std::endl;
                return os;
            }
    };
}
#endif 
