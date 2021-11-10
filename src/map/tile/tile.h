#ifndef	TILE_H
#define TILE_H

#include "../../buildings/template.h"
#include "../../materials/materials.h"

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
        Template* building = nullptr;
        bool available;
    public:
        GroundTile();
        void setBuildingAsNull();
        Template getBuildingTemplate();
        void addBuilding(Template* buildingTemplate);
        void removeBuilding();
        bool isAvailable();
};

class RoadTile : public Tile {
    private:
        Material* material;
        bool available;
	public:
        RoadTile();
        void addMaterial(Material* newMaterial);
        bool isAvailable();
        void clearRoad(std::string& name, int& amount);
};

#endif
