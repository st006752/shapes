#include "App.h"
#include <iostream>
#include <cmath>

int App::count = 0;

App::App() : pointStorage_(), segmentStorage_(), circleStorage_(), relationStorage_() {}

Identi App::addObject(PrimitiveType type) {
    Identi newId(++count);
    
    switch(type) {
        case PrimitiveType::POINT: {
            Point<double> point;
            point.setId(newId);
            pointStorage_.addItem(point);
            break;
        }
        case PrimitiveType::SEGMENT: {
            Segment<double> segment;
            segment.setId(newId);
            segmentStorage_.addItem(segment);
            break;
        }
        case PrimitiveType::CIRCLE: {
            Circle<double> circle;
            circle.setId(newId);
            circleStorage_.addItem(circle);
            break;
        }
    }
    
    return newId;
}

Identi App::addArrange(MutualArrangeType type, const Storage<Identi>& ii) {
    Identi relationId(++count);
    std::cout << "Created relation of type " << static_cast<int>(type) + 1 << " with ID: " << relationId.getID() << " for " << ii.getSize() << " objects\n";
    
    return relationId;
}

Identi App::addArrange(MutualArrangeType type, const Storage<Identi>& ii, double value) {
    Identi relationId(++count);
    std::cout << "Created relation of type " << static_cast<int>(type) +1<< " with ID: " << relationId.getID() 
              << " for " << ii.getSize() << " objects" << " with parameter: " << value << "\n";
    
    return relationId;
}

double App::measure(MutualArrangeType type, const Storage<Identi>& ii) {
    return 0.0;
}