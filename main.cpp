#include <iostream>
#include "Objects.h"

double calculateTime(Line l, Plane f) {
    double t = -(f.d + f.a * l.p.x + f.b * l.p.y + f.c * l.p.z) / (f.a * l.v.x + f.b * l.v.y + f.c * l.v.z);
    return (t > 0) ? t : 999999999999999;
}

int main() {
    Cube space(Plane(1, 0, 0, -1), Plane(0, 1, 0, -1), Plane(0, 0, 1, -1));
    Point position;
    Vector speed;
    double time;
    cin >> position.x >> position.y >> position.z;
    cin >> speed.x >> speed.y >> speed.z;
    cin >> time;
    do{
        Line direction = Line(position, speed);
        double times[] = {calculateTime(direction, Plane(1, 0, 0, 0)), calculateTime(direction, Plane(0, 1, 0, 0)),
                          calculateTime(direction, Plane(0, 0, 1, 0)), calculateTime(direction, space.xy),
                          calculateTime(direction, space.yz), calculateTime(direction, space.xz)};

        double mi = *min_element(times, times + 6);
        for(int i = 0; i < 6; ++i) {
            if(times[i] == mi) {
                if (i == 0 || i == 3)
                    speed.x *= -1;
                else if (i == 1 || i == 4)
                    speed.y *= -1;
                else if (i == 2 || i == 5)
                    speed.z *= -1;
            }
        }
        if(time - mi < 0){
            position = Point(direction.p.x + direction.v.x * time, direction.p.y + direction.v.y * time, direction.p.z + direction.v.z * time);
            time -= mi;

        } else{
            time -= mi;
            position = Point(direction.p.x + direction.v.x * mi, direction.p.y + direction.v.y * mi, direction.p.z + direction.v.z * mi);

        }
        cout << position.x << " " << position.y << " " << position.z << endl;
    } while (time >= 0);
}