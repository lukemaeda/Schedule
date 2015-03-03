//
//  ScheduleScene.cpp
//  Schedule
//
//  Created by MAEDAHAJIME on 2015/03/03.
//
//

#include "ScheduleScene.h"
// 名前空間 #define USING_NS_CC using namespace cocos2d
USING_NS_CC;

using namespace std; // String*

ScheduleScene::ScheduleScene()
{
    
}

ScheduleScene::~ScheduleScene()
{
    
}

Scene* ScheduleScene::createScene()
{
    // 「シーン」は自動解放オブジェクトです
    auto scene = Scene::create();
    
    // 「レイアウト」は自動解放オブジェクトです
    auto layer = ScheduleScene::create();
    
    // シーンに子としてレイヤーを追加
    scene->addChild(layer);
    
    // シーンを返す
    return scene;
}

// 「INIT」初期化
bool ScheduleScene::init()
{
    if ( !Layer::init() )
    {
        
        return false;
    }
    
    //_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
    
    Size winSize = Director::getInstance()->getVisibleSize();
    
    // バックグランドカラー（ブルー）
    auto background = LayerColor::create(Color4B::BLUE,
                                         winSize.width,
                                         winSize.height);
    this->addChild(background);
    
    //_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
    // １番目スプライトの作成
    Sprite01 = Sprite::create("img001.png");
    //画面の中央に表示
    Sprite01->setPosition(Vec2(winSize.width/2, winSize.height/1.5));
    this->addChild(Sprite01);
    
    // ２番目スプライトの作成
    Sprite02 = Sprite::create("img002.png");
    //画面の左に表示
    Sprite02->setPosition(Vec2(winSize.width/5, winSize.height/4));
    this->addChild(Sprite02);
    
    // ３番目スプライトの作成
    Sprite03 = Sprite::create("img003.png");
    //画面の右に表示
    Sprite03->setPosition(Vec2(winSize.width/1.25, winSize.height/4));
    this->addChild(Sprite03);
    
    //_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
        
    // １番目画像１回実行Runアクションスケジュール 2秒後
    this->scheduleOnce(schedule_selector(ScheduleScene::Action01), 2.0f);
    // ２番目画像１回実行Runアクションスケジュール 4秒後
    this->scheduleOnce(schedule_selector(ScheduleScene::Action02), 4.0f);
    // ３番目画像１回実行Runアクションスケジュール 7秒後
    this->scheduleOnce(schedule_selector(ScheduleScene::Action03), 7.0f);
    
    return true;
}

// １番目画像Runアクション
void ScheduleScene::Action01(float frame)
{
    
    // 大きさ（縮小）アクションを適用 1.0秒 0倍
    auto scaleTo1 = ScaleTo::create(1.0f, 0.0f);
    
    //callbackでの消去処理
    auto removeSprite1 = CallFunc::create([this](){
        this->removeChild(Sprite01);
    });
    
    // 縮小、消去アクションを適用
    auto sequence1 = Sequence::create(scaleTo1, removeSprite1, NULL);
    
    // 縮小、消去runアクションを適用
    Sprite01->runAction(sequence1);
    
    
}

// ２番目画像Runアクション
void ScheduleScene::Action02(float frame)
{
    // 大きさ（縮小）アクションを適用 2.5秒 0倍
    auto scaleTo2 = ScaleTo::create(2.5f, 0.0f);
    
    //callbackでの画像消去処理
    auto removeSprite2 = CallFunc::create([this](){
        this->removeChild(Sprite02);
    });
    // 縮小、消去アクションを適用
    auto sequence2 = Sequence::create(scaleTo2, removeSprite2, NULL);
    
    // 縮小、消去runアクションを適用
    Sprite02->runAction(sequence2);
    
}

// ３番目画像Runアクション
void ScheduleScene::Action03(float frame)
{
    // 大きさ（縮小）アクションを適用 2.5秒 0倍
    auto scaleTo3 = ScaleTo::create(2.5f, 0.0f);
    
    //callbackでの画像消去処理
    auto removeSprite3 = CallFunc::create([this](){
        this->removeChild(Sprite03);
    });
    
    // 縮小、消去アクションを適用
    auto sequence3 = Sequence::create(scaleTo3, removeSprite3, NULL);
    
    // 縮小、消去runアクションを適用
    Sprite03->runAction(sequence3);
}

