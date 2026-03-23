#include <iostream>
#include <ctime>
#include "Source/App.h"
#include "Source/Bitmap.h"
#include "Source/shapes.h"
#include "Source/Storage.h"

int main() {
    
     App app;
     Identi i1 = app.addObject(POINT);
     Identi i2 = app.addObject(POINT);

     app.addArange(POINTCOINCIDENT,i1, i2);

     Identi i3 = app.addObject(SEGMENT);
     Identi i4 = app.addObject(SEGMENT);

     app.addArange(SEGMENTSNORMAL,i3,i4);

     Identi i5 = app.addObject(POINT);

     app.addArange(POINTOBELONGSEGMENT,i5,i3);
     app.addArange(POINTOBELONGSEGMENT,i3,i5);

     app.addArange(SEGMENTLENGTH,i3 , 10.1 );
     

    return 0;
}
