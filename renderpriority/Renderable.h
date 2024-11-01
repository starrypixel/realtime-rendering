//
// Created by Thy Tran on 10/31/24.
//

#ifndef RENDERABLE_H
#define RENDERABLE_H



class Renderable {
public:
    Mesh* mesh;
    Material* material;
    Matrix44 model;

    float distance_to_cam;

};



#endif //RENDERABLE_H
