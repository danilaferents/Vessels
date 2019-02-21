#pragma once
#ifndef NavalFreightCompany_hpp
#define NavalFreightCompany_hpp
#include "main.hpp"
#include "Destination.hpp"
#include "Vessels.hpp"
#include "PassengerVessel.hpp"
#include "CargoVessel.hpp"
using namespace cargovessel;
using namespace passengervessel;
namespace navalfreightcompany
{
    class NavalFreightCompany
    {
        private:
            // имеющиеся корабли
            std::list<Vessel*> ships;
            // место где порт расположен
            Destination* location;
        public:
            NavalFreightCompany()
            {
                location=nullptr;
            }
            
            ~NavalFreightCompany()
            {
                for (auto i=ships.begin();i!=ships.end();i++)
                {
                    if (*i) delete (*i);
                }
                if (location) delete location;
            }
            // добавление корабля
            void add(Vessel* v, Destination* d);
            void add(Vessel* v);
            // удаление корабля
            void remove(Vessel* v);
            void remove(int id);
            // списать весь хлам - когда-либо ремонтировавшиеся суда
            void draft();
            // напечатать статистику: сколько пассажирских, сколько грузовых, из них когда-либо ломавшихся
            void printStats() const;
            // внести запись о ремонте корабля по id
            void markRepaired(int id, std::string* date_repaired);
            // внести запись о повреждении корабля по id
            void markDamaged(int id, std::string* date_damaged);
            // поменять пункт назначения корабля
            void changeDestination(int id, Destination* dest);
            // напечатать сколько кораблей идут в пункт назначения X
            void printHeadingTo(std::string s) const;
            // Печать всех данных о компании
            bool AreThereShips() const;
            int HowManyShips() const;
            int HowManyRepairedShips() const;
            void SetLocation(Destination *location)
            {
                this->location=location;
            }
            friend std::ostream& operator<<(std::ostream& os, const NavalFreightCompany& v)
            {
                for(auto i=v.ships.begin();i!=v.ships.end();i++)
                {
                    os<<(**i)<<std::endl;
                }
                return os;
            }
    };
}
#endif /* NavalFreightCompany_hpp */
