int pixelDistance(struct point* a, struct point* b){
    int dist = 0;
    if(a->x > b->x) dist = dist + ((int)a->x-(int)b->x);
    else dist = dist + ((int)b->x-(int)a->x);

    if(a->y > b->y) dist = dist + ((int)a->y-(int)b->y);
    else dist = dist + ((int)b->y-(int)a->y);
}

char doesBoxAndPointColide(struct colideBox* box, struct point* point){
    if(point->x > box->a.x && point->x < box->b.x && point->y > box->a.y && point->y < box->b.y){
        return 1;
    }
    else return 0;
}