#include <iostream>
#include <list>
#include <stdarg.h>
#include <string>
#include <utility>  

// Необходимо реализовать функциональность, где надо исправить ошибки и недописанные куски.
// Интерфейс можно менять в целях исправления, при этом надо быть готовым обосновать.
// Интерфейс можно расширять в целях улучшения, тоже необходимо обосновать. Расставить const-ы.
// Типы данных менять нельзя, то есть если храним где-то указатель, нельзя начать хранить по значению.
// Кроме того, в конце будет необходимо модуляризовать код и написать вызовы демонстрирующие работу.

// Обратите внимание, сейчас код компилируется!

// Свойства корабля: был ли корабль поврежден и отремонтирован; дата соответствующих событий.
// Если не был поврежден, то пустая строка.
struct ShipProperties 
{
    // дата повреждения
    std::string* damaged;
    // дата ремонта
    std::string* repaired;
    ~ShipProperties()
    {
        if (damaged) delete(damaged);
        if (repaired) delete(repaired);
    }
};

// Место назначения
class Destination 
{
    private: //(!!!) Изменил переменные на поля класса на private
        // название порта назначения
        std::string description;
        // координаты места назначения
        int x,y;
    public:
        Destination (std::string description, int x, int y) 
        {
            this->description = description;
            this->x = x;
            this->y = y;
        }
        Destination()
        {
            description=nullptr;
            x=0;
            y=0;
        }
        std::string GetName()
        {
            return description;
        }
        std::pair<int,int> GetCoordinates()
        {
            return std::make_pair(x,y);
        }
};

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
        Vessel(int id, Destination* dest, int eta, ShipProperties* props) 
        {
            this->id = id;
            this->destination = dest;
            this->eta = eta;
            this->props = props;
        }
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
        ~Vessel()
        {
            if(destination) delete(destination);
            if (props) delete (props);

        }
        // операция клонирования, должна присутствовать во всех наследуемых классах
        Vessel (Vessel& cargo)
        {
            id=cargo.id;
            if (cargo.destination) 
            {
                destination=new Destination;
                destination=cargo.destination;
            }
            else 
            {
                destination=nullptr;
            }
            eta=cargo.eta;
            if (cargo.props) 
            {
                props=new ShipProperties;
                props=cargo.props;
            }
            else 
            {
                props=nullptr;
            }
        }
        Destination* GetDestination();
        void ChangeDestination(Destination* );
        void ChangeShipPropertiesDamaged(std::string* date_repaired);
        void ChangeShipPropertiesRepaired(std::string* date_repaired);
        bool WasVesselRepaired();
        bool WasVesselDamaged();
        bool CompareDestination(std::string);
        bool CompareId(int id1);
        // Печать судна
        friend std::ostream& operator<<(std::ostream& os, const Vessel& v)
        {
            os << "Unique Idetifier: " <<v.id <<std::endl;
            os<<"Coordinates of the port: x= "<<(v.destination->GetCoordinates()).first<<"y="<<(v.destination->GetCoordinates()).second<<std::endl;
            os<<"Name of the port of destination: "<<v.destination->GetName()<<std::endl;
            os<<v.eta<<"Days to destination: "<<std::endl;
            if (!(*(v.props->damaged)).size()) 
             {
                os<<"Date of the damage: "<<*(v.props->damaged)<<std::endl;
                os<<"Date of the rdpair: "<<*(v.props->repaired)<<std::endl;
            }
            else 
             {
                os<<"No damages and repairs: "<<std::endl;
            }
            return os;
        }
};
Destination* Vessel::GetDestination()
{
    return destination;
}
bool Vessel::CompareId(int id1)
{ 
    return  (id1==id);
}
void Vessel::ChangeDestination(Destination* dest)
{
    if (destination) delete (destination);
    destination=dest;
}
bool Vessel::WasVesselRepaired()
{
    if ((props->repaired)) return 1;
    else return 0;
}
bool Vessel::WasVesselDamaged()
{
    if ((props->repaired)) return 1;
    else return 0;
}
bool Vessel::CompareDestination(std::string dest)
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
class CargoVessel : public Vessel 
{
    private:
        // Типы  груза
        enum CargoType {FOOD, WOOD, GOOD};
        // максимальная грузоподъемность
        int maxcargo;
        // сколько сейчас загружено
        int curcargo;
        // массив контейнеров,
        int container_num;
        CargoType* containercontent;
    public:
        // Конструктор
        CargoVessel(int id, Destination* dest, int eta, ShipProperties* props,int maxcargo, int curcargo, int container_num, CargoType ...) : Vessel(id,dest,eta,props)
        {
            va_list Cargo;
            //va_start(Cargo,CargoType);
            this->maxcargo=maxcargo;
            this->curcargo=curcargo;
            this->container_num=container_num;
            for (int i=0;i<container_num;i++)
            {
                CargoType ourcargo=va_arg(Cargo,CargoType);
                (this->containercontent)[i]=ourcargo;
            }
        
            va_end(Cargo);
        }
        CargoVessel()
        {
            maxcargo=0;
            curcargo=0;
            container_num=0;
            containercontent=nullptr;
        }
        ~CargoVessel()
        {
            if (containercontent) delete[] containercontent;
            
        }
        int GetMaxCargo();
        int GetCurCargo();
        int GetConteinerNum();
        bool CompareContainernumAndRealContainers();
        CargoType *GetConteinerContent();
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
            // Печать грузового судна
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
         }
        

};
bool CargoVessel::CompareContainernumAndRealContainers()
{
    if ((sizeof(containercontent)/(sizeof(CargoType)))<=container_num) return 1;
    return 0;
}
int CargoVessel::GetMaxCargo()
{
    return maxcargo;
}
int CargoVessel::GetCurCargo()
{
    return curcargo;
}
int CargoVessel::GetConteinerNum()
{
    return container_num;
}
CargoVessel::CargoType *CargoVessel::GetConteinerContent()
{
    return containercontent;
}
class PassengerVessel : public Vessel 
{
    private:
        // максимальная вместимость пассажиров
        int maxpax;
        // сколько сейчас пассажиров
        int curpax;
        // типы кают
        enum CabinType {LUX, FIRSTCLASS, SECONDCLASS};
        // сколько кают на данном корабле
        int cabin_num;
        // список кают с типом
        CabinType* cabincontent;

    public:
        // конструктор
        PassengerVessel(int id, Destination* dest, int eta, ShipProperties* props, int maxpax, int curpax, int cabin_num, CabinType ...) : Vessel(id,dest,eta,props)
        {
            va_list Cargo;
            //va_start(Cargo,CabinType);
            this->maxpax=maxpax;
            this->curpax=curpax;
            this->cabin_num=cabin_num;
            for (int i=0;i<cabin_num;i++)
            {
                CabinType ourcargo=va_arg(Cargo,CabinType);
                (this->cabincontent)[i]=ourcargo;
            }
        
            va_end(Cargo);
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
            if (cabincontent) delete[] cabincontent;
        }
        PassengerVessel(PassengerVessel& passengervessel) : Vessel(passengervessel)
        {
            maxpax=passengervessel.maxpax;
            curpax=passengervessel.curpax;
            int cabin_num=passengervessel.cabin_num;
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
        bool CompareMaxpaxAndCurpax();
        // Печать пассажирского судна
        friend std::ostream& operator<<(std::ostream& os, const PassengerVessel& v)
        {
            os << (const Vessel &) v;
            os << "Max passengers: " <<v.maxpax<< std::endl;
            os<<"How much passengers now: "<<v.curpax<<std::endl;
            os<<"How many cabins: "<<v.cabin_num<<std::endl;
            for (int i=0;i<v.cabin_num;i++) 
             {
                os<<v.cabincontent[i]<<" ";
            }
            os<<std::endl;
            return os;
        }
};
bool PassengerVessel::CompareMaxpaxAndCurpax()
{
    if (curpax<=maxpax) return 1;
    return 0;
}
class NavalFreightCompany
{
    private:
        // имеющиеся корабли
        std::list<Vessel*> ships;
        // место где порт расположен
        Destination* location;
    public:
        // добавление корабля
        void add(Vessel* v, Destination* d);
        void add(Vessel* v);
        // удаление корабля
        void remove(Vessel* v);
        void remove(int id);
        // списать весь хлам - когда-либо ремонтировавшиеся суда
        void draft();
        // напечатать статистику: сколько пассажирских, сколько грузовых, из них когда-либо ломавшихся
        void printStats();
        // внести запись о ремонте корабля по id
        void markRepaired(int id, std::string* date_repaired);
        // внести запись о повреждении корабля по id
        void markDamaged(int id, std::string* date_damaged);
        // поменять пункт назначения корабля
        void changeDestination(int id, Destination* dest);
        // напечатать сколько кораблей идут в пункт назначения X
        void printHeadingTo(std::string s);
        // Печать всех данных о компании
        bool AreThereShips();
        int HowManyShips();
        int HowManyRepairedShips();
        friend std::ostream& operator<<(std::ostream& os, const NavalFreightCompany& v)
        {
             for(auto i=v.ships.begin();i!=v.ships.end();i++)
             {
                os<<**i<<std::endl;
             }
             return os;
        }
};
int NavalFreightCompany::HowManyRepairedShips()
{
    int repairedvessels=0;
    for(auto i=ships.begin();i!=ships.end();i++)
    {
        if((*i)->WasVesselRepaired()) repairedvessels++;;
    }
    return repairedvessels;
}
int NavalFreightCompany::HowManyShips()
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
    v=new Vessel();
    ships.push_back(v);

}
void  NavalFreightCompany::remove(Vessel* v)
{
    ships.remove(v);
    //v-~Vessel();
}
void  NavalFreightCompany::remove(int id)
{
    auto help=ships.begin();
    while (!(*help)->CompareId(id))
    {
        help++;
    }
    ships.erase(help);
}
void NavalFreightCompany::draft()
{
    for(auto i=ships.begin();i!=ships.end();i++)
    {
        if ((*i)->WasVesselRepaired()) ships.erase(i);
    }
}
void NavalFreightCompany::printStats()
{   
    CargoVessel help1;
    PassengerVessel help2;
    auto name1=typeid(help1).name();
    auto name2=typeid(help2).name();
    int cargos=0,passengers=0;
    for (auto i=ships.begin();i!=ships.end();i++)
    {
        if ((typeid(**i).name() == name1) && ((*i)->WasVesselDamaged())) cargos++;
        if ((typeid(**i).name() == name2) && (*i)->WasVesselDamaged()) passengers++;
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
void NavalFreightCompany::printHeadingTo(std::string s)
{
    int numberofvessels=0;
    for (auto i=ships.begin();i!=ships.end();i++)
    {
        if ((*i)->CompareDestination(s)) numberofvessels++;
    }
    std::cout<<"Number of ships to destination "<<s<<":"<<numberofvessels<<std::endl;
}
bool NavalFreightCompany::AreThereShips()
{
    PassengerVessel help2;
    auto name2=typeid(help2).name();
    auto i=ships.begin();
    int result=0;
    while ((*i)->GetDestination() != location) 
    {
        if (((*i)->GetDestination() == location) && (typeid(**i).name() == name2))  result=1;//надо перегрузить оператор сравнения в классе и сравниватт значения
        i++;
    }
    return result;
}
// класс аудитор компании, делает различные проверки
class Audit 
{
    public:
        // Узнать есть ли в порту данной компании дежурящие пассажирские суда (у которых destination совпадает с location)
        bool isPassengerVesselsInPort(NavalFreightCompany& nfc);
        // Сравнить две компании, вывести более крупную (считается суммарно), сигнатуру придумать самостоятельно
        void compare1(NavalFreightCompany& ,NavalFreightCompany&);
        // Сравнить две компании, вывести более надежную (меньше когда-либо ремонтировавшихся судов), сигнатуру придумать самостоятельно
        void compare2(NavalFreightCompany& ,NavalFreightCompany&);
        // проинспектировать пассажирский корабль на предмет наличия большего количества людей чем положено по нормативу
        bool inspectPassengerVessel(PassengerVessel v);
        // проинспектировать грузовой корабль на предмет наличия большего количества контейнеров чем положено по нормативу
        bool inspectCargoVessel(CargoVessel v);
};
bool Audit::inspectCargoVessel(CargoVessel v)
{
    return v.CompareContainernumAndRealContainers();
}
bool Audit::inspectPassengerVessel(PassengerVessel v)
{
    return v.CompareMaxpaxAndCurpax();
}
bool Audit::isPassengerVesselsInPort(NavalFreightCompany& nfc)
{
    return nfc.AreThereShips();
}
void Audit::compare1(NavalFreightCompany& company1,NavalFreightCompany& company2)
{
    if (company1.HowManyShips() < company2.HowManyShips())  std::cout<<"Company 2 is bigger!";
    else if(company1.HowManyShips() > company2.HowManyShips())  std::cout<<"Company 1 is bigger!";
    else  std::cout<<"There is a draw!";
}
void Audit::compare2(NavalFreightCompany& company1,NavalFreightCompany& company2)
{
    if (company1.HowManyRepairedShips() < company2.HowManyRepairedShips())  std::cout<<"Company 1 is more reliable!";
    else if(company1.HowManyRepairedShips() > company2.HowManyRepairedShips())  std::cout<<"Company 2 is more reliable!";
    else  std::cout<<"There is a draw!";
}   
int main()
{
    printf("test");
}
