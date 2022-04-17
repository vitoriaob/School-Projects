#include "minimal_fighter.h"

int MinimalFighter::hp(){
    return mHp;
}
int MinimalFighter::power(){
    return mPower;
}
FighterStatus MinimalFighter::status(){
    return mStatus;
}
void MinimalFighter::setHp(int _hp){
    mHp = _hp;
}
void MinimalFighter::hit(MinimalFighter *_enemy){
    mHp = mHp - _enemy->power();
     _enemy->setHp(_enemy->hp() - mPower);
     if(_enemy->hp() <= 0)
         _enemy->mStatus = Dead;
     if(mHp <= 0)
         mStatus = Dead;
    
}
void MinimalFighter::attack(MinimalFighter *_enemy){
    _enemy->setHp(_enemy->mHp - mPower);
    if(_enemy->mHp <= 0)
        _enemy->mStatus = Dead;
    mPower = 0;
}
void MinimalFighter::fight(MinimalFighter *_enemy){
   while(_enemy->mHp >= 0 || mHp >=0){
     mHp = mHp - _enemy->power();
     _enemy->setHp(_enemy->mHp - mPower);
     if(_enemy->mHp <= 0){
         _enemy->mStatus = Dead;
        break;
     }
     if(mHp <= 0){
         mStatus = Dead;
         break;
     }
   }
            
}
