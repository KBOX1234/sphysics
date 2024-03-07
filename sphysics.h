struct point{
    float x;
    float y;
};

struct colideBox{
    struct point a;
    struct point b;
};

int pixelDistance(struct point* a, struct point* b);

char doesBoxAndPointColide(struct colideBox* box, struct point* point);
#include "./lib/colide.c"
