#pragma once
#ifndef Destination_hpp
#define Destination_hpp
#include "main.hpp"
namespace destination
{
    class Destination 
    {
        private: 
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
                description="";
                x=0;
                y=0;
            }
            std::string GetName() const;
            void SetName(std::string description1);
            void SetCoordinates(std::pair<int,int> coordinates);
            std::pair<int,int> GetCoordinates() const;
            friend std::ostream& operator<<(std::ostream& os, const Destination& v)
            {
                os << "Port: " <<v.description<< std::endl;
                os<<"Coordinate x: "<<v.x<<std::endl;
                os<<"Coordinate y: "<<v.y<<std::endl;
                os<<std::endl;
                return os;
            }
    };
}
#endif /* Destination_hpp */
