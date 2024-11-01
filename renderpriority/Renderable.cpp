//
// Created by Thy Tran on 10/31/24.
//

#include "Renderable.h"

int main(){
    Renderable rc;
    Vector3 nodePos = global_model.getTranslation();
    rc.mesh = mesh;
    rc.material = material;
    rc.model = global_model;
    rc.distance_to_cam = distance(camPos, nodePos);
    renderables.push_back(rc);


}