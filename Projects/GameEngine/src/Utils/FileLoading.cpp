#include "../../include/FileLoading.h"
#include <algorithm>
#include <filesystem>
#include <memory>

Sprite getSpriteFromTextFile(std::string fileLocation) {
  std::ifstream inputFile(fileLocation);

  if (!inputFile.is_open()) {
    std::cerr << "Error opening the file: " << fileLocation << std::endl;
    std::vector<Pixel> errorPixels;
    errorPixels.push_back(Pixel(Position(0, 0), '~'));
    return Sprite(errorPixels);
  }

  std::string line;
  std::vector<Pixel> pixels;

  std::size_t x = 0;
  int y = 0;
  while (getline(inputFile, line)) {
    x = 0;
    while (x < line.size()) {
      pixels.push_back(Pixel(Position(x, y), line.at(x)));
      x++;
    }
    y++;
  }
  inputFile.close();
  return Sprite(pixels);
}

Frame getFrameFromTextFile(std::string fileLocation) {
  std::ifstream inputFile(fileLocation);

  if (!inputFile.is_open()) {
    std::cerr << "Error opening the file: " << fileLocation << std::endl;
    std::vector<Pixel> errorPixels;
    errorPixels.push_back(Pixel(Position(0, 0), '~'));
    return Frame(Sprite(errorPixels), 60);
  }

  std::string line;
  std::vector<Pixel> pixels;

  getline(inputFile, line);
  int duration = stoi(line);

  std::size_t x = 0;
  int y = 0;
  while (getline(inputFile, line)) {
    x = 0;
    while (x < line.size()) {
      pixels.push_back(Pixel(Position(x, y), line.at(x)));
      x++;
    }
    y++;
  }
  inputFile.close();
  return Frame(Sprite(pixels), duration);
}

namespace fs = std::filesystem;
Animation loadAnimation(std::string entityName, std::string animationName,
                        bool repeats) {
  std::string folderPath = "src/Animations/" + entityName + "/" + animationName;
  std::vector<Frame> frames;

  try {
    std::vector<fs::directory_entry> entries;
    for (const auto &entry : fs::directory_iterator(folderPath)) {
      if (entry.is_regular_file()) {
        entries.push_back(entry);
      }
    }
    // Sort by filename
    std::sort(entries.begin(), entries.end(),
              [](const fs::directory_entry &a, const fs::directory_entry &b) {
                return a.path().filename().string() <
                       b.path().filename().string();
              });

    for (const auto &entry : entries) {
      std::string fileName = entry.path().filename().string();
      std::string fullFilePath = folderPath + "/" + fileName;
      std::cout << "Loading file: " << fullFilePath << std::endl;
      frames.push_back(getFrameFromTextFile(fullFilePath));
    }
    return Animation(animationName, frames, repeats);
  } catch (const fs::filesystem_error &e) {
    std::cerr << "Filesystem error: " << e.what() << std::endl;
    return Animation();
  }
}

std::shared_ptr<Entity> loadEntity(const std::string entityName, bool visable,
                                   int layer, bool moveableByCamera) {
  std::vector<Animation> animations;
  std::string basePath = "src/Animations/" + entityName;

  try {
    for (const auto &entry : fs::directory_iterator(basePath)) {
      if (entry.is_directory()) {
        std::string animationName = entry.path().filename().string();
        Animation anim = loadAnimation(entityName, animationName, true);
        animations.push_back(anim);
      }
    }
  } catch (const fs::filesystem_error &e) {
    std::cerr << "Error loading animations for entity '" << entityName
              << "': " << e.what() << std::endl;
  }
  auto entity = std::make_shared<Entity>(entityName, animations, visable, layer,
                                         moveableByCamera);
  allEntities.push_back(entity);
  return entity;
}