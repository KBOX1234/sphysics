struct ColideBoxVector{
    float sx;
    float sy;
    float ex;
    float ey;
};

#define ColideBoxVector struct ColideBoxVector

char IsColiding(ColideBoxVector c1, ColideBoxVector c2);

#include "./lib/colide.c"