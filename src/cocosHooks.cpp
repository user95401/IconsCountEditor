#include "cocosHooks.hpp"
#include "SimpleIni.h"
#include "ValueSetupPopup.hpp"

#include "hooks.hpp"
void CreateCocosHooks() {
    CC_HOOK("?create@CCSprite@cocos2d@@SAPAV12@PBD@Z", CCSprite_create);
    CC_HOOK("?createWithSpriteFrameName@CCSprite@cocos2d@@SAPAV12@PBD@Z", CCSprite_createWithSpriteFrameName);
    CC_HOOK("?create@CCLabelBMFont@cocos2d@@SAPAV12@PBD0@Z", CCLabelBMFont_create);
}

CCSprite* CCSprite_create_H(const char* name) {
    if (HideEverySprite) {//blankSprite
        CCSprite* no = CCSprite::create();
        //MessageBoxA(nullptr, name,"CCSprite_createHook -> no sprite", MB_ICONINFORMATION | MB_OK);
        return no;
    }
    return CCSprite_create(name);
}

CCSprite* CCSprite_createWithSpriteFrameName_H(const char* name) {
    if (std::string(name) == HideEveryFrameByName.c_str() || HideEveryFrame == true) {//blankSprite
        CCSprite* no = CCSprite::create();
        //MessageBoxA(nullptr, name, "CCSprite_createWithSpriteFrameNameHook -> no sprite", MB_ICONINFORMATION | MB_OK);
        return no;
    }
    if (ReplaceAllFramesByName::by != "" && ReplaceAllFramesByName::by == std::string(name)) name = ReplaceAllFramesByName::to.c_str();
    return CCSprite_createWithSpriteFrameName(name);
}

CCLabelBMFont* CCLabelBMFont_create_H(const char* str, const char* fntFile) {
    //settings
    if ("settings") {
        //config ini
        if (bool((std::string(str) == "IconsCount.ini")) && std::string(fntFile) == "bigFont.fnt") {
            ReplaceAllFramesByName::by = "GJ_infoIcon_001.png";
            ReplaceAllFramesByName::to = "geode.loader/pencil.png";
            str = "IconsCount.ini";
        }
        if (std::string(str) == "open up IconsCount.ini")
            ShellExecute(NULL, ("open"), (CCFileUtils::sharedFileUtils()->fullPathForFilename("geode/config/IconsCount.ini", 0).c_str()), NULL, NULL, 1);
        //open up cube value popup...
        if (bool((std::string(str) == "cube option 6525")) && std::string(fntFile) == "bigFont.fnt") {
            ReplaceAllFramesByName::by = "GJ_infoIcon_001.png";
            ReplaceAllFramesByName::to = "geode.loader/pencil.png";
            str = "cube";
        }
        if (std::string(str) == "open up cube value popup...")
            popuptoreplace = ValueSetupPopup::create("cube", "IconsCount", "geode/config/IconsCount.ini", "org count of cubes 142");
        //open up ship value popup...
        if (bool((std::string(str) == "ship option 6525")) && std::string(fntFile) == "bigFont.fnt") {
            ReplaceAllFramesByName::by = "GJ_infoIcon_001.png";
            ReplaceAllFramesByName::to = "geode.loader/pencil.png";
            str = "ship";
        }
        if (std::string(str) == "open up ship value popup...")
            popuptoreplace = ValueSetupPopup::create("ship", "IconsCount", "geode/config/IconsCount.ini", "org count of ships 51");
        //open up ball value popup...
        if (bool((std::string(str) == "ball option 6525")) && std::string(fntFile) == "bigFont.fnt") {
            ReplaceAllFramesByName::by = "GJ_infoIcon_001.png";
            ReplaceAllFramesByName::to = "geode.loader/pencil.png";
            str = "ball";
        }
        if (std::string(str) == "open up ball value popup...")
            popuptoreplace = ValueSetupPopup::create("ball", "IconsCount", "geode/config/IconsCount.ini", "org count of BALLS 42");
        //open up cube value popup...
        if (bool((std::string(str) == "ufo option 6525")) && std::string(fntFile) == "bigFont.fnt") {
            ReplaceAllFramesByName::by = "GJ_infoIcon_001.png";
            ReplaceAllFramesByName::to = "geode.loader/pencil.png";
            str = "ufo";
        }
        if (std::string(str) == "open up ufo value popup...")
            popuptoreplace = ValueSetupPopup::create("ufo", "IconsCount", "geode/config/IconsCount.ini", "org count of ufos 35");
        //open wave cube value popup...
        if (bool((std::string(str) == "wave option 6525")) && std::string(fntFile) == "bigFont.fnt") {
            ReplaceAllFramesByName::by = "GJ_infoIcon_001.png";
            ReplaceAllFramesByName::to = "geode.loader/pencil.png";
            str = "wave";
        }
        if (std::string(str) == "open up wave value popup...")
            popuptoreplace = ValueSetupPopup::create("wave", "IconsCount", "geode/config/IconsCount.ini", "org count of waves 35");
        //open up robot value popup...
        if (bool((std::string(str) == "robot option 6525")) && std::string(fntFile) == "bigFont.fnt") {
            ReplaceAllFramesByName::by = "GJ_infoIcon_001.png";
            ReplaceAllFramesByName::to = "geode.loader/pencil.png";
            str = "robot";
        }
        if (std::string(str) == "open up robot value popup...")
            popuptoreplace = ValueSetupPopup::create("robot", "IconsCount", "geode/config/IconsCount.ini", "org count of robots 26");
        //open up spider value popup...
        if (bool((std::string(str) == "spider option 6525")) && std::string(fntFile) == "bigFont.fnt") {
            ReplaceAllFramesByName::by = "GJ_infoIcon_001.png";
            ReplaceAllFramesByName::to = "geode.loader/pencil.png";
            str = "spider";
        }
        if (std::string(str) == "open up spider value popup...")
            popuptoreplace = ValueSetupPopup::create("spider", "IconsCount", "geode/config/IconsCount.ini", "org count of spiders 17");
        //footer or hader
        if (
            bool(ReplaceAllFramesByName::to == "geode.loader/pencil.png" && ReplaceAllFramesByName::by == "GJ_infoIcon_001.png")
            &&
            std::string(str) == "                    "
            &&
            std::string(fntFile) == "bigFont.fnt"
            )
        {
            ReplaceAllFramesByName::by = "";
            ReplaceAllFramesByName::to == "";
        }
    }
    if (HideEveryLabel) {
        CCLabelBMFont* lbl = CCLabelBMFont::create("", "gjFont01.fnt");
        lbl->setVisible(false);
        lbl->setAnchorPoint({ -999.0f,-999.0f });
        //MessageBoxA(nullptr, str, "CCLabelBMFont_createHook -> no lbl", MB_ICONINFORMATION | MB_OK);
        return lbl;
    }
    return CCLabelBMFont_create(str, fntFile);
}