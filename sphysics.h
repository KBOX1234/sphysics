struct point{
    float x;
    float y;
};

struct ColideShape{
    struct point points[255];
    unsigned char active;
};

int pixleDistance(struct point* a, struct point* b);

char DoesPointColideWithShape(struct ColideShape* shape, struct point*);

char DoesShapeColide(struct ColideShape* a, struct ColideShape* b);

#include "./lib/colide.c"
