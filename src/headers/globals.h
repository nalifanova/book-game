#include <iostream>
#ifndef BOOK_GAME_GLOBALS_H
#define BOOK_GAME_GLOBALS_H

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
    const std::string kBookName = "Maze of concealed death";
}

namespace mob {
    const std::string kSirRaul = "Sir Raul";
    const std::string kSirMortimer = "Sir Mortimer";
    const std::string kViscountElk = "Viscount Elk";
    const std::string kRoscht = "Rosht";
}

namespace item {
    // Note: names in Russian because they're taken from paragraphs
    const std::string kFoodName = "Еда"; // (0)
    const std::string kGuidingThreadName = "Путеводная нить"; // (+40)
    const std::string kFishBoneName = "Рыбная кость"; // (-49)
    const std::string kHandkerchiefName = "Расшитый странными узорами "
                                          "белоснежный платок"; // (+194)
    const std::string kSmallMirrorName = "Зеркальце"; // (+59)
    const std::string kBarbarianOutfitName = "Шкуры и меховая шапочка "
                                             "варвара"; // (+50)
    const std::string kMonkOutfitName = "Монашескую ряса"; // (+92)
    const std::string kKnightOutfitName = "Oдежды рыцаря"; // (+377)
    const std::string kSailorsOutfitName = "Oдежда моряка"; // (-77)
    const std::string kDuchyCoinName = "Монета герцогства"; // (+28)"
    // "Helmet (+26)" in backpack or "Helmet(+12)" on head
    const std::string kOldHelmetName = "Старый шлем";
}
#endif //BOOK_GAME_GLOBALS_H
