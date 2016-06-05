//
// Sprite.hpp
// Tom Albrecht, 06.12.15 - 01:13
// (Copyright)
//

#ifndef _TiledMapNode
#define _TiledMapNode 1

#include "SDL.h"
#include "SDL_image.h"
#include "tmxparser.h"
#include <stdio.h>
#include <vector>
#include <iostream>
#include "Sprite.hpp"
#include "Types.hpp"

FE_NAMESPACE_BEGIN

class TiledMapNode;
FE_create_Ptr(TiledMapNode);
typedef std::vector< Rect > RectVector;

/**
 * Loads and Displays a tiled tmx map
 */
class TiledMapNode : public Sprite {
public:
    /**
     * Creates a new TiledMapNode object
     *
     * @return a shared_ptr to the new TiledMapNode instance
     */
    static TiledMapNodePtr create(const std::string &filepath);
    
    /**
     * Deconstructor
     */
    ~TiledMapNode();
    
    /**
     * Returns all tile layers in a vector (as std::weak_ptr<Sprites>)
     */
    std::vector<SpriteWeakPtr> getAllLayers();
    
    /// May return NULL if not found!
    SpritePtr getLayerNamed(std::string);
    
    std::vector<tmxparser::TmxObjectGroup> getAllObjectGroups();
    
    /// May return NULL if not found!
    tmxparser::TmxObjectGroup getObjectGroupNamed(std::string name);
    
    /**
     * Sets the anchorPoint of all layers
     */
    virtual void setAnchorPoint(FE::Vec2 ap);
    
    /**
     * Gets raw TmxMap data from tmxparser 
     */
    tmxparser::TmxMap getRawMap();
    
protected:
    bool init (const std::string &filepath);
private:
    std::string directory = ""; // path of directory the map is located in, in order to load images correctly
    void drawTiles();
    void getObjects();
    tmxparser::TmxMap map;
    std::vector<SpriteWeakPtr> mTileLayer;
};

FE_NAMESPACE_END
#endif
