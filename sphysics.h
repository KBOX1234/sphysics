struct point{
    float x;
    float y;
};

struct colideBox{
    struct point a;
    struct point b;
};

int pixelDistance(struct point* a, struct point* b);

int xDistance(int x1, int x2);

int yDistance(int y1, int y2);

char doesBoxAndPointColide(struct colideBox* box, struct point* point);

char doesBoxAndBoxColide(struct colideBox* box1, struct colideBox* box2);



#include "./lib/colide.c"
