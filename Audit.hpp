#pragma once
#ifndef Audit_hpp
#define Audit_hpp
#include "main.hpp"
#include "NavalFreightCompany.hpp"
#include "PassengerVessel.hpp"
#include "CargoVessel.hpp"
using namespace cargovessel;
using namespace passengervessel;
using namespace navalfreightcompany;
namespace audit
{
    class Audit 
    {
        public:
            // Узнать есть ли в порту данной компании дежурящие пассажирские суда (у которых destination совпадает с location)
            static bool isPassengerVesselsInPort(const NavalFreightCompany& nfc);
            // Сравнить две компании, вывести более крупную (считается суммарно), сигнатуру придумать самостоятельно
            static void compare1(const NavalFreightCompany& ,const NavalFreightCompany&);
            // Сравнить две компании, вывести более надежную (меньше когда-либо ремонтировавшихся судов), сигнатуру придумать самостоятельно
            static void compare2(const NavalFreightCompany& ,const NavalFreightCompany&);
            // проинспектировать пассажирский корабль на предмет наличия большего количества людей чем положено по нормативу
            static bool inspectPassengerVessel(const PassengerVessel& v);
            // проинспектировать грузовой корабль на предмет наличия большего количества контейнеров чем положено по нормативу
            static bool inspectCargoVessel(const CargoVessel& v);
    };
}
#endif /* Audit_hpp */
//static добавить 