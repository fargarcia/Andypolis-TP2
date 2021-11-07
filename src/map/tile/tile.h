#ifndef	TILE_H
#define TILE_H

class Tile {

    public:
        Tile();
        ~Tile();
};

class LakeTile : public Tile {
	using Tile::Tile;
};

class GroundTile : public Tile {
	using Tile::Tile;
};

class RoadTile : public Tile {
	using Tile::Tile;
};

#endif
