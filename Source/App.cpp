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
    switch(type) {
        case MutualArrangeType::POINTCOINCIDENT: {
            Identi id1 = ii.getItem(0);
            Identi id2 = ii.getItem(1);
            
            Point<double>* p1 = findObjectById(id1, pointStorage_);
            Point<double>* p2 = findObjectById(id2, pointStorage_);

            double dx = p1->x() - p2->x();
            double dy = p1->y() - p2->y();

            return std::sqrt(dx*dx + dy*dy);
        }

        case MutualArrangeType::POINTDISTANCE : {}
        case MutualArrangeType::POINTBELONGSTOSEGMENT : {}
        case MutualArrangeType::POINTSSYMMETRYSEGMENT : {}
        case MutualArrangeType::SEGMENTLENGTH : {}
        case MutualArrangeType::SEGMENTVERTICAL : {}
        case MutualArrangeType::SEGMENTSNORMAL : {}
    }
}
