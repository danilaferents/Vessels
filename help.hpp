#ifndef help_hpp
#define help_hpp
#include <fstream>
#include <stdio.h>
#include "Vessels.hpp"
#include "PassengerVessel.hpp"
#include "CargoVessel.hpp"
#include "ShipProperties.hpp"
#include "Destination.hpp"
Vessel* BuildNewVessel()
{
    std::ifstream fcin;
    fcin.open("input.txt");
    int Id,Eta,X,Y;
    std::string damages,repairs,description;
    fcin>>Id;
    fcin>>Eta;
    fcin>>damages>>repairs;
    fcin>>description>>X>>Y;
    ShipProperties *newshipproperties=new ShipProperties(damages,repairs);
    Destination *newdestination=new Destination(description,X,Y);
    Vessel *newvessel=new Vessel(Id,newdestination,Eta,newshipproperties);
    fcin.close();
    return newvessel;
}
Vessel* BuildNewVessel1(int Id,int Eta,int X,int Y,std::string damages,std::string repairs,std::string description)
{
    ShipProperties *newshipproperties=new ShipProperties(damages,repairs);
    Destination *newdestination=new Destination(description,X,Y);
    Vessel *newvessel=new Vessel(Id,newdestination,Eta,newshipproperties);
    return newvessel;
    
}
CargoVessel* BuildNewCargoVessel()
{
    std::ifstream fcin;
    fcin.open("inputcargo.txt");
    int Id,Eta,X,Y,maxcargo,curcargo,container_num;
    std::string damages,repairs,description;
    fcin>>Id>>Eta;
    fcin>>damages>>repairs;
    fcin>>description>>X>>Y;
    fcin>>maxcargo>>curcargo>>container_num;
    ShipProperties *newshipproperties=new ShipProperties(damages,repairs);
    Destination *newdestination=new Destination(description,X,Y);
    CargoVessel::CargoType material,material2;
    material=CargoVessel::WOOD;
    material2=CargoVessel::FOOD;
    CargoVessel *newcargovessel=new CargoVessel(Id,newdestination,Eta,newshipproperties,maxcargo,curcargo,container_num,{material,material2});
    fcin.close();
    return newcargovessel;
    
}
PassengerVessel* BuildNewPassengerVessel()
{
    std::ifstream fcin;
    fcin.open("inputpassenger.txt");
    int Id,Eta,X,Y,maxpax,curpax,cabin_num;
    std::string damages,repairs,description;
    fcin>>Id>>Eta;
    fcin>>damages>>repairs;
    fcin>>description>>X>>Y;
    fcin>>maxpax>>curpax>>cabin_num;
    ShipProperties *newshipproperties=new ShipProperties(damages,repairs);
    Destination *newdestination=new Destination(description,X,Y);
    PassengerVessel::CabinType lux,secondclass,firstclass;
    lux=PassengerVessel::LUX;
    secondclass=PassengerVessel::SECONDCLASS;
    firstclass=PassengerVessel::FIRSTCLASS;
    PassengerVessel *newpassengervessel=new PassengerVessel(Id,newdestination,Eta,newshipproperties,maxpax,curpax,cabin_num,{lux,secondclass,firstclass});
    fcin.close();
    return newpassengervessel;
    
}
Destination *BuildNewDestination()
{
    std::ifstream fcin;
    fcin.open("destination.txt");
    std::string description;
    fcin>>description;
    int X,Y;
    fcin>>X>>Y;
    Destination *newdestination=new Destination(description,X,Y);
    fcin.close();
    return newdestination;
}
#endif /* help_hpp */
