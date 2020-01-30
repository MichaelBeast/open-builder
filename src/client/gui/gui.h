#pragma once

#include "../gl/shader.h"
#include "../gl/textures.h"
#include "../gl/vertex_array.h"
#include <SFML/Window/Event.hpp>
#include <common/macros.h>
#include <common/scripting/script_engine.h>
#include <memory>
#include <vector>

// Todo: Maybe move these out into their own files

// Stores the scale and offset of a GUI element in 2 dimensions
struct GDim {
    sf::Vector2f scale;
    sf::Vector2f offset;

    GDim()
        : scale(sf::Vector2f(0, 0))
        , offset(sf::Vector2f(0, 0))
    {
    }

    GDim(float x_s, float x_o, float y_s, float y_o)
        : scale(sf::Vector2f(x_s, y_s))
        , offset(sf::Vector2f(x_o, y_o))
    {
    }
};

// GUI Image,
struct GuiImage {
    gl::Texture2d m_image;
    
    glm::vec2 position;
    glm::vec2 size;
    glm::vec3 colour;

    //GDim m_size;
    //GDim m_position;

    // Setters (TODO: Getters?)
    void setSource(const std::string &imageSource);
    void setSize(float width, float height);
    void setPosition(float x, float y);
    void setColour(float r, float g, float b);
};

class Gui final {
  public:
    Gui();

    void addUsertypes(sol::table &m_lua);
    void processKeypress(sf::Event e);
    void processMouseEvent(sf::Event e);

    void addImage(sol::userdata image);

    void render(int width, int height);

  private:
    struct {
        gl::Shader program;
        gl::UniformLocation modelLocation;
        gl::UniformLocation colorLocation;
    } m_guiShader;

    gl::VertexArray m_quad;
    std::vector<sol::userdata> m_images;
};