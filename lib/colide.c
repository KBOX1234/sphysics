int pixelDistance(struct point* a, struct point* b){
    int dist = 0;
    if(a->x > b->x) dist = dist + ((int)a->x-(int)b->x);
    else dist = dist + ((int)b->x-(int)a->x);

    if(a->y > b->y) dist = dist + ((int)a->y-(int)b->y);
    else dist = dist + ((int)b->y-(int)a->y);
    return dist;
}

int xDistance(int x1, int x2){
    if(x1 > x2) return x1 - x2;
    else return x2 - x1;
}

int yDistance(int y1, int y2){
    if(y1 > y2)return y1 - y2;
    else return y2 - y1;
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
