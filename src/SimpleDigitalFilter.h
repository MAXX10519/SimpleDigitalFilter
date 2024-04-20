#include <Arduino.h>

#ifndef SIMPLEDIGITALFILTER_H
#define SIMPLEDIGITALFILTER_H

class SimpleDigitalFilter
{
private:
  uint32_t delayTime = 0;   // (ms)
  boolean inState = 0;
  boolean outState = 0;
  uint32_t oldTime = 0;
public:
  SimpleDigitalFilter();   // Default delayTime = 10ms
  SimpleDigitalFilter(uint32_t); 
  ~SimpleDigitalFilter();
  boolean updateState(boolean);
  uint32_t setDelayTime(uint32_t);
  uint32_t getDelayTime();
  boolean getInState();
  boolean getOutState();
};
/**
 * Default delayTime = 10ms
*/
SimpleDigitalFilter::SimpleDigitalFilter() 
{
  this->delayTime = 10;
  this->oldTime = millis();
}

SimpleDigitalFilter::SimpleDigitalFilter(uint32_t delayTime) // (ms)
{
  this->delayTime = delayTime;
  this->oldTime = millis();
}

SimpleDigitalFilter::~SimpleDigitalFilter()
{
}

boolean SimpleDigitalFilter::updateState(boolean inState){
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

boolean SimpleDigitalFilter::getInState(){
  return inState;
}

boolean SimpleDigitalFilter::getOutState(){
  return outState;
}

uint32_t SimpleDigitalFilter::getDelayTime(){
  return delayTime;
}

uint32_t SimpleDigitalFilter::setDelayTime(uint32_t delayTime){
  this->delayTime = delayTime;
  return this->delayTime;
}

#endif