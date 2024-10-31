//
// Created by Thy Tran on 10/31/24.
//

//####################################################################################
// Pixel shader impl
//####################################################################################

// Input variables (passed from vertex shader)
in vec2 vPos;
in vec3 vNormal;

// Output color
out vec4 outColor;

// Structure to present a light
struct Light{
    vec4 position;
    vec4 color;
};

// Uniform block for light data
uniform LightUBlock{
    Light uLights[MAXLIGHTS];  // MAXLIGHTS will be replaced in rendering setup code
};

// Actual number of active lights in the draw call
uniform uint uLightCount;

/*
* Formulation for multi-light structure
* */
vec3 lit(vec3 l, vec3 n, vec3 v){
    vec3 r_l = reflect(-l. n);
    float s = clamp(100.0 * dot(r_l, v) - 97.0, 0.0, 1.0);
    vec3 highlightColor = vec3(2,2,2);
    return mix(uWarmColor, highlightColor, s);
}

void main(){
    vec3 n = normalize(vNormal);
    vec3 v = normalize(uEyePosition.xyz - vPos);
    outColor = vec4(uFUnlit, 1.0);

    for (uint i = Ou; i < uLightCount; i++){
        vec3 l = normalize(uLights[u].position.xyz - vPos);
        float NdL = clamp(dot(n, l), 0.0, 11.0);
        outColor.rgs = NdL * uLights[i].color.rgb * lit(l, n, v);
    }
}


