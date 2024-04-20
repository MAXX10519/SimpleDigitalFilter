#include <Arduino.h>

#ifndef SIMPLEFILTERDIGITAL_H
#define SIMPLEFILTERDIGITAL_H

class SimpleFilterDigital
{
private:
  uint32_t delayTime = 0;   // (ms)
  boolean inState = 0;
  boolean outState = 0;
  uint32_t oldTime = 0;
public:
  SimpleFilterDigital();   // Default delayTime = 10ms
  SimpleFilterDigital(uint32_t); 
  ~SimpleFilterDigital();
  boolean updateState(boolean);
  uint32_t setDelayTime(uint32_t);
  uint32_t getDelayTime();
  boolean getInState();
  boolean getOutState();
};
/**
 * Default delayTime = 10ms
*/
SimpleFilterDigital::SimpleFilterDigital() 
{
  this->delayTime = 10;
  this->oldTime = millis();
}

SimpleFilterDigital::SimpleFilterDigital(uint32_t delayTime) // (ms)
{
  this->delayTime = delayTime;
  this->oldTime = millis();
}

SimpleFilterDigital::~SimpleFilterDigital()
{
}

boolean SimpleFilterDigital::updateState(boolean inState){
  uint32_t nowTime = millis();
  if (inState != this->inState)
  {
    oldTime = nowTime;
    this->inState = inState;
    return outState;
  }
  if (inState != outState &&
    nowTime - oldTime >= delayTime)
  {
    outState = inState;
  }
  return outState;
}

boolean SimpleFilterDigital::getInState(){
  return inState;
}

boolean SimpleFilterDigital::getOutState(){
  return outState;
}

uint32_t SimpleFilterDigital::getDelayTime(){
  return delayTime;
}

uint32_t SimpleFilterDigital::setDelayTime(uint32_t delayTime){
  this->delayTime = delayTime;
  return this->delayTime;
}

#endif