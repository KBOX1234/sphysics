#include "../sphysics.h"

int pixelDistance(struct point* a, struct point* b){
    int dist = 0;
    if(a->x > b->x) dist = dist + ((int)a->x-(int)b->x);
    else dist = dist + ((int)b->x-(int)a->x);

    if(a->y > b->y) dist = dist + ((int)a->y-(int)b->y);
    else dist = dist + ((int)b->y-(int)a->y);
    return dist;
}

char doesBoxAndPointColide(struct colideBox* box, struct point* point){
    if(point->x >= box->a.x && point->x <= box->b.x && point->y >= box->a.y && point->y <= box->b.y){
        return 1;
    }
    else return 0;
}

char doesBoxAndBoxColide(struct colideBox* box1, struct colideBox* box2){
    if(doesBoxAndPointColide(box1, &box2->a) == 1) return 1;
    struct point cache = {box2->b.x + box2->a.y};
    if(doesBoxAndPointColide(box1, &cache) == 1) return 2;
    if(doesBoxAndPointColide(box1, &box2->b) == 1) return 3;
    cache.y =  box2->b.y;
    cache.x = box2->a.x;
    if(doesBoxAndPointColide(box1, &cache) == 1) return 4;

    if(doesBoxAndPointColide(box2, &box1->a) == 1) return 5;
    cache.x = box1->b.x;
    cache.y = box1->a.y;
    if(doesBoxAndPointColide(box2, &cache) == 1) return 6;
    if(doesBoxAndPointColide(box2, &box1->b) == 1) return 7;
    cache.y =  box1->b.y;
    cache.x = box1->a.x;
    if(doesBoxAndPointColide(box2, &cache) == 1) return 8;

    else return 0;
}

char doesBoxAndBoxColideD(struct colideBox* box1, struct colideBox* box2) {
    // Check if there is a separation on the x-axis
    if (box1->a.x > box2->b.x || box2->a.x > box1->b.x) {
        return 0;  // No collision
    }

    // Check if there is a separation on the y-axis
    if (box1->a.y > box2->b.y || box2->a.y > box1->b.y) {
        return 0;  // No collision
    }

    // If there is no separation, boxes are colliding
    return 1;
}

bool doesBoxAndBoxCollide(struct colideBox* box1, struct colideBox* box2) {
    // Check if there is a separation on the x-axis
    if (box1->a.x > box2->b.x || box2->a.x > box1->b.x) {
        return false;  // No collision
    }

    // Check if there is a separation on the y-axis
    if (box1->a.y > box2->b.y || box2->a.y > box1->b.y) {
        return false;  // No collision
    }

    // If there is no separation, boxes are colliding
    return true;
}

int gcd(struct fraction fract) {
    while (fract.down != 0) {
        int temp = fract.down;
        fract.down = fract.up % fract.down;
        fract.up = temp;
    }
    return fract.up;
}

struct fraction yincPerXdincPolygon(struct colidePolygon* poly){
    struct fraction res;
    if(poly->a.x > poly->b.x) res.up = poly->a.x - poly->b.x;
    else res.up = poly->b.x - poly->a.x;

    if(poly->a.y > poly->b.y) res.down = poly->a.y - poly->b.y;
    else res.down = poly->b.y - poly->a.y;

    int divisor = gcd(res); // Calculate GCD after defining res
    res.up = res.up / divisor;
    res.down = res.down / divisor;

    return res;
}

int doesPointAndPolyColide(struct colidePolygon* poly, struct point* point) {
    float x1 = poly->a.x;
    float y1 = poly->a.y;
    float x2 = poly->b.x;
    float y2 = poly->b.y;
    float x3 = poly->c.x;
    float y3 = poly->c.y;
    float px = point->x;
    float py = point->y;

    float area = 0.5 * (-y2 * x3 + y1 * (-x2 + x3) + x1 * (y2 - y3) + x2 * y3);
    float s = 1 / (2 * area) * (y1 * x3 - x1 * y3 + (y3 - y1) * px + (x1 - x3) * py);
    float t = 1 / (2 * area) * (x1 * y2 - y1 * x2 + (y1 - y2) * px + (x2 - x1) * py);

    if (s > 0 && t > 0 && 1 - s - t > 0)
        return 1; // Point is inside the triangle
    else
        return 0; // Point is outside the triangle
}

int doesPolyAndPolyColide(struct colidePolygon* poly1, struct colidePolygon* poly2){
    if(doesPointAndPolyColide(poly1, &poly2->a)) return 1;
    if(doesPointAndPolyColide(poly1, &poly2->b)) return 2;
    if(doesPointAndPolyColide(poly1, &poly2->c)) return 3;

    if(doesPointAndPolyColide(poly2, &poly1->a)) return 4;
    if(doesPointAndPolyColide(poly2, &poly1->b)) return 5;
    if(doesPointAndPolyColide(poly2, &poly1->c)) return 6;
    else return 0;
}
