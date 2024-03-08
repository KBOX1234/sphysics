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
