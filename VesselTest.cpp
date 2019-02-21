#include <iostream>
#include <cstdlib>
#include <vector>
#include "gtest/gtest.h"
#include "Audit.hpp"
#include "CargoVessel.hpp"
#include "Destination.hpp"
#include "NavalFreightCompany.hpp"
#include "Vessels.hpp"
using namespace audit;
using namespace destination;
using namespace cargovessel;
using namespace passengervessel;
//#include "help.hpp"
Vessel* BuildNewVessel(int Id,int Eta,int X,int Y,std::string damages,std::string repairs,std::string description)
{
    ShipProperties *newshipproperties=new ShipProperties(damages,repairs);
    Destination *newdestination=new Destination(description,X,Y);
    Vessel *newvessel=new Vessel(Id,newdestination,Eta,newshipproperties);
    return newvessel;
}
CargoVessel* BuildNewCargoVessel(int Id,int Eta,int X,int Y,std::string damages,std::string repairs,std::string description,int maxcargo,int curcargo,int container_num)
{
    ShipProperties *newshipproperties=new ShipProperties(damages,repairs);
    Destination *newdestination=new Destination(description,X,Y);
    CargoVessel::CargoType material,material2;
    material=CargoVessel::WOOD;
    material2=CargoVessel::FOOD;
    CargoVessel *newcargovessel=new CargoVessel(Id,newdestination,Eta,newshipproperties,maxcargo,curcargo,container_num,{material,material2});
    return newcargovessel;
}
PassengerVessel* BuildNewPassengerVessel(int Id,int Eta,int X,int Y,std::string damages,std::string repairs,std::string description,int maxpax,int curpax,int cabin_num)
{
    ShipProperties *newshipproperties=new ShipProperties(damages,repairs);
    Destination *newdestination=new Destination(description,X,Y);
    PassengerVessel::CabinType lux,secondclass,firstclass;
    lux=PassengerVessel::LUX;
    secondclass=PassengerVessel::SECONDCLASS;
    firstclass=PassengerVessel::FIRSTCLASS;
    PassengerVessel *newpassengervessel=new PassengerVessel(Id,newdestination,Eta,newshipproperties,maxpax,curpax,cabin_num,{lux,secondclass,firstclass});
    return newpassengervessel;
    
}
namespace  {
    TEST(TestsVessels,TestVesselsMain)
    {
        Vessel *newvessel=BuildNewVessel(1,228,6,36,"21.06.1999","21.07.1999","Vanino");
        //std::cout<<*newvessel;
        ASSERT_TRUE(newvessel->WasVesselRepaired());
        ASSERT_TRUE(newvessel->WasVesselDamaged());
        std::string destinationtocompare="PortVanino";
        ASSERT_FALSE(newvessel->CompareDestination(destinationtocompare));
        int idtocompare=1;
        ASSERT_EQ(1,newvessel->CompareId(idtocompare));


        CargoVessel *newcargovessel=BuildNewCargoVessel(7,239,5,25,"25.05.1999","26.05.1999","PortArtur",8,4,3);
        ASSERT_EQ(8,newcargovessel->GetMaxCargo());
        ASSERT_EQ(4,newcargovessel->GetCurCargo());
        ASSERT_EQ(3,newcargovessel->GetContainerNum());


        PassengerVessel *newpassengervessel=BuildNewPassengerVessel(8,239,5,25,"25.05.1999","26.05.1999","PortArtur",8,4,3);
        ASSERT_TRUE(newpassengervessel->CompareMaxpaxAndCurpax());
        
        NavalFreightCompany *newnavalcompany=new NavalFreightCompany();
        Vessel *newvessel5=BuildNewVessel(6,30,6,25,"1.06.2007","2.09.19","Artur");
        Vessel *newvessel1=BuildNewVessel(2,5,5,36,"2.08.2015","7.03.08","Lancelot");
        Vessel *newvessel2=BuildNewVessel(3,33,1,1,"3.09.2017","6.05.18","King");
        Vessel *newvessel3=BuildNewVessel(4,56,2,4,"4.10.2018","2.09.18","Poetry");
        Vessel *newvessel4=BuildNewVessel(5,2,12,144,"","","Artur");
        newnavalcompany->add(newvessel);
        newnavalcompany->add(newvessel1);
        newnavalcompany->add(newvessel2);
        newnavalcompany->add(newvessel3);
        newnavalcompany->add(newvessel4);
        newnavalcompany->add(newvessel5);
        newnavalcompany->add(newcargovessel);
        newnavalcompany->add(newpassengervessel);

        newnavalcompany->remove(newvessel);

        newnavalcompany->printStats();

        std::string changerepairedhelp="19.09.2020";
        std::string *changerepaired=new std::string;
        *changerepaired=changerepairedhelp;
        std::cout<<changerepairedhelp<<std::endl;
        newnavalcompany->markRepaired(2,changerepaired);

        std::string changedamagedhelp="10.10.2025";
        std::string* changedamaged=new std::string;
        *changedamaged=changedamagedhelp;
        std::cout<<changedamagedhelp<<std::endl;
        newnavalcompany->markDamaged(3,changedamaged);

        std::string description="PortSaint-Petersburg";
        int X=123,Y=456;
        Destination *newdestination=new Destination(description,X,Y);
        newnavalcompany->changeDestination(5,newdestination);

        newnavalcompany->printHeadingTo("Artur");

        std::string newstring="SmallVanino";
        Destination *location=new Destination(newstring,6,36);
        newnavalcompany->SetLocation(location);

        NavalFreightCompany *newnavalcompany1=new NavalFreightCompany();           
        Audit::compare1(*newnavalcompany,*newnavalcompany1);

        Audit::compare2(*newnavalcompany,*newnavalcompany1);

        Audit::isPassengerVesselsInPort(*newnavalcompany);

        Audit::inspectPassengerVessel(*newpassengervessel);

        Audit::inspectCargoVessel(*newcargovessel);
        delete newnavalcompany;
        delete newnavalcompany1;
    }
    TEST(TestsVessels,Testdraft)
    {
        NavalFreightCompany *newnavalcompany=new NavalFreightCompany();
        Vessel *newvessel=BuildNewVessel(1,228,6,36,"21.06.1999","21.07.1999","Vanino");
        CargoVessel *newcargovessel=BuildNewCargoVessel(7,239,5,25,"25.05.1999","26.05.1999","PortArtur",8,4,3);
        PassengerVessel *newpassengervessel=BuildNewPassengerVessel(8,239,5,25,"25.05.1999","26.05.1999","PortArtur",8,4,3);
        Vessel *newvessel5=BuildNewVessel(6,30,6,25,"1.06.2007","2.09.19","Artur");
        Vessel *newvessel1=BuildNewVessel(2,5,5,36,"2.08.2015","7.03.08","Lancelot");
        Vessel *newvessel2=BuildNewVessel(3,33,1,1,"3.09.2017","6.05.18","King");
        Vessel *newvessel3=BuildNewVessel(4,56,2,4,"4.10.2018","2.09.18","Poetry");
        Vessel *newvessel4=BuildNewVessel(5,2,12,144,"","","Artur");
        newnavalcompany->add(newvessel);
        newnavalcompany->add(newvessel1);
        newnavalcompany->add(newvessel2);
        newnavalcompany->add(newvessel3);
        newnavalcompany->add(newvessel4);
        newnavalcompany->add(newvessel5);
        newnavalcompany->add(newcargovessel);
        newnavalcompany->add(newpassengervessel);


        newnavalcompany->draft();

        delete newnavalcompany;
    }
}

 //g++ --std=c++11 -stdlib=libc++ Vessels_main.cpp Audit.cpp CargoVessel.cpp Destination.cpp NavalFreightCompany.cpp PassengerVessel.cpp Vessel.cpp VesselTest.cpp -lgtest -lpthread -o VesselTest
//valgrind   --leak-check=full --leak-resolution=high ./VesselTest

