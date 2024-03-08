struct point{
    float x;
    float y;
};

struct colideBox{
    struct point a;
    struct point b;
};

struct colidePolygon{
    struct point a;
    struct point b;
    struct point c;
};

struct fraction{
    int up;
    int down;
};

int pixelDistance(struct point* a, struct point* b);

int gcd(struct fraction fract);

struct fraction yincPerXdincPolygon(struct colidePolygon* poly);

char doesBoxAndPointColide(struct colideBox* box, struct point* point);

char doesBoxAndBoxColide(struct colideBox* box1, struct colideBox* box2);

int doesPointAndPolyColide(struct colidePolygon* poly, struct point* point);



#include "./lib/colide.c"
