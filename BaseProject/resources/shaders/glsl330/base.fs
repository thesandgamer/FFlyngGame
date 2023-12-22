#version 330
#define     MAX_LIGHTS              4
#define     LIGHT_DIRECTIONAL       0
#define     LIGHT_POINT             1

// Input vertex attributes (from vertex shader)
in vec2 fragTexCoord;
in vec4 fragColor;

// Input uniform values
uniform sampler2D texture0;//Texture de l'objet
uniform vec4 colDiffuse;//Couleur de l'objet


// Output fragment color
out vec4 finalColor;
// NOTE: Add here your custom variables
uniform vec3 viewPos;

in vec3 fragPos;
in vec3 fragNorm;

struct MaterialProperty {
    vec3 color;
    int useSampler;
    sampler2D sampler;
};

struct Light {
    int enabled;
    int type;
    vec3 position;
    vec3 target;
    vec4 color;
};

// Input lighting values
uniform Light lights[MAX_LIGHTS];
uniform vec4 ambientColor;   //Ici l'ambiant qu'on va changer

void main()
{
    vec3 result = vec3(0,0,0);
  	for (int i = 0; i < MAX_LIGHTS; i++)
    {
        if (lights[i].enabled == 1)
        {
            // ambient
            vec3 ambient = ambientColor.xyz * lights[i].color.xyz;


            // diffuse 
            vec3 norm = normalize(fragNorm);
            vec3 lightDir = normalize(lights[i].position - fragPos);
            float diff = max(dot(norm, lightDir), 0.0);
            vec3 diffuse = diff * lights[i].color.xyz;
            
            // specular
            float specularStrength = 0.5;
            vec3 viewDir = normalize(viewPos - fragPos);
            vec3 reflectDir = reflect(-lightDir, norm);  
            float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
            vec3 specular = specularStrength * spec * lights[i].color.xyz;  
        // vec3 specular = lights[i].spec.xyz * spec * vec3(texture(material.specular, TexCoords));  
            
            result += (ambient + diffuse + specular) * colDiffuse.xyz;
            }

    }
        
    
    finalColor = vec4(result, 1.0);
}

