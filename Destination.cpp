#include "Destination.hpp"
using namespace destination;
std::string Destination::GetName() const
{
	return description;
}
std::pair<int,int> Destination::GetCoordinates() const
{
	return std::make_pair(x,y);
}
void Destination::SetName(std::string description1)
{
    description=description1;
}
void Destination::SetCoordinates(std::pair<int,int> coordinates)
{
	x=coordinates.first;
	y=coordinates.second;
}