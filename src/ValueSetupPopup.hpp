#pragma once
#include "mod_utils.hpp"
#include "hooks.hpp"
#include "SimpleIni.h"
using namespace cocos2d;
using namespace cocos2d::extension;
using namespace gd;
using namespace std;

class ValueSetupPopup : public FLAlertLayer {
public:
    CCTextInputNode* mainInput;
    FLAlertLayer* helper;
    CCTextInputNode* input;
    const char* m_key;
    const char* m_section;
    const char* m_file;
    const char* m_comment;

    static ValueSetupPopup* create(const char* value, const char* section, const char* file, const char* comment);
    bool init(const char* value, const char* section, const char* file, const char* comment);
    virtual void keyBackClicked();
    virtual void update(float dt);

    void onClose(CCObject* callback);
};