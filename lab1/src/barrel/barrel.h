#ifndef __barrel_h__
#define __barrel_h__

#include <iostream>
#include <stdlib.h>

class Barrel
{
  double volume;
  double conc;

public:
  Barrel( void ) : volume(100), conc(0) {}
  
  Barrel( double new_volume, double new_conc )
  {
    if (new_conc > 100)
      new_conc = 100;
    if (new_volume <= 0)
      new_volume = 1;

    volume = new_volume;
    conc = new_conc;
  }

  double get_conc( void )
  {
    return conc;
  }

  void pout_from( Barrel &barrel_to, double pout_vol )
  {
    if (pout_vol > volume)
      pout_vol = volume;

    barrel_to.conc = (conc * pout_vol + barrel_to.volume * barrel_to.conc) / (barrel_to.volume + pout_vol);
    barrel_to.volume += pout_vol;
    volume -= pout_vol;
  }
};


#endif /* __barrel_h__ */