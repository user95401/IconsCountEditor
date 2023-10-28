#include "ValueSetupPopup.hpp"
ValueSetupPopup* ValueSetupPopup::create(const char* key, const char* section, const char* file, const char* comment) {
    ValueSetupPopup* ret = new ValueSetupPopup();
    if (ret && ret->init(key, section, file, comment)) ret->autorelease();
    else CC_SAFE_DELETE(ret);
    return ret;
}
void ValueSetupPopup::update(float dt) {
    if(m_pLayer->getScale() < 0.01) this->removeFromParentAndCleanup(true);
}
void ValueSetupPopup::onClose(CCObject* callback) {
    if (string(input->getString()) == "" || m_pLayer->getScale() != 1.000f) return;
    CSimpleIni ini;//make CSimpleIni
    ini.LoadFile(m_file);//load to mem
    ini.SetValue(m_section, m_key, input->getString());//set valie of input
    ini.SaveFile(m_file);//save to file from mem
    m_pLayer->runAction(CCEaseBackIn::create(CCScaleTo::create(0.3, 0.f)));
    input->setString("Saved!");
}
void ValueSetupPopup::keyBackClicked() {
    onClose(NULL);
}
bool ValueSetupPopup::init(const char* key, const char* section, const char* file, const char* comment) {
    m_key = key;
    m_section = section;
    m_file = file;
    m_comment = comment;
    //ini
    CSimpleIni ini;
    ini.LoadFile(m_file);
    //layer
    if (CCLayerColor::initWithColor(ccc4(0, 0, 0, 150))) {
        registerWithTouchDispatcher();
        setTouchEnabled(true);
        setKeypadEnabled(true);
        schedule(schedule_selector(ValueSetupPopup::update), 0);

        m_pLayer = CCLayer::create();
        addChild(m_pLayer);
        m_pButtonMenu = CCMenu::create();
        m_pLayer->addChild(m_pButtonMenu);

        //square bg
        auto scale9 = extension::CCScale9Sprite::create("square01_001.png");
        scale9->setContentSize({ 360, 160 });
        m_pButtonMenu->addChild(scale9, -2);

        //title
        CCLabelBMFont* title = CCLabelBMFont::create(("" + string(m_key) + " key setup").c_str(), "goldFont.fnt", 900, CCTextAlignment::kCCTextAlignmentCenter);
        title->setPositionY(58.f);
        title->setScale((scale9->getContentSize().width - 160) / title->getContentSize().width);
        m_pButtonMenu->addChild(title);

        //keyInf
        CCLabelBMFont* keyInf = CCLabelBMFont::create(
            ("key: " + string(m_key) + ", section: " + m_section + 
                ", \nfile: " + m_file + "\n" + 
                comment
                ).c_str(), "chatFont.fnt", 900, CCTextAlignment::kCCTextAlignmentCenter);
        keyInf->setPositionY(40.f);
        keyInf->setAnchorPoint({0.5f, 1.f});
        keyInf->setScale(0.5f);
        keyInf->setOpacity(90);
        m_pButtonMenu->addChild(keyInf);
        
        //input
        input = CCTextInputNode::create("You cant leave empty value!", this, "chatFont.fnt", 280.f, 20.f);
        input->setPositionY(-10.f);
        input->setLabelPlaceholderColor(ccRED);
        input->setString(ini.GetValue(m_section, m_key));
        m_pButtonMenu->addChild(input);

        //inputbg
        CCScale9Sprite* inputbg = CCScale9Sprite::create("square02_001.png");
        inputbg->setContentSize({ input->getContentSize().width * 2 + 20, input->getContentSize().height * 2 + 15 });
        inputbg->setScale(0.5f);
        inputbg->setOpacity(60);
        inputbg->setPosition(input->getPosition());
        m_pButtonMenu->addChild(inputbg, -1);

        //okBtn
        auto okBtn = CCMenuItemSpriteExtra::create(ButtonSprite::create("OK", 160.f, true, "goldFont.fnt", "GJ_button_01.png", 0, 1.0),
            this, menu_selector(ValueSetupPopup::onClose));
        m_pButtonMenu->addChild(okBtn);
        okBtn->setScale(0.8f);
        okBtn->setPositionY(-50.0f);

        return true;
    }
    else return false;
}