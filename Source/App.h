#pragma once 
#include "Storage.h"
#include "Identi.h"
#include "Shapes.h"

enum class PrimitiveType{ POINT, SEGMENT, CIRCLE };

enum class MutualArrangeType {
	POINTCOINCIDENT, // Две точки совпадают
	POINTDISTANCE, // Две точки на заданном расстоянии
	POINTSSYMMETRYSEGMENT,  // Две точки симметричны относительно отрезка      
	POINTBELONGSTOSEGMENT,
	SEGMENTSNORMAL, // Два отрезка ортогональны
	SEGMENTVERTICAL,
	SEGMENTLENGTH
};

class App{
    static int count;
    Storage<Point<double>>   pointStorage_;
    Storage<Segment<double>> segmentStorage_;
    Storage<Circle<double>>  circleStorage_;
    
public:
    App(); 
    
    Identi addObject(PrimitiveType type);
    Identi addArrange(MutualArrangeType type, const Storage<Identi>& ii);
    Identi addArrange(MutualArrangeType type, const Storage<Identi>& ii, double value);
    double measure(MutualArrangeType type, const Storage<Identi>& ii);
    
    const Storage<Point<double>>& getPoints() const { return pointStorage_; }
    const Storage<Segment<double>>& getSegments() const { return segmentStorage_; }
    const Storage<Circle<double>>& getCircles() const { return circleStorage_; }
    
    template<typename T> 
    T* findObjectById(const Identi& id, Storage<T>& storage) {
        for(size_t i = 0; i < storage.getSize(); ++i) {
            if(storage.getItem(i).getId() == id) {
                return &storage.getItem(i);
            }
        }
        return nullptr;
    }
};