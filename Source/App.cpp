#include "App.h"
#include "Relations.h"
#include <iostream>
#include <algorithm>
#include <cmath>

int App::count = 0;

App::App()
    : pointStorage_(), segmentStorage_(), circleStorage_(), relationStorage_() {
}

App::~App() {
  for (size_t i = 0; i < relationStorage_.getSize(); ++i) {
    delete relationStorage_.getItem(i);
  }
}

Identi App::addObject(PrimitiveType type) {
  Identi newId(++count);

  switch (type) {
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

Identi App::addArrange(MutualArrangeType type, const Storage<Identi> &ii) {
  return addArrange(type, ii, 0.0);
}

Identi App::addArrange(MutualArrangeType type, const Storage<Identi> &ii,
                       double value) {
  Identi relationId(++count);
  Relation *relation = nullptr;

  switch (type) {
  case MutualArrangeType::POINTCOINCIDENT:
    relation = new PointCoincidentRelation(relationId, ii, value);
    break;
  case MutualArrangeType::POINTDISTANCE:
    relation = new PointDistanceRelation(relationId, ii, value);
    break;
  case MutualArrangeType::POINTBELONGSTOSEGMENT:
    relation = new PointBelongsToSegmentRelation(relationId, ii, value);
    break;
  case MutualArrangeType::POINTSSYMMETRYSEGMENT:
    relation = new PointsSymmetrySegmentRelation(relationId, ii, value);
    break;
  case MutualArrangeType::SEGMENTLENGTH:
    relation = new SegmentLengthRelation(relationId, ii, value);
    break;
  case MutualArrangeType::SEGMENTVERTICAL:
    relation = new SegmentVerticalRelation(relationId, ii, value);
    break;
  case MutualArrangeType::SEGMENTSNORMAL:
    relation = new SegmentsNormalRelation(relationId, ii, value);
    break;
  }

    if (relation != nullptr) {
        relation->setApp(this);
        relationStorage_.addItem(relation);
    }

  std::cout << "Created relation of type " << static_cast<int>(type) + 1
            << " with ID: " << relationId.getID() << " for " << ii.getSize()
            << " objects" << " with parameter: " << value << "\n";

  return relationId;
}

Rectangle<double> App::unionRect() const {
  double minX = 0, minY = 0, maxX = 0, maxY = 0;
  bool first = true;

  for (size_t i = 0; i < pointStorage_.getSize(); ++i) {
    Rectangle<double> r = pointStorage_.getItem(i).getBoundingRect();
    if (first) {
      minX = r.topLeft().x();
      maxY = r.topLeft().y();
      maxX = r.bottomRight().x();
      minY = r.bottomRight().y();
      first = false;
    } else {
      minX = std::min<double>(minX, r.topLeft().x());
      maxY = std::max<double>(maxY, r.topLeft().y());
      maxX = std::max<double>(maxX, r.bottomRight().x());
      minY = std::min<double>(minY, r.bottomRight().y());
    }
  }
  for (size_t i = 0; i < segmentStorage_.getSize(); ++i) {
    Rectangle<double> r = segmentStorage_.getItem(i).getBoundingRect();
    if (first) {
      minX = r.topLeft().x();
      maxY = r.topLeft().y();
      maxX = r.bottomRight().x();
      minY = r.bottomRight().y();
      first = false;
    } else {
      minX = std::min<double>(minX, r.topLeft().x());
      maxY = std::max<double>(maxY, r.topLeft().y());
      maxX = std::max<double>(maxX, r.bottomRight().x());
      minY = std::min<double>(minY, r.bottomRight().y());
    }
  }
  for (size_t i = 0; i < circleStorage_.getSize(); ++i) {
    Rectangle<double> r = circleStorage_.getItem(i).getBoundingRect();
    if (first) {
      minX = r.topLeft().x();
      maxY = r.topLeft().y();
      maxX = r.bottomRight().x();
      minY = r.bottomRight().y();
      first = false;
    } else {
      minX = std::min<double>(minX, r.topLeft().x());
      maxY = std::max<double>(maxY, r.topLeft().y());
      maxX = std::max<double>(maxX, r.bottomRight().x());
      minY = std::min<double>(minY, r.bottomRight().y());
    }
  }

  return Rectangle<double>(point_coor<double>(minX, maxY),
                           point_coor<double>(maxX, minY));
}

double App::sumErrors() {
    double total = 0.0;
    for (size_t i = 0; i < relationStorage_.getSize(); ++i) {
        Relation* relation = relationStorage_.getItem(i);
        if (relation != nullptr) {
            total += relation->error();
        }
    }
    return total;
}
bool App::solve() {
  // Пока работаем только с одним требованием
  if (relationStorage_.getSize() == 1) {

    // Посчитаем текущее значение ошибки
    double current_error = relationStorage_.getItem(0)->error();

    const double errorThrreshold = 1e-3;

    while (current_error > errorThrreshold) {
      // Получим массив значений параметров
      Storage<double> parameters = relationStorage_.getItem(0)->getParameters();

      // Вычислим вектор частных производных для требования
      Storage<double> grad = relationStorage_.getItem(0)->partitions();

      // Сформируем новый вектор параметров
      static const double learning_rate = 0.1;
      Storage<double> newParameters;
      for (size_t i = 0; i < grad.getSize(); ++i) {
        newParameters.addItem(parameters.getItem(i) -
                              learning_rate * grad.getItem(i));
      }

      // Обновим параметры
      relationStorage_.getItem(0)->setParameters(newParameters);

      // Посчитаем новое значение ошибки
      current_error = relationStorage_.getItem(0)->error();
      std::cout << "Error " << current_error << std::endl;
    }
  }

  return true;
}
