#include "PassengerVessel.hpp"
using namespace passengervessel;
bool PassengerVessel::CompareMaxpaxAndCurpax() const
{
    if (curpax<=maxpax) return 1;
    return 0;
}
/*
PassengerVessel*  PassengerVessel::clone()
{
    return new PassengerVessel(*this);
}*/