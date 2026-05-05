#include <iostream>
#include "App.h"

void printMenu() {
    std::cout << "\n--- Menu ---\n";
    std::cout << "1. Create point\n";
    std::cout << "2. Create segment\n";
    std::cout << "3. Create circle\n";
    std::cout << "4. Set relation\n";
    std::cout << "5. Show all objects\n";
    std::cout << "6. Show sum of errors\n";
    std::cout << "7. Show bounding rectangle\n";
	std::cout << "8. Print to file\n";
	std::cout << "9. Solve the errors\n";
    std::cout << "0. Quit\n";
    std::cout << "> ";
}

void printMutualArrangeTypes() {
    std::cout << "\n--- Relation types ---\n";
    std::cout << "1. Point coincidence\n";
    std::cout << "2. Distance between points\n";
    std::cout << "3. Point symmetry relative to segment\n";
    std::cout << "4. Point belongs to segment\n";
    std::cout << "5. Segment orthogonality\n";
    std::cout << "6. Segment verticality\n";
    std::cout << "7. Segment length\n";
    std::cout << "> ";
}

int main() {
    App app;

	Identi p1 = app.addObject(PrimitiveType::POINT);
	Point<double>* pt1 = app.findObjectById(p1, app.getPoints());
	if (pt1) { pt1->set_x(0); pt1->set_y(0); }

	Identi p2 = app.addObject(PrimitiveType::POINT);
	Point<double>* pt2 = app.findObjectById(p2, app.getPoints());
	if (pt2) { pt2->set_x(100); pt2->set_y(0); }

	Identi p3 = app.addObject(PrimitiveType::POINT);
	Point<double>* pt3 = app.findObjectById(p3, app.getPoints());
	if (pt3) { pt3->set_x(100); pt3->set_y(100); }

	Identi p4 = app.addObject(PrimitiveType::POINT);
	Point<double>* pt4 = app.findObjectById(p4, app.getPoints());
	if (pt4) { pt4->set_x(0); pt4->set_y(100); }

	Identi s1 = app.addObject(PrimitiveType::SEGMENT);
	Segment<double>* seg1 = app.findObjectById(s1, app.getSegments());
	if (seg1) {
		seg1->set_p1(Point<double>(0, 0));
		seg1->set_p2(Point<double>(100, 100));
	}
	Identi c1 = app.addObject(PrimitiveType::CIRCLE);
	Circle<double>* circ1 = app.findObjectById(c1, app.getCircles());
	if (circ1) {
		circ1->set_center(Point<double>(50, 50));
		circ1->set_radius(25);
	}

	// Additional points
	Identi p5 = app.addObject(PrimitiveType::POINT);
	Point<double>* pt5 = app.findObjectById(p5, app.getPoints());
	if (pt5) { pt5->set_x(50); pt5->set_y(50); }

	Identi p6 = app.addObject(PrimitiveType::POINT);
	Point<double>* pt6 = app.findObjectById(p6, app.getPoints());
	if (pt6) { pt6->set_x(150); pt6->set_y(50); }

	Identi p7 = app.addObject(PrimitiveType::POINT);
	Point<double>* pt7 = app.findObjectById(p7, app.getPoints());
	if (pt7) { pt7->set_x(100); pt7->set_y(150); }

	Identi p8 = app.addObject(PrimitiveType::POINT);
	Point<double>* pt8 = app.findObjectById(p8, app.getPoints());
	if (pt8) { pt8->set_x(50); pt8->set_y(150); }

	// Additional segments
	Identi s2 = app.addObject(PrimitiveType::SEGMENT);
	Segment<double>* seg2 = app.findObjectById(s2, app.getSegments());
	if (seg2) {
		seg2->set_p1(Point<double>(100, 0));
		seg2->set_p2(Point<double>(100, 100));
	}

	Identi s3 = app.addObject(PrimitiveType::SEGMENT);
	Segment<double>* seg3 = app.findObjectById(s3, app.getSegments());
	if (seg3) {
		seg3->set_p1(Point<double>(0, 100));
		seg3->set_p2(Point<double>(150, 100));
	}

	// Additional circles
	Identi c2 = app.addObject(PrimitiveType::CIRCLE);
	Circle<double>* circ2 = app.findObjectById(c2, app.getCircles());
	if (circ2) {
		circ2->set_center(Point<double>(150, 75));
		circ2->set_radius(30);
	}

	Identi c3 = app.addObject(PrimitiveType::CIRCLE);
	Circle<double>* circ3 = app.findObjectById(c3, app.getCircles());
	if (circ3) {
		circ3->set_center(Point<double>(100, 150));
		circ3->set_radius(20);
	}


    int choice = 1;
    while (choice != 0) {
        printMenu();
        std::cin >> choice;

        switch(choice) {
            case 1: {
                double x, y;
                std::cout << "Enter point coordinates (x y): ";
                std::cin >> x >> y;

                Identi id = app.addObject(PrimitiveType::POINT);
                Point<double>* pt = app.findObjectById(id, app.getPoints());
                if (pt) {
                    pt->set_x(x);
                    pt->set_y(y);
                }
                std::cout << "Point created with ID: " << id.getID()
                          << " at (" << x << ", " << y << ")\n";
                break;
            }

            case 2: {
                double x1, y1, x2, y2;
                std::cout << "Enter first point coordinates (x1 y1): ";
                std::cin >> x1 >> y1;
                std::cout << "Enter second point coordinates (x2 y2): ";
                std::cin >> x2 >> y2;

                Identi id = app.addObject(PrimitiveType::SEGMENT);
                Segment<double>* seg = app.findObjectById(id, app.getSegments());
                if (seg) {
                    seg->set_p1(Point<double>(x1, y1));
                    seg->set_p2(Point<double>(x2, y2));
                }
                std::cout << "Segment created with ID: " << id.getID()
                          << " from (" << x1 << ", " << y1
                          << ") to (" << x2 << ", " << y2 << ")\n";
                break;
            }

            case 3: {
                double x, y, radius;
                std::cout << "Enter center coordinates (x y): ";
                std::cin >> x >> y;
                std::cout << "Enter radius: ";
                std::cin >> radius;

                Identi id = app.addObject(PrimitiveType::CIRCLE);
                Circle<double>* circ = app.findObjectById(id, app.getCircles());
                if (circ) {
                    circ->set_center(Point<double>(x, y));
                    circ->set_radius(radius);
                }
                std::cout << "Circle created with ID: " << id.getID()
                          << " center (" << x << ", " << y
                          << "), radius " << radius << "\n";
                break;
            }

            case 4: {
                int arrangeType;
                printMutualArrangeTypes();
                std::cin >> arrangeType;

                std::cout << "Enter number of objects: ";
                int numObjects;
                std::cin >> numObjects;

                Storage<Identi> idStorage;
                std::cout << "Enter object IDs (one per line):\n";
                for (int i = 0; i < numObjects; ++i) {
                    int idValue;
                    std::cin >> idValue;
                    idStorage.addItem(Identi(idValue));
                }

                double value = 0.0;
                if (arrangeType == 2 || arrangeType == 7) {
                    std::cout << "Enter target value: ";
                    std::cin >> value;
                }

                MutualArrangeType type = static_cast<MutualArrangeType>(arrangeType - 1);
                Identi relationId = app.addArrange(type, idStorage, value);

                std::cout << "Relation created with ID: " << relationId.getID() << "\n";
                break;
            }

            case 5: {
                std::cout << "\n=== Current objects ===\n";
                std::cout << "Points:\n";
                app.getPoints().print();
                std::cout << "\nSegments:\n";
                app.getSegments().print();
                std::cout << "\nCircles:\n";
                app.getCircles().print();
                std::cout << "\n";
                break;
            }

            case 6: {
                std::cout << "Sum of errors: " << app.sumErrors() << "\n";
                break;
            }

            case 7: {
                Rect<double> r = app.unionRect();
                std::cout << "Bounding rectangle:\n";
                std::cout << "  top-left:     (" << r.topLeft().x()     << ", " << r.topLeft().y()     << ")\n";
                std::cout << "  bottom-right: (" << r.bottomRight().x() << ", " << r.bottomRight().y() << ")\n";
				 
                break;
            }

			case 8: {
				app.print("result.bmp");				
				break;
			}

            case 9: {
                app.solve();
            }

        }
    }

    return 0;
}
