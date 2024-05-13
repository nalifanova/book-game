#ifndef BOOK_GAME_GLOBALS_H
#define BOOK_GAME_GLOBALS_H

#include <iostream>

// Note: should be used for GUI window
namespace globals {
    const int kScreenWidth = 640;
    const int kScreenHeight = 480;
}

namespace row {
    const int kUnderlineLength = 50;
    const int kCliOutputLineWidth = 121;
}

namespace msg {
    const std::string kTitle = "Book Game:";
    const std::string kBookName = "Maze of Concealed Death";
}

namespace mob {
    const std::string kSirRaul = "Sir Raul";
    const std::string kSirMortimer = "Sir Mortimer";
    const std::string kViscountElk = "Viscount Elk";
    const std::string kRoscht = "Rosht";
}

namespace item {
    // Note: names in Russian because they're taken from paragraphs
    const std::string kFoodName = "Food"; // (0)
    const std::string kGuidingThreadName = "Guiding Thread"; // (+40)
    const std::string kFishBoneName = "Fish Bone"; // (-49)
    const std::string kHandkerchiefName = "White Handkerchief"; // (+194)
    const std::string kSmallMirrorName = "Mirror"; // (+59)
    const std::string kBarbarianOutfitName = "The skins and fur cap of a "
                                             "barbarian"; // (+50)
    const std::string kMonkOutfitName = "A monk's robe"; // (+92)
    const std::string kKnightOutfitName = "Knight's attire"; // (+377)
    const std::string kMerchantOutfitName = "A merchant's outfit"; // (-48)
    const std::string kSailorsOutfitName = "A sailor's attire"; // (-77)
    const std::string kDuchyCoinName = "Duchy coin"; // (+28)"
    // "Helmet (+26)" in backpack or "Helmet(+12)" on head
    const std::string kKnightsHelmetName = "Knight's helmet";
}
#endif //BOOK_GAME_GLOBALS_H
