#include "mod_utils.hpp"
#include "hooks.hpp"
using namespace cocos2d;
using namespace gd;
using namespace cocos2d::extension;
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
    ModUtils::write_bytes((base + 0x1F7E48), { 0xB9, cube, 0x00, 0x00, 0x00});//5, NULL);
    ModUtils::write_bytes((base + 0x12B095), { 0xc7, 0x44, 0x24, 0x1c, cube, 0x00, 0x00, 0x00});//8, NULL);
    ModUtils::write_bytes((base + 0x12C766), { 0xc7, 0x44, 0x24, 0x14, cube, 0x00, 0x00, 0x00});//8, NULL);
    ModUtils::write_bytes((base + 0x12807A), { 0xb8, cube, 0x00, 0x00, 0x00});//5, NULL);
    ModUtils::write_bytes((base + 0x12BE64), { 0xb9, cube, 0x00, 0x00, 0x00});//5, NULL);
    ModUtils::write_bytes((base + 0x1E6DD9), { 0xba, cube, 0x00, 0x00, 0x00});//5, NULL);
    ModUtils::write_bytes((base + 0x12C26C), { 0xba, cube, 0x00, 0x00, 0x00});//5, NULL);

    // ship = 16 = 10;                                                                             ship default = 55 = 33;
    ModUtils::write_bytes((base + 0x1E6DEF), { 0xB8, ship, 0x00, 0x00, 0x00});//5, NULL);
    ModUtils::write_bytes((base + 0x1F7FF6), { 0xBa, ship, 0x00, 0x00, 0x00});//5, NULL);
    ModUtils::write_bytes((base + 0x12C6D1), { 0xc7, 0x44, 0x24, 0x14, ship, 0x00, 0x00, 0x00});//8, NULL);
    ModUtils::write_bytes((base + 0x12B0CA), { 0xc7, 0x44, 0x24, 0x1c, ship, 0x00, 0x00, 0x00});//8, NULL);

    // balls = 15 = 0F;                                                                             ship balls = 42 = 2a;
    ModUtils::write_bytes((base + 0x12C6EC), { 0xc7, 0x44, 0x24, 0x14, ball, 0x00, 0x00, 0x00});//8, NULL);
    ModUtils::write_bytes((base + 0x12B0FF), { 0xc7, 0x44, 0x24, 0x1c, ball, 0x00, 0x00, 0x00});//8, NULL);
    ModUtils::write_bytes((base + 0x1F83A6), { 0xba, ball, 0x00, 0x00, 0x00});//5, NULL);

    // ufo = 14 = 0E;                                                                             ufo default = 35 = 23; 
    ModUtils::write_bytes((base + 0x22DA45), { 0xB9, ufo, 0x00, 0x00, 0x00});//5, NULL);
    ModUtils::write_bytes((base + 0x24A18F), { 0xB8, ufo, 0x00, 0x00, 0x00});//5, NULL);
    ModUtils::write_bytes((base + 0x24B210), { 0xB8, ufo, 0x00, 0x00, 0x00});//5, NULL);
    ModUtils::write_bytes((base + 0x1F81A6), { 0xBA, ufo, 0x00, 0x00, 0x00});//5, NULL);
    ModUtils::write_bytes((base + 0x12B134), { 0xc7, 0x44, 0x24, 0x1c, ufo, 0x00, 0x00, 0x00});//8, NULL);
    ModUtils::write_bytes((base + 0x12C704), { 0xc7, 0x44, 0x24, 0x14, ufo, 0x00, 0x00, 0x00});//8, NULL);
    ModUtils::write_bytes((base + 0x25612A), { 0xc7, 0x84, 0x24, 0x28, 0x0a, 0x00, 0x00, ufo, 0x00, 0x00, 0x00});//11, NULL);

    // wave = 13 = 0D;                                                                             wave default = 35 = 23; 
    ModUtils::write_bytes((base + 0x128568), { 0xb8, wave, 0x00, 0x00, 0x00});//5, NULL);
    ModUtils::write_bytes((base + 0x142762), { 0xbb, wave, 0x00, 0x00, 0x00});//5, NULL);
    ModUtils::write_bytes((base + 0x1F8586), { 0xba, wave, 0x00, 0x00, 0x00});//5, NULL);
    ModUtils::write_bytes((base + 0x12B169), { 0xc7, 0x44, 0x24, 0x1c, wave, 0x00, 0x00, 0x00});//8, NULL);
    ModUtils::write_bytes((base + 0x12C71C), { 0xc7, 0x44, 0x24, 0x1c, wave, 0x00, 0x00, 0x00});//8, NULL);

    // robot = 12 = 0c;                                                                             robot default = 26 = 1a; 
    ModUtils::write_bytes((base + 0x12B19E), { 0xC7, 0x44, 0x24, 0x1C, robot, 0x00, 0x00, 0x00});//8, NULL);
    ModUtils::write_bytes((base + 0x12C734), { 0xC7, 0x44, 0x24, 0x14, robot, 0x00, 0x00, 0x00});//8, NULL);
    ModUtils::write_bytes((base + 0x255ADC), { 0xc7, 0x84, 0x24, 0x28, 0x0a, 0x00, 0x00, robot, 0x00, 0x00, 0x00});//11, NULL);
    //(crash - no access thing idk)ModUtils::write_bytes((base + 0x199436), { 0xC7, 0x84, 0x24, 0x08, 0x2E, 0x44, 0x00, robot, 0x00, 0x00, 0x00});//11, NULL);
    ModUtils::write_bytes((base + 0x1F855A), { 0xba, robot, 0x00, 0x00, 0x00});//5, NULL);
    ModUtils::write_bytes((base + 0x20CCD5), { 0xb9, robot, 0x00, 0x00, 0x00});//5, NULL);
    ModUtils::write_bytes((base + 0x14673D), { 0xb8, robot, 0x00, 0x00, 0x00});//5, NULL);
    ModUtils::write_bytes((base + 0x1F6ACD), { 0xb8, robot, 0x00, 0x00, 0x00});//5, NULL);
    ModUtils::write_bytes((base + 0x20900F), { 0xb9, robot, 0x00, 0x00, 0x00});//5, NULL);
    ModUtils::write_bytes((base + 0x20CCC3), { 0x6a, robot});//2, NULL);

    ModUtils::write_bytes((base + 0x125F61), { 0xb9, robot, 0x00, 0x00, 0x00});//5, NULL);
    ModUtils::write_bytes((base + 0x12880E), { 0xb9, robot, 0x00, 0x00, 0x00});//5, NULL);


    // spider = 16 = 10;                                                                             spider default = 17 = 11; 
    ModUtils::write_bytes((base + 0x12B1D3), { 0xC7, 0x44, 0x24, 0x1C, spider, 0x00, 0x00, 0x00});//8, NULL);
    ModUtils::write_bytes((base + 0x12C74C), { 0xC7, 0x44, 0x24, 0x14, spider, 0x00, 0x00, 0x00});//8, NULL});//
    ModUtils::write_bytes((base + 0x146745), { 0xba, spider, 0x00, 0x00, 0x00});//5, NULL);
    ModUtils::write_bytes((base + 0x1553A2), { 0xC7, 0x84, 0x24, 0xC0, spider, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00});//11, NULL);
    ModUtils::write_bytes((base + 0x1289CE), { 0xb9, spider, 0x00, 0x00, 0x00});//5, NULL);
    ModUtils::write_bytes((base + 0x126021), { 0xb9, spider});//2, NULL);

    //find + replace moment
}

inline void(__thiscall* update)(GameManager* self, float);//0xce440
void __fastcall update_H(GameManager* self, void*, float dt) {
    update(self, dt);
    updateIconsCount();
}

#include "cocosHooks.hpp" //ну и псих бляtь

DWORD WINAPI IconsCount(void* hModule) {
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
        ini.SetValue("IconsCount", "spider", "17", "; org count of robots 17");
    ini.SaveFile("geode/config/IconsCount.ini");
    MH_SafeInitialize();
    HOOK(base + 0xce440, update);
    CreateCocosHooks();
    MH_EnableHook(MH_ALL_HOOKS);
    //CCMessageBox("created hooks", __func__);
    updateIconsCount();
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
        CreateThread(0, 0, IconsCount, hModule, 0, 0);
    return TRUE;
}
