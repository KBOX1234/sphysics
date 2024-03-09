void rotatePoly(struct colidePolygon* poly, float angle, struct point origin){
        // Translate the point so that the custom origin becomes the new origi
  //
    
    angle = angle * 3.141 / 180;

    poly->a.x -= origin.x;
    poly->a.y -= origin.y;

    // Perform rotation around the translated origin
    float x = poly->a.x;
    float y = poly->a.y;
    poly->a.x = x * cos(angle) - y * sin(angle);
    poly->a.y = x * sin(angle) + y * cos(angle);

    // Translate the point back to its original position
    poly->a.x += origin.x;
    poly->a.y += origin.y;



    poly->b.x -= origin.x;
    poly->b.y -= origin.y;

    // Perform rotation around the translated origin
    x = poly->b.x;
    y = poly->b.y;
    poly->b.x = x * cos(angle) - y * sin(angle);
    poly->b.y = x * sin(angle) + y * cos(angle);

    // Translate the point back to its original position
    poly->b.x += origin.x;
    poly->b.y += origin.y;


    poly->c.x -= origin.x;
    poly->c.y -= origin.y;

    // Perform rotation around the translated origin
    x = poly->c.x;
    y = poly->c.y;
    poly->c.x = x * cos(angle) - y * sin(angle);
    poly->c.y = x * sin(angle) + y * cos(angle);

    // Translate the point back to its original position
    poly->c.x += origin.x;
    poly->c.y += origin.y;

}

struct point getOrigin(struct colidePolygon* poly){
    struct point center = {0, 0};
    
    // Calculate the average of x and y coordinates of all vertices
    center.x = (poly->a.x + poly->b.x + poly->c.x) / 3.0f;
    center.y = (poly->a.y + poly->b.y + poly->c.y) / 3.0f;
    
    return center;
}

void movePoly(struct colidePolygon* poly, struct point xy){
    poly->a.x = poly->a.x + xy.x;
    poly->a.y = poly->a.y + xy.y;

    poly->b.x = poly->b.x + xy.x;
    poly->b.y = poly->b.y + xy.y;

    poly->c.x = poly->c.x + xy.x;
    poly->c.y = poly->c.y + xy.y;
}

void moveBox(struct colideBox* box, struct point xy){
    box->a.x = box->a.x + xy.x;
    box->a.y = box->a.y + xy.y;

    box->b.x = box->b.x + xy.x;
    box->b.y = box->b.y + xy.y;
}
