#ifndef	TILE_H
#define TILE_H

#include "../../buildings/template.h"

class Tile {

    private:
        std::string tileType;

    public:
        Tile();
        ~Tile();
        void setType(std::string type);
        std::string getType();
};

class LakeTile : public Tile {
    public:
        LakeTile();
};

class GroundTile : public Tile {
    private:
        Template* building;
    public:
        GroundTile();
        void addBuilding(Template* buildingTemplate);
        bool isAvailable();

};

class RoadTile : public Tile {
	public:
        RoadTile();
};

#endif
