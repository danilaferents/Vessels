#include "main.hpp"
#include "Audit.hpp"
#include "CargoVessel.hpp"
#include "Destination.hpp"
#include "NavalFreightCompany.hpp"
#include "Vessels.hpp"
#include "stdlib.h"
//#include <Windows.h>
#include <fstream>
using namespace audit;
using namespace destination;
using namespace cargovessel;
using namespace passengervessel;
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
int main()
{	
	//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout<<std::endl;
	std::cout<<"Let's start calibration"<<std::endl<<std::endl;
	std::cout<<"Choose object you want to inspect!!!"<<std::endl<<std::endl;
	std::cout<<"1.Class Vessel."<<std::endl;
	std::cout<<"2.Class CargoVessel."<<std::endl;
	std::cout<<"3.Class PassengerVessel."<<std::endl;
	std::cout<<"4.Class Destination."<<std::endl;
	std::cout<<"5.Class NavalFreightCompany."<<std::endl;
	std::cout<<"6.Class Audit."<<std::endl;
	std::cout<<"7.Copying."<<std::endl;
	int n=0;
	std::cin>>n;
	printf("\033c");
	std::cout<<"Great choice!"<<std::endl;
	switch(n)
	{	
		case 1:
		{
			std::cout<<"Choose function you want to inspect!!!"<<std::endl<<std::endl;
			std::cout<<"1.Constructors."<<std::endl;
			std::cout<<"2.WasVeselRepaired."<<std::endl;
			std::cout<<"3.WasVesselDamaged."<<std::endl;
			std::cout<<"4.CompareDestination."<<std::endl;
			std::cout<<"5.CompareId."<<std::endl;
			//std::cout<<"6.Class Audit."<<std::endl;
			std::cin>>n;
			printf("\033c");
			std::cout<<"Great choice!"<<std::endl;
			switch(n)
			{
				case 1:
				{
					std::cout<<"Choose constructor you want to inspect!!!"<<std::endl<<std::endl;
					std::cout<<"1.Default."<<std::endl;
					std::cout<<"2.Full."<<std::endl;
					std::cin>>n;
					printf("\033c");
					std::cout<<"Great choice!"<<std::endl;
					switch(n)
					{
						case 1:
						{
							Vessel *newvessel=new Vessel();
							std::cout<<"-------"<<std::endl;
							std::cout<<"OUTPUT:"<<std::endl<<*newvessel;
							delete newvessel;
							break;
						}
						case 2:
						{
							std::cout<<"Put In id,eta"<<std::endl; 
							int Id,Eta,X,Y;
							std::string damages,repairs,description;
							std::cin>>Id>>Eta;
							std::cout<<"Damages, Repairs."<<std::endl;  
							std::cin>>damages>>repairs;
							std::cout<<" Descriptions, Coordinates:"<<std::endl<<std::endl;
							std::cin>>description>>X>>Y;
							ShipProperties *newshipproperties=new ShipProperties(damages,repairs);
							Destination *newdestination=new Destination(description,X,Y);
							Vessel *newvessel=new Vessel(Id,newdestination,Eta,newshipproperties);
							std::cout<<"-------"<<std::endl;
							std::cout<<"OUTPUT:"<<std::endl<<*newvessel;
							delete newvessel;
							break;

						}
						default:
						{
							std::cout<<"Try again!";
						}
					}
					break;
					//SetConsoleTextAttribute(hConsole, (WORD) ((DarkGray << 4) | Yellow));
				}
				case 2:
				{
					Vessel *newvessel=BuildNewVessel();
					std::cout<<"-------"<<std::endl;
					std::cout<<"INPUT:"<<std::endl<<*newvessel<<std::endl;
					std::cout<<"-------"<<std::endl;
					std::cout<<"OUTPUT:"<<std::endl;
					std::cout<<"Was Vessel Repaired?"<<std::endl<<std::endl;
					if (newvessel->WasVesselRepaired()) std::cout<<"YES!"<<std::endl<<std::endl;
					else std::cout<<"NO!"<<std::endl<<std::endl;
					delete newvessel;
					break;
				}
				case 3:
				{
					Vessel *newvessel=BuildNewVessel();
					std::cout<<"-------"<<std::endl;
					std::cout<<"INPUT:"<<std::endl<<*newvessel<<std::endl;
					std::cout<<"-------"<<std::endl;
					std::cout<<"OUTPUT:"<<std::endl;
					std::cout<<"Was Vessel Damaged?"<<std::endl<<std::endl;
					if (newvessel->WasVesselDamaged()) std::cout<<"YES!"<<std::endl<<std::endl;
					else std::cout<<"NO!"<<std::endl<<std::endl;
					delete newvessel;
					break;
				}
				case 4:
				{
					Vessel *newvessel=BuildNewVessel();
					std::cout<<"Input Destination To Compare?"<<std::endl;
					std::string destinationtocompare;
					std::cin>>destinationtocompare;
					std::cout<<"-------"<<std::endl;
					std::cout<<"INPUT:"<<std::endl<<*newvessel<<std::endl;
					std::cout<<"Comparing string: "<<destinationtocompare<<std::endl;
					std::cout<<"-------"<<std::endl;
					std::cout<<"OUTPUT:"<<std::endl;
					if (newvessel->CompareDestination(destinationtocompare)) std::cout<<"SAME!"<<std::endl<<std::endl;
					else std::cout<<"OTHER!"<<std::endl<<std::endl;
					delete newvessel;
					break;
				}
				case 5:
				{
					Vessel *newvessel=BuildNewVessel();
					std::cout<<"Input Id To Compare?"<<std::endl;
					int idtocompare;
					std::cin>>idtocompare;
					std::cout<<"-------"<<std::endl;
					std::cout<<"INPUT:"<<std::endl<<*newvessel<<std::endl;
					std::cout<<"Comparing id: "<<idtocompare<<std::endl;
					std::cout<<"-------"<<std::endl;
					std::cout<<"OUTPUT:"<<std::endl;
					if (newvessel->CompareId(idtocompare)) std::cout<<"Same!"<<std::endl;
					else std::cout<<"Other!"<<std::endl;
					delete newvessel;
					break;
				}
				default:
				{
					std::cout<<"Try again!";
				}
			}
			break;
		}
		case 2:
		{
			std::cout<<"Choose function you want to inspect!!!"<<std::endl<<std::endl;
			std::cout<<"1.Constructors."<<std::endl;
			std::cout<<"2.GetMaxCargo."<<std::endl;
			std::cout<<"3.GetCurCargo."<<std::endl;
			std::cout<<"4.GetContainerNUm."<<std::endl;
			//std::cout<<"6.Class Audit."<<std::endl;
			std::cin>>n;
			printf("\033c");
			std::cout<<"Great choice!"<<std::endl;
			switch(n)
			{
				case 1:
				{
					std::cout<<"Choose constructor you want to inspect!!!"<<std::endl<<std::endl;
					std::cout<<"1.Default."<<std::endl;
					std::cout<<"2.Full."<<std::endl;
					std::cin>>n;
					printf("\033c");
					std::cout<<"Great choice!"<<std::endl;
					switch(n)
					{
						case 1:
						{
							CargoVessel *newcargovessel=new CargoVessel();
							std::cout<<"-------"<<std::endl;
							std::cout<<"OUTPUT:"<<std::endl<<*newcargovessel;
							//delete newvessel;
							delete newcargovessel;
							break;
						}
						case 2:
						{
							// std::cout<<"Put In maxcargo,curcargo,container_num"<<std::endl; 
							//int maxcargo,curcargo,container_num;
							//std::cin>>maxcargo>>curcargo>>container_num;
							CargoVessel *newcargovessel=BuildNewCargoVessel();
							std::cout<<"-------"<<std::endl;
							std::cout<<"OUTPUT:"<<std::endl<<*newcargovessel;
							delete newcargovessel;
							break;

						}
						default:
						{
							std::cout<<"Try again!";
							break;
						}
					}
					break;
					//SetConsoleTextAttribute(hConsole, (WORD) ((DarkGray << 4) | Yellow));
				}
				case 2:
				{
					CargoVessel *newcargovessel=BuildNewCargoVessel();
					std::cout<<"-------"<<std::endl;
					std::cout<<"INPUT:"<<std::endl<<*newcargovessel<<std::endl;
					std::cout<<"-------"<<std::endl;
					std::cout<<"OUTPUT:"<<std::endl<<std::endl;
					std::cout<<"Max Cargo of our Vessel: "<<newcargovessel->GetMaxCargo()<<std::endl;
					delete newcargovessel;
					break;
				}
				case 3:
				{
					CargoVessel *newcargovessel=BuildNewCargoVessel();
					std::cout<<"-------"<<std::endl;
					std::cout<<"INPUT:"<<std::endl<<*newcargovessel<<std::endl;
					std::cout<<"-------"<<std::endl;
					std::cout<<"OUTPUT:"<<std::endl<<std::endl;
					std::cout<<"Cur Cargo of our Vessel: "<<newcargovessel->GetCurCargo()<<std::endl;
					delete newcargovessel;
					break;
				}
				case 4:
				{
					CargoVessel *newcargovessel=BuildNewCargoVessel();
					std::cout<<"-------"<<std::endl;
					std::cout<<"INPUT:"<<std::endl<<*newcargovessel<<std::endl;
					std::cout<<"-------"<<std::endl;
					std::cout<<"OUTPUT:"<<std::endl<<std::endl;
					std::cout<<"Container_Num of our Vessel: "<<newcargovessel->GetContainerNum()<<std::endl;
					delete newcargovessel;
					break;
				}
				default:
				{
					std::cout<<"Try again!";
					break;
				}
			}
			break;
		}
		case 3:
		{
			std::cout<<"Choose function you want to inspect!!!"<<std::endl<<std::endl;
			std::cout<<"1.Constructors."<<std::endl;
			std::cout<<"2.CompareMaxAndCurPax."<<std::endl;
			//std::cout<<"6.Class Audit."<<std::endl;
			std::cin>>n;
			printf("\033c");
			std::cout<<"Great choice!"<<std::endl;
			switch(n)
			{
				case 1:
				{	

					std::cout<<"Choose constructor you want to inspect!!!"<<std::endl<<std::endl;
					std::cout<<"1.Default."<<std::endl;
					std::cout<<"2.Full."<<std::endl;
					std::cin>>n;
					printf("\033c");
					std::cout<<"Great choice!"<<std::endl;
					switch(n)
					{
						case 1:
						{
							PassengerVessel *newpassengervessel=new PassengerVessel();
							std::cout<<"-------"<<std::endl;
							std::cout<<"OUTPUT:"<<std::endl<<*newpassengervessel;
							delete newpassengervessel;
							break;
						}
						case 2:
						{
							//std::cout<<"Put In maxcargo,curcargo,container_num"<<std::endl; 
							//int maxcargo,curcargo,container_num;
							//std::cin>>maxcargo>>curcargo>>container_num;
							PassengerVessel *newpassengervessel=BuildNewPassengerVessel();
							std::cout<<"-------"<<std::endl;
							std::cout<<"OUTPUT:"<<std::endl<<*newpassengervessel;
							delete newpassengervessel;
							break;

						}
						default:
						{
							std::cout<<"Try again!";
						}
					}
					break;
				}
				case 2:
				{
					PassengerVessel *newpassengervessel=BuildNewPassengerVessel();
					std::cout<<"-------"<<std::endl;
					std::cout<<"INPUT:"<<std::endl<<*newpassengervessel<<std::endl;
					std::cout<<"-------"<<std::endl;
					std::cout<<"OUTPUT:"<<std::endl<<std::endl;
					if (newpassengervessel->CompareMaxpaxAndCurpax()) std::cout<<"Normal!";
					else std::cout<<"Fault!People can die!";
					delete newpassengervessel;
					break;
				}
			}
			break;
		}
		case 4:
		{
			std::cout<<"Choose function you want to inspect!!!"<<std::endl<<std::endl;
			std::cout<<"1.Constructors."<<std::endl;
			std::cout<<"2.GetName."<<std::endl;
			std::cout<<"3.GetCoordinates."<<std::endl;
			//std::cout<<"6.Class Audit."<<std::endl;
			std::cin>>n;
			printf("\033c");
			std::cout<<"Great choice!"<<std::endl;
			switch(n)
			{
				case 1:
				{	

					std::cout<<"Choose constructor you want to inspect!!!"<<std::endl<<std::endl;
					std::cout<<"1.Default."<<std::endl;
					std::cout<<"2.Full."<<std::endl;
					std::cin>>n;
					printf("\033c");
					std::cout<<"Great choice!"<<std::endl;
					switch(n)
					{
						case 1:
						{
							Destination *newdestination=new Destination();
							std::cout<<*newdestination;
							std::cout<<"-------"<<std::endl;
							std::cout<<"OUTPUT:"<<std::endl<<*newdestination;
							delete newdestination;
							break;
						}
						case 2:
						{
							std::string description;
							int X,Y;
							std::cout<<" Descriptions, Coordinates:"<<std::endl<<std::endl;
							std::cin>>description>>X>>Y;
							Destination *newdestination=new Destination(description,X,Y);
							std::cout<<"-------"<<std::endl;
							std::cout<<"OUTPUT:"<<std::endl<<*newdestination;
							delete newdestination;
							break;

						}
						default:
						{
							std::cout<<"Try again!";
						}
					}
					break;
				}
				case 2:
				{		
					Destination* newdestination=BuildNewDestination();
					std::cout<<"-------"<<std::endl;
					std::cout<<"INPUT:"<<std::endl<<*newdestination<<std::endl;
					std::cout<<"-------"<<std::endl;
					std::cout<<"OUTPUT:"<<std::endl<<std::endl;
					std::cout<<"Destination: "<<newdestination->GetName()<<std::endl;
					delete newdestination;
					break;
				}
				case 3:		
				{
					Destination* newdestination=BuildNewDestination();
					std::cout<<"-------"<<std::endl;
					std::cout<<"INPUT:"<<std::endl<<*newdestination<<std::endl;
					std::cout<<"-------"<<std::endl;
					std::cout<<"OUTPUT:"<<std::endl<<std::endl;
					std::cout<<" X= "<<newdestination->GetCoordinates().first<<"  Y= "<<newdestination->GetCoordinates().second<<std::endl;
					delete newdestination;
					break;
				}
				default:
				{
					std::cout<<"Try again!";
					break;
				}
			}
			break;
		}
		case 5:
		{
			NavalFreightCompany *newnavalcompany=new NavalFreightCompany();
			Vessel *newvessel=BuildNewVessel1(1,30,6,25,"1.06.2007","2.09.19","Artur");
			Vessel *newvessel1=BuildNewVessel1(2,5,5,36,"2.08.2015","7.03.08","Lancelot");
			Vessel *newvessel2=BuildNewVessel1(3,33,1,1,"3.09.2017","6.05.18","King");
			Vessel *newvessel3=BuildNewVessel1(4,56,2,4,"4.10.2018","2.09.18","Poetry");
			Vessel *newvessel4=BuildNewVessel1(5,2,12,144,"","","Artur");
			newnavalcompany->add(newvessel);
			newnavalcompany->add(newvessel1);
			newnavalcompany->add(newvessel2);
			newnavalcompany->add(newvessel3);
			newnavalcompany->add(newvessel4);
			std::cout<<"-------"<<std::endl;
			std::cout<<"INPUT:"<<std::endl<<*newnavalcompany<<std::endl;
			std::cout<<"Choose function you want to inspect!!!"<<std::endl<<std::endl;
			std::cout<<"1.Add."<<std::endl;
			std::cout<<"2.Remove."<<std::endl;
			std::cout<<"3.Draft."<<std::endl;
			std::cout<<"4.PrintStats."<<std::endl;
			std::cout<<"5.MarkRepaired."<<std::endl;
			std::cout<<"6.MarkDamaged."<<std::endl;
			std::cout<<"7.ChangeDestination."<<std::endl;
			std::cout<<"8.PrintHeadingTo."<<std::endl;
			std::cin>>n;
			// printf("\033c");
			std::cout<<"Great choice!"<<std::endl;
			switch(n)
			{
				case 1:
				{
					std::cout<<"Choose how many arguments you want to inspect!!!"<<std::endl<<std::endl;
					std::cout<<"1.1 Argument."<<std::endl;
					std::cout<<"2.2 Arguments."<<std::endl;
					std::cin>>n;
					printf("\033c");
					std::cout<<"Great choice!"<<std::endl;
					switch(n)
					{
						case 1:
						{
							Vessel *newvessel=BuildNewVessel();
							// Vessel *newvessel1=BuildNewVessel();
							newnavalcompany->add(newvessel);
							std::cout<<"-------"<<std::endl;
							std::cout<<"OUTPUT:"<<std::endl<<*newnavalcompany;
							// newnavalcompany->add(newvessel1);
							break;
						}
						case 2:
						{
							Vessel *newvessel;
							Destination* newdestinsation=BuildNewDestination();
							// Vessel *newvessel1=BuildNewVessel();
							newnavalcompany->add(newvessel,newdestinsation);
							// newnavalcompany->add(newvessel1);
							std::cout<<"-------"<<std::endl;
							std::cout<<"OUTPUT:"<<std::endl<<*newnavalcompany;
							break;
						}
						default:
						{
							std::cout<<"Try again!";
							break;
						}
					}
					break;
				}
				case 2:
				{
					std::cout<<"Choose what you want to remove!!!"<<std::endl<<std::endl;
					std::cout<<"1.1 Vessel."<<std::endl;
					std::cout<<"2.2 Id."<<std::endl;
					std::cin>>n;
					printf("\033c");
					std::cout<<"Great choice!"<<std::endl;
					switch(n)
					{
						case 1:
						{
							// Vessel *newvessel=BuildNewVessel();
							// Vessel *newvessel1=BuildNewVessel();
							// Vessel *newvessel2=new Vessel();
							// Vessel *newvessel1=BuildNewVessel();
							// newnavalcompany->add(newvessel);
							// newnavalcompany->add(newvessel1);
							// newnavalcompany->add(newvessel2);
							std::cout<<"--------------"<<std::endl;
							std::cout<<"AFTER DELETING!"<<std::endl<<std::endl;
							// std::cout<<*newnavalcompany;
							newnavalcompany->remove(newvessel2);
							// newnavalcompany->add(newvessel1);
							std::cout<<*newnavalcompany;
							break;
						}
						case 2:
						{
							// Vessel *newvessel=BuildNewVessel();
							// Vessel *newvessel1=BuildNewVessel();
							// Vessel *newvessel2=new Vessel();
							// Vessel *newvessel1=BuildNewVessel();
							// newnavalcompany->add(newvessel);
							// newnavalcompany->add(newvessel1);
							// newnavalcompany->add(newvessel2);
							std::cout<<"--------------"<<std::endl;
							std::cout<<"AFTER DELETING!"<<std::endl<<std::endl;
							// std::cout<<*newnavalcompany;
							newnavalcompany->remove(4);
							// newnavalcompany->add(newvessel1);
							std::cout<<*newnavalcompany;
							break;
						}
						
						default:
						{
							std::cout<<"Try again!";
							break;
						}
					}
					break;
				}
				case 3:
				{
					std::cout<<"--------------"<<std::endl;
					std::cout<<"AFTER DELETING!"<<std::endl<<std::endl;
					newnavalcompany->draft();
					std::cout<<*newnavalcompany;
					break;
				}
				case 4:
				{
					printf("\033c");
					CargoVessel* newcargovessel=BuildNewCargoVessel();
					newnavalcompany->add(newcargovessel);
					CargoVessel* newcargovessel1=BuildNewCargoVessel();
					newnavalcompany->add(newcargovessel1);
					PassengerVessel* newpassengervessel1=BuildNewPassengerVessel();
					newnavalcompany->add(newpassengervessel1);
					PassengerVessel* newpassengervessel2=new PassengerVessel();
					newnavalcompany->add(newpassengervessel2);
					std::cout<<"-------"<<std::endl;
					std::cout<<"INPUT:"<<std::endl<<std::endl;
					std::cout<<*newnavalcompany;
					std::cout<<"-------"<<std::endl;
					std::cout<<"OUTPUT:"<<std::endl<<std::endl;
					newnavalcompany->printStats();
					break;
				}
				case 5:
				{
					std::cout<<"-------"<<std::endl;
					std::cout<<"INPUT:"<<std::endl<<std::endl;
					std::cout<<*newnavalcompany;
					std::string changerepairedhelp="19.09.2020";
					std::string *changerepaired=new std::string;
					*changerepaired=changerepairedhelp;
					std::cout<<changerepairedhelp<<std::endl;
					newnavalcompany->markRepaired(2,changerepaired);
					std::cout<<"-------"<<std::endl;
					std::cout<<"OUTPUT:"<<std::endl<<std::endl;
					std::cout<<*newnavalcompany;
					break;
				}
				case 6:
				{
					std::cout<<"-------"<<std::endl;
					std::cout<<"INPUT:"<<std::endl<<std::endl;
					std::cout<<*newnavalcompany;
					std::string changedamagedhelp="10.10.2025";
					std::string* changedamaged=new std::string;
					*changedamaged=changedamagedhelp;
					std::cout<<changedamagedhelp<<std::endl;
					newnavalcompany->markDamaged(1,changedamaged);
					std::cout<<"-------"<<std::endl;
					std::cout<<"OUTPUT:"<<std::endl<<std::endl;
					std::cout<<*newnavalcompany;
					break;
				}
				case 7:
				{
					std::cout<<"-------"<<std::endl;
					std::cout<<"INPUT:"<<std::endl<<std::endl;
					std::cout<<*newnavalcompany;
					std::string description="PortSaint-Petersburg";
					std::cout<<description<<std::endl;
					int X=123,Y=456;
					Destination *newdestination=new Destination(description,X,Y);
					newnavalcompany->changeDestination(5,newdestination);
					std::cout<<"-------"<<std::endl;
					std::cout<<"OUTPUT:"<<std::endl<<std::endl;
					std::cout<<*newnavalcompany;
					break;
				}
				case 8:
				{
					std::cout<<"-------"<<std::endl;
					std::cout<<"OUTPUT:"<<std::endl<<std::endl;
					std::cout<<*newnavalcompany;
					newnavalcompany->printHeadingTo("Artur");
					break;
				}
				default:
				{
					std::cout<<"Try again!";
					break;
				}
			}
			delete newnavalcompany;
			break;
		}
		case 6:
		{
			std::string newstring="SmallVanino";
			Destination *location=new Destination(newstring,6,36);
			NavalFreightCompany *newnavalcompany=new NavalFreightCompany();
			//std::cout<<"HELP"<<*location;
			Vessel *newvessel=BuildNewVessel1(1,30,6,25,"1.06.2007","2.09.19","Artur");
			Vessel *newvessel1=BuildNewVessel1(2,5,5,36,"2.08.2015","7.03.08","Lancelot");
			Vessel *newvessel2=BuildNewVessel1(3,33,1,1,"3.09.2017","6.05.18","King");
			Vessel *newvessel3=BuildNewVessel1(4,56,2,4,"4.10.2018","2.09.18","Poetry");
			Vessel *newvessel4=BuildNewVessel1(5,2,12,144,"","","Artur");
			PassengerVessel *newpassengervessel=BuildNewPassengerVessel();
			newnavalcompany->add(newpassengervessel);
			newnavalcompany->SetLocation(location);
			newnavalcompany->add(newvessel);
			newnavalcompany->add(newvessel1);
			newnavalcompany->add(newvessel2);
			newnavalcompany->add(newvessel3);
			newnavalcompany->add(newvessel4);
			std::cout<<*newnavalcompany;
			std::cout<<"Choose function you want to inspect!!!"<<std::endl<<std::endl;
			std::cout<<"1.compare1."<<std::endl;
			std::cout<<"2.compare2."<<std::endl;
			std::cout<<"3.Is PassenegerVessel in Port."<<std::endl;
			std::cout<<"4.inspectPassengerVessel."<<std::endl;
			std::cout<<"5.inspectCargoVessel."<<std::endl;
			
			//std::cout<<"6.Class Audit."<<std::endl;
			std::cin>>n;
			printf("\033c");
			std::cout<<"Great choice!"<<std::endl;
			switch(n)
			{
				case 1:
				{	
					NavalFreightCompany *newnavalcompany1=new NavalFreightCompany();
					std::cout<<"-------"<<std::endl;
					std::cout<<"OUTPUT:"<<std::endl<<std::endl;
					Audit::compare1(*newnavalcompany,*newnavalcompany1);
					delete newnavalcompany1;
					break;
				}
				case 2:
				{		
					NavalFreightCompany *newnavalcompany1=new NavalFreightCompany();
					std::cout<<"-------"<<std::endl;
					std::cout<<"OUTPUT:"<<std::endl;
					Audit::compare2(*newnavalcompany,*newnavalcompany1);
					delete newnavalcompany1;
					break;
				}
				case 3:		
				{
					std::cout<<"-------"<<std::endl;
					std::cout<<"OUTPUT:"<<std::endl;
					if (Audit::isPassengerVesselsInPort(*newnavalcompany)) std::cout<<"There are some vessels on duty!";
					else std::cout<<"There is no vessels on duty!";
					break;
				}
				case 4:		
				{
					PassengerVessel *newpassengervessel=BuildNewPassengerVessel();
					std::cout<<"-------"<<std::endl;
					std::cout<<"INPUT:"<<std::endl<<std::endl;
					std::cout<<*newpassengervessel<<std::endl;
					std::cout<<"-------"<<std::endl;
					std::cout<<"OUTPUT:"<<std::endl;
					if (Audit::inspectPassengerVessel(*newpassengervessel)) std::cout<<"Excellent! Everything is good!"<<std::endl;
					else std::cout<<"WARING! People can die"<<std::endl;
					delete newpassengervessel;
					break;
				}
				case 5:		
				{
					CargoVessel *newcargovessel=BuildNewCargoVessel();
					std::cout<<"-------"<<std::endl;
					std::cout<<"INPUT:"<<std::endl<<std::endl;
					std::cout<<*newcargovessel<<std::endl;
					std::cout<<"-------"<<std::endl;
					std::cout<<"OUTPUT:"<<std::endl;
					if (Audit::inspectCargoVessel(*newcargovessel)) std::cout<<"Excellent! Everything is good!"<<std::endl;
					else std::cout<<"WARING! Vessel can drown"<<std::endl;
					delete newcargovessel;
					break;
				}
				default:
				{
					std::cout<<"Try again!";
					 break;
				}
			}
			delete newnavalcompany;
			break;
		}
		case 7:
		{
			std::cout<<"Great choice!"<<std::endl;
			std::cout<<std::endl;
			std::cout<<"Let's start calibration"<<std::endl<<std::endl;
			std::cout<<"Choose object you want to copy!!!"<<std::endl<<std::endl;
			std::cout<<"1.Class Vessel."<<std::endl;
			std::cout<<"2.Class CargoVessel."<<std::endl;
			std::cout<<"3.Class PassengerVessel."<<std::endl;
			std::cin>>n;
			printf("\033c");
			switch(n)
			{
				
				case 1:
				{
					Vessel *newvessel=BuildNewVessel();
					std::cout<<"-------"<<std::endl;
					std::cout<<"INPUT:"<<std::endl<<*newvessel<<std::endl;
					std::cout<<"-------"<<std::endl;
					std::cout<<"OUTPUT:"<<std::endl<<std::endl;
					Vessel *newvessel1=new Vessel(*newvessel);
					std::cout<<*newvessel1;
					delete newvessel;
					delete newvessel1;
					break;
				}
				case 2:
				{
					PassengerVessel *newpassengervessel=BuildNewPassengerVessel();
					std::cout<<"-------"<<std::endl;
					std::cout<<"INPUT:"<<std::endl<<*newpassengervessel<<std::endl;
					std::cout<<"-------"<<std::endl;
					std::cout<<"OUTPUT:"<<std::endl<<std::endl;
					PassengerVessel *newpassengervessel1=new PassengerVessel(*newpassengervessel);
					std::cout<<*newpassengervessel1;
					delete newpassengervessel1;
					delete newpassengervessel;
					break;
				}
				case 3:
				{
					CargoVessel *newcargovessel=BuildNewCargoVessel();
					std::cout<<"-------"<<std::endl;
					std::cout<<"INPUT:"<<std::endl<<*newcargovessel<<std::endl;
					std::cout<<"-------"<<std::endl;
					std::cout<<"OUTPUT:"<<std::endl<<std::endl;
					CargoVessel *newcargovessel1=new CargoVessel(*newcargovessel);
					std::cout<<*newcargovessel1;
					delete newcargovessel1;
					delete newcargovessel;
					break;
				}
			}
			break;
		}
	}

}
//g++ -std=c++11 main.cpp Audit.cpp CargoVessel.cpp Destination.cpp NavalFreightCompany.cpp PassengerVessel.cpp Vessel.cpp -o Vessel
//valgrind --leak-check=full --leak-resolution=high ./Vessel
