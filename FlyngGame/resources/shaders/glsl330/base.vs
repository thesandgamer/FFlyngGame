#version 330

// Input vertex attributes
in vec3 vertexPosition;
in vec2 vertexTexCoord;//For texture
in vec3 vertexNormal;
in vec4 vertexColor;

// Input uniform values
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

// Output vertex attributes (to fragment shader)
out vec2 fragTexCoord;//For texture
out vec4 fragColor;
out vec3 fragPos;
out vec3 fragNorm;

// NOTE: Add here your custom variables

void main()
{
    // Send vertex attributes to fragment shader
    fragTexCoord = vertexTexCoord;
    fragColor = fragColor;

    fragPos = vec3(model * vec4(vertexPosition, 1.0));
    fragNorm = mat3(transpose(inverse(model))) * vertexNormal;
    
    // Calculate final vertex position
    gl_Position = projection * view * model * vec4(vertexPosition, 1.0);
}