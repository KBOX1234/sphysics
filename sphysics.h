
//A vector 2 point with an X and a Y axis
struct point{
    float x;
    float y;
};

//A rectangler colide box (its faster than a colidePolygon on systems without a fpu)
struct colideBox{
    struct point a;
    struct point b;
};

//A triangle shaped colision box for more complex/accurate colisions
struct colidePolygon{
    struct point a;
    struct point b;
    struct point c;
};

//just a fraction
struct fraction{
    int up;
    int down;
};

struct shape{
    unsigned char active;
    struct colidePolygon polygons[255];
    int Xoffset;
    int Yoffset;
}

//measures the distance between point a and point b
int pixelDistance(struct point* a, struct point* b);

//gets the greatest common factor
int gcd(struct fraction fract);

//useless function that I ended up not using
struct fraction yincPerXdincPolygon(struct colidePolygon* poly);

//sees if a point and a box colide
char doesBoxAndPointColide(struct colideBox* box, struct point* point);

//sees if 2 boxes are coliding
char doesBoxAndBoxColide(struct colideBox* box1, struct colideBox* box2);

//sees if a point and a polygon are coliding
int doesPointAndPolyColide(struct colidePolygon* poly, struct point* point);

//sees if 2 polygons are coliding
int doesPolyAndPolyColide(struct colidePolygon* poly1, struct colidePolygon* poly2);

#include "./lib/colide.c"

void rotatePolygon(struct colidePolygon* poly, float angle);

#include "./lib/translate.h"