//
//  ScheduleScene.h
//  Schedule
//
//  Created by MAEDAHAJIME on 2015/03/03.
//
//

#ifndef __Schedule__ScheduleScene__
#define __Schedule__ScheduleScene__

#include "cocos2d.h"

// 名前空間 #define USING_NS_CC using namespace cocos2d
USING_NS_CC;

class ScheduleScene : public cocos2d::Layer
{
protected:
    ScheduleScene();
    virtual ~ScheduleScene();
    //初期化のメソッド
    bool init() override;
    
public:
    static cocos2d::Scene* createScene();
    
    // create()を使えるようにしている。
    CREATE_FUNC(ScheduleScene);
    
    // １番目画像
    Sprite* Sprite01;
    // ２番目画像
    Sprite* Sprite02;
    // ３番目画像
    Sprite* Sprite03;
    
    
    // １番目画像Runアクション
    void Action01(float frame); // float型のパラメータが必要です。
    // ２番目画像Runアクション
    void Action02(float frame); // float型のパラメータが必要です。
    // ３番目画像Runアクション
    void Action03(float frame); // float型のパラメータが必要です。
    
};

#endif /* defined(__Schedule__ScheduleScene__) */
