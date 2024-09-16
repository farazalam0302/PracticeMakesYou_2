#include <bits/stdc++.h>
using namespace std;

class Texture {
public:
  explicit Texture(const string &fileName)
      : m_FileName(fileName), m_Id(arc4random_uniform(INT_MAX)) {}

  const string description() const {
    return "<" + m_FileName + " id" + to_string(m_Id) + ">";
  }

private:
  const string m_FileName;
  const int m_Id;
};

class Sprite {

public:
  Sprite(const Texture *texture) : m_Texture(texture) {
    cout << "Creating sprite with texture file " << texture->description()
         << endl;
  }

  void setPositionSize(int x, int y, int width, int height) {
    m_Height = height;
    m_Width = width;
    m_X = x;
    m_Y = y;
  }

  void render() {
    // draw sprite
    cout << "Rendering sprite with texture: " << m_Texture->description()
         << endl;
  }

private:
  int m_Width;
  int m_Height;
  int m_X;
  int m_Y;

  const Texture *m_Texture;
};

class SpriteFactory {
public:
  Sprite *makeSprite(const string &filename) {
    auto it = m_spritePool.find(filename);
    if (it != m_spritePool.end()) {
      return it->second;
    } else {
      const auto texture = getTexture(filename);
      auto [newItr, flag] = m_spritePool.emplace(filename, new Sprite(texture));
      return newItr->second;
    }
  }
  ~SpriteFactory() {
    for (auto &[filename, sprite] : m_spritePool) {
      delete sprite;
    }

    for (auto &[filename, texture] : m_texturePool) {
      delete texture;
    }
  }

private:
  unordered_map<string, Sprite *> m_spritePool;
  unordered_map<string, Texture *> m_texturePool;

  const Texture *getTexture(const string &filename) {
    auto it = m_texturePool.find(filename);
    if (it != m_texturePool.end()) {
      return it->second;
    } else {
      auto [newIT, flag] =
          m_texturePool.emplace(filename, new Texture(filename));
      return newIT->second;
    }
  }
};

int main() {
  // create a list of sprite objects
  vector<Sprite *> sprites;
  const int numSprites = 10;
  const string textureFile = "spaceship.png";

  SpriteFactory factory;

  for (int i = 0; i < numSprites; ++i) {
    auto sprite = factory.makeSprite((textureFile));
    sprite->setPositionSize(10, 10, 10 * i, 10 * i);
    sprites.push_back(sprite);
  }

  // draw all sprites
  for (auto &sprite : sprites) {
    sprite->render();
  }

  return 0;
}
