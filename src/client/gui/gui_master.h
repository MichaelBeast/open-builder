#pragma once

#include "../gl/shader.h"
#include "../gl/textures.h"
#include "../gl/vertex_array.h"
#include "gui_container.h"
#include "gui_shader.h"

/**
 * @brief Render master for the GUIs
 *
 */
class GuiMaster final {
  public:
    GuiMaster(float viewportWidth, float viewportHeight);

    GuiContainer* addGui();

    void render();

    int getTexture(const std::string& textureName);

    // For testing purposes
    int guiCount() const;
    int textureCount() const;

  private:
    // Pointers to containers (stored in lua or elsewhere)
    std::vector<GuiContainer> m_containers;

    // Maps a string to a texture index of m_textures
    std::unordered_map<std::string, int> m_textureIds;
    std::vector<gl::Texture2d> m_textures;

    // OpenGL Rendering stuff
    GuiShader m_shader;
    gl::VertexArray m_quadVao;
    glm::mat4 m_projection;
    glm::vec2 m_viewport;
};