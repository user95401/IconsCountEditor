#include "mod_utils.hpp"
#include "hooks.hpp"
using namespace cocos2d;
using namespace cocos2d::extension;
using namespace gd;
using namespace std;

#include "SimpleIni.h"

void updateIconsCount() {
    CSimpleIni ini;
    ini.LoadFile("geode/config/IconsCount.ini");
    uint8_t cube = stoi(ini.GetValue("IconsCount", "cube"));
    uint8_t ship = stoi(ini.GetValue("IconsCount", "ship"));
    uint8_t ball = stoi(ini.GetValue("IconsCount", "ball"));
    uint8_t ufo = stoi(ini.GetValue("IconsCount", "ufo"));
    uint8_t wave = stoi(ini.GetValue("IconsCount", "wave"));
    uint8_t robot = stoi(ini.GetValue("IconsCount", "robot"));
    uint8_t spider = stoi(ini.GetValue("IconsCount", "spider"));

    /// BY RUHAX | GUSCHIN

    // cube = 143 = 8f;                                                                             cube default = 142 = 8e;
    ModUtils::write_bytes(base + 0x1F7E48, { 0xB9, cube, 0x00, 0x00, 0x00 });
    ModUtils::write_bytes(base + 0x12B095, { 0xC7, 0x44, 0x24, 0x1C, cube, 0x00, 0x00, 0x00 });
    ModUtils::write_bytes(base + 0x12C766, { 0xC7, 0x44, 0x24, 0x14, cube, 0x00, 0x00, 0x00 });
    ModUtils::write_bytes(base + 0x12807A, { 0xB8, cube, 0x00, 0x00, 0x00 });
    ModUtils::write_bytes(base + 0x12BE64, { 0xB9, cube, 0x00, 0x00, 0x00 });
    ModUtils::write_bytes(base + 0x1E6DD9, { 0xBA, cube, 0x00, 0x00, 0x00 });
    ModUtils::write_bytes(base + 0x12C26C, { 0xBA, cube, 0x00, 0x00, 0x00 });
    
    // ship = 16 = 10;                                                                             ship default = 55 = 33;
    ModUtils::write_bytes(base + 0x1E6DEF, { 0xB8, ship });
    ModUtils::write_bytes(base + 0x1F7FF6, { 0xBa, ship });
    ModUtils::write_bytes(base + 0x12C6D1, { 0xc7, 0x44, 0x24, 0x14, ship });
    ModUtils::write_bytes(base + 0x12B0CA, { 0xc7, 0x44, 0x24, 0x1c, ship });

    // balls = 15 = 0F;                                                                             ship balls = 42 = 2a;
    ModUtils::write_bytes(base + 0x12C6EC, { 0xc7, 0x44, 0x24, 0x14, ball });
    ModUtils::write_bytes(base + 0x12B0FF, { 0xc7, 0x44, 0x24, 0x1c, ball });
    ModUtils::write_bytes(base + 0x1F83A6, { 0xba, ball });

    // ufo = 14 = 0E;                                                                             ufo default = 35 = 23; 
    ModUtils::write_bytes(base + 0x22DA45, { 0xB9, ufo });
    ModUtils::write_bytes(base + 0x24A18F, { 0xB8, ufo });
    ModUtils::write_bytes(base + 0x24B210, { 0xB8, ufo });
    ModUtils::write_bytes(base + 0x1F81A6, { 0xBA, ufo });
    ModUtils::write_bytes(base + 0x12B134, { 0xc7, 0x44, 0x24, 0x1c, ufo });
    ModUtils::write_bytes(base + 0x12C704, { 0xc7, 0x44, 0x24, 0x14, ufo });
    ModUtils::write_bytes(base + 0x25612A, { 0xc7, 0x84, 0x24, 0x28, 0x0a, 0x00, 0x00, ufo });

    // wave = 13 = 0D;                                                                             wave default = 35 = 23; 
    ModUtils::write_bytes(base + 0x128568, { 0xB8, wave });
    ModUtils::write_bytes(base + 0x142762, { 0xBB, wave });
    ModUtils::write_bytes(base + 0x1F8586, { 0xBA, wave });
    ModUtils::write_bytes(base + 0x12B169, { 0xC7, 0x44, 0x24, 0x1C, wave });
    ModUtils::write_bytes(base + 0x12C71C, { 0xC7, 0x44, 0x24, 0x14, wave });

    // robot = 12 = 0c;                                                                             robot default = 26 = 1a; 
    ModUtils::write_bytes(base + 0x12B19E, { 0xC7, 0x44, 0x24, 0x1C, robot });
    ModUtils::write_bytes(base + 0x12C734, { 0xC7, 0x44, 0x24, 0x14, robot });
    ModUtils::write_bytes(base + 0x255ADC, { 0xc7, 0x84, 0x24, 0x28, 0x0a, 0x00, 0x00, robot });
    //(crash - no access thing idk)
//ModUtils::write_bytes(base + 0x199436, { 0xC7, 0x84, 0x24, 0x08, 0x2E, 0x44, 0x00, robot});
    //ModUtils::write_bytes(base + 0x199436, { 0xC7, 0x84, 0x24, 0x08, 0x2E, 0x44, 0x00, robot });
    ModUtils::write_bytes(base + 0x1F855A, { 0xba, robot });
    ModUtils::write_bytes(base + 0x20CCD5, { 0xb9, robot });
    ModUtils::write_bytes(base + 0x14673D, { 0xb8, robot });
    ModUtils::write_bytes(base + 0x1F6ACD, { 0xb8, robot });
    ModUtils::write_bytes(base + 0x20900F, { 0xb9, robot });
    ModUtils::write_bytes(base + 0x20CCC3, { 0x6a, robot });
    //GeometryDash.exe+125F61  - ВИДИМОСТЬ В ГАРАЖЕ 1
    ModUtils::write_bytes(base + 0x125F61, { 0xb9, robot });
    //GeometryDash.exe+12880E   - ВИДИМОСТЬ В ГАРАЖЕ 2
    ModUtils::write_bytes(base + 0x12880E, { 0xb9, robot });


    // spider = 16 = 10;                                                                             spider default = 17 = 11; 
    ModUtils::write_bytes(base + 0x12B1D3, { 0xC7, 0x44, 0x24, 0x1C, spider });
    ModUtils::write_bytes(base + 0x12C74C, { 0xC7, 0x44, 0x24, 0x14, spider });
    ModUtils::write_bytes(base + 0x146745, { 0xba, spider });
    ModUtils::write_bytes(base + 0x1553A2, { 0xC7, 0x84, 0x24, 0xC0, spider });
    //GeometryDash.exe+1289CE  - видимость спайдера 1
    ModUtils::write_bytes(base + 0x1289CE, { 0xb9, spider });
    //GeometryDash.exe+126021  - видимость спайдера 2
    ModUtils::write_bytes(base + 0x126021, { 0xb9, spider });

    //find + replace moment
}

void calcIconsCount() {
    CSimpleIni ini;
    ini.LoadFile("geode/config/IconsCount.ini");
    std::stringstream num;

    int cube = 0;
    for (int i = 1; i < 500; ++i) {
        num << std::setw(2) << std::setfill('0') << i;
        if (CCSprite::createWithSpriteFrameName(("player_" + num.str() + "_001.png").c_str()))
        {
            ++cube;
            //ModUtils::log(("created player_" + num.str() + "_001.png, count is " + to_string(player)));
        }
        num.str("");
    }
    ini.SetValue("IconsCount", "cube", to_string(cube).c_str());

    int ship = 0;
    for (int i = 1; i < 500; ++i) {
        num << std::setw(2) << std::setfill('0') << i;
        if (CCSprite::createWithSpriteFrameName(("ship_" + num.str() + "_001.png").c_str()))
        {
            ++ship;
            //ModUtils::log(("created ship_" + num.str() + "_001.png, now count is " + to_string(ship)));
        }
        num.str("");
    }
    ini.SetValue("IconsCount", "ship", to_string(ship).c_str());

    int ball = 0;
    for (int i = 1; i < 500; ++i) {
        num << std::setw(2) << std::setfill('0') << i;
        if (CCSprite::createWithSpriteFrameName(("player_ball_" + num.str() + "_001.png").c_str()))
        {
            ++ball;
            //ModUtils::log(("created player_ball_" + num.str() + "_001.png, now count is " + to_string(ship)));
        }
        num.str("");
    }
    ini.SetValue("IconsCount", "ball", to_string(ball).c_str());

    int ufo = 0;
    for (int i = 1; i < 500; ++i) {
        num << std::setw(2) << std::setfill('0') << i;
        if (CCSprite::createWithSpriteFrameName(("bird_" + num.str() + "_001.png").c_str()))
        {
            ++ufo;
            //ModUtils::log(("created bird_" + num.str() + "_001.png, now count is " + to_string(ship)));
        }
        num.str("");
    }
    ini.SetValue("IconsCount", "ufo", to_string(ufo).c_str());

    int wave = 0;
    for (int i = 1; i < 500; ++i) {
        num << std::setw(2) << std::setfill('0') << i;
        if (CCSprite::createWithSpriteFrameName(("dart_" + num.str() + "_001.png").c_str()))
        {
            ++wave;
            //ModUtils::log(("created dart_" + num.str() + "_001.png, now count is " + to_string(ship)));
        }
        num.str("");
    }
    ini.SetValue("IconsCount", "wave", to_string(wave).c_str());

    int robot = 0;
    for (int i = 1; i < 500; ++i) {
        num << std::setw(2) << std::setfill('0') << i;
        if (CCSprite::createWithSpriteFrameName(("robot_" + num.str() + "_01_001.png").c_str()))
        {
            ++robot;
            //ModUtils::log(("created robot_" + num.str() + "_001.png, now count is " + to_string(ship)));
        }
        num.str("");
    }
    ini.SetValue("IconsCount", "robot", to_string(robot).c_str());

    int spider = 0;
    for (int i = 1; i < 500; ++i) {
        num << std::setw(2) << std::setfill('0') << i;
        if (CCSprite::createWithSpriteFrameName(("spider_" + num.str() + "_01_001.png").c_str()))
        {
            ++spider;
            //ModUtils::log(("created spider_" + num.str() + "_001.png, now count is " + to_string(ship)));
        }
        num.str("");
    }
    ini.SetValue("IconsCount", "spider", to_string(spider).c_str());

    ini.SaveFile("geode/config/IconsCount.ini");
}

#include "cocosHooks.hpp" //ну и псих бляtь

inline void(__thiscall* update)(GameManager* self, float);//0xce440
void __fastcall update_H(GameManager* self, void*, float dt) {
    update(self, dt);
    updateIconsCount();
}

void(__thiscall* LoadingLayer_loadingFinished)(LoadingLayer*);//0x18C790
void __fastcall LoadingLayer_loadingFinished_H(LoadingLayer* self, void*) {
    CSimpleIni ini;
    ini.LoadFile("geode/config/IconsCount.ini");
    if(!ModUtils::ttlihe(self) && ini.GetBoolValue("IconsCount", "Auto calculation")) calcIconsCount();
    LoadingLayer_loadingFinished(self);
}

inline void(__thiscall* FLAlertLayer_show)(FLAlertLayer* self);//0x23560
void __fastcall FLAlertLayer_show_H(FLAlertLayer* self, void*) {
    if (popuptoreplace) self = popuptoreplace;
    FLAlertLayer_show(self);
    popuptoreplace = nullptr;
}

DWORD WINAPI IconsCountEditor(void* hModule) {
    filesystem::create_directories("geode/config");
    CSimpleIni ini;
    ini.LoadFile("geode/config/IconsCount.ini");
    if (!(ini.KeyExists("IconsCount", "cube")))
        ini.SetValue("IconsCount", "cube", "142", ";------------------------\n; DISCOVERED BY GUSCHIN\n; https://github.com/zGuschin/IconPatch\n;------------------------\n\n; org count of cubes 142");
    if (!(ini.KeyExists("IconsCount", "ship")))
        ini.SetValue("IconsCount", "ship", "51", "; org count of ships 51");
    if (!(ini.KeyExists("IconsCount", "ball")))
        ini.SetValue("IconsCount", "ball", "42", "; org count of BALLS 42");
    if (!(ini.KeyExists("IconsCount", "ufo")))
        ini.SetValue("IconsCount", "ufo", "35", "; org count of ufos 35");
    if (!(ini.KeyExists("IconsCount", "wave")))
        ini.SetValue("IconsCount", "wave", "35", "; org count of waves 35");
    if (!(ini.KeyExists("IconsCount", "robot")))
        ini.SetValue("IconsCount", "robot", "26", "; org count of robots 26");
    if (!(ini.KeyExists("IconsCount", "spider")))
        ini.SetValue("IconsCount", "spider", "17", "; org count of spiders 17");
    if (!(ini.KeyExists("IconsCount", "Auto calculation")))
        ini.SetBoolValue("IconsCount", "Auto calculation", false, "; Auto calculation icons count by loaded textures");
    ini.SaveFile("geode/config/IconsCount.ini");
    MH_SafeInitialize();
    HOOK(base + 0xce440, update);
    HOOK(base + 0x23560, FLAlertLayer_show);
    HOOK(base + 0x18C790, LoadingLayer_loadingFinished);
    CreateCocosHooks();
    //CCMessageBox("created hooks", __func__);
    updateIconsCount();
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
        CreateThread(0, 0, IconsCountEditor, hModule, 0, 0);
    return TRUE;
}
