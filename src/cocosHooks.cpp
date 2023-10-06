#include "cocosHooks.hpp"
#include "SimpleIni.h"

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
        if (
            bool((std::string(str) == "IconsCount.ini"))
            &&
            std::string(fntFile) == "bigFont.fnt"
            ) {
            ReplaceAllFramesByName::by = "GJ_infoIcon_001.png";
            ReplaceAllFramesByName::to = "geode.loader/pencil.png";
        }
        if (std::string(str) == "open up IconsCount.ini")
            ShellExecute(NULL, ("open"), (CCFileUtils::sharedFileUtils()->fullPathForFilename("geode/config/IconsCount.ini", 0).c_str()), NULL, NULL, 1);
        //footer
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