#ifndef Speaker_h
#define Speaker_h

class Speaker
{
  public:
    Speaker(int pin);
    void begin();
    void play();
    void stop();
  
  private:
    int _pin;
};

#endif
